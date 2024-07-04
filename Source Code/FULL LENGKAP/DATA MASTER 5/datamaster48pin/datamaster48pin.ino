#include <Wire.h>

#define LDR69   ...  // isi pin ldr1
#define LDR70   ...  // isi pin ldr2 
#define LDR71   ...  // isi pin ldr3
#define LDR72   ...  // isi pin ldr1
#define LDR73   ...  // isi pin ldr2 
#define LDR74   ...  // isi pin ldr3
#define LDR75   ...  // isi pin ldr1
#define LDR76   ...  // isi pin ldr2 
#define LDR77   ...  // isi pin ldr3
#define LDR78   ...  // isi pin ldr1
#define LDR79   ...  // isi pin ldr2 
#define LDR80   ...  // isi pin ldr3
#define LDR81   ...  // isi pin ldr1
#define LDR82   ...  // isi pin ldr2 
#define LDR83   ...  // isi pin ldr3
#define LDR84   ...  // isi pin ldr1
#define LDR85   ...  // isi pin ldr2 
#define LDR86   ...  // isi pin ldr3
#define LDR87   ...  // isi pin ldr1
#define LDR88   ...  // isi pin ldr2 
#define LDR89   ...  // isi pin ldr3
#define LDR90   ...  // isi pin ldr1
#define LDR91   ...  // isi pin ldr2 
#define LDR92   ...  // isi pin ldr3
#define LDR93   ...  // isi pin ldr1
#define LDR94   ...  // isi pin ldr2 
#define LDR95   ...  // isi pin ldr3
#define LDR96   ...  // isi pin ldr1
#define LDR97   ...  // isi pin ldr2 
#define LDR98   ...  // isi pin ldr3
#define LDR99   ...  // isi pin ldr1
#define LDR100  ...  // isi pin ldr2 
#define LDR101  ...  // isi pin ldr3
#define LDR102  ...  // isi pin ldr1
#define LDR103  ...  // isi pin ldr2 
#define LDR104  ...  // isi pin ldr3
#define LDR105  ...  // isi pin ldr1
#define LDR106  ...  // isi pin ldr2 
#define LDR107  ...  // isi pin ldr3
#define LDR108  ...  // isi pin ldr1
#define LDR109  ...  // isi pin ldr2 
#define LDR110  ...  // isi pin ldr3
#define LDR111  ...  // isi pin ldr1
#define LDR112  ...  // isi pin ldr2 
#define LDR113  ...  // isi pin ldr3
#define LDR114  ...  // isi pin ldr1
#define LDR115  ...  // isi pin ldr2 
#define LDR116  ...  // isi pin ldr3

void setup() {
  Wire.begin();                                                                   // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  pinMode(LDR69, INPUT);
  pinMode(LDR70, INPUT);
  pinMode(LDR71, INPUT);
  pinMode(LDR72, INPUT);
  pinMode(LDR73, INPUT);
  pinMode(LDR74, INPUT);
  pinMode(LDR75, INPUT);
  pinMode(LDR76, INPUT);
  pinMode(LDR77, INPUT);
  pinMode(LDR78, INPUT);
  pinMode(LDR79, INPUT);
  pinMode(LDR80, INPUT);
  pinMode(LDR81, INPUT);
  pinMode(LDR82, INPUT);
  pinMode(LDR83, INPUT);
  pinMode(LDR84, INPUT);
  pinMode(LDR85, INPUT);
  pinMode(LDR86, INPUT);
  pinMode(LDR87, INPUT);
  pinMode(LDR88, INPUT);
  pinMode(LDR89, INPUT);
  pinMode(LDR90, INPUT);
  pinMode(LDR91, INPUT);
  pinMode(LDR92, INPUT);
  pinMode(LDR93, INPUT);
  pinMode(LDR94, INPUT);
  pinMode(LDR95, INPUT);
  pinMode(LDR96, INPUT);
  pinMode(LDR97, INPUT);
  pinMode(LDR98, INPUT);
  pinMode(LDR99, INPUT);
  pinMode(LDR100, INPUT);
  pinMode(LDR101, INPUT);
  pinMode(LDR102, INPUT);
  pinMode(LDR103, INPUT);
  pinMode(LDR104, INPUT);
  pinMode(LDR105, INPUT);
  pinMode(LDR106, INPUT);
  pinMode(LDR107, INPUT);
  pinMode(LDR108, INPUT);
  pinMode(LDR109, INPUT);
  pinMode(LDR110, INPUT);
  pinMode(LDR111, INPUT);
  pinMode(LDR112, INPUT);
  pinMode(LDR113, INPUT);
  pinMode(LDR114, INPUT);
  pinMode(LDR115, INPUT);
  pinMode(LDR116, INPUT);
}

void loop() {
  uint8_t numberToSend69   = digitalRead(LDR69);                                    // Angka integer 69 yang akan dikirim ke slave
  uint8_t numberToSend70   = digitalRead(LDR70);                                    // Angka integer 70 yang akan dikirim ke slave
  uint8_t numberToSend71   = digitalRead(LDR71);                                    // Angka integer 71 yang akan dikirim ke slave
  uint8_t numberToSend72   = digitalRead(LDR72);                                    // Angka integer 72 yang akan dikirim ke slave
  uint8_t numberToSend73   = digitalRead(LDR73);                                    // Angka integer 73 yang akan dikirim ke slave
  uint8_t numberToSend74   = digitalRead(LDR74);                                    // Angka integer 74 yang akan dikirim ke slave
  uint8_t numberToSend75   = digitalRead(LDR75);                                    // Angka integer 75 yang akan dikirim ke slave
  uint8_t numberToSend76   = digitalRead(LDR76);                                    // Angka integer 76 yang akan dikirim ke slave
  uint8_t numberToSend77   = digitalRead(LDR77);                                    // Angka integer 77 yang akan dikirim ke slave
  uint8_t numberToSend78   = digitalRead(LDR78);                                    // Angka integer 78 yang akan dikirim ke slave
  uint8_t numberToSend79   = digitalRead(LDR79);                                    // Angka integer 79 yang akan dikirim ke slave
  uint8_t numberToSend80   = digitalRead(LDR80);                                    // Angka integer 80 yang akan dikirim ke slave
  uint8_t numberToSend81   = digitalRead(LDR81);                                    // Angka integer 81 yang akan dikirim ke slave
  uint8_t numberToSend82   = digitalRead(LDR82);                                    // Angka integer 82 yang akan dikirim ke slave
  uint8_t numberToSend83   = digitalRead(LDR83);                                    // Angka integer 83 yang akan dikirim ke slave
  uint8_t numberToSend84   = digitalRead(LDR84);                                    // Angka integer 84 yang akan dikirim ke slave
  uint8_t numberToSend85   = digitalRead(LDR85);                                    // Angka integer 85 yang akan dikirim ke slave
  uint8_t numberToSend86   = digitalRead(LDR86);                                    // Angka integer 86 yang akan dikirim ke slave
  uint8_t numberToSend87   = digitalRead(LDR87);                                    // Angka integer 87 yang akan dikirim ke slave
  uint8_t numberToSend88   = digitalRead(LDR88);                                    // Angka integer 88 yang akan dikirim ke slave
  uint8_t numberToSend89   = digitalRead(LDR89);                                    // Angka integer 89 yang akan dikirim ke slave
  uint8_t numberToSend90   = digitalRead(LDR90);                                    // Angka integer 90 yang akan dikirim ke slave
  uint8_t numberToSend91   = digitalRead(LDR91);                                    // Angka integer 91 yang akan dikirim ke slave
  uint8_t numberToSend92   = digitalRead(LDR92);                                    // Angka integer 92 yang akan dikirim ke slave
  uint8_t numberToSend93   = digitalRead(LDR93);                                    // Angka integer 93 yang akan dikirim ke slave
  uint8_t numberToSend94   = digitalRead(LDR94);                                    // Angka integer 94 yang akan dikirim ke slave
  uint8_t numberToSend95   = digitalRead(LDR95);                                    // Angka integer 95 yang akan dikirim ke slave
  uint8_t numberToSend96   = digitalRead(LDR96);                                    // Angka integer 96 yang akan dikirim ke slave
  uint8_t numberToSend97   = digitalRead(LDR97);                                    // Angka integer 97 yang akan dikirim ke slave
  uint8_t numberToSend98   = digitalRead(LDR98);                                    // Angka integer 98 yang akan dikirim ke slave
  uint8_t numberToSend99   = digitalRead(LDR99);                                    // Angka integer 99 yang akan dikirim ke slave
  uint8_t numberToSend100  = digitalRead(LDR100);                                   // Angka integer 100 yang akan dikirim ke slave
  uint8_t numberToSend101  = digitalRead(LDR101);                                   // Angka integer 101 yang akan dikirim ke slave
  uint8_t numberToSend102  = digitalRead(LDR102);                                   // Angka integer 102 yang akan dikirim ke slave
  uint8_t numberToSend103  = digitalRead(LDR103);                                   // Angka integer 103 yang akan dikirim ke slave
  uint8_t numberToSend104  = digitalRead(LDR104);                                   // Angka integer 104 yang akan dikirim ke slave
  uint8_t numberToSend105  = digitalRead(LDR105);                                   // Angka integer 105 yang akan dikirim ke slave
  uint8_t numberToSend106  = digitalRead(LDR106);                                   // Angka integer 106 yang akan dikirim ke slave
  uint8_t numberToSend107  = digitalRead(LDR107);                                   // Angka integer 107 yang akan dikirim ke slave
  uint8_t numberToSend108  = digitalRead(LDR108);                                   // Angka integer 108 yang akan dikirim ke slave
  uint8_t numberToSend109  = digitalRead(LDR109);                                   // Angka integer 109 yang akan dikirim ke slave
  uint8_t numberToSend110  = digitalRead(LDR110);                                   // Angka integer 110 yang akan dikirim ke slave
  uint8_t numberToSend111  = digitalRead(LDR111);                                   // Angka integer 111 yang akan dikirim ke slave
  uint8_t numberToSend112  = digitalRead(LDR112);                                   // Angka integer 112 yang akan dikirim ke slave
  uint8_t numberToSend113  = digitalRead(LDR113);                                   // Angka integer 113 yang akan dikirim ke slave
  uint8_t numberToSend114  = digitalRead(LDR114);                                   // Angka integer 114 yang akan dikirim ke slave
  uint8_t numberToSend115  = digitalRead(LDR115);                                   // Angka integer 115 yang akan dikirim ke slave
  uint8_t numberToSend116  = digitalRead(LDR116);                                   // Angka integer 116 yang akan dikirim ke slave

  // Kirim data dari Master 5 ke slave dengan menambahkan tanda atau kode unik (5)
  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(69);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend69, sizeof(numberToSend69));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(70);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend70, sizeof(numberToSend70));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(71);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend71, sizeof(numberToSend71));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(72);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend72, sizeof(numberToSend72));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(73);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend73, sizeof(numberToSend73));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(74);                                                                   // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend74, sizeof(numberToSend74));                    // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(75);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend75, sizeof(numberToSend75));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(76);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend76, sizeof(numberToSend76));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(77);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend77, sizeof(numberToSend77));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(78);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend78, sizeof(numberToSend78));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(79);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend79, sizeof(numberToSend79));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(80);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend80, sizeof(numberToSend80));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(81);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend81, sizeof(numberToSend81));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(82);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend82, sizeof(numberToSend82));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(83);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend83, sizeof(numberToSend83));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(84);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend84, sizeof(numberToSend84));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(85);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend85, sizeof(numberToSend85));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(86);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend86, sizeof(numberToSend86));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(87);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend87, sizeof(numberToSend87));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(88);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend88, sizeof(numberToSend88));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(89);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend89, sizeof(numberToSend89));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(90);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend90, sizeof(numberToSend90));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

    Wire.beginTransmission(8);                                    // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(91);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend91, sizeof(numberToSend91));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(92);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend92, sizeof(numberToSend92));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(93);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend93, sizeof(numberToSend93));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(94);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend94, sizeof(numberToSend94));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(95);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend95, sizeof(numberToSend95));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(96);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend96, sizeof(numberToSend96));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(97);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend97, sizeof(numberToSend97));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(98);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend98, sizeof(numberToSend98));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                      // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(99);                                                 // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend99, sizeof(numberToSend99));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(100);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend100, sizeof(numberToSend100));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(101);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend101, sizeof(numberToSend101));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(102);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend102, sizeof(numberToSend102));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(103);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend103, sizeof(numberToSend103));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(104);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend104, sizeof(numberToSend104));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(105);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend105, sizeof(numberToSend105));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(106);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend106, sizeof(numberToSend106));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(107);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend107, sizeof(numberToSend107));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(108);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend108, sizeof(numberToSend108));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(109);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend109, sizeof(numberToSend109));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(110);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend110, sizeof(numberToSend110));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                         // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(111);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend111, sizeof(numberToSend111));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(112);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend112, sizeof(numberToSend112));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(113);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend113, sizeof(numberToSend113));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(114);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend114, sizeof(numberToSend114));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(115);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend115, sizeof(numberToSend115));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  Wire.beginTransmission(8);                                        // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(116);                                                  // Tambahkan kode unik sebagai tanda sumber data (Master 5)
  Wire.write((uint8_t*)&numberToSend116, sizeof(numberToSend116));  // Mengirim byte array dari angka integer
  Wire.endTransmission();

  delay(1000);                                                                    // Tunggu 1 detik
}
