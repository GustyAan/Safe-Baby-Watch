# Safe Baby Watch 
Merupakan proyek SmartWatch Pemantau Kesehatan Bayi ini adalah memberikan solusi kesehatan yang inovatif untuk memantau kondisi kesehatan bayi secara real-time. Proyek ini bertujuan untuk membantu orang tua dan pengasuh dalam mendeteksi dini masalah kesehatan bayi, sehingga mereka dapat mengambil tindakan pencegahan atau perawatan yang tepat dengan cepat. Dengan menggunakan teknologi IoT, alat ini memungkinkan pemantauan kesehatan bayi yang lebih praktis, efisien, dan akurat, sehingga memberikan ketenangan bagi orang tua dalam menjaga kesejahteraan bayi mereka.

[CARA KERJA SISTEM DENGAN PETA KONEKSI DAN DIAGRAM SISTEM]

Sensor MAX30105 mendeteksi detak jantung dan kadar oksigen dalam darah bayi dan Sensor MLX90614 memantau suhu tubuh bayi tanpa kontak langsung **-->** Pemrosesan dan Tampilan Data dari sensor diproses oleh modul ESP12 **-->** Layar OLED menampilkan informasi suhu dan detak jantung secara langsung **-->** Jika terdeteksi kondisi abnormal, sistem mengirimkan notifikasi **-->** Data dikirimkan melalui WiFi ke aplikasi mobile untuk pemantauan jarak jauh dan real-time **-->** Diagram menunjukkan koneksi dari sensor ke ESP12 dan aliran data menuju aplikasi.

Peta koneksi 

![image](https://github.com/user-attachments/assets/213d96c3-f8b7-4db5-96b1-607c25e38d71)

Hasil desain PCB:

Tampak bawah:

![image](https://github.com/user-attachments/assets/81e9ae7a-c2b7-4c75-8271-1d56c0955975)

Tampak atas:

![image](https://github.com/user-attachments/assets/19f89f37-dbe7-4766-bc7b-5b2adfc76da6)

DIAGRAM SISTEM

![image](https://github.com/user-attachments/assets/e3545708-e1d0-4b24-80e6-9357fcf48d4f)

[PENJELASAN KOMPONEN DARI MASING2 KOMPONEN DALAM GAMBAR KERJA SISTEM]

Berikut penjelasan dari fungsi masing-masing komponen yang digunakan dalam proyek **Safe Baby Watch** (alat pemantauan kesehatan bayi berbasis IoT):

1. **ESP12**:
   - ESP12 adalah modul berbasis microcontroller ESP8266 yang memiliki kemampuan Wi-Fi, sehingga dapat mengirim dan menerima data secara nirkabel melalui internet. Pada proyek Safe Baby Watch, ESP12 digunakan sebagai otak utama yang mengumpulkan data dari berbagai sensor, memprosesnya, dan mengirimkan data tersebut ke aplikasi atau platform IoT. Hal ini memungkinkan pemantauan jarak jauh terhadap kondisi kesehatan bayi.

2. **Sensor MAX30105**:
   - MAX30105 adalah sensor optik yang dapat mendeteksi detak jantung dan kadar oksigen dalam darah. Sensor ini bekerja dengan memancarkan cahaya dan mendeteksi refleksi cahaya tersebut dari pembuluh darah di kulit. Pada proyek ini, MAX30105 berguna untuk memantau detak jantung dan saturasi oksigen bayi, sehingga dapat mendeteksi tanda-tanda vital dan memastikan bayi dalam kondisi yang aman.

3. **Sensor MLX90614**:
   - MLX90614 adalah sensor inframerah yang dapat mengukur suhu tanpa kontak fisik (non-contact). Ini memungkinkan pengukuran suhu tubuh bayi dari jarak dekat, tanpa perlu menyentuh kulit bayi, yang sangat penting untuk kenyamanan dan keamanan. Di proyek ini, MLX90614 digunakan untuk memantau suhu tubuh bayi secara real-time dan mendeteksi potensi demam atau perubahan suhu yang signifikan.

4. **OLED 0.96**:
   - OLED 0.96 adalah layar kecil berukuran 0.96 inci yang menggunakan teknologi OLED (Organic Light Emitting Diode). Layar ini memiliki tampilan yang jernih dan kontras tinggi sehingga cocok untuk menampilkan informasi penting dalam ruang yang terbatas. Dalam proyek ini, OLED 0.96 digunakan untuk menampilkan data seperti detak jantung, kadar oksigen, dan suhu bayi secara langsung, memudahkan pemantauan oleh pengguna di lokasi yang sama.

Komponen-komponen ini bekerja bersama-sama untuk memantau kondisi kesehatan bayi secara real-time, memberikan peringatan dini jika ada anomali, dan memungkinkan pemantauan jarak jauh oleh orang tua atau pengasuh melalui internet.

[PENJELASAN ESP 12: Pin I/O dll]

![image](https://github.com/user-attachments/assets/01c10f11-8491-4afe-9a1a-e402481b7fd1)

[PENJELASAN SENSOR GY-906]

Flowchart pengambilan datasensor GY-906

![DLOWCHART GY](https://github.com/user-attachments/assets/b7ca2806-85aa-4c06-a2f3-4e988c5c50df)

[DATASHEET GY-906]

**GY-906** merupakan modul sensor inframerah non-kontak berdasarkan sensor MLX90614 dari Melexis, yang dapat mendeteksi suhu tanpa perlu menyentuh objek. Berikut adalah beberapa spesifikasi utama dari GY-906:

- Sensor: MLX90614
- Rentang Suhu Objek: -70°C hingga 380°C
- Rentang Suhu Operasional: -40°C hingga 125°C
- Akurasi: ±0.5°C pada suhu objek antara 0 hingga 50°C
- Resolusi: 0.02°C
- Antarmuka Komunikasi: I2C dan PWM
- Tegangan Operasional: 3V hingga 5V
- Sudut Pandang: Sekitar 35°
- 
**KELEBIHAN**
- Pengukuran Suhu Non-Kontak: GY-906 menggunakan teknologi inframerah untuk mengukur suhu objek tanpa perlu menyentuhnya
- Akurasi Tinggi: Sensor ini memiliki akurasi sekitar ±0,5°C pada rentang suhu 0°C hingga 50°C
- Resolusi Tinggi: Dengan resolusi 0,02°C, sensor ini dapat mendeteksi perubahan suhu yang sangat kecil.
- Rentang Pengukuran Luas: GY-906 memiliki rentang pengukuran yang luas, dari -70°C hingga 380°C
- Konsumsi Daya Rendah: Sensor ini memiliki konsumsi daya yang rendah
- Antarmuka I2C dan PWM: Memiliki dua jenis antarmuka (I2C dan PWM)
- Sudut Pandang Lebar: Memiliki sudut pandang sekitar 35°, yang memungkinkannya untuk mendeteksi suhu dari area yang lebih luas
- Tahan terhadap Gangguan Elektromagnetik: Didesain dengan ketahanan yang baik terhadap interferensi elektromagnetik pengukuran lebih stabil dan dapat diandalkan dalam lingkungan industri.

Hasil sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/63aa29ad-b7ee-499b-b67e-d243dc401204)

Test Solder (suhu tinggi):

![image](https://github.com/user-attachments/assets/9a97053b-3404-4814-ab52-21849c30fd0d)

[PENJELASAN HASIL SENSOR TESTING]

[PENJELASAN SENSOR GY-906]

Flowchart pengambilan datasensor MAX30102

![MAX30102](https://github.com/user-attachments/assets/e6edf8a3-6180-4b97-a5d3-7798063bdd32)

[DATASHEET MAX30102]


**MAX30102**: sensor optik yang dirancang untuk mengukur detak jantung dan kadar oksigen dalam darah (SpO2). Sensor ini mengintegrasikan LED merah dan inframerah, fotodetektor, optik khusus, dan elektronik pemrosesan sinyal. Berikut adalah beberapa spesifikasi utama dari MAX30102:

- Sensor: LED merah dan inframerah untuk mendeteksi detak jantung dan SpO2
- Tegangan Operasional: 1.8V untuk inti, 3.3V untuk LED
- Antarmuka Komunikasi: I2C
- Arus Rata-rata: 600µA (tergantung pengaturan)
- Mode Pengukuran: Detak jantung dan oksigen darah (SpO2)
- Rentang Panjang Gelombang LED:
- LED Merah: 660 nm
- LED Inframerah: 880 nm

  **KELEBIHAN**
- Penggunaan Daya: Rendah, cocok untuk perangkat wearable
- Penggunaan: Oximeter, deteksi detak jantung, perangkat medis wearable
- Dilengkapi dengan algoritma yang dapat membantu dalam pemrosesan sinyal detak jantung dan oksigen dalam darah, sehingga **cocok untuk perangkat wearable dan aplikasi kesehatan**.

Hasil sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/a90fc63f-1751-4e69-ba81-464ffe95bdcf)

Output testing:

Jika berhasil:

![Sensor Valid](https://github.com/user-attachments/assets/e712430c-d82a-4a49-bb8c-c2ae0d07dec6)

Jika Sensor gagal terinisialisasi:

![Sensor Invalid](https://github.com/user-attachments/assets/711b09dd-5df4-44f2-adc5-06b53c0a75ee)

[PENJELASAN HASIL SENSOR TESTING]

[TAMBAHIN PENJELASAN TENTANG UI/UX YANG DIBUAT (kalau bisa tambahin gambarnya juga)]









