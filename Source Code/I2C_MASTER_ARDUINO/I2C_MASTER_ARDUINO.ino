#include <Wire.h>

#define LDR1 50
#define LDR2 22
#define LDR3 24


void setup() {
  Wire.begin(); // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
}

void loop() {
  uint8_t numberToSend = digitalRead(LDR1); // Angka integer yang akan dikirim ke slave
  Serial.print("ldr 1: ");
  Serial.println(numberToSend);

  uint8_t numberToSend2 = digitalRead(LDR2); // Angka integer yang akan dikirim ke slave
  Serial.print("ldr 2: ");
  Serial.println(numberToSend2);

  uint8_t numberToSend3 = digitalRead(LDR3); // Angka integer yang akan dikirim ke slave
  Serial.print("ldr 3: ");
  Serial.println(numberToSend3);

  // Kirim data dari Master 1 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(1); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&numberToSend, sizeof(numberToSend)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(2); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&numberToSend2, sizeof(numberToSend2)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(3); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&numberToSend3, sizeof(numberToSend3)); // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000); // Tunggu 1 detik
}
