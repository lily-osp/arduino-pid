//========================================================================
// Subroutines to check motor
void motor_check() {
  lcd.clear();
  lcd.print("  MOTOR CHECK");
  lcd.setCursor(0, 1);
  lcd.print("     RIGHT");
  PWM_Val = 70; //max 255
  digitalWrite(Motor_L, LOW);
  analogWrite(Motor_L_PWM, PWM_Val);
  delay(100);
  digitalWrite(Motor_R, LOW);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(1000);
  lcd.clear();
  lcd.print("  MOTOR CHECK");
  lcd.setCursor(0, 1);
  lcd.print("     LEFT");
  PWM_Val = 70; //max 255
  digitalWrite(Motor_L, HIGH);
  analogWrite(Motor_L_PWM, PWM_Val);
  delay(100);
  digitalWrite(Motor_R, HIGH);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(1000);
}
//========================================================================

//========================================================================
// Subroutine to make the right motor move forward
void right_Forward() {
  digitalWrite(Motor_R, LOW);
}
//========================================================================

//========================================================================
// Subroutine to make the right motor move backward
void right_Backward() {
  digitalWrite(Motor_R, HIGH);
}
//========================================================================

//========================================================================
// Subroutine to make the left motor move forward
void left_Forward() {
  digitalWrite(Motor_L, LOW);
}
//========================================================================

//========================================================================
// Subroutine to make the left motor move backward
void left_Backward() {
  digitalWrite(Motor_L, HIGH);
}
//========================================================================
