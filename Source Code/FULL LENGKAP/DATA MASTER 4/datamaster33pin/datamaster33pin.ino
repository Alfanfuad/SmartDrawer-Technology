#include <Wire.h>

#define LDR36  ...                                                                // isi pin ldr1
#define LDR37  ...                                                                // isi pin ldr2 
#define LDR38  ...                                                                // isi pin ldr3
#define LDR39  ...                                                                // isi pin ldr1
#define LDR40  ...                                                                // isi pin ldr2 
#define LDR41  ...                                                                // isi pin ldr3
#define LDR42  ...                                                                // isi pin ldr1
#define LDR43  ...                                                                // isi pin ldr2 
#define LDR44  ...                                                                // isi pin ldr3
#define LDR45  ...                                                                // isi pin ldr1
#define LDR46  ...                                                                // isi pin ldr2 
#define LDR47  ...                                                                // isi pin ldr3
#define LDR48  ...                                                                // isi pin ldr1
#define LDR49  ...                                                                // isi pin ldr2 
#define LDR50  ...                                                                // isi pin ldr3
#define LDR51  ...                                                                // isi pin ldr1
#define LDR52  ...                                                                // isi pin ldr2 
#define LDR53  ...                                                                // isi pin ldr3
#define LDR54  ...                                                                // isi pin ldr1
#define LDR55  ...                                                                // isi pin ldr2 
#define LDR56  ...                                                                // isi pin ldr3
#define LDR57  ...                                                                // isi pin ldr1
#define LDR58  ...                                                                // isi pin ldr2 
#define LDR59  ...                                                                // isi pin ldr3
#define LDR60  ...                                                                // isi pin ldr1
#define LDR61  ...                                                                // isi pin ldr2 
#define LDR62  ...                                                                // isi pin ldr3
#define LDR63  ...                                                                // isi pin ldr1
#define LDR64  ...                                                                // isi pin ldr2 
#define LDR65  ...                                                                // isi pin ldr3
#define LDR66  ...                                                                // isi pin ldr1
#define LDR67  ...                                                                // isi pin ldr2 
#define LDR68  ...                                                                // isi pin ldr3

void setup() {
  Wire.begin();                                                                   // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR36, INPUT);
  pinMode(LDR37, INPUT);
  pinMode(LDR38, INPUT);
  pinMode(LDR39, INPUT);
  pinMode(LDR40, INPUT);
  pinMode(LDR41, INPUT);
  pinMode(LDR42, INPUT);
  pinMode(LDR43, INPUT);
  pinMode(LDR44, INPUT);
  pinMode(LDR45, INPUT);
  pinMode(LDR46, INPUT);
  pinMode(LDR47, INPUT);
  pinMode(LDR48, INPUT);
  pinMode(LDR49, INPUT);
  pinMode(LDR50, INPUT);
  pinMode(LDR51, INPUT);
  pinMode(LDR52, INPUT);
  pinMode(LDR53, INPUT);
  pinMode(LDR54, INPUT);
  pinMode(LDR55, INPUT);
  pinMode(LDR56, INPUT);
  pinMode(LDR57, INPUT);
  pinMode(LDR58, INPUT);
  pinMode(LDR59, INPUT);
  pinMode(LDR60, INPUT);
  pinMode(LDR61, INPUT);
  pinMode(LDR62, INPUT);
  pinMode(LDR63, INPUT);
  pinMode(LDR64, INPUT);
  pinMode(LDR65, INPUT);
  pinMode(LDR66, INPUT);
  pinMode(LDR67, INPUT);
  pinMode(LDR68, INPUT);
}

void loop() {
  uint8_t numberToSend36 = digitalRead(LDR36);                                     // Angka integer 36 yang akan dikirim ke slave
  uint8_t numberToSend37 = digitalRead(LDR37);                                     // Angka integer 37 yang akan dikirim ke slave
  uint8_t numberToSend38 = digitalRead(LDR38);                                     // Angka integer 38 yang akan dikirim ke slave
  uint8_t numberToSend39 = digitalRead(LDR39);                                     // Angka integer 39 yang akan dikirim ke slave
  uint8_t numberToSend40 = digitalRead(LDR40);                                     // Angka integer 40 yang akan dikirim ke slave
  uint8_t numberToSend41 = digitalRead(LDR41);                                     // Angka integer 41 yang akan dikirim ke slave
  uint8_t numberToSend42 = digitalRead(LDR42);                                     // Angka integer 42 yang akan dikirim ke slave
  uint8_t numberToSend43 = digitalRead(LDR43);                                     // Angka integer 43 yang akan dikirim ke slave
  uint8_t numberToSend44 = digitalRead(LDR44);                                     // Angka integer 44 yang akan dikirim ke slave
  uint8_t numberToSend45 = digitalRead(LDR45);                                     // Angka integer 45 yang akan dikirim ke slave
  uint8_t numberToSend46 = digitalRead(LDR46);                                     // Angka integer 46 yang akan dikirim ke slave
  uint8_t numberToSend47 = digitalRead(LDR47);                                     // Angka integer 47 yang akan dikirim ke slave
  uint8_t numberToSend48 = digitalRead(LDR48);                                     // Angka integer 48 yang akan dikirim ke slave
  uint8_t numberToSend49 = digitalRead(LDR49);                                     // Angka integer 49 yang akan dikirim ke slave
  uint8_t numberToSend50 = digitalRead(LDR50);                                     // Angka integer 50 yang akan dikirim ke slave
  uint8_t numberToSend51 = digitalRead(LDR51);                                     // Angka integer 51 yang akan dikirim ke slave
  uint8_t numberToSend52 = digitalRead(LDR52);                                     // Angka integer 52 yang akan dikirim ke slave
  uint8_t numberToSend53 = digitalRead(LDR53);                                     // Angka integer 53 yang akan dikirim ke slave
  uint8_t numberToSend54 = digitalRead(LDR54);                                     // Angka integer 54 yang akan dikirim ke slave
  uint8_t numberToSend55 = digitalRead(LDR55);                                     // Angka integer 55 yang akan dikirim ke slave
  uint8_t numberToSend56 = digitalRead(LDR56);                                     // Angka integer 56 yang akan dikirim ke slave
  uint8_t numberToSend57 = digitalRead(LDR57);                                     // Angka integer 57 yang akan dikirim ke slave
  uint8_t numberToSend58 = digitalRead(LDR58);                                     // Angka integer 58 yang akan dikirim ke slave
  uint8_t numberToSend59 = digitalRead(LDR59);                                     // Angka integer 59 yang akan dikirim ke slave
  uint8_t numberToSend60 = digitalRead(LDR60);                                     // Angka integer 60 yang akan dikirim ke slave
  uint8_t numberToSend61 = digitalRead(LDR61);                                     // Angka integer 61 yang akan dikirim ke slave
  uint8_t numberToSend62 = digitalRead(LDR62);                                     // Angka integer 62 yang akan dikirim ke slave
  uint8_t numberToSend63 = digitalRead(LDR63);                                     // Angka integer 63 yang akan dikirim ke slave
  uint8_t numberToSend64 = digitalRead(LDR64);                                     // Angka integer 64 yang akan dikirim ke slave
  uint8_t numberToSend65 = digitalRead(LDR65);                                     // Angka integer 65 yang akan dikirim ke slave
  uint8_t numberToSend66 = digitalRead(LDR66);                                     // Angka integer 66 yang akan dikirim ke slave
  uint8_t numberToSend67 = digitalRead(LDR67);                                     // Angka integer 67 yang akan dikirim ke slave
  uint8_t numberToSend68 = digitalRead(LDR68);                                     // Angka integer 68 yang akan dikirim ke slave

  // Kirim data dari Master 4 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(36);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend36, sizeof(numberToSend36));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(37);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend37, sizeof(numberToSend37));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(38);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend38, sizeof(numberToSend38));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(39);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend39, sizeof(numberToSend39));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(40);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend40, sizeof(numberToSend40));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(41);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend41, sizeof(numberToSend41));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(42);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend42, sizeof(numberToSend42));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(43);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend43, sizeof(numberToSend43));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(44);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend44, sizeof(numberToSend44));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(45);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend45, sizeof(numberToSend45));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(46);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend46, sizeof(numberToSend46));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(47);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend47, sizeof(numberToSend47));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(48);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend48, sizeof(numberToSend48));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(49);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend49, sizeof(numberToSend49));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(50);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend50, sizeof(numberToSend50));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(51);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend51, sizeof(numberToSend51));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(52);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend52, sizeof(numberToSend52));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(53);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend53, sizeof(numberToSend53));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(54);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend54, sizeof(numberToSend54));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(55);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend55, sizeof(numberToSend55));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(56);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend56, sizeof(numberToSend56));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(57);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend57, sizeof(numberToSend57));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(58);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend58, sizeof(numberToSend58));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(59);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend59, sizeof(numberToSend59));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(60);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend60, sizeof(numberToSend60));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(61);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend61, sizeof(numberToSend61));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(62);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend62, sizeof(numberToSend62));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(63);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend63, sizeof(numberToSend63));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(64);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend64, sizeof(numberToSend64));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(65);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend65, sizeof(numberToSend65));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(66);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend66, sizeof(numberToSend66));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(67);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend67, sizeof(numberToSend67));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(68);                                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 4)
  Wire.write((uint8_t*)&numberToSend68, sizeof(numberToSend68));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000);                                                                    // Tunggu 1 detik
}
