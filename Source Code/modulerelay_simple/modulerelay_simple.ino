const int relayPin = 14; // Pin connected to relay module

void setup() {
  pinMode(relayPin, OUTPUT); // Set relayPin as an output
}

void loop() {
  digitalWrite(relayPin, HIGH); // Turn the relay on (HIGH)
  delay(1000); // Wait for 1 second
  digitalWrite(relayPin, LOW); // Turn the relay off (LOW)
  delay(1000); // Wait for 1 second
}
