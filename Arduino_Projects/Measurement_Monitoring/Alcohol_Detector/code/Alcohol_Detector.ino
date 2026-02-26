/*
====================================================
 Title   : Alcohol Detector
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int sensorPin = A0;    // MQ-3 alcohol sensor analog output connected to A0
int led = 13;         // LED connected to digital pin 13
int threshold = 350; // Alcohol detection threshold (adjust as per calibration)

void setup() {
  pinMode(led, OUTPUT);      
  digitalWrite(led, LOW);   // Keep LED OFF at start
  Serial.begin(9600);       // Serial Monitor for debugging (optional)
}

void loop() {
  int value = analogRead(sensorPin);   // Read MQ-3 sensor value (0–1023)
  Serial.println(value);               // Print value for calibration (optional)

  // Check alcohol level
  if (value > threshold) {
    digitalWrite(led, HIGH);   // Alcohol detected → LED ON
  } else {
    digitalWrite(led, LOW);    // No alcohol detected → LED OFF
  }

  delay(500);   // Small delay for stable readings
}
