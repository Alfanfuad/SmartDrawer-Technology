#include <Wire.h>
#define LDR1 35
#define LDR2 34
#define LDR3 25
#define LDR4 33
#define LDR5 32


void setup() {
  Wire.begin(); // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR3, OUTPUT);
}

void loop() {
  int LDR1V = analogRead(LDR1); // Angka integer yang akan dikirim ke slave
  Serial.println(LDR1V);
  int LDR2V = analogRead(LDR2); // Angka integer yang akan dikirim ke slave
  Serial.println(LDR2V);
  int LDR3V = analogRead(LDR3); // Angka integer yang akan dikirim ke slave
  Serial.println(LDR3V);
  int LDR4V = analogRead(LDR4); // Angka integer yang akan dikirim ke slave
  Serial.println(LDR4V);
  int LDR5V = analogRead(LDR5); // Angka integer yang akan dikirim ke slave
  Serial.println(LDR5V);

  // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (2)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(1); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR1V, sizeof(LDR1V)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(2); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR2V, sizeof(LDR2V)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(3); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR3V, sizeof(LDR3V)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(4); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR4V, sizeof(LDR4V)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(5); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR5V, sizeof(LDR5V)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000); // Tunggu 1 detik
}
