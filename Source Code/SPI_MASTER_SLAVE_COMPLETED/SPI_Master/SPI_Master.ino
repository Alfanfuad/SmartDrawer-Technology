#include <SPI.h>

  #define HSPI_MISO   12
  #define HSPI_MOSI   13
  #define HSPI_SCLK   14
  #define HSPI_SS     15
  #define LDR1PIN     26
  #define LDR2PIN     27
  #define LDR3PIN     25

static const int spiClk = 1000000; // 1 MHz
SPIClass * hspi = NULL;

void setup() {
  Serial.begin(115200);
  hspi = new SPIClass(HSPI);
  hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);
  pinMode(HSPI_SS, OUTPUT); //HSPI SS
}

void loop() {
  hspi_send_command();
  delay(100);
}

void hspi_send_command() {
  byte data_on = 0b00000001; // data 1 to turn on LED of slave
  byte data_off = 0b0000000; // data 0 to turn off LED of slave
  int ldrvalue1 = analogRead(LDR1PIN);
  int ldrvalue2 = analogRead(LDR2PIN);
  int ldrvalue3 = analogRead(LDR3PIN);
  byte ldrByte1 = map(ldrvalue1, 0, 4095, 0, 255); //map the analog value to a byte value (0-255)
  byte ldrByte2 = map(ldrvalue2, 0, 4095, 0, 255);
  byte ldrByte3 = map(ldrvalue3, 0, 4095, 0, 255);

  Serial.print("this value byte LDR1: ");
  Serial.println(ldrvalue1);
  Serial.print("this value byte LDR2: ");
  Serial.println(ldrvalue2);
  Serial.print("this value byte LDR3: ");
  Serial.println(ldrvalue3);

  hspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(HSPI_SS, LOW);
  hspi->transfer(data_on);
  hspi->transfer(ldrByte1);
  hspi->transfer(ldrByte2);
  hspi->transfer(ldrByte3);
  digitalWrite(HSPI_SS, HIGH);
  hspi->endTransaction();
  delay(1000);
  
  hspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(HSPI_SS, LOW);
  hspi->transfer(data_off);
  digitalWrite(HSPI_SS, HIGH);
  hspi->endTransaction();
  delay(1000);

}