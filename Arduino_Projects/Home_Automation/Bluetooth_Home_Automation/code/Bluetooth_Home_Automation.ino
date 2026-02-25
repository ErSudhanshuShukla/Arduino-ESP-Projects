/**************************************************
 *  Title   : Home Automation (Bluetooth)
 *  Author  : Sudhanshu Shukla
 *  GitHub  : https://github.com/ErSudhanshuShukla
 *  License : Released under MIT License
 **************************************************/

#include <SoftwareSerial.h>

// HC-05 Bluetooth on SoftwareSerial
#define BT_RX 2   // Arduino RX  <- HC-05 TX
#define BT_TX 3   // Arduino TX  -> HC-05 RX (use voltage divider)

SoftwareSerial btSerial(BT_RX, BT_TX);  // RX, TX

int relay = 8;            // Relay control pin
bool activeLow = true;   // true = Active LOW relay, false = Active HIGH

void setup() {
  Serial.begin(9600);     // Serial Monitor (debug)
  btSerial.begin(9600);  // HC-05 default baud rate

  pinMode(relay, OUTPUT);

  // Turn relay OFF at startup (safety)
  digitalWrite(relay, activeLow ? HIGH : LOW);

  Serial.println("Bluetooth Home Automation Ready");
  btSerial.println("Device Connected. Send 1 = ON, 0 = OFF");
}

void loop() {
  // Check if any data is received from Bluetooth
  if (btSerial.available()) {
    char c = btSerial.read();   // Read command
    Serial.print("Received: ");
    Serial.println(c);

    // If '1' is received, turn relay ON
    if (c == '1') {
      digitalWrite(relay, activeLow ? LOW : HIGH);  // Relay ON
      Serial.println("RELAY ON");
      btSerial.println("RELAY ON");
    }
    // If '0' is received, turn relay OFF
    else if (c == '0') {
      digitalWrite(relay, activeLow ? HIGH : LOW);  // Relay OFF
      Serial.println("RELAY OFF");
      btSerial.println("RELAY OFF");
    }

    delay(200);  // Small delay to avoid rapid toggling
  }
}
