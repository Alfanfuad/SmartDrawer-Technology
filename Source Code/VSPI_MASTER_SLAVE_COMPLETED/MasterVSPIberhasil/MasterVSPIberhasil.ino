#include <SPI.h>

// Define ALTERNATE_PINS to use non-standard GPIO pins for SPI bus

  #define VSPI_MISO   23
  #define VSPI_MOSI   19
  #define VSPI_SCLK   18
  #define VSPI_SS     5


static const int spiClk = 1000000; // 1 MHz

//uninitalised pointers to SPI objects
SPIClass * vspi = NULL;

void setup() {
  //initialise instance of the SPIClass attached to HSPI
  vspi = new SPIClass(VSPI);
  

  //alternatively route through GPIO pins
  vspi->begin(); //SCLK, MISO, MOSI, SS


  //set up slave select pins as outputs as the Arduino API
  //doesn't handle automatically pulling SS low
  pinMode(VSPI_SS, OUTPUT); //HSPI SS
}

// the loop function runs over and over again until power down or reset
void loop() {
  vspi_send_command();
  delay(100);
}

void vspi_send_command() {
  byte data_on = 0b00000001; // data 1 to turn on LED of slave
  byte data_off = 0b0000000; // data 0 to turn off LED of slave
  
  vspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(VSPI_SS, LOW);
  vspi->transfer(data_on);
  digitalWrite(VSPI_SS, HIGH);
  vspi->endTransaction();

  delay(1000);
  
  vspi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(VSPI_SS, LOW);
  vspi->transfer(data_off);
  digitalWrite(VSPI_SS, HIGH);
  vspi->endTransaction();
  delay(1000);

}