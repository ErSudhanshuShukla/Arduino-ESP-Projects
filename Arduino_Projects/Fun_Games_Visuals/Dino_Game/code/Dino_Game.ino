/*
====================================================
 Title   : Dino Game
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define IR_PIN 8
#define BUZZER 11

// ---------------- GAME VARIABLES ----------------
int dinoRow = 1;          // 1 = ground, 0 = jump
int obstacleCol = 15;
int score = 0;
int gameSpeed = 320;
bool gameOverFlag = false;

// Obstacle system
int obstacleType = 0;     
// 0 = cactus batch
// 1 = crow batch

int cactusCount = 1;      // 1–3
int crowCount   = 0;      // 1–2

// ---------------- CUSTOM CHARACTERS ----------------

// 🦖 Dinosaur
byte dinoChar[8] = {
  B00100,
  B01110,
  B10101,
  B11111,
  B00100,
  B01110,
  B10100,
  B00000
};

// 🌵 Cactus
byte cactusChar[8] = {
  B00100,
  B00100,
  B10101,
  B10101,
  B00100,
  B00100,
  B00100,
  B00000
};

// 🐦 Crow
byte crowChar[8] = {
  B00000,
  B10101,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup() {
  pinMode(IR_PIN, INPUT);     // IR sensor for jump detection
  pinMode(BUZZER, OUTPUT);   // Buzzer for game over alert

  lcd.init();                // Initialize LCD
  lcd.backlight();          // Turn ON LCD backlight

  // Load custom characters into LCD
  lcd.createChar(0, dinoChar);
  lcd.createChar(1, cactusChar);
  lcd.createChar(2, crowChar);

  randomSeed(analogRead(A0));  // Randomize obstacle patterns

  startScreen();   // Show welcome screen
  resetGame();     // Initialize game variables
}

void loop() {

  // ---------------- GAME OVER MODE ----------------
  if (gameOverFlag) {
    lcd.setCursor(0, 1);
    lcd.print("Wave IR restart ");

    if (digitalRead(IR_PIN) == LOW) {
      delay(300);        // Debounce delay
      resetGame();      // Restart game
    }
    return;
  }

  // ---------------- JUMP LOGIC ----------------
  if (digitalRead(IR_PIN) == LOW)
    dinoRow = 0;   // Jump
  else
    dinoRow = 1;   // Stay on ground

  lcd.clear();

  // ---------------- DRAW DINO ----------------
  lcd.setCursor(2, dinoRow);
  lcd.write(byte(0));   // Draw dinosaur

  // ---------------- DRAW OBSTACLE ----------------
  if (obstacleType == 0) {             // Cactus batch (ground)
    for (int i = 0; i < cactusCount; i++) {
      lcd.setCursor(obstacleCol + i, 1);
      lcd.write(byte(1));
    }
  } 
  else {                               // Crow batch (air)
    for (int i = 0; i < crowCount; i++) {
      lcd.setCursor(obstacleCol + i, 0);
      lcd.write(byte(2));
    }
  }

  // ---------------- COLLISION CHECK ----------------
  int width = max(cactusCount, crowCount);

  if (obstacleCol <= 2 && obstacleCol + width > 2) {

    if (obstacleType == 0 && dinoRow == 1) {
      triggerGameOver();    // Hit cactus
    }

    if (obstacleType == 1 && dinoRow == 0) {
      triggerGameOver();    // Hit crow
    }
  }

  obstacleCol--;   // Move obstacle left

  // ---------------- NEW OBSTACLE GENERATION ----------------
  if (obstacleCol < -3) {
    obstacleCol = 15 + random(2, 6);     // Reset obstacle position

    obstacleType = random(0, 2);        // Random: cactus or crow

    if (obstacleType == 0) {
      cactusCount = random(1, 4);       // 1–3 cactus
      crowCount = 0;
    } else {
      crowCount = random(1, 3);         // 1–2 crow
      cactusCount = 0;
    }

    score++;   // Increase score

    // Increase difficulty gradually
    if (score % 3 == 0 && gameSpeed > 90)
      gameSpeed -= 20;
  }

  // ---------------- SCORE DISPLAY ----------------
  lcd.setCursor(11, 0);
  lcd.print("S:");
  lcd.print(score);

  delay(gameSpeed);   // Control game speed
}

// ---------------- GAME OVER FUNCTION ----------------
void triggerGameOver() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  GAME OVER  ");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);

  digitalWrite(BUZZER, HIGH);   // Buzzer ON
  delay(400);
  digitalWrite(BUZZER, LOW);    // Buzzer OFF

  gameOverFlag = true;
}

// ---------------- RESET GAME ----------------
void resetGame() {
  lcd.clear();
  score = 0;
  dinoRow = 1;
  obstacleCol = 15;
  gameSpeed = 320;
  gameOverFlag = false;

  obstacleType = random(0, 2);
  if (obstacleType == 0) {
    cactusCount = random(1, 4);
    crowCount = 0;
  } else {
    crowCount = random(1, 3);
    cactusCount = 0;
  }
}

// ---------------- START SCREEN ----------------
void startScreen() {
  lcd.setCursor(0, 0);
  lcd.print("  DINO GAME  ");
  lcd.setCursor(0, 1);
  lcd.print("Think & Jump!");
  delay(2000);
  lcd.clear();
}
