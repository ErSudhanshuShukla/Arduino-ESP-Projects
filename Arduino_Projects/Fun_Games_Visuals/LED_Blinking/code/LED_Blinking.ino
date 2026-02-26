/*
====================================================
 Title   : LED Blinking
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

int led = 13;   // Onboard LED connected to digital pin 13

void setup() {
  pinMode(led, OUTPUT);   // Set LED pin as OUTPUT
}

void loop() {
  digitalWrite(led, HIGH);  // Turn LED ON
  delay(1000);              // Wait for 1 second

  digitalWrite(led, LOW);   // Turn LED OFF
  delay(1000);              // Wait for 1 second
}
