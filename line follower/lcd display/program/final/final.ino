#include "config.h"

void setup() {

  lcd.init();
  lcd.backlight();
  delay(50);
  lcd.setCursor(0, 0);
  lcd.print(" line Follower");
  lcd.setCursor(0, 1);
  lcd.print(" -Kelompok 01-");
  delay(3000);
  lcd.clear();

  //----------------------------------------Set up the select pins as outputs:
  for (int i = 0; i < 3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }
  //----------------------------------------

  //----------------------------------------Buttons PIN as input
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  updateMenu();
  //----------------------------------------

  //----------------------------------------Motor PIN as output
  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);
  //----------------------------------------
}

void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(100);
    while (!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)) {
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }
}
