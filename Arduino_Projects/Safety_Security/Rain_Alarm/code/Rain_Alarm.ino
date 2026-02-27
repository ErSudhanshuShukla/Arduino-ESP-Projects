/*
====================================================
 Title   : Rain Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int rainSensor = 8;   // Rain sensor digital output connected to Pin 8
int buzzer = 11;      // Buzzer connected to Pin 11

void setup() {

  // Configure pin modes
  pinMode(rainSensor, INPUT);
  pinMode(buzzer, OUTPUT);

  // Ensure buzzer is OFF initially
  digitalWrite(buzzer, LOW);
}

void loop() {

  // Read rain sensor state
  int rainState = digitalRead(rainSensor);

  // =============================
  // Rain Detection Logic
  // =============================
  // Most rain sensor modules are Active LOW:
  // LOW  → Rain detected
  // HIGH → No rain

  if (rainState == LOW) {
    // Rain detected → Turn ON buzzer
    digitalWrite(buzzer, HIGH);
  } 
  else {
    // No rain → Turn OFF buzzer
    digitalWrite(buzzer, LOW);
  }
}
