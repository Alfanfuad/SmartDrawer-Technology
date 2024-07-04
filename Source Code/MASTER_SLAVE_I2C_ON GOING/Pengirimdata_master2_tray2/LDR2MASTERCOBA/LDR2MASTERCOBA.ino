//  TRAY 2 .... SD-TECH DRAWER


#include <Wire.h>
#define LDR4 15
#define LDR5 4
#define LDR6 13
#define LDR7 14
#define LDR8 27
#define LDR9 26
#define LDR10 25
#define LDR11 33
#define LDR12 32
#define LDR13 35
#define LDR14 34


void setup() {
  Serial.begin(115200);
  Wire.begin(); // Inisialisasi I2C komunikasi
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
  int LDR4Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR5Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR6Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR7Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR8Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR9Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR10Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR11Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR12Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR13Z = 1; // Angka integer yang akan dikirim ke slave
  int LDR14Z = 1; // Angka integer yang akan dikirim ke slave

  

  // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(4); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR4Z, sizeof(LDR4Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 4 : ");
  Serial.println(LDR4Z);
  delay(10);

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(5); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR5Z, sizeof(LDR5Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 5 : ");
  Serial.println(LDR5Z);
  delay(10);
  
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(6); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR6Z, sizeof(LDR6Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 6 : ");
  Serial.println(LDR6Z);  
  delay(10);

  // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(7); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR7Z, sizeof(LDR7Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 7 : ");
  Serial.println(LDR7Z);
  delay(10);

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(8); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR8Z, sizeof(LDR8Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 8 : ");
  Serial.println(LDR8Z);
  delay(10);
  
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(9); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR9Z, sizeof(LDR9Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 9 : ");
  Serial.println(LDR9Z);  
  delay(10);

    // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(10); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR10Z, sizeof(LDR10Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 10 : ");
  Serial.println(LDR10Z);
  delay(10);

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(11); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR11Z, sizeof(LDR11Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 11 : ");
  Serial.println(LDR11Z);
  delay(10);
  
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(12); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR12Z, sizeof(LDR12Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 12 : ");
  Serial.println(LDR12Z);  
  delay(10);

    // Kirim data dari Master 2 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(13); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR13Z, sizeof(LDR13Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 13 : ");
  Serial.println(LDR13Z);
  delay(10);

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(14); // Tambahkan kode unik sebagai tanda sumber data (Master 2)
  Wire.write((uint8_t*)&LDR14Z, sizeof(LDR14Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 14 : ");
  Serial.println(LDR14Z);
  delay(10);
  

  delay(1000); // Tunggu 1 detik
}

