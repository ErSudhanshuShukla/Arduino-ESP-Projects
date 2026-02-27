/*
====================================================
 Title   : Bluetooth Car
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Motor Control Pins (L298N)
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

// Speed Control Pins
#define ENA 3
#define ENB 11

// Horn & Headlights
#define HORN 12
#define HL1 7
#define HL2 8

// Speed Settings
int speedFB = 190;   // Forward / Backward speed
int speedLR = 120;   // Left / Right speed

// Safety Timeout
unsigned long lastCmdTime = 0;
const unsigned long CMD_TIMEOUT = 150;

char cmd;
bool headlightState = false;

void setup() {

  Serial.begin(9600);  // Bluetooth communication baud rate

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(HORN, OUTPUT);
  pinMode(HL1, OUTPUT);
  pinMode(HL2, OUTPUT);

  digitalWrite(HORN, LOW);
  digitalWrite(HL1, LOW);
  digitalWrite(HL2, LOW);

  stopMotor(); // Start in safe state
}

void loop() {

  if (Serial.available()) {
    cmd = Serial.read();
    lastCmdTime = millis();

    if (cmd == 'F') forward();
    else if (cmd == 'B') backward();
    else if (cmd == 'L') left();
    else if (cmd == 'R') right();
    else if (cmd == 'S') stopMotor();
    else if (cmd == 'H') hornOn();
    else if (cmd == '1') headlightsOn();
    else if (cmd == '0') headlightsOff();
  }

  // Safety auto-stop
  if (millis() - lastCmdTime > CMD_TIMEOUT) {
    stopMotor();
    hornOff();
  }
}

// -------- MOTOR FUNCTIONS --------

void forward() {
  analogWrite(ENA, speedFB);
  analogWrite(ENB, speedFB);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(60);
  stopMotor();
}

void backward() {
  analogWrite(ENA, speedFB);
  analogWrite(ENB, speedFB);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(60);
  stopMotor();
}

void left() {
  analogWrite(ENA, speedLR);
  analogWrite(ENB, speedLR);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, speedLR);
  analogWrite(ENB, speedLR);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotor() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------- HORN --------
void hornOn() {
  digitalWrite(HORN, HIGH);
}

void hornOff() {
  digitalWrite(HORN, LOW);
}

// -------- HEADLIGHTS --------
void headlightsOn() {
  digitalWrite(HL1, HIGH);
  digitalWrite(HL2, HIGH);
}

void headlightsOff() {
  digitalWrite(HL1, LOW);
  digitalWrite(HL2, LOW);
}
