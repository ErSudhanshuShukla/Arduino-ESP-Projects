/*
====================================================
 Title   : Music Rhythm Light System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int sound = A0;    // Sound sensor (microphone module) connected to analog pin A0

int led1 = 9;     // LED 1 (Low beat level)
int led2 = 10;    // LED 2 (Medium beat level)
int led3 = 11;    // LED 3 (High beat level)
int led4 = 12;    // LED 4 (Very high beat level)

void setup() {
  pinMode(led1, OUTPUT);   // Set LED pins as OUTPUT
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600);     // Start Serial Monitor for debugging
}

void loop() {
  int val = analogRead(sound);   // Read sound sensor value (0–1023)
  Serial.println(val);          // Print sound level to Serial Monitor

  // Level 1 (low beat / low sound)
  digitalWrite(led1, val > 200);

  // Level 2 (medium beat)
  digitalWrite(led2, val > 250);

  // Level 3 (high beat)
  digitalWrite(led3, val > 300);

  // Level 4 (very high beat)
  digitalWrite(led4, val > 350);

  delay(10);   // Small delay for smooth response
}
