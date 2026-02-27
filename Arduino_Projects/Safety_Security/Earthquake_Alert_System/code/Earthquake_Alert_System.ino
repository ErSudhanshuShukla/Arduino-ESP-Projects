/*
====================================================
 Title   : Earthquake Alert System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
const int tiltPin  = 8;    // Tilt Sensor Output Pin
const int buzzer   = 11;   // Buzzer Pin
const int ledPin   = 12;   // LED Indicator Pin

void setup() {

  // Configure pin modes
  pinMode(tiltPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Ensure buzzer and LED are OFF initially
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {

  // Read tilt sensor state
  int tiltState = digitalRead(tiltPin);

  // =============================
  // No Movement Detected
  // =============================
  if (tiltState == LOW) {

    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  } 

  // =============================
  // Movement / Vibration Detected
  // =============================
  else {

    digitalWrite(buzzer, HIGH); 
    digitalWrite(ledPin, HIGH);

    delay(2000);   // Alert duration (2 seconds)

    digitalWrite(buzzer, LOW); 
    digitalWrite(ledPin, LOW);
  }

  delay(50);   // Small delay for stability
}
