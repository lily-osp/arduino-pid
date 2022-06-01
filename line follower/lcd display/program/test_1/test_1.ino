#include "config.h"

void setup() {
  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);
}

void loop() {
  PWM_Val = 70; //max 255
  digitalWrite(Motor_L, LOW);
  analogWrite(Motor_L_PWM, PWM_Val);
  delay(100);
  digitalWrite(Motor_R, LOW);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(1000);
  PWM_Val = 70; //max 255
  digitalWrite(Motor_L, HIGH);
  analogWrite(Motor_L_PWM, PWM_Val);
  delay(100);
  digitalWrite(Motor_R, HIGH);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(1000);
}
