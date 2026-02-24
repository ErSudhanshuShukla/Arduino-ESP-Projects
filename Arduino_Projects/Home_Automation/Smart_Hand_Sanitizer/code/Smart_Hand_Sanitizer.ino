/*
====================================================
 Title   : Smart Hand Sanitizer
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Pin definitions
int IR_PIN = 9;        // IR sensor digital output pin
int RELAY_PIN = 8;     // Relay control pin (connected to pump)

void setup() {
  pinMode(IR_PIN, INPUT);       // Configure IR sensor as input
  pinMode(RELAY_PIN, OUTPUT);   // Configure relay as output

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF initially (active LOW relay)

  Serial.begin(9600);           // Start serial communication for debugging
  Serial.println("Smart Hand Sanitizer Ready");
}

void loop() {
  int sensorValue = digitalRead(IR_PIN);  // Read IR sensor state

  // IR sensor outputs LOW when a hand is detected
  if (sensorValue == LOW) {
    digitalWrite(RELAY_PIN, LOW);   // Turn pump ON
    Serial.println("Hand detected - Pump ON");

    delay(1500);                    // Run pump for 1.5 seconds

    digitalWrite(RELAY_PIN, HIGH);  // Turn pump OFF
    Serial.println("Pump OFF");

    delay(1000);                    // Small delay to avoid repeated triggering
  }
}
