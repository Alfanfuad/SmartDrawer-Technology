#include <Wire.h>


#define s0 4
#define s1 15
#define s2 27
#define pin_analog_1 32
#define pin_analog_2 14                                                          

int i, data;

void setup() {
  Wire.begin(); // Inisialisasi I2C komunikasi
  Serial.begin(115200);
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(pin_analog_1, OUTPUT);  
  pinMode(pin_analog_2, OUTPUT);

  baca_sensor();
}

void loop() {
  // Kirim data dari Master 1 ke slave dengan menambahkan tanda atau kode unik (1)
  baca_sensor();
  delay(1000); // Tunggu 1 detik
}

void baca_sensor(){
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(pin_analog_1); 
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(1);
  Wire.write((uint8_t*)&data, sizeof(data)); 
  Wire.endTransmission();
  Serial.print("ldr 1= ");
  Serial.println(data);
  delay(10);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(pin_analog_2);
  Wire.beginTransmission(8); // Alamat slave ESP32 (alamat 8 pada contoh ini)
  Wire.write(2);
  Wire.write((uint8_t*)&data2, sizeof(data2)); 
  Wire.endTransmission();
  Serial.print("ldr 2= ");
  Serial.println(data);
  delay (10);
  
  delay(10);
  delay(500);
}

