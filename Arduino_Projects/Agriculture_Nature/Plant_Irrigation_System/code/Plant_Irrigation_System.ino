/*
====================================================
 Title   : Plant Irrigation System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int soil = A0;     // Soil moisture sensor connected to analog pin A0
int relay = 8;     // Relay module connected to digital pin 8 (water pump control)

void setup() {
  pinMode(relay, OUTPUT);     
  digitalWrite(relay, HIGH);   // Pump OFF initially (Active LOW relay logic)

  Serial.begin(9600);          // Start Serial Monitor for debugging
}

void loop() {
  int value = analogRead(soil);   // Read soil moisture sensor value (0–1023)
  Serial.println(value);         // Print moisture value on Serial Monitor

  // If soil is dry (low moisture value), turn pump ON
  if (value < 500) {
    digitalWrite(relay, LOW);    // Dry soil → Pump ON (Active LOW)
  } else {
    digitalWrite(relay, HIGH);   // Wet soil → Pump OFF (Active LOW)
  }

  delay(500);   // Small delay to avoid rapid switching
}
