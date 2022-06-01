//01 Test Driver L298N
#include "config.h"

void setup() {
  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);
}

void loop() {
  //Forward Motor Rotation Direction
  PWM_Val = 70; //max value 255
  digitalWrite(Motor_L, LOW);
  analogWrite(Motor_L_PWM, PWM_Val);
  digitalWrite(Motor_R, LOW);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(2000);

  //Backward Motor Rotation Direction
  PWM_Val = 70; //max value 255
  digitalWrite(Motor_L, HIGH);
  analogWrite(Motor_L_PWM, PWM_Val);
  digitalWrite(Motor_R, HIGH);
  analogWrite(Motor_R_PWM, PWM_Val);
  delay(2000);
}
