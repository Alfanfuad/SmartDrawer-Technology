#include <Wire.h>

void setup() {
  Wire.begin(); // Inisialisasi I2C komunikasi
  Serial.begin(115200);
}

void loop() {
  int numberToSend = 42; // Angka integer yang akan dikirim ke slave

  // Kirim data dari Master 1 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(1); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&numberToSend, sizeof(numberToSend)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000); // Tunggu 1 detik
}