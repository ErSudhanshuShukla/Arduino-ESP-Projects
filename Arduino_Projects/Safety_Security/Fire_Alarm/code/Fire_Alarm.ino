/*
====================================================
 Title   : Fire Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int flameSensor = 2;   // Flame sensor digital output connected to Pin 2
int buzzer = 11;       // Buzzer connected to Pin 11

void setup() {

  // Configure pin modes
  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);

  // Ensure buzzer is OFF initially
  digitalWrite(buzzer, LOW);
}

void loop() {

  // Read flame sensor state
  int flameState = digitalRead(flameSensor);

  // =============================
  // Flame Detection Logic
  // =============================
  if (flameState == LOW) {   
    // LOW means flame detected (Active LOW module)
    digitalWrite(buzzer, HIGH);  
  } 
  else {
    // No flame detected
    digitalWrite(buzzer, LOW);
  }
}
