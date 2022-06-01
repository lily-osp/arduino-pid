//========================================================================
// Subroutines to start the robot
void start_robot() {
  /*
    #################################################### PID CONTROLLER ####################################################
    To be honest, I don't really understand the concept of PID. I'm also still learning about this.
    So I can't write a detailed description of the PID.
    I got the PID formula from : https://create.arduino.cc/projecthub/mjrobot/line-follower-robot-pid-control-android-setup-e5113a
    You can visit the link above to get a more detailed PID explanation.
    I am aware that maybe the application of the results of the PID Calculation in this program code may still have many shortcomings.
  */

  lcd.clear();
  lcd.print("  robot started");
  
  int PWM_Max_R = PWM_Speed;
  int PWM_Max_L = PWM_Speed;

  check_Error(); //--> Call the check_Error () subroutine to get an Error value.

  //PID calculations
  int P = error;
  int I = I + error;
  int D = error - last_error;
  int PID = (Kp * P) + (Ki * I) + (Kd * D);

  //Applying the result of PID calculation to the driving motors.
  int PWM_R = PWM_Max_R - PID;
  int PWM_L = PWM_Max_L + PID;
  PWM_R = PWM_R - PID;
  PWM_L = PWM_L + PID;

  last_error = error;

  if (PWM_R >= 0) {
    right_Forward();
  } else {
    right_Backward();
  }

  if (PWM_L >= 0) {
    left_Forward();
  } else {
    left_Backward();
  }

  if (PWM_R < 0) PWM_R = 0 - PWM_R;
  if (PWM_L < 0) PWM_L = 0 - PWM_L;
  if (PWM_R > 255) PWM_R = 255;
  if (PWM_L > 255) PWM_L = 255;

  if (digitalRead(Motor_R) == LOW) {
    PWM_R = abs(PWM_R);
  } else {
    PWM_R = 255 - PWM_R;
  }

  if (digitalRead(Motor_L) == LOW) {
    PWM_L = abs(PWM_L);
  } else {
    PWM_L = 255 - PWM_L;
  }

  analogWrite(Motor_R_PWM, PWM_R);
  analogWrite(Motor_L_PWM, PWM_L);
}
//========================================================================
