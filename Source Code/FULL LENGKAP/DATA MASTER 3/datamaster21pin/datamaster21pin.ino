#include <Wire.h>

#define LDR15  ...                                                                // isi pin ldr1
#define LDR16  ...                                                                // isi pin ldr2 
#define LDR17  ...                                                                // isi pin ldr3
#define LDR18  ...                                                                // isi pin ldr1
#define LDR19  ...                                                                // isi pin ldr2 
#define LDR20  ...                                                                // isi pin ldr3
#define LDR21  ...                                                                // isi pin ldr1
#define LDR22  ...                                                                // isi pin ldr2 
#define LDR23  ...                                                                // isi pin ldr3
#define LDR24  ...                                                                // isi pin ldr1
#define LDR25  ...                                                                // isi pin ldr2 
#define LDR26  ...                                                                // isi pin ldr3
#define LDR27  ...                                                                // isi pin ldr1
#define LDR28  ...                                                                // isi pin ldr2 
#define LDR29  ...                                                                // isi pin ldr3
#define LDR30  ...                                                                // isi pin ldr1
#define LDR31  ...                                                                // isi pin ldr2 
#define LDR32  ...                                                                // isi pin ldr3
#define LDR33  ...                                                                // isi pin ldr1
#define LDR34  ...                                                                // isi pin ldr2 
#define LDR35  ...                                                                // isi pin ldr3

void setup() {
  Wire.begin();                                                                   // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR15, INPUT);
  pinMode(LDR16, INPUT);
  pinMode(LDR17, INPUT);
  pinMode(LDR18, INPUT);
  pinMode(LDR19, INPUT);
  pinMode(LDR20, INPUT);
  pinMode(LDR21, INPUT);
  pinMode(LDR22, INPUT);
  pinMode(LDR23, INPUT);
  pinMode(LDR24, INPUT);
  pinMode(LDR25, INPUT);
  pinMode(LDR26, INPUT);
  pinMode(LDR27, INPUT);
  pinMode(LDR28, INPUT);
  pinMode(LDR29, INPUT);
  pinMode(LDR30, INPUT);
  pinMode(LDR31, INPUT);
  pinMode(LDR32, INPUT);
  pinMode(LDR33, INPUT);
  pinMode(LDR34, INPUT);
  pinMode(LDR35, INPUT);
}

void loop() {
  uint8_t numberToSend15 = digitalRead(LDR15);                                     // Angka integer 15 yang akan dikirim ke slave
  uint8_t numberToSend16 = digitalRead(LDR16);                                     // Angka integer 16 yang akan dikirim ke slave
  uint8_t numberToSend17 = digitalRead(LDR17);                                     // Angka integer 17 yang akan dikirim ke slave
  uint8_t numberToSend18 = digitalRead(LDR18);                                     // Angka integer 18 yang akan dikirim ke slave
  uint8_t numberToSend19 = digitalRead(LDR19);                                     // Angka integer 19 yang akan dikirim ke slave
  uint8_t numberToSend20 = digitalRead(LDR20);                                     // Angka integer 20 yang akan dikirim ke slave
  uint8_t numberToSend21 = digitalRead(LDR21);                                     // Angka integer 21 yang akan dikirim ke slave
  uint8_t numberToSend22 = digitalRead(LDR22);                                     // Angka integer 22 yang akan dikirim ke slave
  uint8_t numberToSend23 = digitalRead(LDR23);                                     // Angka integer 23 yang akan dikirim ke slave
  uint8_t numberToSend24 = digitalRead(LDR24);                                     // Angka integer 24 yang akan dikirim ke slave
  uint8_t numberToSend25 = digitalRead(LDR25);                                     // Angka integer 25 yang akan dikirim ke slave
  uint8_t numberToSend26 = digitalRead(LDR26);                                     // Angka integer 26 yang akan dikirim ke slave
  uint8_t numberToSend27 = digitalRead(LDR27);                                     // Angka integer 27 yang akan dikirim ke slave
  uint8_t numberToSend28 = digitalRead(LDR28);                                     // Angka integer 28 yang akan dikirim ke slave
  uint8_t numberToSend29 = digitalRead(LDR29);                                     // Angka integer 29 yang akan dikirim ke slave
  uint8_t numberToSend30 = digitalRead(LDR30);                                     // Angka integer 30 yang akan dikirim ke slave
  uint8_t numberToSend31 = digitalRead(LDR31);                                     // Angka integer 31 yang akan dikirim ke slave
  uint8_t numberToSend32 = digitalRead(LDR32);                                     // Angka integer 32 yang akan dikirim ke slave
  uint8_t numberToSend33 = digitalRead(LDR33);                                     // Angka integer 33 yang akan dikirim ke slave
  uint8_t numberToSend34 = digitalRead(LDR34);                                     // Angka integer 34 yang akan dikirim ke slave
  uint8_t numberToSend35 = digitalRead(LDR35);                                     // Angka integer 35 yang akan dikirim ke slave

  // Kirim data dari Master 3 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(15);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend15, sizeof(numberToSend15));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(16);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend16, sizeof(numberToSend16));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(17);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend17, sizeof(numberToSend17));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(18);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend18, sizeof(numberToSend18));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(19);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend19, sizeof(numberToSend19));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(20);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend20, sizeof(numberToSend20));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(21);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend21, sizeof(numberToSend21));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(22);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend22, sizeof(numberToSend22));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(23);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend23, sizeof(numberToSend23));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(24);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend24, sizeof(numberToSend24));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(25);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend25, sizeof(numberToSend25));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(26);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend26, sizeof(numberToSend26));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(27);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend27, sizeof(numberToSend27));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(28);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend28, sizeof(numberToSend28));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(29);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend29, sizeof(numberToSend29));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(30);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend30, sizeof(numberToSend30));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(31);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend31, sizeof(numberToSend31));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(32);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend32, sizeof(numberToSend32));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(33);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend33, sizeof(numberToSend33));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(34);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend34, sizeof(numberToSend34));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(35);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 3)
  Wire.write((uint8_t*)&numberToSend35, sizeof(numberToSend35));                  // Mengirim byte array dari angka integer
  Wire.endTransmission();
  
  delay(1000);                                                                    // Tunggu 1 detik
}
