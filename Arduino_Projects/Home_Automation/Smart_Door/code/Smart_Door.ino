/*
====================================================
 Title   : Smart Door
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Servo.h>    // Library to control servo motor

Servo door;          // Servo object for door mechanism

#define trig 9       // Ultrasonic sensor Trigger pin
#define echo 10      // Ultrasonic sensor Echo pin
int distance;        // Variable to store calculated distance

void setup() {
  pinMode(trig, OUTPUT);   // Set trigger pin as OUTPUT
  pinMode(echo, INPUT);   // Set echo pin as INPUT

  door.attach(8);         // Attach servo motor to pin 8
  door.write(0);         // Initial position: Door Closed
  Serial.begin(9600);    // Start serial communication for distance monitoring
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
  distance = duration * 0.034 / 2;   // Convert time to distance (in cm)

  Serial.println(distance);          // Print distance on Serial Monitor

  // Person detected near the door
  if (distance < 10 && distance > 0) {
    door.write(90);       // Open door
    delay(3000);          // Keep door open for 3 seconds
    door.write(0);        // Close door
  }

  delay(200);            // Small delay to stabilize readings
}
