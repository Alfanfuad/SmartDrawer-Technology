#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include <HTTPClient.h>


////////////////////////////////////////////////////



#define SS_PIN 5                                                                                        // Sesuaikan dengan pin SS (atau RST) modul RC522
#define RST_PIN 27                                                                                      // Sesuaikan dengan pin RST modul RC522
#define NUM_CARDS 3                                                                                     // Jumlah kartu yang ingin didaftarkan (ganti ini apabila kartu yang ingin didaftarkan lebih banyak!!!)
#define NFC_UID_SIZE 4                                                                                  // Ukuran UID kartu NFC (pada modul RC522 UID hanya berukuran 4 byte)
#define BUTTON_PIN 34                                                                                   // Sesuaikan dengan pin untuk button state akhiri program NFC reader di pin 34
#define RELAY_PIN 14                                                                                    // Sesuaikan dengan pin untuk Relay pin untuk solenoid di pin 14


////////////////////////////////////////////////////

int status1 = WL_IDLE_STATUS;
int tray1;
int tray2;


//Konfigurasi WiFi
const char *ssid = "vivo 1820";
const char *password = "123456780";

//IP Address Server yang terpasang XAMPP
const char *host = "192.168.43.236";
   

MFRC522 mfrc522(SS_PIN, RST_PIN);                                                                       // Inisialisasi pustaka RC522 dengan pin yang sesuai

byte registeredUIDs[NUM_CARDS][NFC_UID_SIZE] = {
  {0x53, 0xD3, 0x3C, 0x10},                                                                             // Registrasi kartu ke-1
  {0x0F, 0X1C, 0X8A, 0XAD}                                                                              // Registrasi kartu ke-2
};

const char* owners[NUM_CARDS] ={
  "12231231"                                                                                                // Owner kartu ke-1                                                                                               
  "32432322"                                                                                                // Owner kartu ke-2
};

String ID_Number = owners[0];

int x;                                                                                                  // inisialisasi nilai x untuk penghentian stop button akhiri program 
int receivedNumber = 0;
int a;
int t[120];
int c;


void setup() {
  Serial.begin(115200);
  Wire.begin(8);

  InitWiFi();

  
  pinMode(BUTTON_PIN, INPUT_PULLUP);                                                                    // inisialisasi button pin sebagai 
  pinMode(RELAY_PIN, OUTPUT);                                                                           // inisialisasi module relay sebagai output

  while (!Serial);                                                                                      // Tunggu hingga Serial Monitor terbuka
  SPI.begin();                                                                                          // Inisialisasi SPI bus
  mfrc522.PCD_Init();                                                                                   // Inisialisasi pustaka RC522
  Serial.println("Waiting for an NFC card ...");
}

void loop() {

  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  delay(1000);
  // String url = "/sdtech/test/write.php?";
  //           url = url + "nopeg=" + ID_Number.toInt() + "&tray1=" + c;
    
  //       Serial.print("Requesting URL: ");
  //       Serial.println(url);
  //     // Mengirimkan Request ke Server -----------------------------------------------
  //       client.print(String("GET ") + url + " HTTP/1.1\r\n" +
  //                   "Host: " + host + "\r\n" +
  //                   "Connection: close\r\n\r\n");
  //     client.println("");               
  //       unsigned long timeout = millis();

  //       while (client.available() == 0) {
  //         if (millis() - timeout > 1000) {
  //           Serial.println(">>> Client Timeout !");
  //           client.stop();
  //           return;
  //         }
  //       }

  //     // Read all the lines of the reply from server and print them to Serial
  //       while (client.available()) {
  //         String line = client.readStringUntil('\r');
  //         Serial.print(line);
  //       }

  //       Serial.println();
  //       Serial.println("closing connection");
  //       delay(100);


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
      
      //////////////////////////////////////////


      String url = "/sdtech/test/write.php?";
            url = url + "nopeg=" + ID_Number.toInt() + "&tray1=" + tray1;
    
        Serial.print("Requesting URL: ");
        Serial.println(url);
      // Mengirimkan Request ke Server -----------------------------------------------
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                    "Host: " + host + "\r\n" +
                    "Connection: close\r\n\r\n");
      client.println("");               
        unsigned long timeout = millis();

        while (client.available() == 0) {
          if (millis() - timeout > 1000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
          }
        }

      // Read all the lines of the reply from server and print them to Serial
        while (client.available()) {
          String line = client.readStringUntil('\r');
          Serial.print(line);
        }

        Serial.println();
        Serial.println("closing connection");
        delay(100);

      ////////////////////////////////////////////////


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

    tray1=0;
    tray2=0;  
    
    if(x == 0){
      if (numBytes >= sizeof(int)) {
        byte sourceID = Wire.read();                                                                    // Baca byte pertama untuk mengetahui sumber data (Master 1 atau Master 2)
        Wire.readBytes((uint8_t*)&receivedNumber, sizeof(receivedNumber));                              // Baca byte array dan ubah menjadi angka integer       
        Wire.begin(8);  
        

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
        } else if (sourceID == 4) {
          Serial.print("Data 4: ");
          Serial.println(receivedNumber);
           t[3]=receivedNumber;
          if (t[3] == 1){
            t[3]=1;
          } else {
            t[3]=0;
          }
        } else if (sourceID == 5) {
          Serial.print("Data 5: ");
          Serial.println(receivedNumber);  
           t[4]=receivedNumber;
          if (t[4] == 1){
            t[4]=1;
          } else {
            t[4]=0;
          }
        } else if (sourceID == 6) {
          Serial.print("Data 6: ");
          Serial.println(receivedNumber);
           t[5]=receivedNumber;
          if (t[5] == 1){
            t[5]=1;
          } else {
            t[5]=0;
          }
        } else if (sourceID == 7) {
          Serial.print("Data 7: ");
          Serial.println(receivedNumber);  
           t[6]=receivedNumber;
          if (t[6] == 1){
            t[6]=1;
          } else {
            t[6]=0;
          }
        } else if (sourceID == 8) {
          Serial.print("Data 8: ");
          Serial.println(receivedNumber);
           t[7]=receivedNumber;
          if (t[7] == 1){
            t[7]=1;
          } else {
            t[7]=0;
          }
        } else if (sourceID == 9){
          Serial.print("Data 9: ");
          Serial.println(receivedNumber);  
           t[8]=receivedNumber;
          if (t[8] == 1){
            t[8]=1;
          } else {
            t[8]=0;
          }
        } else if (sourceID == 10) {
          Serial.print("Data 10: ");
          Serial.println(receivedNumber);
           t[9]=receivedNumber;
          if (t[9] == 1){
            t[9]=1;
          } else {
            t[9]=0;
          }
        } else if (sourceID == 11) {
          Serial.print("Data 11: ");
          Serial.println(receivedNumber);  
           t[10]=receivedNumber;
          if (t[10] == 1){
            t[10]=1;
          } else {
            t[10]=0;
          }
        } else if (sourceID == 12) {
          Serial.print("Data 12: ");
          Serial.println(receivedNumber);
           t[11]=receivedNumber;
          if (t[11] == 1){
            t[11]=1;
          } else {
            t[11]=0;
          }
        } else if (sourceID == 13) {
          Serial.print("Data 13: ");
          Serial.println(receivedNumber);  
           t[12]=receivedNumber;
          if (t[12] == 1){
            t[12]=1;
          } else {
            t[12]=0;
          }
        } else if (sourceID == 14) {
          Serial.print("Data 14: ");
          Serial.println(receivedNumber);
           t[13]=receivedNumber;
          if (t[13] == 1){
            t[13]=1;
          } else {
            t[13]=0;
          }
        } else if (sourceID == 15) {
          Serial.print("Data 15: ");
          Serial.println(receivedNumber);
           t[14]=receivedNumber;
          if (t[14] == 1){
            t[14]=1;
          } else {
            t[14]=0;
          }
        } else if (sourceID == 16) {
          Serial.print("Data 16: ");
          Serial.println(receivedNumber);
           t[15]=receivedNumber;
          if (t[15] == 1){
            t[15]=1;
          } else {
            t[15]=0;
          }
        } else if (sourceID == 17) {
          Serial.print("Data 17: ");
          Serial.println(receivedNumber);
           t[16]=receivedNumber;
          if (t[16] == 1){
            t[16]=1;
          } else {
            t[16]=0;
          }
        } else if (sourceID == 18) {
          Serial.print("Data 18: ");
          Serial.println(receivedNumber);
           t[17]=receivedNumber;
          if (t[17] == 1){
            t[17]=1;
          } else {
            t[17]=0;
          }
        } else if (sourceID == 19) {
          Serial.print("Data 19: ");
          Serial.println(receivedNumber);  
           t[18]=receivedNumber;
          if (t[18] == 1){
            t[18]=1;
          } else {
            t[18]=0;
          }
        } else if (sourceID == 20) {
          Serial.print("Data 20: ");
          Serial.println(receivedNumber);
           t[19]=receivedNumber;
          if (t[19] == 1){
            t[19]=1;
          } else {
            t[19]=0;
          }
        } else if (sourceID == 21) {
          Serial.print("Data 21: ");
          Serial.println(receivedNumber);  
           t[20]=receivedNumber;
          if (t[20] == 1){
            t[20]=1;
          } else {
            t[20]=0;
          }
        } else if (sourceID == 22) {
          Serial.print("Data 22: ");
          Serial.println(receivedNumber);
           t[21]=receivedNumber;
          if (t[21] == 1){
            t[21]=1;
          } else {
            t[21]=0;
          }
        } else if (sourceID == 23) {
          Serial.print("Data 23: ");
          Serial.println(receivedNumber);  
           t[22]=receivedNumber;
          if (t[22] == 1){
            t[22]=1;
          } else {
            t[22]=0;
          }
        } else if (sourceID == 24) {
          Serial.print("Data 24: ");
          Serial.println(receivedNumber);
           t[23]=receivedNumber;
          if (t[23] == 1){
            t[23]=1;
          } else {
            t[23]=0;
          }
        } else if (sourceID == 25){
          Serial.print("Data 25: ");
          Serial.println(receivedNumber);  
           t[24]=receivedNumber;
          if (t[24] == 1){
            t[24]=1;
          } else {
            t[24]=0;
          }
        } else if (sourceID == 26) {
          Serial.print("Data 26: ");
          Serial.println(receivedNumber);
           t[25]=receivedNumber;
          if (t[25] == 1){
            t[25]=1;
          } else {
            t[25]=0;
          }
        } else if (sourceID == 27) {
          Serial.print("Data 27: ");
          Serial.println(receivedNumber);  
           t[26]=receivedNumber;
          if (t[26] == 1){
            t[26]=1;
          } else {
            t[26]=0;
          }
        } else if (sourceID == 28) {
          Serial.print("Data 28: ");
          Serial.println(receivedNumber);
           t[27]=receivedNumber;
          if (t[27] == 1){
            t[27]=1;
          } else {
            t[27]=0;
          }
        } else if (sourceID == 29) {
          Serial.print("Data 29: ");
          Serial.println(receivedNumber);  
           t[28]=receivedNumber;
          if (t[28] == 1){
            t[28]=1;
          } else {
            t[28]=0;
          }
        } else if (sourceID == 30) {
          Serial.print("Data 30: ");
          Serial.println(receivedNumber);
           t[29]=receivedNumber;
          if (t[29] == 1){
            t[29]=1;
          } else {
            t[29]=0;
          }
        } else if (sourceID == 31) {
          Serial.print("Data 31: ");
          Serial.println(receivedNumber);
           t[30]=receivedNumber;
          if (t[30] == 1){
            t[30]=1;
          } else {
            t[30]=0;
          }
        } else if (sourceID == 32) {
          Serial.print("Data 32: ");
          Serial.println(receivedNumber);
           t[31]=receivedNumber;
          if (t[31] == 1){
            t[31]=1;
          } else {
            t[31]=0;
          }
        } else if (sourceID == 33) {
          Serial.print("Data 33: ");
          Serial.println(receivedNumber);
           t[32]=receivedNumber;
          if (t[32] == 1){
            t[32]=1;
          } else {
            t[32]=0;
          }
        }  else if (sourceID == 34) {
          Serial.print("Data 34: ");
          Serial.println(receivedNumber);
           t[33]=receivedNumber;
          if (t[33] == 1){
            t[33]=1;
          } else {
            t[33]=0;
          }
        } else if (sourceID == 35) {
          Serial.print("Data 35: ");
          Serial.println(receivedNumber);  
           t[34]=receivedNumber;
          if (t[34] == 1){
            t[34]=1;
          } else {
            t[34]=0;
          }
        } else if (sourceID == 36) {
          Serial.print("Data 36: ");
          Serial.println(receivedNumber);
           t[35]=receivedNumber;
          if (t[35] == 1){
            t[35]=1;
          } else {
            t[35]=0;
          }
        } else if (sourceID == 37) {
          Serial.print("Data 37: ");
          Serial.println(receivedNumber);  
           t[36]=receivedNumber;
          if (t[36] == 1){
            t[36]=1;
          } else {
            t[36]=0;
          }
        } else if (sourceID == 38) {
          Serial.print("Data 38: ");
          Serial.println(receivedNumber);
           t[37]=receivedNumber;
          if (t[37] == 1){
            t[37]=1;
          } else {
            t[37]=0;
          }
        } else if (sourceID == 39){
          Serial.print("Data 39: ");
          Serial.println(receivedNumber);  
           t[38]=receivedNumber;
          if (t[38] == 1){
            t[38]=1;
          } else {
            t[38]=0;
          }
        } else if (sourceID == 40) {
          Serial.print("Data 40: ");
          Serial.println(receivedNumber);
           t[39]=receivedNumber;
          if (t[39] == 1){
            t[39]=1;
          } else {
            t[39]=0;
          }
        } else if (sourceID == 41) {
          Serial.print("Data 41: ");
          Serial.println(receivedNumber);  
           t[10]=receivedNumber;
          if (t[10] == 1){
            t[10]=1;
          } else {
            t[10]=0;
          }
        } else if (sourceID == 42) {
          Serial.print("Data 42: ");
          Serial.println(receivedNumber);
           t[41]=receivedNumber;
          if (t[41] == 1){
            t[41]=1;
          } else {
            t[41]=0;
          }
        } else if (sourceID == 43) {
          Serial.print("Data 43: ");
          Serial.println(receivedNumber);  
           t[42]=receivedNumber;
          if (t[42] == 1){
            t[42]=1;
          } else {
            t[42]=0;
          }
        } else if (sourceID == 44) {
          Serial.print("Data 44: ");
          Serial.println(receivedNumber);
           t[43]=receivedNumber;
          if (t[43] == 1){
            t[43]=1;
          } else {
            t[43]=0;
          }
        } else if (sourceID == 45) {
          Serial.print("Data 45: ");
          Serial.println(receivedNumber);
           t[44]=receivedNumber;
          if (t[44] == 1){
            t[44]=1;
          } else {
            t[44]=0;
          }
        } else if (sourceID == 46) {
          Serial.print("Data 46: ");
          Serial.println(receivedNumber);
           t[45]=receivedNumber;
          if (t[45] == 1){
            t[45]=1;
          } else {
            t[45]=0;
          }
        } else if (sourceID == 47) {
          Serial.print("Data 47: ");
          Serial.println(receivedNumber);
           t[46]=receivedNumber;
          if (t[46] == 1){
            t[46]=1;
          } else {
            t[46]=0;
          }
        } else if (sourceID == 48) {
          Serial.print("Data 48: ");
          Serial.println(receivedNumber);
           t[47]=receivedNumber;
          if (t[47] == 1){
            t[47]=1;
          } else {
            t[47]=0;
          }
        } else if (sourceID == 49) {
          Serial.print("Data 49: ");
          Serial.println(receivedNumber);  
           t[48]=receivedNumber;
          if (t[48] == 1){
            t[48]=1;
          } else {
            t[48]=0;
          }
        } else if (sourceID == 50) {
          Serial.print("Data 50: ");
          Serial.println(receivedNumber);
           t[49]=receivedNumber;
          if (t[49] == 1){
            t[49]=1;
          } else {
            t[49]=0;
          }
        } else if (sourceID == 51) {
          Serial.print("Data 51: ");
          Serial.println(receivedNumber);  
           t[50]=receivedNumber;
          if (t[50] == 1){
            t[50]=1;
          } else {
            t[50]=0;
          }
        } else if (sourceID == 52) {
          Serial.print("Data 52: ");
          Serial.println(receivedNumber);
           t[51]=receivedNumber;
          if (t[51] == 1){
            t[51]=1;
          } else {
            t[51]=0;
          }
        } else if (sourceID == 53) {
          Serial.print("Data 53: ");
          Serial.println(receivedNumber);  
           t[52]=receivedNumber;
          if (t[52] == 1){
            t[52]=1;
          } else {
            t[52]=0;
          }
        } else if (sourceID == 54) {
          Serial.print("Data 54: ");
          Serial.println(receivedNumber);
           t[53]=receivedNumber;
          if (t[53] == 1){
            t[53]=1;
          } else {
            t[53]=0;
          }
        } else if (sourceID == 55){
          Serial.print("Data 55: ");
          Serial.println(receivedNumber);  
           t[54]=receivedNumber;
          if (t[54] == 1){
            t[54]=1;
          } else {
            t[54]=0;
          }
        } else if (sourceID == 56) {
          Serial.print("Data 56: ");
          Serial.println(receivedNumber);
           t[55]=receivedNumber;
          if (t[55] == 1){
            t[55]=1;
          } else {
            t[55]=0;
          }
        } else if (sourceID == 57) {
          Serial.print("Data 57: ");
          Serial.println(receivedNumber);  
           t[56]=receivedNumber;
          if (t[56] == 1){
            t[56]=1;
          } else {
            t[56]=0;
          }
        } else if (sourceID == 58) {
          Serial.print("Data 58: ");
          Serial.println(receivedNumber);
           t[57]=receivedNumber;
          if (t[57] == 1){
            t[57]=1;
          } else {
            t[57]=0;
          }
        } else if (sourceID == 59) {
          Serial.print("Data 59: ");
          Serial.println(receivedNumber);  
           t[58]=receivedNumber;
          if (t[58] == 1){
            t[58]=1;
          } else {
            t[58]=0;
          }
        } else if (sourceID == 60) {
          Serial.print("Data 60: ");
          Serial.println(receivedNumber);
           t[59]=receivedNumber;
          if (t[59] == 1){
            t[59]=1;
          } else {
            t[59]=0;
          }
        } else if (sourceID == 61) {
          Serial.print("Data 61: ");
          Serial.println(receivedNumber);        
          t[60]=receivedNumber;
          if (t[60] == 1){
            t[60]=1;
          } else {
            t[60]=0;
          }
        } else if (sourceID == 62) {
          Serial.print("Data 62: ");
          Serial.println(receivedNumber);
           t[61]=receivedNumber;
          if (t[61] == 1){
            t[61]=1;
          } else {
            t[61]=0;
          }
        } else if (sourceID == 63) {
          Serial.print("Data 63: ");
          Serial.println(receivedNumber);  
           t[62]=receivedNumber;
          if (t[62] == 1){
            t[62]=1;
          } else {
            t[62]=0;
          }
        } else if (sourceID == 64) {
          Serial.print("Data 64: ");
          Serial.println(receivedNumber);
           t[63]=receivedNumber;
          if (t[63] == 1){
            t[63]=1;
          } else {
            t[63]=0;
          }
        } else if (sourceID == 65) {
          Serial.print("Data 65: ");
          Serial.println(receivedNumber);  
           t[64]=receivedNumber;
          if (t[64] == 1){
            t[64]=1;
          } else {
            t[64]=0;
          }
        } else if (sourceID == 66) {
          Serial.print("Data 66: ");
          Serial.println(receivedNumber);
           t[65]=receivedNumber;
          if (t[65] == 1){
            t[65]=1;
          } else {
            t[65]=0;
          }
        } else if (sourceID == 67) {
          Serial.print("Data 67: ");
          Serial.println(receivedNumber);  
           t[66]=receivedNumber;
          if (t[66] == 1){
            t[66]=1;
          } else {
            t[66]=0;
          }
        } else if (sourceID == 68) {
          Serial.print("Data 68: ");
          Serial.println(receivedNumber);
           t[67]=receivedNumber;
          if (t[67] == 1){
            t[67]=1;
          } else {
            t[67]=0;
          }
        } else if (sourceID == 69){
          Serial.print("Data 69: ");
          Serial.println(receivedNumber);  
           t[68]=receivedNumber;
          if (t[68] == 1){
            t[68]=1;
          } else {
            t[68]=0;
          }
        } else if (sourceID == 70) {
          Serial.print("Data 70: ");
          Serial.println(receivedNumber);
           t[69]=receivedNumber;
          if (t[69] == 1){
            t[69]=1;
          } else {
            t[69]=0;
          }
        } else if (sourceID == 71) {
          Serial.print("Data 71: ");
          Serial.println(receivedNumber);        
          t[70]=receivedNumber;
          if (t[70] == 1){
            t[70]=1;
          } else {
            t[70]=0;
          }
        } else if (sourceID == 72) {
          Serial.print("Data 72: ");
          Serial.println(receivedNumber);
           t[71]=receivedNumber;
          if (t[71] == 1){
            t[71]=1;
          } else {
            t[71]=0;
          }
        } else if (sourceID == 73) {
          Serial.print("Data 73: ");
          Serial.println(receivedNumber);  
           t[72]=receivedNumber;
          if (t[72] == 1){
            t[72]=1;
          } else {
            t[72]=0;
          }
        } else if (sourceID == 74) {
          Serial.print("Data 74: ");
          Serial.println(receivedNumber);
           t[73]=receivedNumber;
          if (t[73] == 1){
            t[73]=1;
          } else {
            t[73]=0;
          }
        } else if (sourceID == 75) {
          Serial.print("Data 75: ");
          Serial.println(receivedNumber);  
           t[74]=receivedNumber;
          if (t[74] == 1){
            t[74]=1;
          } else {
            t[74]=0;
          }
        } else if (sourceID == 76) {
          Serial.print("Data 76: ");
          Serial.println(receivedNumber);
           t[75]=receivedNumber;
          if (t[75] == 1){
            t[75]=1;
          } else {
            t[75]=0;
          }
        } else if (sourceID == 77) {
          Serial.print("Data 77: ");
          Serial.println(receivedNumber);  
           t[76]=receivedNumber;
          if (t[76] == 1){
            t[76]=1;
          } else {
            t[76]=0;
          }
        } else if (sourceID == 78) {
          Serial.print("Data 78: ");
          Serial.println(receivedNumber);
           t[77]=receivedNumber;
          if (t[77] == 1){
            t[77]=1;
          } else {
            t[77]=0;
          }
        } else if (sourceID == 79){
          Serial.print("Data 79: ");
          Serial.println(receivedNumber);  
           t[78]=receivedNumber;
          if (t[78] == 1){
            t[78]=1;
          } else {
            t[78]=0;
          }
        } else if (sourceID == 80) {
          Serial.print("Data 80: ");
          Serial.println(receivedNumber);
           t[79]=receivedNumber;
          if (t[79] == 1){
            t[79]=1;
          } else {
            t[79]=0;
          }
        } else if (sourceID == 81) {
          Serial.print("Data 81: ");
          Serial.println(receivedNumber);        
          t[80]=receivedNumber;
          if (t[80] == 1){
            t[80]=1;
          } else {
            t[80]=0;
          }
        } else if (sourceID == 82) {
          Serial.print("Data 82: ");
          Serial.println(receivedNumber);
           t[81]=receivedNumber;
          if (t[81] == 1){
            t[81]=1;
          } else {
            t[81]=0;
          }
        } else if (sourceID == 83) {
          Serial.print("Data 83: ");
          Serial.println(receivedNumber);  
           t[82]=receivedNumber;
          if (t[82] == 1){
            t[82]=1;
          } else {
            t[82]=0;
          }
        } else if (sourceID == 84) {
          Serial.print("Data 84: ");
          Serial.println(receivedNumber);
           t[83]=receivedNumber;
          if (t[83] == 1){
            t[83]=1;
          } else {
            t[83]=0;
          }
        } else if (sourceID == 85) {
          Serial.print("Data 85: ");
          Serial.println(receivedNumber);  
           t[84]=receivedNumber;
          if (t[84] == 1){
            t[84]=1;
          } else {
            t[84]=0;
          }
        } else if (sourceID == 86) {
          Serial.print("Data 86: ");
          Serial.println(receivedNumber);
           t[85]=receivedNumber;
          if (t[85] == 1){
            t[85]=1;
          } else {
            t[85]=0;
          }
        } else if (sourceID == 87) {
          Serial.print("Data 87: ");
          Serial.println(receivedNumber);  
           t[86]=receivedNumber;
          if (t[86] == 1){
            t[86]=1;
          } else {
            t[86]=0;
          }
        } else if (sourceID == 88) {
          Serial.print("Data 88: ");
          Serial.println(receivedNumber);
           t[87]=receivedNumber;
          if (t[87] == 1){
            t[87]=1;
          } else {
            t[87]=0;
          }
        } else if (sourceID == 89){
          Serial.print("Data 89: ");
          Serial.println(receivedNumber);  
           t[88]=receivedNumber;
          if (t[88] == 1){
            t[88]=1;
          } else {
            t[88]=0;
          }
        } else if (sourceID == 90) {
          Serial.print("Data 90: ");
          Serial.println(receivedNumber);
           t[89]=receivedNumber;
          if (t[89] == 1){
            t[89]=1;
          } else {
            t[89]=0;
          }
        } else if (sourceID == 91) {
          Serial.print("Data 91: ");
          Serial.println(receivedNumber);        
          t[90]=receivedNumber;
          if (t[90] == 1){
            t[90]=1;
          } else {
            t[90]=0;
          }
        } else if (sourceID == 92) {
          Serial.print("Data 92: ");
          Serial.println(receivedNumber);
           t[91]=receivedNumber;
          if (t[91] == 1){
            t[91]=1;
          } else {
            t[91]=0;
          }
        } else if (sourceID == 93) {
          Serial.print("Data 93: ");
          Serial.println(receivedNumber);  
           t[92]=receivedNumber;
          if (t[92] == 1){
            t[92]=1;
          } else {
            t[92]=0;
          }
        } else if (sourceID == 94) {
          Serial.print("Data 94: ");
          Serial.println(receivedNumber);
           t[93]=receivedNumber;
          if (t[93] == 1){
            t[93]=1;
          } else {
            t[93]=0;
          }
        } else if (sourceID == 95) {
          Serial.print("Data 95: ");
          Serial.println(receivedNumber);  
           t[94]=receivedNumber;
          if (t[94] == 1){
            t[94]=1;
          } else {
            t[94]=0;
          }
        } else if (sourceID == 96) {
          Serial.print("Data 96: ");
          Serial.println(receivedNumber);
           t[95]=receivedNumber;
          if (t[95] == 1){
            t[95]=1;
          } else {
            t[95]=0;
          }
        } else if (sourceID == 97) {
          Serial.print("Data 97: ");
          Serial.println(receivedNumber);  
           t[96]=receivedNumber;
          if (t[96] == 1){
            t[96]=1;
          } else {
            t[96]=0;
          }
        } else if (sourceID == 98) {
          Serial.print("Data 98: ");
          Serial.println(receivedNumber);
           t[97]=receivedNumber;
          if (t[97] == 1){
            t[97]=1;
          } else {
            t[97]=0;
          }
        } else if (sourceID == 99){
          Serial.print("Data 99: ");
          Serial.println(receivedNumber);  
           t[98]=receivedNumber;
          if (t[98] == 1){
            t[98]=1;
          } else {
            t[98]=0;
          }
        } else if (sourceID == 100) {
          Serial.print("Data 100: ");
          Serial.println(receivedNumber);
           t[99]=receivedNumber;
          if (t[99] == 1){
            t[99]=1;
          } else {
            t[99]=0;
          }
        } else if (sourceID == 101) {
          Serial.print("Data 1: ");
          Serial.println(receivedNumber);        
          t[100]=receivedNumber;
          if (t[100] == 1){
            t[100]=1;
          } else {
            t[100]=0;
          }
        } else if (sourceID == 102) {
          Serial.print("Data 102: ");
          Serial.println(receivedNumber);
           t[101]=receivedNumber;
          if (t[1] == 1){
            t[101]=1;
          } else {
            t[101]=0;
          }
        } else if (sourceID == 103) {
          Serial.print("Data 103: ");
          Serial.println(receivedNumber);  
           t[102]=receivedNumber;
          if (t[102] == 1){
            t[102]=1;
          } else {
            t[102]=0;
          }
        } else if (sourceID == 104) {
          Serial.print("Data 104: ");
          Serial.println(receivedNumber);
           t[103]=receivedNumber;
          if (t[103] == 1){
            t[103]=1;
          } else {
            t[103]=0;
          }
        } else if (sourceID == 105) {
          Serial.print("Data 105: ");
          Serial.println(receivedNumber);  
           t[104]=receivedNumber;
          if (t[104] == 1){
            t[104]=1;
          } else {
            t[104]=0;
          }
        } else if (sourceID == 106) {
          Serial.print("Data 106: ");
          Serial.println(receivedNumber);
           t[105]=receivedNumber;
          if (t[105] == 1){
            t[105]=1;
          } else {
            t[105]=0;
          }
        } else if (sourceID == 107) {
          Serial.print("Data 107: ");
          Serial.println(receivedNumber);  
           t[106]=receivedNumber;
          if (t[106] == 1){
            t[106]=1;
          } else {
            t[106]=0;
          }
        } else if (sourceID == 108) {
          Serial.print("Data 108: ");
          Serial.println(receivedNumber);
           t[107]=receivedNumber;
          if (t[107] == 1){
            t[107]=1;
          } else {
            t[107]=0;
          }
        } else if (sourceID == 109){
          Serial.print("Data 109: ");
          Serial.println(receivedNumber);  
           t[108]=receivedNumber;
          if (t[108] == 1){
            t[108]=1;
          } else {
            t[108]=0;
          }
        } else if (sourceID == 110) {
          Serial.print("Data 110: ");
          Serial.println(receivedNumber);
           t[109]=receivedNumber;
          if (t[109] == 1){
            t[109]=1;
          } else {
            t[109]=0;
          }
        } else if (sourceID == 111) {
          Serial.print("Data 111: ");
          Serial.println(receivedNumber);  
           t[110]=receivedNumber;
          if (t[110] == 1){
            t[110]=1;
          } else {
            t[110]=0;
          }
        } else if (sourceID == 112) {
          Serial.print("Data 112: ");
          Serial.println(receivedNumber);
           t[111]=receivedNumber;
          if (t[111] == 1){
            t[111]=1;
          } else {
            t[111]=0;
          }
        } else if (sourceID == 113) {
          Serial.print("Data 113: ");
          Serial.println(receivedNumber);  
           t[112]=receivedNumber;
          if (t[112] == 1){
            t[112]=1;
          } else {
            t[112]=0;
          }
        } else if (sourceID == 114) {
          Serial.print("Data 114: ");
          Serial.println(receivedNumber);
           t[113]=receivedNumber;
          if (t[113] == 1){
            t[113]=1;
          } else {
            t[113]=0;
          }
        } else if (sourceID == 115) {
          Serial.print("Data 115: ");
          Serial.println(receivedNumber);
           t[114]=receivedNumber;
          if (t[114] == 1){
            t[114]=1;
          } else {
            t[114]=0;
          }
        } else if (sourceID == 116) {
          Serial.print("Data 116: ");
          Serial.println(receivedNumber);
           t[115]=receivedNumber;
          if (t[115] == 1){
            t[115]=1;
          } else {
            t[115]=0;
          }
        } else {
          Serial.print("Unknown source data: ");
        }
      }

      for (a=0; a<3; a++){
        tray1=tray1<<1;
        tray1=tray1|t[a];
      }
      for (a=3; a<14; a++){
        tray2=tray2<<1;
        tray2=tray2|t[a];
      }
      
        Serial.print("Tray 1: ");
        Serial.println(tray1);
        Serial.print("Tray 2: ");
        Serial.println(tray2);

    } else if(x == 1){
        return;
      }

}

void openDrawer() {
  Serial.println("Laci terbuka");
  mfrc522.PICC_HaltA();
  delay(1000);
}


void InitWiFi()
{


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // Serial.println("Connecting to AP ...");
  // // attempt to connect to WiFi fnetwork

  // WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // Serial.println("Connected to AP");
}
