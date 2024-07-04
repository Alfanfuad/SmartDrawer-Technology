#include <Wire.h>

uint8_t receivedNumber = 0;

void setup() {
 
  Wire.begin(8); // Inisialisasi I2C komunikasi dan tentukan alamat slave (alamat 8 pada contoh ini)
  Wire.onReceive(receiveEvent); // Atur fungsi yang akan dipanggil saat menerima data
  Serial.begin(115200);
}

void loop() {
  // Tidak ada yang perlu dilakukan di loop slave
}

// Fungsi ini akan dipanggil saat master mengirimkan data
void receiveEvent(int numBytes) {
if (numBytes <= sizeof(int)) {
    byte sourceID = Wire.read(); // Baca byte pertama untuk mengetahui sumber data (Master 1 atau Master 2)
    Wire.readBytes((uint8_t*)&receivedNumber, sizeof(receivedNumber)); // Baca byte array dan ubah menjadi angka integer
    
    if (sourceID == 1) {
      Serial.print("Data from Master 1: ");
    } else if (sourceID == 2) {
      Serial.print("Data from Master 2: ");
    } else if (sourceID == 3) {
      Serial.print("Data from Master 3: ");
    } else if (sourceID == 4) {
      Serial.print("Data from Master 4: ");
    } else if (sourceID == 5) {
      Serial.print("Data from Master 5: ");
    } else if (sourceID == 6) {
      Serial.print("Data from Master 6: ");
    } else if (sourceID == 7) {
      Serial.print("Data from Master 7: ");
    } else if (sourceID == 8) {
      Serial.print("Data from Master 8: ");
    } else if (sourceID == 9) {
      Serial.print("Data from Master 9: ");
    } else if (sourceID == 10) {
      Serial.print("Data from Master 10: ");
    } else if (sourceID == 11) {
      Serial.print("Data from Master 11: ");
    } else if (sourceID == 12) {
      Serial.print("Data from Master 12: ");
    } else if (sourceID == 13) {
      Serial.print("Data from Master 13: ");
    } else if (sourceID == 14) {
      Serial.print("Data from Master 14: ");
    } else if (sourceID == 15) {
      Serial.print("Data from Master 15: ");
    } else if (sourceID == 16) {
      Serial.print("Data from Master 16: ");
    } else if (sourceID == 17) {
      Serial.print("Data from Master 17: ");
    } else if (sourceID == 18) {
      Serial.print("Data from Master 18: ");
    } else if (sourceID == 19) {
      Serial.print("Data from Master 19: ");
    } else if (sourceID == 20) {
      Serial.print("Data from Master 20: ");
    } else if (sourceID == 21) {
      Serial.print("Data from Master 21: ");
    } else if (sourceID == 22) {
      Serial.print("Data from Master 22: ");
    } else if (sourceID == 23) {
      Serial.print("Data from Master 23: ");
    } else if (sourceID == 24) {
      Serial.print("Data from Master 24: ");
    } else if (sourceID == 25) {
      Serial.print("Data from Master 25: ");
    } else if (sourceID == 26) {
      Serial.print("Data from Master 26: ");
    } else if (sourceID == 27) {
      Serial.print("Data from Master 27: ");
    } else if (sourceID == 28) {
      Serial.print("Data from Master 28: ");
    } else if (sourceID == 29) {
      Serial.print("Data from Master 29: ");
    } else if (sourceID == 30) {
      Serial.print("Data from Master 30: ");
    } else if (sourceID == 31) {
      Serial.print("Data from Master 31: ");
    } else if (sourceID == 32) {
      Serial.print("Data from Master 32: ");
    } else if (sourceID == 33) {
      Serial.print("Data from Master 33: ");
    } else if (sourceID == 34) {
      Serial.print("Data from Master 34: ");
    } else if (sourceID == 35) {
      Serial.print("Data from Master 35: ");
    } else if (sourceID == 36) {
      Serial.print("Data from Master 36: ");
    } else if (sourceID == 37) {
      Serial.print("Data from Master 37: ");
    } else if (sourceID == 38) {
      Serial.print("Data from Master 38: ");
    } else if (sourceID == 39) {
      Serial.print("Data from Master 39: ");
    } else if (sourceID == 40) {
      Serial.print("Data from Master 40: ");
    } else if (sourceID == 41) {
      Serial.print("Data from Master 41: ");
    } else if (sourceID == 42) {
      Serial.print("Data from Master 42: ");
    } else if (sourceID == 43) {
      Serial.print("Data from Master 43: ");
    } else if (sourceID == 44) {
      Serial.print("Data from Master 44: ");
    } else if (sourceID == 45) {
      Serial.print("Data from Master 45: ");
    } else if (sourceID == 46) {
      Serial.print("Data from Master 46: ");
    } else if (sourceID == 47) {
      Serial.print("Data from Master 47: ");
    } else if (sourceID == 48) {
      Serial.print("Data from Master 48: ");
    } else if (sourceID == 49) {
      Serial.print("Data from Master 49: ");
    } else if (sourceID == 50) {
      Serial.print("Data from Master 50: ");
    } else if (sourceID == 51) {
      Serial.print("Data from Master 51: ");
    } else if (sourceID == 52) {
      Serial.print("Data from Master 52: ");
    } else if (sourceID == 53) {
      Serial.print("Data from Master 53: ");
    } else if (sourceID == 54) {
      Serial.print("Data from Master 54: ");
    } else if (sourceID == 55) {
      Serial.print("Data from Master 55: ");
    } else if (sourceID == 56) {
      Serial.print("Data from Master 56: ");
    } else if (sourceID == 57) {
      Serial.print("Data from Master 57: ");
    } else if (sourceID == 58) {
      Serial.print("Data from Master 58: ");
    } else if (sourceID == 59) {
      Serial.print("Data from Master 59: ");
    } else if (sourceID == 60) {
      Serial.print("Data from Master 60: ");
    } else if (sourceID == 61) {
      Serial.print("Data from Master 61: ");
    } else if (sourceID == 62) {
      Serial.print("Data from Master 62: ");
    } else if (sourceID == 63) {
      Serial.print("Data from Master 63: ");
    } else if (sourceID == 64) {
      Serial.print("Data from Master 64: ");
    } else if (sourceID == 65) {
      Serial.print("Data from Master 65: ");
    } else if (sourceID == 66) {
      Serial.print("Data from Master 66: ");
    } else if (sourceID == 67) {
      Serial.print("Data from Master 67: ");
    } else if (sourceID == 68) {
      Serial.print("Data from Master 68: ");
    } else if (sourceID == 69) {
      Serial.print("Data from Master 69: ");
    } else if (sourceID == 70) {
      Serial.print("Data from Master 70: ");
    } else if (sourceID == 71) {
      Serial.print("Data from Master 71: ");
    } else if (sourceID == 72) {
      Serial.print("Data from Master 72: ");
    } else if (sourceID == 73) {
      Serial.print("Data from Master 73: ");
    } else if (sourceID == 74) {
      Serial.print("Data from Master 74: ");
    } else if (sourceID == 75) {
      Serial.print("Data from Master 75: ");
    } else if (sourceID == 76) {
      Serial.print("Data from Master 76: ");
    } else if (sourceID == 77) {
      Serial.print("Data from Master 77: ");
    } else if (sourceID == 78) {
      Serial.print("Data from Master 78: ");
    } else if (sourceID == 79) {
      Serial.print("Data from Master 79: ");
    } else if (sourceID == 80) {
      Serial.print("Data from Master 80: ");
    } else if (sourceID == 81) {
      Serial.print("Data from Master 81: ");
    } else if (sourceID == 82) {
      Serial.print("Data from Master 82: ");
    } else if (sourceID == 83) {
      Serial.print("Data from Master 83: ");
    } else if (sourceID == 84) {
      Serial.print("Data from Master 84: ");
    } else if (sourceID == 85) {
      Serial.print("Data from Master 85: ");
    } else if (sourceID == 86) {
      Serial.print("Data from Master 86: ");
    } else if (sourceID == 87) {
      Serial.print("Data from Master 87: ");
    } else if (sourceID == 88) {
      Serial.print("Data from Master 88: ");
    } else if (sourceID == 89) {
      Serial.print("Data from Master 89: ");
    } else if (sourceID == 90) {
      Serial.print("Data from Master 90: ");
    } else if (sourceID == 91) {
      Serial.print("Data from Master 91: ");
    } else if (sourceID == 92) {
      Serial.print("Data from Master 92: ");
    } else if (sourceID == 93) {
      Serial.print("Data from Master 93: ");
    } else if (sourceID == 94) {
      Serial.print("Data from Master 94: ");
    } else if (sourceID == 95) {
      Serial.print("Data from Master 95: ");
    } else if (sourceID == 96) {
      Serial.print("Data from Master 96: ");
    } else if (sourceID == 97) {
      Serial.print("Data from Master 97: ");
    } else if (sourceID == 98) {
      Serial.print("Data from Master 98: ");
    } else if (sourceID == 99) {
      Serial.print("Data from Master 99: ");
    } else if (sourceID == 100) {
      Serial.print("Data from Master 100: ");
    } else if (sourceID == 101) {
      Serial.print("Data from Master 101: ");
    } else if (sourceID == 102) {
      Serial.print("Data from Master 102: ");
    } else if (sourceID == 103) {
      Serial.print("Data from Master 103: ");
    } else if (sourceID == 104) {
      Serial.print("Data from Master 104: ");
    } else if (sourceID == 105) {
      Serial.print("Data from Master 105: ");
    } else if (sourceID == 106) {
      Serial.print("Data from Master 106: ");
    } else if (sourceID == 107) {
      Serial.print("Data from Master 107: ");
    } else if (sourceID == 108) {
      Serial.print("Data from Master 108: ");
    } else if (sourceID == 109) {
      Serial.print("Data from Master 109: ");
    } else if (sourceID == 110) {
      Serial.print("Data from Master 110: ");
    } else if (sourceID == 111) {
      Serial.print("Data from Master 111: ");
    } else if (sourceID == 112) {
      Serial.print("Data from Master 112: ");
    } else if (sourceID == 113) {
      Serial.print("Data from Master 113: ");
    } else if (sourceID == 114) {
      Serial.print("Data from Master 114: ");
    } else if (sourceID == 115) {
      Serial.print("Data from Master 115: ");
    } else if (sourceID == 116) {
      Serial.print("Data from Master 116: ");
    } else {
      Serial.print("Unknown source data: ");
    }
    
    Serial.println(receivedNumber);
  }
}
