/*
====================================================
 Title   : Obstacle Avoiding Car
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// ================= SENSOR PINS =================
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200   // Maximum sensing distance (cm)

// ================= SPEED SETTINGS =================
#define CRUISE_SPEED 120   // Forward speed
#define TURN_SPEED    90   // Turning speed

// ================= SERVO ANGLES =================
#define SERVO_CENTER 90
#define SERVO_RIGHT  40
#define SERVO_LEFT   140

// ================= OBJECTS =================
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  // Ultrasonic object
Servo myservo;                                   // Servo object

// Motors (L293D shield ports)
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// ================= VARIABLES =================
boolean goesForward = false;   // Track forward state
int distance = 100;            // Store distance
int speedSet = 0;              // Speed ramp variable

// ================= SETUP =================
void setup() {

  myservo.attach(9);           // Attach servo to D9
  delay(500);

  myservo.write(SERVO_CENTER); // Center servo
  delay(1000);

  distance = readPing();       // Initial distance read
}

// ================= LOOP =================
void loop() {

  // Obstacle detected within 30 cm
  if (distance <= 30) {              
    moveStop();
    delay(150);

    moveBackward();            // Move back slightly
    delay(300);

    moveStop();
    delay(200);

    int distanceR = lookRight();  // Scan right
    delay(150);
    int distanceL = lookLeft();   // Scan left
    delay(150);

    // Turn towards clearer direction
    if (distanceR >= distanceL) {
      turnRight();
    } else {
      turnLeft();
    }

    moveStop();
    delay(150);
  } 
  else {
    moveForward();             // Path clear → move forward
  }

  distance = readPing();       // Update distance
}

// ================= SENSOR FUNCTIONS =================

// Measure distance using ultrasonic sensor
int readPing() {
  delay(50);
  int cm = sonar.ping_cm();
  if (cm == 0) cm = MAX_DISTANCE;  // If no reading, assume max
  return cm;
}

// Rotate servo right and measure distance
int lookRight() {
  myservo.write(SERVO_RIGHT);
  delay(350);
  int d = readPing();
  myservo.write(SERVO_CENTER);     // Return to center
  return d;
}

// Rotate servo left and measure distance
int lookLeft() {
  myservo.write(SERVO_LEFT);
  delay(350);
  int d = readPing();
  myservo.write(SERVO_CENTER);     // Return to center
  return d;
}

// ================= MOTOR FUNCTIONS =================

// Stop all motors
void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  goesForward = false;
}

// Move forward with smooth acceleration
void moveForward() {
  if (!goesForward) {
    goesForward = true;

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);

    for (speedSet = 90; speedSet <= CRUISE_SPEED; speedSet += 3) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}

// Move backward with smooth acceleration
void moveBackward() {
  goesForward = false;

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  for (speedSet = 90; speedSet <= CRUISE_SPEED; speedSet += 3) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

// Turn right
void turnRight() {
  motor1.setSpeed(TURN_SPEED);
  motor2.setSpeed(TURN_SPEED);
  motor3.setSpeed(TURN_SPEED);
  motor4.setSpeed(TURN_SPEED);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(450);
}

// Turn left
void turnLeft() {
  motor1.setSpeed(TURN_SPEED);
  motor2.setSpeed(TURN_SPEED);
  motor3.setSpeed(TURN_SPEED);
  motor4.setSpeed(TURN_SPEED);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(450);
}
