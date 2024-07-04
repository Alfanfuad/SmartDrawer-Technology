#include <ESP32SPISlave.h>


ESP32SPISlave slave;

static constexpr uint32_t BUFFER_SIZE {32};
uint8_t spi_slave_tx_buf[BUFFER_SIZE];
uint8_t spi_slave_rx_buf[BUFFER_SIZE];

#define LED 2

void setup() {
    Serial.begin(115200);
    delay(2000);
    pinMode(LED, OUTPUT);
    // begin() after setting
    // HSPI = CS: 15, CLK: 14, MOSI: 13, MISO: 12 -> default
    // VSPI = CS:  5, CLK: 18, MOSI: 23, MISO: 19
    slave.setDataMode(SPI_MODE0);
    slave.begin();
    // slave.begin(VSPI);   // you can use VSPI like this

    // clear buffers
    memset(spi_slave_tx_buf, 0, BUFFER_SIZE);
    memset(spi_slave_rx_buf, 0, BUFFER_SIZE);
}

void loop() {
    // block until the transaction comes from master
    slave.wait(spi_slave_rx_buf, spi_slave_tx_buf, BUFFER_SIZE);

    // if transaction has completed from master,
    // available() returns size of results of transaction,
    // and buffer is automatically updated
    byte command = spi_slave_rx_buf[0];
    if (command == 0b00000001) {
        // LED ON
        digitalWrite(LED, HIGH);
        Serial.println("Setting LED active HIGH");
    } else if (command == 0b00000000) {
        // LED OFF
        digitalWrite(LED, LOW);
        Serial.println("Setting LED active LOW");
    }

    // LDR value received
    byte ldrValue1 = spi_slave_rx_buf[1];
    int ldrReadValue1 = map(ldrValue1, 0, 255, 0, 4095);
    Serial.print("Received LDR 1 value: ");
    Serial.println(ldrReadValue1);
    
    byte ldrValue2 = spi_slave_rx_buf[2];
    int ldrReadValue2 = map(ldrValue2, 0, 255, 0, 4095);
    Serial.print("Received LDR 2 value: ");
    Serial.println(ldrReadValue2);

    byte ldrValue3 = spi_slave_rx_buf[3];
    int ldrReadValue3 = map(ldrValue3, 0, 255, 0, 4095);
    Serial.print("Received LDR 3 value: ");
    Serial.println(ldrReadValue3);

    // Acknowledge to the master that the data has been received
    spi_slave_tx_buf[0] = 0b00000010; // Send an acknowledgment byte (e.g., 0b00000010)

}