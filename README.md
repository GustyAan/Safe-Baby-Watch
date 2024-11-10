# Safe Baby Watch 
Merupakan proyek SmartWatch Pemantau Kesehatan Bayi ini adalah memberikan solusi kesehatan yang inovatif untuk memantau kondisi kesehatan bayi secara real-time. Proyek ini bertujuan untuk membantu orang tua dan pengasuh dalam mendeteksi dini masalah kesehatan bayi, sehingga mereka dapat mengambil tindakan pencegahan atau perawatan yang tepat dengan cepat. Dengan menggunakan teknologi IoT, alat ini memungkinkan pemantauan kesehatan bayi yang lebih praktis, efisien, dan akurat, sehingga memberikan ketenangan bagi orang tua dalam menjaga kesejahteraan bayi mereka.

Peta koneksi 

![image](https://github.com/user-attachments/assets/213d96c3-f8b7-4db5-96b1-607c25e38d71)

PCB yang telah dicetak didokumentasikan dengan hasil cetak desain PCB berikut:

Tampak bawah:

![image](https://github.com/user-attachments/assets/81e9ae7a-c2b7-4c75-8271-1d56c0955975)

Tampak atas:

![image](https://github.com/user-attachments/assets/19f89f37-dbe7-4766-bc7b-5b2adfc76da6)

DIAGRAM SISTEM

![image](https://github.com/user-attachments/assets/e3545708-e1d0-4b24-80e6-9357fcf48d4f)

Sistem Safe Baby Watch bekerja dengan sensor MAX30102 yang mendeteksi detak jantung (HR) dan kadar oksigen dalam darah bayi (SPO2), sedangkan sensor GY906 mengukur suhu tubuh bayi  tanpa kontak fisik sensor melalui jam tangan yang terkoneksi dengan internet melalui ESP 12. Data yang dikumpulkan dari kedua sensor ini kemudian diproses oleh modul ESP12, yang berfungsi sebagai pusat pemrosesan data dalam sistem. Layar OLED pada perangkat menampilkan informasi detak jantung dan suhu tubuh bayi secara real-time, memudahkan pemantauan langsung. Jika sistem mendeteksi adanya kondisi abnormal, seperti peningkatan suhu atau perubahan signifikan dalam detak jantung atau turunnya saturasi oksigen, notifikasi otomatis akan dikirimkan sebagai peringatan melalui ponsel pintar yang terkoneksi. Data ini juga dikirimkan melalui koneksi WiFi ke tambilan mobile, memungkinkan pemantauan jarak jauh dan real-time oleh orang tua atau pengasuh. Diagram sistem ini memberikan gambaran jelas tentang koneksi antara sensor dan ESP12, serta aliran data menuju aplikasi untuk pemantauan.

Safe Baby Watch secara garis besar memiliki komponen penting seperti kontroller dan perangkat sensing sebagai berikut:

1. **ESP12**:

![image](https://github.com/user-attachments/assets/01c10f11-8491-4afe-9a1a-e402481b7fd1)

ESP12 adalah modul berbasis microcontroller ESP8266 yang memiliki kemampuan Wi-Fi, sehingga dapat mengirim dan menerima data secara nirkabel melalui internet. Pada proyek Safe Baby Watch, ESP12 digunakan sebagai otak utama yang mengumpulkan data dari berbagai sensor, memprosesnya, dan mengirimkan data tersebut ke aplikasi atau platform IoT. Hal ini memungkinkan pemantauan jarak jauh terhadap kondisi kesehatan bayi.

3. **Sensor MAX30102**:
   
MAX30102 adalah sensor optik yang dapat mendeteksi detak jantung dan kadar oksigen dalam darah. Sensor ini bekerja dengan memancarkan cahaya dan mendeteksi refleksi cahaya tersebut dari pembuluh darah di kulit. Pada proyek ini, MAX30102 berguna untuk memantau detak jantung dan saturasi oksigen bayi, sehingga dapat mendeteksi tanda-tanda vital dan memastikan bayi dalam kondisi yang aman. Sensor MAX 30102 memiliki spesifikasi sebagai berikut:
- Sensor: LED merah dan inframerah untuk mendeteksi detak jantung dan SpO2
- Tegangan Operasional: 1.8V untuk inti, 3.3V untuk LED
- Antarmuka Komunikasi: I2C
- Arus Rata-rata: 600µA (tergantung pengaturan)
- Mode Pengukuran: Detak jantung dan oksigen darah (SpO2)
- Rentang Panjang Gelombang LED:
- LED Merah: 660 nm
- LED Inframerah: 880 nm

  Sensor MAX30102 ini sipilih karena memiliki kelebihan sebagai berikut:
- Penggunaan Daya: Rendah, cocok untuk perangkat wearable
- Penggunaan: Oximeter, deteksi detak jantung, perangkat medis wearable
- Dilengkapi dengan algoritma yang dapat membantu dalam pemrosesan sinyal detak jantung dan oksigen dalam darah, sehingga **cocok untuk perangkat wearable dan aplikasi kesehatan**.

Dengan adanya kelebihan dan spesifikasi diatas, pengambilan data dalam sensor testing dapat dilakukan dengan mekanisme pengambilan data sebagai berikut:

![MAX30102](https://github.com/user-attachments/assets/e6edf8a3-6180-4b97-a5d3-7798063bdd32)

Hasil sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/a90fc63f-1751-4e69-ba81-464ffe95bdcf)

Output testing:

Jika berhasil:

![Sensor Valid](https://github.com/user-attachments/assets/e712430c-d82a-4a49-bb8c-c2ae0d07dec6)

Jika Sensor gagal terinisialisasi:

![Sensor Invalid](https://github.com/user-attachments/assets/711b09dd-5df4-44f2-adc5-06b53c0a75ee)

Sensor testing ini ditujukan untuk mengetes fungsi sensor dengan memanfaatkan fungsi utamanya yakni mengukur kadar oksigen dalam darah (SpO2) dan denyut jantung menggunakan sensor MAX30102. Pertama, sistem menginisialisasi komunikasi serial untuk mengirim dan menerima data serta mengatur LED indikator sebagai output. Setelah itu, sensor MAX30102 diinisialisasi; jika berhasil, sistem menampilkan pesan "Attach sensor to finger. Press key to start" untuk meminta pengguna menempatkan jari mereka pada sensor. Namun, jika inisialisasi gagal, pesan kesalahan akan muncul untuk memeriksa kembali sambungan daya atau kabel.

Setelah sensor terpasang dan pengguna menekan tombol untuk memulai, sistem mengonfigurasi parameter sensor seperti kecerahan LED dan kecepatan sampel. Dalam loop utama, sistem membaca sampel data dari sensor, menyimpan data cahaya merah dan inframerah (IR) dalam buffer, dan menampilkan data ini pada monitor serial. Setelah pengumpulan data, sistem menghitung SpO2 dan denyut jantung, kemudian menampilkannya. Loop ini berjalan terus menerus, memperbarui pembacaan SpO2 dan denyut jantung, hingga kondisi penghentian dicapai.

5. **Sensor GY906**:
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

Sistem dan cara kerja testing sensor ini menggunakan sensor GY906 dan layar OLED untuk menampilkan suhu secara real-time dalam sebuah aplikasi monitoring, seperti "SAFE BABYWATCH." Cara kerja sistem dimulai dengan inisialisasi pustaka dan variabel untuk layar OLED dan sensor suhu, yang bertugas membaca suhu objek dari lingkungan sekitar. Program mengonfigurasi OLED display pada fungsi `setup`, termasuk pengaturan warna teks dan resolusi tampilan, serta mengaktifkan sensor inframerah agar dapat mengambil data suhu.

Selanjutnya, pada fungsi task utama, sistem membaca suhu secara berulang dan memperbarui tampilan OLED. Proses ini melibatkan pengambilan data suhu dari sensor inframerah, membersihkan buffer tampilan OLED agar tidak ada residu tampilan sebelumnya, dan menampilkan teks pengaman "SAFE BABYWATCH" serta label suhu yang menunjukkan nilai terbaru. Suhu yang diperoleh dari sensor diubah menjadi string untuk memudahkan penampilannya pada layar, bersama dengan satuan suhu (derajat Celsius). Setelah proses ini selesai, OLED display diperbarui, dan loop berulang, memungkinkan pembacaan suhu terkini untuk ditampilkan terus-menerus pada layar sebagai informasi real-time.

6. **OLED 0.96**:
OLED 0.96 adalah layar kecil berukuran 0.96 inci yang menggunakan teknologi OLED (Organic Light Emitting Diode). Layar ini memiliki tampilan yang jernih dan kontras tinggi sehingga cocok untuk menampilkan informasi penting dalam ruang yang terbatas. Dalam proyek ini, OLED 0.96 digunakan untuk menampilkan data seperti detak jantung, kadar oksigen, dan suhu bayi secara langsung, memudahkan pemantauan oleh pengguna di lokasi yang sama.

Komponen-komponen ini bekerja bersama-sama untuk memantau kondisi kesehatan bayi secara real-time, memberikan peringatan dini jika ada anomali kondisi bayi, dan memungkinkan pemantauan jarak jauh oleh orang tua atau pengasuh melalui internet.

**Tampilan Aplikasi Monitoring**
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







