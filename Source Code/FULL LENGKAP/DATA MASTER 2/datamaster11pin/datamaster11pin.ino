#include <Wire.h>

#define LDR4  ...                                                                 // isi pin ldr1
#define LDR5  ...                                                                 // isi pin ldr2 
#define LDR6  ...                                                                 // isi pin ldr3
#define LDR7  ...                                                                 // isi pin ldr1
#define LDR8  ...                                                                 // isi pin ldr2 
#define LDR9  ...                                                                 // isi pin ldr3
#define LDR10 ...                                                                 // isi pin ldr1
#define LDR11 ...                                                                 // isi pin ldr2 
#define LDR12 ...                                                                 // isi pin ldr3
#define LDR13 ...                                                                 // isi pin ldr1
#define LDR14 ...                                                                 // isi pin ldr2 


void setup() {
  Wire.begin();                                                                   // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR4, INPUT);
  pinMode(LDR5, INPUT);
  pinMode(LDR6, INPUT);
  pinMode(LDR7, INPUT);
  pinMode(LDR8, INPUT);
  pinMode(LDR9, INPUT);
  pinMode(LDR10, INPUT);
  pinMode(LDR11, INPUT);
  pinMode(LDR12, INPUT);
  pinMode(LDR13, INPUT);
  pinMode(LDR14, INPUT);
}

void loop() {
  uint8_t numberToSend4  = digitalRead(LDR4);                                     // Angka integer 4 yang akan dikirim ke slave
  uint8_t numberToSend5  = digitalRead(LDR5);                                     // Angka integer 5 yang akan dikirim ke slave
  uint8_t numberToSend6  = digitalRead(LDR6);                                     // Angka integer 6 yang akan dikirim ke slave
  uint8_t numberToSend7  = digitalRead(LDR7);                                     // Angka integer 7 yang akan dikirim ke slave
  uint8_t numberToSend8  = digitalRead(LDR8);                                     // Angka integer 8 yang akan dikirim ke slave
  uint8_t numberToSend9  = digitalRead(LDR9);                                     // Angka integer 9 yang akan dikirim ke slave
  uint8_t numberToSend10 = digitalRead(LDR10);                                    // Angka integer 10 yang akan dikirim ke slave
  uint8_t numberToSend11 = digitalRead(LDR11);                                    // Angka integer 11 yang akan dikirim ke slave
  uint8_t numberToSend12 = digitalRead(LDR12);                                    // Angka integer 12 yang akan dikirim ke slave
  uint8_t numberToSend13 = digitalRead(LDR13);                                    // Angka integer 13 yang akan dikirim ke slave
  uint8_t numberToSend14 = digitalRead(LDR14);                                    // Angka integer 14 yang akan dikirim ke slave


  // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(4);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend4, sizeof(numberToSend4));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(5);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend5, sizeof(numberToSend5));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(6);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend6, sizeof(numberToSend6));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(7);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend7, sizeof(numberToSend7));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(8);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend8, sizeof(numberToSend8));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(9);                                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend9, sizeof(numberToSend9));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(10);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend10, sizeof(numberToSend10));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(11);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend11, sizeof(numberToSend11));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(12);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend12, sizeof(numberToSend12));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(13);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend13, sizeof(numberToSend13));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(14);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&numberToSend14, sizeof(numberToSend14));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000);                                                                    // Tunggu 1 detik
}
