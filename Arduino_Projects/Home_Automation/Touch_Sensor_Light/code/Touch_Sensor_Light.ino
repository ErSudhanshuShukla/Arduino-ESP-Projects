/*
====================================================
 Title   : Touch Sensor Light
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int touchPin = 2;   // Touch sensor digital output pin
int relayPin = 8;   // Relay control input pin

int lastTouch = LOW;   // Stores previous touch state
int relayState = LOW;  // Stores current relay state

void setup() {
  pinMode(touchPin, INPUT);     // Configure touch sensor pin as input
  pinMode(relayPin, OUTPUT);    // Configure relay pin as output
  digitalWrite(relayPin, HIGH); // Relay OFF at start (active LOW relay)
}

void loop() {
  int t = digitalRead(touchPin);  // Read touch sensor state

  // Detect rising edge (new touch event)
  if (t == HIGH && lastTouch == LOW) {
    relayState = !relayState;     // Toggle relay state

    // Reverse logic for active LOW relay: LOW = ON, HIGH = OFF
    if (relayState == HIGH) {
      digitalWrite(relayPin, LOW);   // Turn light ON
    } else {
      digitalWrite(relayPin, HIGH);  // Turn light OFF
    }

    delay(200);  // Simple debounce to avoid multiple toggles
  }

  lastTouch = t;  // Update last touch state
}
