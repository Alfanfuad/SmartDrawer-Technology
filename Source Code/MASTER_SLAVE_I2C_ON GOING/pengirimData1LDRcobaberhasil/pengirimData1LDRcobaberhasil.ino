//  TRAY 1  ....  SD-TECH DRAWER


#include <Wire.h>
#define LDR1 24
#define LDR2 22
//#define LDR3 4


void setup() {
  Serial.begin(115200);
  Wire.begin(); // Inisialisasi I2C komunikasi
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
// pinMode(LDR3, INPUT);
 
}

void loop() {
  int LDR1Z = digitalRead(LDR1); // Angka integer yang akan dikirim ke slave
  int LDR2Z = digitalRead(LDR2); // Angka integer yang akan dikirim ke slave
  int LDR3Z = digitalRead(LDR3); // Angka integer yang akan dikirim ke slave
  

  // Kirim data dari Master 1 ke slave dengan menambahkan tanda atau kode unik (1)
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(1); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR1Z, sizeof(LDR1Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 1 : ");
  Serial.println(LDR1Z);
  delay(10);

  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(2); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR2Z, sizeof(LDR2Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 2 : ");
  Serial.println(LDR2Z);
  delay(10);
  
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(3); // Tambahkan kode unik sebagai tanda sumber data (Master 1)
  Wire.write((uint8_t*)&LDR3Z, sizeof(LDR3Z)); // Mengirim byte array dari angka integer
  Wire.endTransmission();
  Serial.print("LDR 3 : ");
  Serial.println(LDR3Z);  
  delay(10);

  delay(1000); // Tunggu 1 detik
}

