/**************************************************
 *  Title   : Home Automation (Bluetooth)
 *  Author  : Sudhanshu Shukla
 *  GitHub  : https://github.com/ErSudhanshuShukla
 *  License : Released under MIT License
 **************************************************/

int relay = 8;           // Relay control pin connected to Arduino pin 8
bool activeLow = true;  // Set true if relay module is Active LOW, false if Active HIGH

void setup() {
  Serial.begin(9600);   // Start serial communication (same baud rate as HC-05 Bluetooth module)

  pinMode(relay, OUTPUT);  // Set relay pin as output

  // Turn relay OFF at startup (safety: device remains OFF when Arduino powers on)
  digitalWrite(relay, activeLow ? HIGH : LOW);

  Serial.println("Bluetooth Home Automation Ready"); // Status message
}

void loop() {
  // Check if any data is received from Bluetooth (via Serial)
  if (Serial.available()) {
    char c = Serial.read();    // Read one character sent from Bluetooth app
    Serial.print("Received: ");
    Serial.println(c);        // Print received command on Serial Monitor

    // If '1' is received, turn relay ON
    if (c == '1') {
      digitalWrite(relay, activeLow ? LOW : HIGH);  // Relay ON (depends on relay type)
      Serial.println("RELAY ON");                   // Debug message
    }
    // If '0' is received, turn relay OFF
    else if (c == '0') {
      digitalWrite(relay, activeLow ? HIGH : LOW);  // Relay OFF (depends on relay type)
      Serial.println("RELAY OFF");                  // Debug message
    }
  }
}