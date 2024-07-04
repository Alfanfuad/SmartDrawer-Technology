#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>


#define SS_PIN 5                                                                                        // Sesuaikan dengan pin SS (atau RST) modul RC522
#define RST_PIN 27                                                                                      // Sesuaikan dengan pin RST modul RC522
#define NUM_CARDS 3                                                                                     // Jumlah kartu yang ingin didaftarkan (ganti ini apabila kartu yang ingin didaftarkan lebih banyak!!!)
#define NFC_UID_SIZE 4                                                                                  // Ukuran UID kartu NFC (pada modul RC522 UID hanya berukuran 4 byte)
#define BUTTON_PIN 34                                                                                   // Sesuaikan dengan pin untuk button state akhiri program NFC reader di pin 34
#define RELAY_PIN 14                                                                                    // Sesuaikan dengan pin untuk Relay pin untuk solenoid di pin 14

MFRC522 mfrc522(SS_PIN, RST_PIN);                                                                       // Inisialisasi pustaka RC522 dengan pin yang sesuai

byte registeredUIDs[NUM_CARDS][NFC_UID_SIZE] = {
  {0x53, 0xD3, 0x3C, 0x10},                                                                             // Registrasi kartu ke-1
  {0x0F, 0X1C, 0X8A, 0XAD},
  {0x8F, 0X2A, 0XCA, 0X34}                                                                              // Registrasi kartu ke-2
};

const char* owners[NUM_CARDS] ={
  "GMF",                                                                                                // Owner kartu ke-1
  "Alfan",
  "Fuad"                                                                                               // Owner kartu ke-2
};

int x;                                                                                                  // inisialisasi nilai x untuk penghentian stop button akhiri program 
uint8_t receivedNumber = 0;
int a;
int t[3];
signed int c;


void setup() {
  Serial.begin(115200);
  Wire.begin(8);
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);                                                                    // inisialisasi button pin sebagai 
  pinMode(RELAY_PIN, OUTPUT);                                                                           // inisialisasi module relay sebagai output

  while (!Serial);                                                                                      // Tunggu hingga Serial Monitor terbuka
  SPI.begin();                                                                                          // Inisialisasi SPI bus
  mfrc522.PCD_Init();                                                                                   // Inisialisasi pustaka RC522
  Serial.println("Waiting for an NFC card ...");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
      if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        Serial.println("Found an NFC card!");
        if (mfrc522.uid.size == NFC_UID_SIZE) {
          byte* uidData = mfrc522.uid.uidByte;
          if (isRegisteredCard(uidData)) {
            digitalWrite(RELAY_PIN, HIGH);
            openDrawer();                                                                               // Fungsi untuk membuka laci
            x = 0;
            Wire.onReceive(receiveEvent);                                                               // Atur fungsi yang akan dipanggil saat menerima data
            

          } else {
              Serial.println("Access denied! Unauthorized card.");
              Serial.println("Waiting for an NFC card ...");
           }
        } else {
          Serial.println("Invalid NFC card.");
          }
        
        delay(1000);                                                                                    // Beri jeda agar kartu tidak terus-menerus terdeteksi saat ditempatkan di atas reader
        mfrc522.PICC_HaltA();                                                                           // Hentikan kartu NFC yang terdeteksi saat ini
      }
  } else if(digitalRead(BUTTON_PIN) == HIGH){
      Serial.println("Button Pressed! Ending RFID code.");
      digitalWrite(RELAY_PIN, LOW);
      x = 1; 
      delay(1000);
      return setup();    
    }
  

}

bool isRegisteredCard(byte* uidData) {
  for (int i = 0; i < NUM_CARDS; i++) {
    if (memcmp(uidData, registeredUIDs[i], NFC_UID_SIZE) == 0) {
      Serial.println("Access granted! Opening drawer...");
      Serial.print("Hello ");                                                                           // Inisialisasi I2C komunikasi dan tentukan alamat slave (alamat 8 pada contoh ini)
      Serial.print(owners[i]);
      Serial.println("!");
      return true;                                                                                      // Kartu terdeteksi ada dalam daftar kartu terdaftar
    }
  }
  return false;                                                                                         // Kartu tidak ada dalam daftar kartu terdaftar
}

// Fungsi ini akan dipanggil saat master mengirimkan data
void receiveEvent(int numBytes) {
    Wire.begin(8);  
    if(x == 0){
      if (numBytes <= sizeof(int)) {
        byte sourceID = Wire.read();                                                                    // Baca byte pertama untuk mengetahui sumber data (Master 1 atau Master 2)
        Wire.readBytes((uint8_t*)&receivedNumber, sizeof(receivedNumber));                              // Baca byte array dan ubah menjadi angka integer       
        Wire.begin(8);  

        c=0;

        if (sourceID == 1) {
          Serial.print("Data 1: ");
          Serial.println(receivedNumber);        
          t[0]=receivedNumber;
          if (t[0] == 1){
            t[0]=1;
          } else {
            t[0]=0;
          }
        } else if (sourceID == 2) {
          Serial.print("Data 2: ");
          Serial.println(receivedNumber);
           t[1]=receivedNumber;
          if (t[1] == 1){
            t[1]=1;
          } else {
            t[1]=0;
          }
        } else if (sourceID == 3) {
          Serial.print("Data 3: ");
          Serial.println(receivedNumber);  
           t[2]=receivedNumber;
          if (t[2] == 1){
            t[2]=1;
          } else {
            t[2]=0;
          }
        } else {
          Serial.print("Unknown source data: ");
        }
      }

      for (a=0; a<3; a++){
        c=c<<1;
        c=c|t[a];
      }
        Serial.print(c);
        Serial.println("");

    } else if(x == 1){
        return;
      }
}

void openDrawer() {
  Serial.println("Laci terbuka");
  mfrc522.PICC_HaltA();
  delay(1000);
}