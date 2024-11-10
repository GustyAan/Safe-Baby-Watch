**#PROJECCT PBL: Safe Watch**
**#PROGRAM STUDI SARJANA TERAPAN TEKNIK ELEKTRONIKA, DEPARTEMEN TEKNIK ELEKTRO, POLITEKNIK ELEKTRONIKA NEGERI SURABAYA, 2024**

# Safe Watch 
Merupakan proyek SmartWatch Pemantau Kesehatan Bayi ini adalah memberikan solusi kesehatan yang inovatif untuk memantau kondisi kesehatan bayi secara real-time. Proyek ini bertujuan untuk membantu orang tua dan pengasuh dalam mendeteksi dini masalah kesehatan bayi, sehingga mereka dapat mengambil tindakan pencegahan atau perawatan yang tepat dengan cepat. Dengan menggunakan teknologi IoT, alat ini memungkinkan pemantauan kesehatan bayi yang lebih praktis, efisien, dan akurat, sehingga memberikan ketenangan bagi orang tua dalam menjaga kesejahteraan bayi mereka.

**Desain dan Perencanaan**

**A. Perancangan awal**

Peta koneksi 

![image](https://github.com/user-attachments/assets/213d96c3-f8b7-4db5-96b1-607c25e38d71)

PCB yang telah dicetak didokumentasikan dengan hasil cetak desain PCB berikut:

Tampak bawah:

![image](https://github.com/user-attachments/assets/81e9ae7a-c2b7-4c75-8271-1d56c0955975)

Tampak atas:

![image](https://github.com/user-attachments/assets/19f89f37-dbe7-4766-bc7b-5b2adfc76da6)

DIAGRAM SISTEM

![image](https://github.com/user-attachments/assets/e3545708-e1d0-4b24-80e6-9357fcf48d4f)

Sistem Safe Watch bekerja dengan sensor MAX30102 yang mendeteksi detak jantung (HR) sedangkan sensor GY906 mengukur suhu tubuh bayi dan suhu lingkungan tanpa kontak fisik sensor melalui jam tangan yang terkoneksi dengan internet melalui ESP32. Data yang dikumpulkan dari kedua sensor ini kemudian diproses oleh modul ESP32, yang berfungsi sebagai pusat pemrosesan data dalam sistem. Layar OLED pada perangkat menampilkan informasi detak jantung dan suhu tubuh bayi secara real-time, memudahkan pemantauan langsung. Jika sistem mendeteksi adanya kondisi abnormal, seperti peningkatan suhu atau perubahan signifikan dalam detak jantung. Data ini juga dikirimkan melalui koneksi WiFi ke tambilan mobile, memungkinkan pemantauan jarak jauh dan real-time oleh orang tua atau pengasuh. Diagram sistem ini memberikan gambaran jelas tentang koneksi antara sensor dan ESP32, serta aliran data menuju aplikasi untuk pemantauan.

**B. Diagram dan arsitektur**

USE CASE DIAGRAM:

![image](https://github.com/user-attachments/assets/be8592f2-f5d5-41c5-828e-7899528ed779)
![image](https://github.com/user-attachments/assets/122f8146-2a26-44c5-826f-a586404d9e0f) ![image](https://github.com/user-attachments/assets/94b70f10-c363-45ee-b04f-aaac74db31cc)

Pengguna dapat menerima data sensor yang dipublikasikan oleh ESP32 melalui broker MQTT. Dalam skenario ini, ESP32 bertanggung jawab untuk menghubungkan perangkat ke jaringan WiFi, mengumpulkan data dari berbagai sensor seperti suhu tubuh dan detak jantung, serta mengirimkan data tersebut ke broker MQTT. ESP32 juga melakukan sinkronisasi waktu dengan server NTP untuk memastikan waktu yang akurat digunakan dalam pengolahan dan penyajian data.

Broker MQTT berfungsi sebagai perantara dalam pengelolaan pesan yang dikirim oleh ESP32. Setiap perangkat yang berlangganan ke topik tertentu dapat menerima data yang sesuai dengan topik tersebut, seperti data sensor dari ESP32. Server NTP menyediakan waktu yang tepat yang digunakan oleh ESP32 untuk menyinkronkan waktu dalam sistem. Hal ini memastikan bahwa data yang dikirim dan diterima oleh ESP32 serta perangkat lainnya tetap terorganisir dengan baik dan sesuai dengan waktu yang akurat.

CLASS DIAGRAM

Class diagram dalam sistem ini menggambarkan struktur perangkat dan fungsionalitas masing-masing komponen. Ada beberapa kelas utama, yaitu kelas ESP32 yang berfungsi untuk menghubungkan perangkat ke WiFi, mengumpulkan data dari sensor, dan mengirimkan data tersebut ke broker MQTT. Kelas Sensor menjadi kelas dasar, dengan kelas turunannya seperti TemperatureSensor dan HeartRateSensor, yang masing-masing memiliki atribut dan metode untuk membaca data sensor suhu tubuh dan kadar oksigen dalam darah. Kelas MQTTClient mengelola koneksi dan komunikasi dengan broker MQTT, sementara kelas NTPClient mengelola sinkronisasi waktu dengan server NTP. Setiap kelas ini berinteraksi satu sama lain untuk menjalankan sistem secara keseluruhan. Berikut adalah diagram untuk class diagram:

![image](https://github.com/user-attachments/assets/956ddd09-2f74-4653-931c-c7cc29f03ff6)

SEQUNCE DIAGRAM

Sequence diagram menggambarkan urutan interaksi antara objek dalam sistem. Pada diagram ini, urutan langkah-langkah yang dilakukan adalah sebagai berikut: 

Pengguna mengirimkan perintah kepada ESP32, yang kemudian menghubungkan ke WiFi, mengumpulkan data sensor dari TemperatureSensor dan HeartRateSensor, kemudian mengirimkan data tersebut ke Broker MQTT. Broker MQTT kemudian mempublikasikan data ke topik yang sesuai, yang akan diterima oleh Pengguna yang berlangganan topik tersebut. Selain itu, ESP32 melakukan sinkronisasi waktu dengan Server NTP. Berikut adalah diagram untuk sequence diagram:

![image](https://github.com/user-attachments/assets/10a24828-5c7d-4898-994c-85fa0c0d9a41)

ARSITEKTUR IoT

Arsitektur sistem IoT pada program ini terdiri dari beberapa komponen yang saling terhubung. ESP32 adalah perangkat utama yang menghubungkan ke WiFi, mengumpulkan data dari sensor, dan mengirimkan data ke broker MQTT. Broker MQTT bertanggung jawab untuk mengelola komunikasi antara perangkat, seperti mengirimkan data sensor kepada perangkat yang berlangganan topik tertentu. Server NTP digunakan untuk memastikan waktu yang akurat di ESP32 sehingga data yang dikirimkan memiliki timestamp yang tepat. Sistem ini berbasis IoT, dimana ESP32 menghubungkan sensor fisik dengan cloud melalui MQTT. Berikut adalah mermaid diagram untuk arsitektur sistem IoT:

![image](https://github.com/user-attachments/assets/a0379fcf-5933-4aa5-8da7-a1d460d42f54)

TOPOLOGI JARINGAN

Topologi jaringan yang digunakan dalam proect ini adalah model client-server yang berbasis pada topologi bintang (star topology), dengan ESP32 sebagai client dan broker MQTT sebagai server. Dalam model client-server ini, ESP32 mengirimkan data sensor ke broker MQTT, yang kemudian akan mendistribusikan data tersebut ke perangkat lain yang berlangganan topik yang relevan. Broker MQTT berperan sebagai server yang mengelola komunikasi antara ESP32 dan perangkat lain yang membutuhkan data, seperti perangkat yang memantau suhu atau data kesehatan lainnya. Dengan cara ini, perangkat lain dapat mengakses data secara real-time melalui proses publikasi dan langganan (publish-subscribe) yang dilakukan oleh broker MQTT.

Pada topologi bintang, semua perangkat dalam jaringan terhubung ke pusat yang sama, yaitu WiFi router. ESP32 terhubung ke router WiFi untuk mengirimkan data ke broker MQTT melalui internet, serta untuk mengakses waktu yang akurat dari server NTP. WiFi router berfungsi sebagai jalur komunikasi utama yang menghubungkan semua perangkat dalam jaringan. Dengan struktur ini, ESP32 dapat mengirimkan data sensor melalui WiFi ke broker MQTT, yang kemudian menyebarkan data tersebut kepada perangkat yang berlangganan. Di sisi lain, NTP server memastikan bahwa ESP32 selalu memiliki waktu yang akurat, yang sangat penting untuk pencatatan data sensor yang bergantung pada timestamp yang tepat.

![image](https://github.com/user-attachments/assets/2ae7ebf7-d7ab-444a-9ba1-042d57bc936c)

TAMPILAN APLIKASI

Tampilan aplikasi ini dirancang untuk menampilkan data sensor secara real-time, yang mencakup data heart rate, suhu tubuh, dan suhu udara sekitar. Setiap sensor memiliki tampilan berupa angka yang terus diperbarui sesuai pembacaan terbaru.

1. Setting Tampilan Suhu Udara

   ![image](https://github.com/user-attachments/assets/bb21f061-c784-4b38-ba2e-bc19b985ec75)
   
Client Publish: esp32/ambientTemp

Suhu Udara: Menampilkan suhu tubuh dalam °C.

Penyesuaian dan Kalibrasi: Jika lingkungan sekitar lebih panas, maka threshold bisa dinaikkan.

2. Setting tampilan Suhu Tubuh

![image](https://github.com/user-attachments/assets/3bc5dff8-5dac-42c9-ab0a-5b5fcbc5e376)
   
Client Publish: esp32/objectTemp

Suhu Tubuh: Menampilkan suhu tubuh dalam °C.

Penyesuaian dan Kalibrasi: Jika hasil bacaan suhu tidak akurat, lakukan kalibrasi sensor GY90614 agar data lebih akurat.

3. Setting tampilan Suhu Heart Rate

![image](https://github.com/user-attachments/assets/cce12a0c-53f5-4912-a28c-9b15203b86b4)
   
Client Publish: esp32/heartRate

Heart Rate: Menampilkan heart rate dalam BPM.

Penyesuaian dan Kalibrasi: Jika hasil bacaan herat rate tidak akurat, lakukan kalibrasi sensor MAX30102 agar data lebih akurat.

**C. IMPLEMENTASI HARDWARE**

Safe Watch secara garis besar memiliki komponen penting seperti kontroller dan perangkat sensing sebagai berikut:

1. **ESP32**:

![image](https://github.com/user-attachments/assets/d6294644-da8b-4ad8-ab61-5c486c9162e2)

ESP32 adalah modul berbasis microcontroller ESP8266 yang memiliki kemampuan Wi-Fi, sehingga dapat mengirim dan menerima data secara nirkabel melalui internet. Pada proyek Safe Watch, ESP32 digunakan sebagai otak utama yang mengumpulkan data dari berbagai sensor, memprosesnya, dan mengirimkan data tersebut ke aplikasi atau platform IoT. Hal ini memungkinkan pemantauan jarak jauh terhadap kondisi kesehatan bayi.

Tes koneksi WIFI ESP32

![image](https://github.com/user-attachments/assets/f1723e3d-c1bc-4413-9a46-a10e712eec22)

Pengujian koneksi WiFi pada ESP32 dengan metode WiFi Scan bertujuan untuk memastikan bahwa modul ESP32 dapat mendeteksi dan menampilkan daftar jaringan WiFi yang ada di sekitarnya. Proses ini berguna untuk memverifikasi bahwa antena dan modul WiFi pada ESP32 berfungsi dengan baik serta memastikan bahwa perangkat berada dalam jangkauan jaringan yang diinginkan. Metode ini juga membantu untuk mengetahui kekuatan sinyal (RSSI) dari masing-masing jaringan, sehingga kita dapat memilih jaringan yang paling kuat atau stabil untuk koneksi yang optimal.

2. **Sensor MAX30102**:
   
MAX30102 adalah sensor optik yang dapat mendeteksi detak jantung. Sensor ini bekerja dengan memancarkan cahaya dan mendeteksi refleksi cahaya tersebut dari pembuluh darah di kulit. Pada proyek ini, MAX30102 berguna untuk memantau detak jantung, sehingga dapat mendeteksi tanda-tanda vital dan memastikan bayi dalam kondisi yang aman. Sensor MAX 30102 memiliki spesifikasi sebagai berikut:
- Sensor: LED merah dan inframerah untuk mendeteksi detak jantung
- Tegangan Operasional: 1.8V untuk inti, 3.3V untuk LED
- Antarmuka Komunikasi: I2C
- Arus Rata-rata: 600µA (tergantung pengaturan)
- Mode Pengukuran: Detak jantung.
- Rentang Panjang Gelombang LED:
- LED Merah: 660 nm
- LED Inframerah: 880 nm

  Sensor MAX30102 ini sipilih karena memiliki kelebihan sebagai berikut:
- Penggunaan Daya: Rendah, cocok untuk perangkat wearable
- Penggunaan: Oximeter, deteksi detak jantung, perangkat medis wearable
- Dilengkapi dengan algoritma yang dapat membantu dalam pemrosesan sinyal detak jantung, sehingga cocok untuk perangkat wearable dan aplikasi kesehatan.

Dengan adanya kelebihan dan spesifikasi diatas, pengambilan data dalam sensor testing dapat dilakukan dengan mekanisme pengambilan data sebagai berikut:

![MAX30102](https://github.com/user-attachments/assets/e6edf8a3-6180-4b97-a5d3-7798063bdd32)

Sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/a90fc63f-1751-4e69-ba81-464ffe95bdcf)

Output testing:

Jika berhasil:

![Sensor Valid](https://github.com/user-attachments/assets/e712430c-d82a-4a49-bb8c-c2ae0d07dec6)

Jika Sensor gagal terinisialisasi:

![Sensor Invalid](https://github.com/user-attachments/assets/711b09dd-5df4-44f2-adc5-06b53c0a75ee)

Sensor testing ini ditujukan untuk mengetes fungsi sensor dengan memanfaatkan fungsi utamanya yakni mengukur denyut jantung menggunakan sensor MAX30102. Pertama, sistem menginisialisasi komunikasi serial untuk mengirim dan menerima data serta mengatur LED indikator sebagai output. Setelah itu, sensor MAX30102 diinisialisasi; jika berhasil, sistem menampilkan pesan "Attach sensor to finger. Press key to start" untuk meminta pengguna menempatkan jari mereka pada sensor. Namun, jika inisialisasi gagal, pesan kesalahan akan muncul untuk memeriksa kembali sambungan daya atau kabel.

Setelah sensor terpasang dan pengguna menekan tombol untuk memulai, sistem mengonfigurasi parameter sensor seperti kecerahan LED dan kecepatan sampel. Dalam loop utama, sistem membaca sampel data dari sensor, menyimpan data cahaya merah dan inframerah (IR) dalam buffer, dan menampilkan data ini pada monitor serial. Setelah pengumpulan data, sistem menghitung denyut jantung, kemudian menampilkannya. Loop ini berjalan terus menerus, memperbarui pembacaan denyut jantung, hingga kondisi penghentian dicapai.

3. **Sensor GY906**:
GY906 adalah sensor inframerah yang dapat mengukur suhu tanpa kontak fisik (non-contact) denganspesifikasi sebagai berikut:

- Sensor: GY906
- Rentang Suhu Objek: -70°C hingga 380°C
- Rentang Suhu Operasional: -40°C hingga 125°C
- Akurasi: ±0.5°C pada suhu objek antara 0 hingga 50°C
- Resolusi: 0.02°C
- Antarmuka Komunikasi: I2C dan PWM
- Tegangan Operasional: 3V hingga 5V
- Sudut Pandang: Sekitar 35°

Kelebihan non-contact ni memungkinkan pengukuran suhu tubuh bayi dari jarak dekat, tanpa perlu menyentuh kulit bayi, yang sangat penting untuk kenyamanan dan keamanan. Di proyek ini, GY906 digunakan untuk memantau suhu tubuh bayi secara real-time dan mendeteksi potensi demam atau perubahan suhu yang signifikan. Penggunaan sensor GY906 dikarenakan sensor memiliki beberapa kelebihan sebagai berikut:

- Pengukuran Suhu Non-Kontak: GY-906 menggunakan teknologi inframerah untuk mengukur suhu objek tanpa perlu menyentuhnya
- Akurasi Tinggi: Sensor ini memiliki akurasi sekitar ±0,5°C pada rentang suhu 0°C hingga 50°C
- Resolusi Tinggi: Dengan resolusi 0,02°C, sensor ini dapat mendeteksi perubahan suhu yang sangat kecil.
- Rentang Pengukuran Luas: GY-906 memiliki rentang pengukuran yang luas, dari -70°C hingga 380°C
- Konsumsi Daya Rendah: Sensor ini memiliki konsumsi daya yang rendah
- Antarmuka I2C dan PWM: Memiliki dua jenis antarmuka (I2C dan PWM)
- Sudut Pandang Lebar: Memiliki sudut pandang sekitar 35°, yang memungkinkannya untuk mendeteksi suhu dari area yang lebih luas
- Tahan terhadap Gangguan Elektromagnetik: Didesain dengan ketahanan yang baik terhadap interferensi elektromagnetik pengukuran lebih stabil dan dapat diandalkan dalam lingkungan industri.

Dengan kelebihan tersebut mekanisme pengambilan data dapat diambil sebagai berikut:

![DLOWCHART GY](https://github.com/user-attachments/assets/b7ca2806-85aa-4c06-a2f3-4e988c5c50df)

Hasil sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/63aa29ad-b7ee-499b-b67e-d243dc401204)

Test Solder (suhu tinggi):

![image](https://github.com/user-attachments/assets/9a97053b-3404-4814-ab52-21849c30fd0d)

Sistem dan cara kerja testing sensor ini menggunakan sensor GY906 dan layar OLED untuk menampilkan suhu secara real-time dalam sebuah aplikasi monitoring, seperti "SAFE WATCH." Cara kerja sistem dimulai dengan inisialisasi pustaka dan variabel untuk layar OLED dan sensor suhu, yang bertugas membaca suhu objek dari lingkungan sekitar. Program mengonfigurasi OLED display pada fungsi `setup`, termasuk pengaturan warna teks dan resolusi tampilan, serta mengaktifkan sensor inframerah agar dapat mengambil data suhu.

Selanjutnya, pada fungsi task utama, sistem membaca suhu secara berulang dan memperbarui tampilan OLED. Proses ini melibatkan pengambilan data suhu dari sensor inframerah, membersihkan buffer tampilan OLED agar tidak ada residu tampilan sebelumnya, dan menampilkan teks pengaman "SAFE WATCH" serta label suhu yang menunjukkan nilai terbaru. Suhu yang diperoleh dari sensor diubah menjadi string untuk memudahkan penampilannya pada layar, bersama dengan satuan suhu (derajat Celsius). Setelah proses ini selesai, OLED display diperbarui, dan loop berulang, memungkinkan pembacaan suhu terkini untuk ditampilkan terus-menerus pada layar sebagai informasi real-time.

4. **OLED 0.96**:
OLED 0.96 adalah layar kecil berukuran 0.96 inci yang menggunakan teknologi OLED (Organic Light Emitting Diode). Layar ini memiliki tampilan yang jernih dan kontras tinggi sehingga cocok untuk menampilkan informasi penting dalam ruang yang terbatas. Dalam proyek ini, OLED 0.96 digunakan untuk menampilkan data seperti detak jantung, suhu lingkungan, dan suhu bayi secara langsung, memudahkan pemantauan oleh pengguna di lokasi yang sama.

**D. IMPLEMENTASI SOFTWARE**

   1. Komunikasi dan Data

   a. Implementasi MQTT dalam program ESP32 menggunakan pustaka `PubSubClient` untuk menghubungkan ESP32 ke broker MQTT dan mengirimkan data sensor seperti suhu, dan detak jantung ke topik-topik yang telah ditentukan. Program ini memanfaatkan WiFi untuk mengakses internet dan menggunakan MQTT untuk berkomunikasi dengan broker secara teratur, mengirimkan pembaruan data sensor setiap beberapa detik. Dengan demikian, data sensor dapat diakses secara real-time oleh penerima yang berlangganan topik tertentu.

   b. Topik MQTT Terstruktur memungkinkan sistem untuk mengelola banyak node dengan cara mengorganisir topik menjadi kategori atau subkategori, seperti `esp32/device1/ambientTemp` atau. Struktur ini memungkinkan skalabilitas yang lebih besar, memungkinkan lebih dari 100 node dengan mengelompokkan data berdasarkan perangkat atau lokasi. Hal ini membuat manajemen data sensor menjadi lebih efisien dan memudahkan pemantauan berbagai perangkat dalam satu sistem yang terintegrasi.

   c. Sistem Batch Data dalam implementasi ini mengumpulkan data sensor dalam satu periode waktu tertentu, seperti setiap 5 detik, lalu mengirimkan data tersebut dalam satu batch ke broker MQTT. Metode ini mengurangi frekuensi pengiriman data dan meningkatkan efisiensi jaringan. Dengan mengirimkan beberapa nilai sensor sekaligus, sistem dapat mengurangi latensi dan memproses data dalam kelompok yang lebih besar, cocok untuk aplikasi yang membutuhkan pengumpulan data dalam jangka waktu tertentu.

   d. Error Handling diterapkan untuk memastikan kestabilan sistem dengan memeriksa koneksi WiFi dan MQTT secara berkala. Jika koneksi gagal, sistem akan mencoba kembali secara otomatis setelah jeda tertentu, sehingga memastikan bahwa komunikasi tetap terjaga tanpa interupsi. Jika terjadi masalah dalam koneksi atau pengiriman data, error handling akan memberi feedback kepada pengguna dan melakukan percobaan ulang sampai koneksi berhasil.

   e. Data Encryption dapat diimplementasikan untuk melindungi data yang dikirimkan melalui MQTT dengan menggunakan SSL/TLS. Hal ini dilakukan pada project dengan mengonfigurasi broker untuk menggunakan port SSL (seperti port 8883) dan mengaktifkan enkripsi dalam pengaturan koneksi MQTT. Enkripsi ini memastikan bahwa data yang dikirim antara ESP32 dan broker tetap aman dari potensi ancaman atau penyadapan, memberikan lapisan perlindungan tambahan pada sistem komunikasi.

   2. Dashboard dan Monitoring

   a. Real-time monitoring dalam program ESP32 ini merujuk pada kemampuan sistem untuk secara terus-menerus memantau dan menampilkan data sensor tanpa penundaan yang signifikan. Program ini mengintegrasikan sensor-sensor seperti suhu (dari MLX90614), detak jantung (dari MAX30105), serta waktu yang diperoleh dari NTP server untuk memastikan data yang ditampilkan pada layar OLED selalu diperbarui setiap detik. Program menggunakan fungsi `millis()` untuk memastikan pembaruan data sensor dan tampilan pada layar terjadi secara periodik tanpa memblokir eksekusi program lainnya. Data sensor yang diperoleh secara real-time juga diteruskan ke broker MQTT untuk dikirimkan ke sistem penerima atau dashboard yang mengamati kondisi sensor secara langsung, memberikan informasi terkini tentang suhu tubuh, kadar oksigen dalam darah, dan detak jantung pada setiap pembaruan yang terjadi. Ini memungkinkan pemantauan kesehatan atau kondisi lingkungan secara langsung dan dapat diakses secara cepat tanpa menunggu pembaruan data yang lambat.

   b. User Interface Responsif dalam program di atas mengacu pada tampilan antarmuka pengguna (UI) yang dapat memperbarui dan menampilkan informasi secara dinamis berdasarkan data sensor yang diterima dari ESP32. UI ini menggunakan layar OLED (SSD1306) untuk menampilkan data waktu, suhu, detak jantung dengan pembaruan yang teratur dan responsif. Program memanfaatkan fungsi `millis()` untuk memperbarui tampilan secara non-blok, memastikan bahwa layar tetap terperbarui tanpa mengganggu proses lainnya seperti pengambilan data sensor atau komunikasi MQTT.

Tampilan pada layar OLED ini dirancang agar informasinya dapat berubah sesuai dengan waktu dan data sensor yang terbaru. Sebagai contoh, waktu dan tanggal diperbarui setiap detik, sementara nilai sensor, seperti suhu dan HeartRate, diambil secara periodik dan ditampilkan secara real-time. Jika ada perubahan data sensor, tampilan akan diperbarui untuk menampilkan nilai terbaru dengan jelas.

UI yang responsif juga mencakup penanganan pembaruan tampilan dengan cara yang efisien. Misalnya, dengan menggunakan fungsi `display.clearDisplay()` dan `display.display()`, tampilan layar akan dibersihkan dan diperbarui dengan data terbaru tanpa menunggu proses lain selesai, yang memastikan bahwa data yang tampil selalu up-to-date dan menciptakan pengalaman pengguna yang lebih baik.

   c. Data Visualization dengan Broker Gratis dan Aplikasi MQTT dalam konteks program di atas melibatkan penggunaan broker MQTT gratis, seperti `broker.hivemq.com` yang digunakan dalam project ini, yang menerima data dari ESP32 dan memungkinkan visualisasi real-time data sensor di aplikasi yang mendukung MQTT, seperti `MQTT Dash`, `ThingSpeak`, atau platform serupa.

Program ESP32 mengirimkan data sensor, seperti suhu ambient dan objek, detak jantung, ke topik-topik MQTT yang terstruktur. Broker MQTT bertugas untuk menerima data tersebut dan mendistribusikannya ke semua perangkat yang berlangganan topik-topik yang relevan. Misalnya, aplikasi visualisasi dapat berlangganan topik seperti `esp32/ambientTemp`, dan `esp32/heartRate` untuk menerima pembaruan sensor secara langsung.

Dengan menggunakan aplikasi MQTT, pengguna dapat mengonfigurasi dashboard untuk menampilkan data yang diterima dari ESP32 dalam bentuk grafik atau angka yang mudah dipahami. Aplikasi ini memungkinkan pengguna untuk memantau data sensor secara real-time dan menyesuaikan tampilan untuk menunjukkan data yang relevan seperti suhu, detak jantung. Dalam hal ini, broker gratis menyediakan infrastruktur komunikasi yang mendukung pertukaran data antara perangkat dan aplikasi tanpa memerlukan server pribadi, menjadikannya solusi yang praktis untuk aplikasi IoT dengan visualisasi data berbasis cloud.

   Tampilan apabila alat tidak terpasang pada bagian tubuh (tangan) user:

![image](https://github.com/user-attachments/assets/fcf25cd9-7eeb-4e40-8c3e-059c6e5afd8a)

   Tampilan apabila alat terpasang pada bagian tubuh (tangan) user:
   
![image](https://github.com/user-attachments/assets/80fc2387-7e42-4a2d-82c5-4cea1e9c9bb7)

**D. IMPLEMENTASI SOFTWARE**

   a. Manajemen Resource Efisien, Project ini mengimplementasikan beberapa teknik untuk efisiensi manajemen sumber daya, seperti penggunaan task scheduling di ESP32 dengan FreeRTOS untuk menjalankan tugas MQTT secara terpisah di Core 0. Penggunaan millis() untuk pembaruan sensor non-blocking juga berkontribusi pada manajemen sumber daya yang efisien, sehingga mengurangi beban pada prosesor dan menghindari delay yang tidak perlu.

   b. Security Best Practices, meskipun beberapa teknik dasar keamanan seperti koneksi WiFi dan penggunaan SSL/TLS untuk MQTT dapat diterapkan, program ini tidak secara eksplisit menerapkan praktik terbaik keamanan, seperti validasi input atau perlindungan dari serangan DDoS. Sebaiknya, sistem diperkuat dengan autentikasi, enkripsi, dan perlindungan terhadap akses yang tidak sah.

   c. Keamanan Jaringan: Program ini terhubung ke WiFi dengan autentikasi standar menggunakan SSID dan password. Ini memberikan tingkat keamanan dasar dengan melindungi perangkat dari akses tanpa izin selama jaringan WiFi dilindungi dengan baik.

   d. Koneksi Broker MQTT: Program ini menggunakan broker MQTT publik yang tidak memiliki enkripsi atau autentikasi tambahan. Data dikirimkan ke broker MQTT dengan port 1883, yang tidak mendukung enkripsi (seperti TLS). Hal ini berarti data yang dikirim dan diterima dapat diakses oleh pihak yang tidak berwenang jika jaringan terpapar.

   e. ID Klien MQTT: Setiap kali perangkat mencoba menyambung ke broker MQTT, ia menggunakan ID unik yang terdiri dari MAC address ESP32. Namun, ID klien ini lebih bersifat identifikasi dan tidak memberikan autentikasi atau keamanan tambahan terhadap akses yang tidak sah.

   f. Pengelolaan Koneksi: Program ini memastikan bahwa ESP32 selalu terhubung dengan broker MQTT. Jika terputus, perangkat akan mencoba untuk tersambung kembali. Meskipun ini merupakan praktik pengelolaan koneksi yang baik, hal ini tidak terkait langsung dengan keamanan data atau autentikasi.

   g. Pengiriman Data: Data yang dikirimkan mencakup suhu, dan detak jantung, yang bisa dianggap sebagai data sensitif. Karena data ini tidak dienkripsi, ada risiko bahwa informasi tersebut bisa diakses oleh pihak yang tidak berwenang.
