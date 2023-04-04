# Program Kontrol Motor DC dengan PID

Program ini adalah contoh implementasi kontrol motor DC menggunakan PID (Proportional-Integral-Derivative) pada Arduino. Kontrol PID digunakan untuk mengatur kecepatan motor DC berdasarkan nilai input sensor dan nilai setpoint yang ditentukan.

## Library yang Digunakan

Program ini menggunakan tiga library yaitu:

- Wire.h untuk komunikasi I2C

- LiquidCrystal_I2C.h untuk mengatur tampilan pada LCD I2C

- PID_v1.h untuk mengimplementasikan kontrol PID

## Inisialisasi Variabel dan Objek

Program ini menggunakan beberapa variabel dan objek seperti:

- lcd merupakan objek dari kelas LiquidCrystal_I2C yang digunakan untuk mengatur tampilan pada LCD I2C

- Setpoint, Input, dan Output adalah variabel bertipe data double yang digunakan sebagai nilai setpoint, nilai input sensor, dan nilai output dari PID

- kp, ki, dan kd adalah variabel bertipe data double yang digunakan sebagai konstanta pada kontrol PID

- potPin1, potPin2, potPin3, dan motorPin adalah variabel yang menyimpan nomor pin pada Arduino yang digunakan untuk membaca nilai potensio dan mengatur kecepatan motor DC

- previousMillis dan interval adalah variabel yang digunakan untuk mengatur interval waktu pada program

- myPID adalah objek dari kelas PID yang digunakan untuk menghitung output PID

## Setup

Pada fungsi setup(), dilakukan beberapa hal seperti:

- Mengatur pin motorPin sebagai output

- Membuka serial monitor dengan baud rate 9600

- Inisialisasi objek lcd

- Menghidupkan backlight pada LCD

- Mengatur nilai Setpoint

- Mengatur mode PID ke AUTOMATIC

## Loop

Pada fungsi loop(), dilakukan beberapa hal seperti:

- Membaca waktu saat ini

- Jika sudah mencapai interval waktu yang ditentukan, maka dilakukan pembacaan nilai potensio ke-1, ke-2, dan ke-3

- Konversi nilai analog dari potensio ke range 0-1

- Update konstanta PID dengan nilai dari potensio

- Membaca nilai sensor sebagai input

- Menghitung output PID dengan menggunakan nilai input, nilai setpoint, dan konstanta PID

- Mengontrol motor DC dengan menggunakan output dari PID

- Menampilkan nilai input, output, dan konstanta pada LCD

- Menampilkan nilai input, output, dan konstanta pada serial monitor

## Penutup

Demikianlah program kontrol motor DC dengan PID pada Arduino. Program ini dapat dimodifikasi dan disesuaikan dengan kebutuhan pengguna. Semoga bermanfaat!
