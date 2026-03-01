/*
====================================================
 Title   : IoT Car
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// -------- Blynk Configuration (Keep Private) --------
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

#define BLYNK_PRINT Serial

// -------- Libraries --------
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------- WiFi Credentials --------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Pin Configuration

// Motor Driver (L298N)
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5

// Extra Features
#define HORN D6
#define HEADLIGHT1 D7
#define HEADLIGHT2 D8

// Blynk Virtual Pins
// V9  - Joystick X
// V10 - Joystick Y
// V11 - Speed Slider (0-255)
// V12 - Horn Button (PUSH)
// V13 - Headlight Switch

int x = 50;
int y = 50;
int Speed = 255;   // PWM Speed (0-255)

// Setup
void setup() {

  Serial.begin(9600);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Horn & Headlights
  pinMode(HORN, OUTPUT);
  digitalWrite(HORN, LOW);

  pinMode(HEADLIGHT1, OUTPUT);
  pinMode(HEADLIGHT2, OUTPUT);
  digitalWrite(HEADLIGHT1, LOW);
  digitalWrite(HEADLIGHT2, LOW);

  // Connect to Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  Serial.println("Connecting to Blynk...");
}

// Blynk Controls

// Joystick X-axis
BLYNK_WRITE(V9) {
  x = param[0].asInt();
}

// Joystick Y-axis
BLYNK_WRITE(V10) {
  y = param[0].asInt();
}

// Speed Slider
BLYNK_WRITE(V11) {
  Speed = param.asInt();
  if (Speed < 0) Speed = 0;
  if (Speed > 255) Speed = 255;
}

// Horn Button (Push Mode Recommended)
BLYNK_WRITE(V12) {
  int hornState = param.asInt();
  digitalWrite(HORN, hornState);
}

// Headlight Switch
BLYNK_WRITE(V13) {
  int state = param.asInt();
  digitalWrite(HEADLIGHT1, state);
  digitalWrite(HEADLIGHT2, state);
}

// Smart Movement Logic
void smartcar() {

  if (y > 70) {
    carForward();
  } 
  else if (y < 30) {
    carBackward();
  } 
  else if (x < 30) {
    carLeft();
  } 
  else if (x > 70) {
    carRight();
  } 
  else {
    carStop();
  }
}

void loop() {
  Blynk.run();
  smartcar();
}

// Motor Control Functions

void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carStop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
