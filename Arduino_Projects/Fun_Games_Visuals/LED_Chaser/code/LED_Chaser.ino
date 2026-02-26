/*
====================================================
 Title   : LED Chaser
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

// Multi-effect LED Chaser for 9 LEDs (pins 2..10)
// Auto-cycles through 8 effects.
// Note: PWM pins on Uno in this range: 3, 5, 6, 9, 10
// Non-PWM pins (2, 4, 7, 8) will be toggled digitally when fade is requested.

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int total = 9;

int effectDelay = 80;     // Base speed for chase effects
int effectHold  = 600;   // Hold time for some effects (ms)

// 🔧 Check if a pin supports PWM
bool isPWMpin(int pin) {
  return (pin == 3 || pin == 5 || pin == 6 || pin == 9 || pin == 10);
}

// 🔧 Set LED brightness (0–255)
// PWM pins fade smoothly, non-PWM pins toggle ON/OFF
void setBrightness(int idx, int value) {
  int pin = leds[idx];
  if (isPWMpin(pin)) {
    analogWrite(pin, constrain(value, 0, 255));
  } else {
    digitalWrite(pin, value > 127 ? HIGH : LOW);
  }
}

// 🔧 Turn all LEDs OFF
void allOff() {
  for (int i = 0; i < total; i++) {
    digitalWrite(leds[i], LOW);
  }
}

// =================== EFFECTS ===================

// Effect 1: Simple Forward Chase
void effectForwardChase(int speed) {
  for (int i = 0; i < total; i++) {
    digitalWrite(leds[i], HIGH);
    delay(speed);
    digitalWrite(leds[i], LOW);
  }
}

// Effect 2: Reverse Chase
void effectReverseChase(int speed) {
  for (int i = total - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(speed);
    digitalWrite(leds[i], LOW);
  }
}

// Effect 3: Ping-Pong with trailing effect
void effectPingPong(int speed) {
  // Forward
  for (int i = 0; i < total; i++) {
    digitalWrite(leds[i], HIGH);
    if (i - 1 >= 0) digitalWrite(leds[i - 1], LOW);
    delay(speed);
  }
  // Reverse
  for (int i = total - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    if (i + 1 < total) digitalWrite(leds[i + 1], LOW);
    delay(speed);
  }
  allOff();
}

// Effect 4: Double-Side Wave (ends to center)
void effectDoubleSideWave(int speed) {
  int half = total / 2; // 9 LEDs → 4 pairs + center
  for (int i = 0; i < half; i++) {
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[total - 1 - i], HIGH);
    delay(speed);
    digitalWrite(leds[i], LOW);
    digitalWrite(leds[total - 1 - i], LOW);
  }
  // Center LED for odd count
  if (total % 2 == 1) {
    digitalWrite(leds[half], HIGH);
    delay(speed * 2);
    digitalWrite(leds[half], LOW);
  }
}

// Effect 5: Breathing / Pulse
void effectBreathing(int fadeStep, int pauseMs) {
  // Fade up
  for (int b = 0; b <= 255; b += fadeStep) {
    for (int i = 0; i < total; i++) setBrightness(i, b);
    delay(pauseMs);
  }
  delay(200);

  // Fade down
  for (int b = 255; b >= 0; b -= fadeStep) {
    for (int i = 0; i < total; i++) setBrightness(i, b);
    delay(pauseMs);
  }
  allOff();
}

// Effect 6: Knight Rider (moving light with tail)
void effectKnightRider(int tailLen, int stepDelay) {
  // Left to right
  for (int center = 0; center < total; center++) {
    for (int i = 0; i < total; i++) {
      int dist = abs(center - i);
      int brightness = 0;
      if (dist == 0) brightness = 255;
      else if (dist <= tailLen) brightness = map(dist, 0, tailLen, 255, 50);
      setBrightness(i, brightness);
    }
    delay(stepDelay);
  }

  // Right to left
  for (int center = total - 1; center >= 0; center--) {
    for (int i = 0; i < total; i++) {
      int dist = abs(center - i);
      int brightness = 0;
      if (dist == 0) brightness = 255;
      else if (dist <= tailLen) brightness = map(dist, 0, tailLen, 255, 50);
      setBrightness(i, brightness);
    }
    delay(stepDelay);
  }
  allOff();
}

// Effect 7: Random Sparkle
void effectRandomSparkle(int sparks, int onMs, int offMs) {
  for (int s = 0; s < sparks; s++) {
    int r = random(0, total);
    digitalWrite(leds[r], HIGH);
    delay(onMs);
    digitalWrite(leds[r], LOW);
    delay(offMs);
  }
}

// Effect 8: Meteor Tail
void effectMeteor(int tailLen, int speed) {
  for (int i = 0; i < total + tailLen; i++) {

    // Dim all LEDs slightly
    for (int j = 0; j < total; j++) {
      if (isPWMpin(leds[j])) {
        analogWrite(leds[j], 20);   // Low glow for trail effect
      } else {
        digitalWrite(leds[j], LOW);
      }
    }

    // Draw meteor head and tail
    for (int t = 0; t < tailLen; t++) {
      int pos = i - t;
      if (pos >= 0 && pos < total) {
        int bright = map(t, 0, tailLen - 1, 255, 60);
        setBrightness(pos, bright);
      }
    }
    delay(speed);
  }
  allOff();
}

// =================== SETUP & LOOP ===================
void setup() {
  for (int i = 0; i < total; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  randomSeed(analogRead(0));  // Seed randomness for sparkle effect
}

void loop() {
  effectForwardChase(effectDelay);
  delay(80);

  effectReverseChase(effectDelay);
  delay(80);

  effectPingPong(effectDelay);
  delay(120);

  effectDoubleSideWave(effectDelay);
  delay(150);

  effectBreathing(6, 8);
  delay(200);

  effectKnightRider(3, 40);
  delay(120);

  effectRandomSparkle(18, 80, 30);
  delay(120);

  effectMeteor(4, 40);
  delay(300);
}
