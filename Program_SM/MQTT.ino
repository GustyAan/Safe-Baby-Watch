#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Adafruit_MLX90614.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <TimeLib.h>

// WiFi credentials
const char *ssid = "SSSs";
const char *password = "98765123";

// MQTT broker info
const char *mqtt_broker = "broker.hivemq.com";
const int mqtt_port = 1883;

// NTP client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 25200); // Offset WIB

unsigned long lastDisplayUpdate = 0; // For non-blocking display updates
unsigned long lastMqttPublish = 0;   // For non-blocking MQTT publishing

// Display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// MAX30105 Sensor settings
MAX30105 particleSensor;
#define BUFFER_LENGTH 100
uint32_t irBuffer[BUFFER_LENGTH];
uint32_t redBuffer[BUFFER_LENGTH];
int32_t spo2;
int8_t validSPO2;
int32_t heartRate;
int8_t validHeartRate;

// Temperature sensor settings
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float ambientTempC, objectTempC;

// MQTT and WiFi client setup
WiFiClient espClient;
PubSubClient client(espClient);

// Task for MQTT on core 0
TaskHandle_t Task0;

// Function declarations
void wifiSetup();
void mqttTask(void *pvParameters);
void checkConnection();
void callback(char *topic, byte *payload, unsigned int length);
void getSensorData();

void setup() {
  Serial.begin(115200);
  
  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Initialize MLX90614 sensor
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  }

  // Initialize MAX30105 sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) { 
    Serial.println("MAX30105 not found. Check wiring.");
    while (1);
  }
  particleSensor.setup(60, 4, 2, 100, 411, 4096);

  // WiFi setup
  wifiSetup();
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);

  // MQTT task on Core 0
  xTaskCreatePinnedToCore(
    mqttTask, "Task0", 10000, NULL, 1, &Task0, 0);

  // Initialize NTP client
  timeClient.begin();

  // Initial display messages
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 1);
  display.println("Safe Baby Watch");
  
  display.setTextSize(2);
  display.setCursor(0, 18);
  display.println("Sensor:");

    display.setTextSize(2);
  display.setCursor(0, 37);
  display.println("Proses");
  display.display();
}

void loop() {
  // Non-blocking sensor and time updates using millis()
  unsigned long currentMillis = millis();

  if (currentMillis - lastDisplayUpdate >= 1000) {
    lastDisplayUpdate = currentMillis;
    timeClient.update();
    getSensorData();

    // Format time and date
    unsigned long rawTime = timeClient.getEpochTime();
    time_t t = rawTime;

    String jamStr = String(hour(t));
    String menitStr = String(minute(t));
    String detikStr = String(second(t));
    String tanggal = String(day(t)) + "/" + String(month(t)) + "/" + String(year(t));
    String waktu = jamStr + ":" + menitStr + ":" + detikStr;

    // Display time and date
    display.clearDisplay();
    display.setTextSize(1); // Small text size for date
    display.setTextColor(WHITE);
    display.setCursor(0, 1);
    display.println(tanggal);

    display.setTextSize(2); // Larger text for time
    display.setCursor(0, 16);
    display.println(waktu);

    display.setCursor(0, 39);
    display.println("SensorWork");

    display.display(); // Update display
  }
}

// Function to read sensor data
void getSensorData() {
  ambientTempC = mlx.readAmbientTempC();
  objectTempC = mlx.readObjectTempC();
  
  // Update SpO₂ and Heart Rate
  for (int i = 0; i < BUFFER_LENGTH; i++) {
    while (!particleSensor.available()) particleSensor.check();
    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample();
  }
  maxim_heart_rate_and_oxygen_saturation(irBuffer, BUFFER_LENGTH, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);
}

// MQTT Task function
void mqttTask(void *pvParameters) {
  unsigned long lastMqttPublish = 0;
  while (1) {
    Serial.print("MQTT Task running on core ");
    Serial.println(xPortGetCoreID());

    checkConnection();

    unsigned long currentMillis = millis();
    if (currentMillis - lastMqttPublish >= 5000) { // Publish every 5 seconds
      lastMqttPublish = currentMillis;

      // Publish sensor data
      client.publish("esp32/ambientTemp", String(ambientTempC).c_str());
      client.publish("esp32/objectTemp", String(objectTempC).c_str());
      client.publish("esp32/spo2", String(spo2).c_str());
      client.publish("esp32/heartRate", String(heartRate).c_str());
    }
    
    client.loop();
    vTaskDelay(10 / portTICK_PERIOD_MS); // Short delay for task scheduling
  }
}

void wifiSetup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  Serial.println("Connected to WiFi");
}

void checkConnection() {
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("Connecting to MQTT Broker with ID: %s\n", client_id.c_str());

    if (client.connect(client_id.c_str())) {
      Serial.println("MQTT Broker connected");
    } else {
      Serial.print("Failed to connect, state: ");
      Serial.println(client.state());
      vTaskDelay(2000 / portTICK_PERIOD_MS); // Delay before retrying
    }
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char) payload[i]);
  }
  Serial.println();
}
