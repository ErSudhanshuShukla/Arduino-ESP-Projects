/*
====================================================
 Title   : Electronic Voting System
 Author  : Sudhanshu Shukla
 GitHub  : https://github.com/ErSudhanshuShukla
 License : Released under the MIT License
====================================================
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD (Address: 0x27, 16x2 display)

// Push button pins (Active LOW using INPUT_PULLUP)
#define sw5 8    // Result button
#define sw4 9    // Candidate D
#define sw3 10   // Candidate C
#define sw2 11   // Candidate B
#define sw1 12   // Candidate A

int voteA = 0;   // Votes for Candidate A
int voteB = 0;   // Votes for Candidate B
int voteC = 0;   // Votes for Candidate C
int voteD = 0;   // Votes for Candidate D

void setup()
{
  // Configure buttons as INPUT_PULLUP (Active LOW)
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);

  lcd.init();         // Initialize LCD
  lcd.backlight();   // Turn ON LCD backlight

  // Welcome screen
  lcd.setCursor(0, 0);
  lcd.print("Voting Machine");
  lcd.setCursor(0, 1);
  lcd.print("EVM System");
  delay(3000);
  lcd.clear();
}

void loop()
{
  // Display candidate labels on first row
  lcd.setCursor(0, 0);
  lcd.print("A   B   C   D");

  // Clear second row before updating counts
  lcd.setCursor(0, 1);
  lcd.print("                ");

  // Display vote counts under each candidate
  lcd.setCursor(0, 1);   lcd.print(voteA);  // Votes for A
  lcd.setCursor(4, 1);   lcd.print(voteB);  // Votes for B
  lcd.setCursor(8, 1);   lcd.print(voteC);  // Votes for C
  lcd.setCursor(12, 1);  lcd.print(voteD);  // Votes for D

  // Vote buttons (Active LOW)
  if (digitalRead(sw1) == LOW) { 
    voteA++; 
    while (digitalRead(sw1) == LOW);  // Wait for button release (debounce)
  }

  if (digitalRead(sw2) == LOW) { 
    voteB++; 
    while (digitalRead(sw2) == LOW);
  }

  if (digitalRead(sw3) == LOW) { 
    voteC++; 
    while (digitalRead(sw3) == LOW);
  }

  if (digitalRead(sw4) == LOW) { 
    voteD++; 
    while (digitalRead(sw4) == LOW);
  }

  // Result button
  if (digitalRead(sw5) == LOW)
  {
    int total = voteA + voteB + voteC + voteD;
    lcd.clear();

    // If no votes cast
    if (total == 0) {
      lcd.print("No Votes Cast");
      delay(2000);
    } 
    else {
      // Check winner
      if (voteA > voteB && voteA > voteC && voteA > voteD)
        lcd.print("Candidate A Wins");
      else if (voteB > voteA && voteB > voteC && voteB > voteD)
        lcd.print("Candidate B Wins");
      else if (voteC > voteA && voteC > voteB && voteC > voteD)
        lcd.print("Candidate C Wins");
      else if (voteD > voteA && voteD > voteB && voteD > voteC)
        lcd.print("Candidate D Wins");
      else
        lcd.print("Tie / No Result");

      delay(3000);
    }

    // Reset all vote counts after showing result
    voteA = voteB = voteC = voteD = 0;
    lcd.clear();

    // Wait until result button is released
    while (digitalRead(sw5) == LOW);
  }
}
