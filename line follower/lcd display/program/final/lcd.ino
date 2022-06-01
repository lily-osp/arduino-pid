//========================================================================
// Subroutines to update menu
void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">motor check ");
      lcd.setCursor(0, 1);
      lcd.print(" sensor check");
      break;
    case 2:
      lcd.clear();
      lcd.print(" motor check ");
      lcd.setCursor(0, 1);
      lcd.print(">sensor check");
      break;
    case 3:
      lcd.clear();
      lcd.print(">robot start ");
      lcd.setCursor(0, 1);
      lcd.print("             ");
      break;
    case 4:
      menu = 3;
      break;
  }
}
//========================================================================

//========================================================================
// Subroutines to execute an action
void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
  }
}

//========================================================================
// Subroutines for action
void action1() {
  lcd.clear();
  lcd.print("motor check");
  motor_check();
}
void action2() {
  lcd.clear();
  lcd.print("calibration");
  check_Sensor();
  delay(15000);
  lcd.clear();
  lcd.print("  CALIBRATION");
  lcd.setCursor(0, 1);
  lcd.print("  IS COMPLETE");
  delay(1500);
}
void action3() {
  start_robot();
  delay(300000);
}
//=========================================================================
