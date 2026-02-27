/*
====================================================
 Title   : Smart Keypad Lock
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// =============================
// Object Initialization
// =============================
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo lockServo;

// =============================
// Keypad Configuration
// =============================
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'D','C','B','A'},
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// =============================
// Password Settings
// =============================
String password = "2025"; // Change Password
String input = "";
bool unlocked = false;

void setup() {

  delay(2000); // Power stabilization delay

  lcd.init();
  lcd.backlight();

  lockServo.attach(10);
  lockServo.write(0); // Initially Locked

  keypad.setDebounceTime(50); // Prevent ghost key presses

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
}

void loop() {

  char key = keypad.getKey();

  if (key == NO_KEY) return;

  // =============================
  // If Already Unlocked
  // =============================
  if (unlocked) {

    if (key == '#') {
      unlocked = false;
      lockServo.write(0);

      lcd.clear();
      lcd.print("Locked");
      delay(700);

      lcd.clear();
      lcd.print("Enter Password");
    }
    return;
  }

  // =============================
  // Normal Operation
  // =============================
  if (key == '*') { // Clear Input

    input = "";
    lcd.clear();
    lcd.print("Enter Password");
  }

  else if (key == '#') { // Verify Password

    lcd.clear();

    if (input == password) {

      lcd.print("Unlocked!");
      lockServo.write(90);
      unlocked = true;

      delay(700);
      lcd.clear();
      lcd.print("Press # to lock");
    } 
    else {

      lcd.print("Wrong Pass");
      lockServo.write(0);

      delay(1200);
      lcd.clear();
      lcd.print("Enter Password");
    }

    input = "";
  }

  else { // Normal Key Entry

    if (input.length() < 8) { // Safety Limit

      input += key;

      lcd.setCursor(0,1);
      lcd.print("                "); // Clear Line
      lcd.setCursor(0,1);

      for (int i = 0; i < input.length(); i++) {
        lcd.print("*"); // Hide password
      }
    }
  }
}
