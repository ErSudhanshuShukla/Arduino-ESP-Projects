/*
====================================================
 Title   : Laser Security Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int ldrModule = 2;     // LDR Module Digital Output (DO)
int buzzer = 11;       // Buzzer Pin

void setup() {

  pinMode(ldrModule, INPUT);   // LDR Module as INPUT
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, LOW);   // Ensure buzzer OFF initially
}

void loop() {

  // Read digital output from LDR module
  int state = digitalRead(ldrModule);

  // Most LDR modules are Active LOW
  // LOW  = Light detected (Laser Present)
  // HIGH = Laser beam interrupted

  if(state == HIGH) {
    // Laser beam broken → Alarm ON
    digitalWrite(buzzer, HIGH);
  } 
  else {
    // Laser present → Alarm OFF
    digitalWrite(buzzer, LOW);
  }

  delay(50);
}
