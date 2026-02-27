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
int ldr = A0;        // LDR (Light Dependent Resistor) connected to Analog Pin A0
int buzzer = 11;     // Buzzer connected to Digital Pin 11

void setup() {

  Serial.begin(9600);      // Start Serial Monitor for debugging
  pinMode(buzzer, OUTPUT); // Set buzzer as OUTPUT

  digitalWrite(buzzer, LOW);  // Ensure buzzer is OFF initially
}

void loop() {

  // =============================
  // Read Light Intensity
  // =============================
  int val = analogRead(ldr);   // Read analog value (0–1023)
  Serial.println(val);         // Print value for calibration

  // =============================
  // Laser Detection Logic
  // =============================
  // If value increases beyond threshold,
  // it means laser beam is interrupted

  if(val > 300) {   
    // Laser NOT detected → Alarm ON
    digitalWrite(buzzer, HIGH);
  } 
  else {          
    // Laser detected → Alarm OFF
    digitalWrite(buzzer, LOW);
  }

  delay(100);   // Small delay for stability
}
