/*
====================================================
 Title   : Line Follower Car
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
 Library : Adafruit Motor Shield V1 (v1.0.1)
====================================================

Hardware Setup Requirements:
1. Distance between IR sensors: 8 - 9 cm
2. Black line width: 4.5 – 5 cm
3. Sensor height from ground: ~2 cm
*/

#include <AFMotor.h>

// Debug Macro (Set 1 to enable)
#define DEBUG_PRINT 0

// IR Sensor Pins
#define LEFT_IR  A4
#define RIGHT_IR A5

// Robot Control Parameters
#define DETECT_LIMIT        300
#define FORWARD_SPEED       60
#define TURN_SHARP_SPEED    150
#define TURN_SLIGHT_SPEED   120
#define DELAY_AFTER_TURN    140
#define BEFORE_TURN_DELAY   10

// =============================
// Motor Configuration
// M3 → Left Motor
// M4 → Right Motor
// =============================

AF_DCMotor motorL(3);
AF_DCMotor motorR(4);

// Global Variables
int left_value;
int right_value;
char lastDirection = 'S';   // S = Stop, F = Forward, L = Left, R = Right

// Setup
void setup() {

#if DEBUG_PRINT
  Serial.begin(9600);
#endif

  // Initialize Motors
  motorL.setSpeed(0);
  motorR.setSpeed(0);
  motorL.run(RELEASE);
  motorR.run(RELEASE);

  // Initial Push to Start Movement
  motorL.run(FORWARD);
  motorR.run(FORWARD);
  motorL.setSpeed(255);
  motorR.setSpeed(255);
  delay(40);
}

// Main Loop
void loop() {

  // Read IR Sensors
  left_value  = analogRead(LEFT_IR);
  right_value = analogRead(RIGHT_IR);

#if DEBUG_PRINT
  Serial.print(left_value);
  Serial.print(",");
  Serial.print(right_value);
  Serial.print(",");
  Serial.println(lastDirection);
#endif

  // Decision Making Logic

  // Right detects line
  if (right_value >= DETECT_LIMIT && left_value < DETECT_LIMIT) {
    turnRight();
  }

  // Left detects line
  else if (left_value >= DETECT_LIMIT && right_value < DETECT_LIMIT) {
    turnLeft();
  }

  // No sensor detects line
  else if (left_value < DETECT_LIMIT && right_value < DETECT_LIMIT) {
    moveForward();
  }

  // Both sensors detect line
  else if (left_value >= DETECT_LIMIT && right_value >= DETECT_LIMIT) {
    stopRobot();
  }
}

// Movement Functions
void moveForward() {

  if (lastDirection != 'F') {
    // Initial Boost
    motorL.run(FORWARD);
    motorR.run(FORWARD);
    motorL.setSpeed(255);
    motorR.setSpeed(255);
    delay(20);
    lastDirection = 'F';
  } 
  else {
    motorL.run(FORWARD);
    motorR.run(FORWARD);
    motorL.setSpeed(FORWARD_SPEED);
    motorR.setSpeed(FORWARD_SPEED);
  }
}

void stopRobot() {

  if (lastDirection != 'S') {
    // Short Forward Check
    motorL.run(FORWARD);
    motorR.run(FORWARD);
    motorL.setSpeed(255);
    motorR.setSpeed(255);
    delay(40);
    lastDirection = 'S';
  } 
  else {
    motorL.setSpeed(0);
    motorR.setSpeed(0);
    motorL.run(RELEASE);
    motorR.run(RELEASE);
  }
}

void turnRight() {

  if (lastDirection != 'R') {
    lastDirection = 'R';

    motorL.setSpeed(0);
    motorR.setSpeed(0);
    delay(BEFORE_TURN_DELAY);

    motorL.run(FORWARD);
    motorR.run(BACKWARD);
    motorL.setSpeed(TURN_SLIGHT_SPEED);
    motorR.setSpeed(TURN_SLIGHT_SPEED);
  } 
  else {
    motorL.run(FORWARD);
    motorR.run(BACKWARD);
    motorL.setSpeed(TURN_SHARP_SPEED);
    motorR.setSpeed(TURN_SHARP_SPEED);
  }

  delay(DELAY_AFTER_TURN);
}

void turnLeft() {

  if (lastDirection != 'L') {
    lastDirection = 'L';

    motorL.setSpeed(0);
    motorR.setSpeed(0);
    delay(BEFORE_TURN_DELAY);

    motorR.run(FORWARD);
    motorL.run(BACKWARD);
    motorL.setSpeed(TURN_SLIGHT_SPEED);
    motorR.setSpeed(TURN_SLIGHT_SPEED);
  } 
  else {
    motorR.run(FORWARD);
    motorL.run(BACKWARD);
    motorL.setSpeed(TURN_SHARP_SPEED);
    motorR.setSpeed(TURN_SHARP_SPEED);
  }

  delay(DELAY_AFTER_TURN);
}
