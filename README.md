# Safe Baby Watch 
Merupakan proyek SmartWatch Pemantau Kesehatan Bayi ini adalah memberikan solusi kesehatan yang inovatif untuk memantau kondisi kesehatan bayi secara real-time. Proyek ini bertujuan untuk membantu orang tua dan pengasuh dalam mendeteksi dini masalah kesehatan bayi, sehingga mereka dapat mengambil tindakan pencegahan atau perawatan yang tepat dengan cepat. Dengan menggunakan teknologi IoT, alat ini memungkinkan pemantauan kesehatan bayi yang lebih praktis, efisien, dan akurat, sehingga memberikan ketenangan bagi orang tua dalam menjaga kesejahteraan bayi mereka.

[TAMBAHIN CARA KERJA SISTEM YANG DITAMBAHIN KETERANGAN AGAR NYAMBUNG DENGAN PETA KONEKSI DAN DIAGRAM SISTEM]

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

[TAMBAHIN DATASHEET GY-906]

Hasil sensor testing:

Test tangan:

![image](https://github.com/user-attachments/assets/63aa29ad-b7ee-499b-b67e-d243dc401204)

Test Solder (suhu tinggi):

![image](https://github.com/user-attachments/assets/9a97053b-3404-4814-ab52-21849c30fd0d)

[PENJELASAN HASIL SENSOR TESTING]

[PENJELASAN SENSOR GY-906]

Flowchart pengambilan datasensor MAX30102

![MAX30102](https://github.com/user-attachments/assets/e6edf8a3-6180-4b97-a5d3-7798063bdd32)

[TAMBAHIN DATASHEET MAX30102]

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









