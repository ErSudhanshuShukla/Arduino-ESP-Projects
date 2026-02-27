/*
====================================================
 Title   : Smart Fire Extinguisher
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int flame = 9;    // Flame sensor digital output connected to Pin 9
int pump = 8;     // Relay module controlling water pump connected to Pin 8

void setup() {

  // Configure pin modes
  pinMode(flame, INPUT);
  pinMode(pump, OUTPUT);

  // Ensure pump is OFF initially (Active LOW relay)
  digitalWrite(pump, HIGH);
}

void loop() {

  // Read flame sensor state
  int flameState = digitalRead(flame);

  // =============================
  // Fire Detection Logic
  // =============================
  // Most flame sensor modules are Active LOW:
  // LOW  → Fire detected
  // HIGH → No fire

  if (flameState == LOW) {

    // Fire detected → Turn ON pump
    // Relay is Active LOW
    digitalWrite(pump, LOW);
  } 
  else {

    // No fire → Turn OFF pump
    digitalWrite(pump, HIGH);
  }
}
