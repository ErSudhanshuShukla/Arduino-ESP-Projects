/*
====================================================
 Title   : Soil Moisture Alert
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int sensorPin = A0;   // Soil moisture sensor connected to analog pin A0
int buzzer = 11;     // Buzzer connected to digital pin 11
int led = 12;        // LED connected to digital pin 12

void setup() {
  pinMode(buzzer, OUTPUT);   // Set buzzer pin as OUTPUT
  pinMode(led, OUTPUT);      // Set LED pin as OUTPUT
  Serial.begin(9600);        // Start Serial Monitor for debugging
}

void loop() {
  int moisture = analogRead(sensorPin);  // Read soil moisture value (0–1023)
  Serial.println(moisture);              // Print moisture value on Serial Monitor

  // If soil is dry (value above threshold), alert user
  if (moisture < 650) {
    digitalWrite(buzzer, LOW);   // Buzzer OFF (soil is wet)
    digitalWrite(led, LOW);      // LED OFF
  } else {
    digitalWrite(buzzer, HIGH);  // Buzzer ON (soil is dry)
    digitalWrite(led, HIGH);     // LED ON
  }

  delay(500);   // Small delay to stabilize readings
}
