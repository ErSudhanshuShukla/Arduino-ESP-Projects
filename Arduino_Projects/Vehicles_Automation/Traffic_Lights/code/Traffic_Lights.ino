/*
====================================================
 Title   : Traffic Lights
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Pin Definitions
int red = 12;      // Red LED pin
int yellow = 11;   // Yellow LED pin
int green = 13;    // Green LED pin

// Setup Function
void setup() {

  // Set LED pins as output
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// Main Loop
void loop() {

  // RED light ON (STOP)
  digitalWrite(red, HIGH);     // Turn ON Red LED
  delay(8000);                 // Stay red for 8 seconds
  digitalWrite(red, LOW);      // Turn OFF Red LED

  // YELLOW blinking (Red → Green warning)
  for (int i = 0; i < 5; i++) {
    digitalWrite(yellow, HIGH);
    delay(700);                // Yellow ON time
    digitalWrite(yellow, LOW);
    delay(300);                // Yellow OFF time
  }

  // GREEN light ON (GO)
  digitalWrite(green, HIGH);   // Turn ON Green LED
  delay(10000);                // Stay green for 10 seconds
  digitalWrite(green, LOW);    // Turn OFF Green LED

  // YELLOW blinking (Green → Red warning)
  for (int i = 0; i < 5; i++) {
    digitalWrite(yellow, HIGH);
    delay(700);
    digitalWrite(yellow, LOW);
    delay(300);
  }
}
