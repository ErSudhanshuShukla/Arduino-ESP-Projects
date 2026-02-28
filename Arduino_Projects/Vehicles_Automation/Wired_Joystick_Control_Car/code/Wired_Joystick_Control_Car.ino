/*
====================================================
 Title   : Wired Joystick Car
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Joystick Pins
#define joyX A0     // X-axis (Left/Right)
#define joyY A1     // Y-axis (Forward/Backward)
#define joyBtn 7    // Joystick button (pressed = LOW)

// Motor Driver Pins (L298N)
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5       // Left motor speed (PWM)
#define ENB 6       // Right motor speed (PWM)

// Buzzer Pin
#define buzzer 12

// Setup Function
void setup() {

  // Joystick button uses internal pull-up
  pinMode(joyBtn, INPUT_PULLUP);

  // Motor control pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Buzzer output
  pinMode(buzzer, OUTPUT);
}

// Main Loop
void loop() {

  // Read joystick analog values
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  int speedVal = 120;   // Motor speed (0–255)

  // Joystick Button → Control Buzzer
  if (digitalRead(joyBtn) == LOW) {
    digitalWrite(buzzer, HIGH);  // Buzzer ON
  } else {
    digitalWrite(buzzer, LOW);   // Buzzer OFF
  }

  // Set motor speed
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);

  // Direction Control Logic

  // Forward
  if (yVal > 600) {
    moveForward();
  }
  // Backward
  else if (yVal < 400) {
    moveBackward();
  }
  // Right
  else if (xVal > 600) {
    turnRight();
  }
  // Left
  else if (xVal < 400) {
    turnLeft();
  }
  // Neutral → Stop
  else {
    stopCar();
  }
}

// Motor Control Functions

// Move car forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Move car backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn car right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn car left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Stop car
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
