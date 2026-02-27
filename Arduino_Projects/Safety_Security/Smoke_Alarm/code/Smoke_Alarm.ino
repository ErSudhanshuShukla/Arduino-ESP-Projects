/*
====================================================
 Title   : Smoke Alarm
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// =============================
// Pin Definitions
// =============================
int mq2 = A0;        // MQ-2 Gas/Smoke Sensor connected to Analog Pin A0
int buzzer = 11;     // Buzzer connected to Pin 11
int threshold = 150; // Smoke detection threshold (adjust after calibration)

void setup() {

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);   // Ensure buzzer OFF initially

  Serial.begin(9600);          // Start Serial Monitor for debugging
}

void loop() {

  // Read analog value from MQ-2 sensor
  int value = analogRead(mq2);
  Serial.println(value);   // Print value for calibration

  // =============================
  // Smoke Detection Logic
  // =============================
  if (value > threshold) {

    // Smoke/Gas detected
    digitalWrite(buzzer, HIGH);
  } 
  else {

    // No smoke detected
    digitalWrite(buzzer, LOW);
  }
}
