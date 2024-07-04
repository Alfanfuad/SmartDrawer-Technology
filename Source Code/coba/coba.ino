#include <ESP8266HTTPClient.h>

#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2);
// #define WIFI_AP             "modaldong"
// #define WIFI_PASSWORD       "mbulmbul"

//Konfigurasi WiFi
const char *ssid = "vivo 1820";
const char *password = "123456780";

//IP Address Server yang terpasang XAMPP
const char *host = "192.168.43.236";

#define s0 D3
#define s1 D4
#define s2 D5
#define led D0

// the Wifi radio's status
--int status1 = WL_IDLE_STATUS;
Servo myservo;
String t0,t1,t2,t3,t4,t5,ID_Number,nopeg,nopeg1,tools,tools1,miss;
int i,status,data,cek,tool[5];
int hammer;
int wrench;
int punch;
int combwrench;
int ratchet;
int batas = 900;
void setup() {
  Serial.begin(9600);
  
  // initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
  t1 = "Wrench";
  t2 = "CombWrench";
  t3 = "Ratchet";
  t4 = "Punch";
  t5 = "Hammer";
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(led, OUTPUT);
  status = 0;
  myservo.attach(D6);
  InitWiFi();
  baca_sensor();
  cek_drawer();
  myservo.write(0);
}

void loop() {
  // if (WiFi.status() != WL_CONNECTED) {
  //   reconnect();
  // }
  
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  if (status == 0){
    lcd.clear();
    lcd.print("Drawer 01");
    if (cek == 1){
    lcd.setCursor(0,1);
    lcd.print("Tools Complete");
    }
    else {
       for (i=0; i<5; i++){
        if (tool[i]==0){
          switch (i){
        case 0:
        lcd.clear();
        lcd.print("Drawer 01 Miss:");
        lcd.setCursor(0,1);
        lcd.print(t1);
        delay(750);
        break;
        case 1:
        lcd.clear();
        lcd.print("Drawer 01 Miss:");
        lcd.setCursor(0,1);
        lcd.print(t2);
        delay(750);
        break;
        case 2:
        lcd.clear();
        lcd.print("Drawer 01 Miss:");
        lcd.setCursor(0,1);
        lcd.print(t3);
        delay(750);        
        break;
        case 3:
        lcd.clear();
        lcd.print("Drawer 01 Miss:");
        lcd.setCursor(0,1);
        lcd.print(t4);
        delay(750);
        break;
        case 4:
        lcd.clear();
        lcd.print("Drawer 01 Miss:");
        lcd.setCursor(0,1);
        lcd.print(t5);
        delay(750);
        break;
      }
      }
      }
    }
  }
  else {
    lcd.clear();
    lcd.print("Welcome ");
    lcd.print(ID_Number);
    lcd.setCursor(14,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("Take Your Tools");
    }
  delay(100);
     if (Serial.available()) {
        if (Serial.read()=='5'){ID_Number=+"5";
        ID_Number+=Serial.readString();
          if (status ==0){
            myservo.attach(D6);
        lcd.clear();
        lcd.print("Welcome ");
        lcd.print(ID_Number);
        lcd.setCursor(14,0);
        lcd.print(" ");
        lcd.setCursor(0,1);
        lcd.print("Drawer Unlocked");
        baca_sensor();
        cek_drawer();
        myservo.write(135);
        delay(1000);
        myservo.detach();
        status = 1;
        }
        else if (status == 1){
          myservo.attach(D6);
          lcd.clear();
          lcd.print("Pastikan Tray");
          lcd.setCursor(0,1);
          lcd.print("Tertutup!");
          myservo.write(0);
          delay(1000);
          myservo.detach();
          cek_tutup();
          cek_drawer();
          lcd.clear();
          lcd.print("Drawer Locked");
          status=0;
          delay(500);
          }}
        else {
        lcd.clear();
        lcd.print("ID not Valid");
        Serial.println("ID not Valid");
        delay(100);
        Serial.end();
        delay(1500);
        Serial.begin(9600);}
        }
  
      String url = "/sdtech/user/write-data.php?";
      url = url + "nopeg=" + ID_Number.toInt() + "&wrench=" + wrench + "&combwrench=" + combwrench + "&ratchet=" + ratchet + "&punch="+ punch + "&hammer=" + hammer;
 
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
nopeg="0";
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

// void reconnect() {
//   // Loop until we're reconnected
//   status = WiFi.status();
//   if ( status != WL_CONNECTED) {
//     WiFi.begin(WIFI_AP, WIFI_PASSWORD);
//     while (WiFi.status() != WL_CONNECTED) {
//       delay(500);
//       Serial.print(".");
//     }
//     Serial.println("Connected to AP");
//   }
// }

void baca_sensor(){
  digitalWrite(led, HIGH); //bagian yang diambil nyala sisanya mati 
  delay(1000);
  digitalWrite(s0, LOW); 
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0); 
  Serial.print("adc2= ");
  Serial.println(data);
  if (data < batas){
    tool[1] = 0;
    combwrench= 0;
    }
    else {
      tool[1] = 1;
      combwrench= 1;
      }
  delay(10);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  Serial.print("adc5= ");
  Serial.println(data);
    if (data < batas){
    tool[4] = 0;
    hammer=0;
    }
    else {
    tool[4] = 1;
    hammer= 1;
    }
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  Serial.print("adc3= ");
  Serial.println(data);
    if (data < batas){
    tool[2] = 0;
    ratchet= 0;
    }
    else {tool[2] = 1;
    ratchet= 1;
    }
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  Serial.print("adc1= ");
  Serial.println(data);
    if (data < batas){
    tool[0] = 0;
    wrench= 0;
    }
    else {tool[0] = 1;
    wrench= 1;
    }
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  delay(10);
  data = analogRead(A0);
  Serial.print("adc4= ");
  Serial.println(data);
    if (data < batas){
    tool[3] = 0;
    punch= 0;
    }
    else {tool[3] = 1;
    punch= 1;}
    delay(100);
    digitalWrite(led, LOW);
  delay(500);
}

void cek_tutup(){
  digitalWrite(led, HIGH);
  delay(1000);
  //C0
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
    if (data < batas && tool[1] == 1){
    tool[1]=0;
    combwrench=0;
    tools += t2;
    lcd.clear();
    lcd.print("Pinjam: ");
    lcd.setCursor(0,1);
    lcd.print(t2);
    }
    else if (data > batas && tool[1] == 0){
      tool[1]=1;
      combwrench=1;
      tools1 += t2;
      lcd.clear();
      lcd.print("Kembali: ");
      lcd.setCursor(0,1);
      lcd.print(t2);
      }
  delay(500);
  //C1
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  if (data < batas && tool[4] == 1){
    tool[4]=0;
    hammer=0;
    tools += t5;
    lcd.clear();
    lcd.print("Pinjam: ");
    lcd.setCursor(0,1);
    lcd.print(t5);
    }
    else if (data > batas && tool[4] == 0){
      tool[4]=1;
      hammer=1;
      tools1 += t5;
      lcd.clear();
      lcd.print("Kembali: ");
      lcd.setCursor(0,1);
      lcd.print(t5);
    }
  delay(500);
  //C2
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  if (data < batas && tool[2] == 1){
    tool[2]=0;
    ratchet=0;
    tools += t3;
    lcd.clear();
    lcd.print("Pinjam: ");
    lcd.setCursor(0,1);
    lcd.print(t3);
    }
    else if (data > batas && tool[2] == 0){
      tool[2]=1;
      ratchet=1;
      tools1 += t3;
    lcd.clear();
      lcd.print("Kembali: ");
      lcd.setCursor(0,1);
      lcd.print(t3);
    }
  delay(500);
  //C3
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  delay(10);
  data = analogRead(A0);
  if (data < batas && tool[0] == 1){
    tool[0]=0;
    wrench=0;
    tools += t1;
    lcd.clear();
    lcd.print("Pinjam: ");
    lcd.setCursor(0,1);
    lcd.print(t1);
    }
    else if (data > batas && tool[0] == 0){
      tool[0]=1;
      wrench=1;
      tools1 += t1;
    lcd.clear();
      lcd.print("Kembali: ");
      lcd.setCursor(0,1);
      lcd.print(t1);
    }
  delay(500);
  //C4
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  delay(10);
  data = analogRead(A0);
  if (data < batas && tool[3] == 1){
    tool[3]=0;
    punch=0;
    tools += t4;
    lcd.clear();
    lcd.print("Pinjam: ");
    lcd.setCursor(0,1);
    lcd.print(t4);
    }
    else if (data > batas && tool[3] == 0){
      tool[3]=1;
      punch=1;
      tools1 += t4;
    lcd.clear();
      lcd.print("Kembali: ");
      lcd.setCursor(0,1);
      lcd.print(t4);
    }
    delay(500);
    digitalWrite(led, LOW);
  }

void cek_drawer(){
  cek=1;
  for (i=0; i<5; i++){
    cek &= tool[i];
    if (tool[i] == 0){
      switch (i){
        case 0:
        lcd.clear();
        lcd.print("Missing Tool");
        lcd.setCursor(0,1);
        lcd.print(t1);
        delay(500);
        break;
        case 1:
        lcd.clear();
        lcd.print("Missing Tool");
        lcd.setCursor(0,1);
        lcd.print(t2);
        delay(500);
        break;
        case 2:
        lcd.clear();
        lcd.print("Missing Tool");
        lcd.setCursor(0,1);
        lcd.print(t3);
        delay(500);        
        break;
        case 3:
        lcd.clear();
        lcd.print("Missing Tool");
        lcd.setCursor(0,1);
        lcd.print(t4);
        delay(500);
        break;
        case 4:
        lcd.clear();
        lcd.print("Missing Tool");
        lcd.setCursor(0,1);
        lcd.print(t5);
        delay(500);
        break;
      }
      }
      }
  if (cek == 1){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Tools Complete");
    delay(100);
  }
}

