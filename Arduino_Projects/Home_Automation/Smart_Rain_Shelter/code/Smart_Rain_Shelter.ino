/*
====================================================
 Title   : Smart Rain Shelter
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Servo.h>    // Library to control servo motor

#define RAIN_PIN 2    // Rain sensor digital output pin
Servo shelter;       // Servo object for shelter mechanism

// Set angles according to your mechanical setup
int OPEN_ANGLE  = 20;    // Shelter open position (no rain)
int CLOSE_ANGLE = 140;  // Shelter closed position (raining)

void setup() {
  pinMode(RAIN_PIN, INPUT);   // Configure rain sensor pin as input
  shelter.attach(9);          // Attach servo motor to pin 9
  shelter.write(OPEN_ANGLE);  // Start with shelter open
}

void loop() {
  int rainState = digitalRead(RAIN_PIN);  // Read rain sensor state

  if (rainState == LOW) {
    // Rain detected
    shelter.write(CLOSE_ANGLE);   // Close the shelter to protect from rain
  } 
  else {
    // No rain detected
    shelter.write(OPEN_ANGLE);    // Open the shelter
  }

  delay(200);  // Small delay to stabilize readings
}
