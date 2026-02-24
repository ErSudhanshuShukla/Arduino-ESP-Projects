/*
====================================================
 Title   : Smart Dustbin
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Servo.h>    // Library to control servo motor

Servo lid;           // Servo object to control dustbin lid

#define trig 3       // Ultrasonic sensor Trigger pin
#define echo 2       // Ultrasonic sensor Echo pin

void setup() {
  pinMode(trig, OUTPUT);   // Set trigger pin as OUTPUT
  pinMode(echo, INPUT);   // Set echo pin as INPUT

  lid.attach(4);          // Attach servo motor to pin 4
  lid.write(0);          // Initial position: Lid closed
}

void loop() {

  // Generate ultrasonic pulse
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure echo pulse duration
  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;   // Convert time to distance (in cm)

  // Control lid based on distance
  if (distance > 0 && distance < 20) {
    lid.write(90);   // Open lid when a person is near
    delay(1000);     // Keep lid open for 1 second
  } 
  else {
    lid.write(0);    // Close lid when no person is detected
  }
}
