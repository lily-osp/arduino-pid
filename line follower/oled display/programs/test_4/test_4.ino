//04 Arduino Line Follower with PID
#include "config.h"

void setup() {
  //Set up the select pins as outputs:
  for (int i = 0; i < 3; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }

  //----------------------------------------Buttons PIN as input
  pinMode(Button_Pin_1, INPUT_PULLUP);
  pinMode(Button_Pin_2, INPUT_PULLUP);
  pinMode(Button_Pin_3, INPUT_PULLUP);

  //----------------------------------------Motor PIN as output
  pinMode(Motor_L, OUTPUT);
  pinMode(Motor_R, OUTPUT);

  u8g.setFont(u8g_font_unifont); //--> Sets the font for the OLED display

  //----------------------------------------Initial display on OLED
  u8g.firstPage();
  do {
    //u8g.drawFrame(0, 0, 128, 64);
    u8g.setPrintPos(12, 14);
    u8g.print("LINE FOLLOWER");
    u8g.setPrintPos(43, 29);
    u8g.print("ROBOT");
    u8g.setPrintPos(55, 44);
    u8g.print("BY");
    u8g.setPrintPos(33, 59);
    u8g.print("OUR TEAM");
  } while ( u8g.nextPage() );

  delay(1000);
}

void loop() {

  //MENU Display on OLED Display
  if (start_mode == false) {
    u8g.firstPage();
    do {
      u8g.setPrintPos(45, 14);
      u8g.print("MENU");
      u8g.setPrintPos(0, 29);
      u8g.print("1. CALIBRATION");
      u8g.setPrintPos(0, 44);
      u8g.print("2. CHECK SENSOR");
      u8g.setPrintPos(0, 59);
      u8g.print("3. START");
    } while ( u8g.nextPage() );
  }

  //Conditions to start the line sensor calibration process
  if (button(1) == LOW && start_mode == false) {
    calibration_mode = true;
    while (button(1) == LOW) {
      delay(100);
    }
    calibration(); //--> Go to the calibration subroutine
  }

  //Conditions for checking line sensors and displaying on OLED Display
  if (button(2) == LOW && start_mode == false) {
    sensor_check_mode = true;
    while (button(2) == LOW) {
      delay(100);
    }

    while (sensor_check_mode == true) {
      check_Sensor(); //--> Go to the check sensor subroutine

      u8g.firstPage();
      do {
        u8g.setPrintPos(16, 14);
        u8g.print("CHECK SENSOR");
        u8g.setPrintPos(33, 29);
        printBinaryByte(bin_Sensor);
        u8g.setPrintPos(0, 59);
        u8g.print("1. BACK");
      } while ( u8g.nextPage() );

      if (button(1) == LOW) {
        sensor_check_mode = false;
        while (button(1) == LOW) {
          delay(100);
        }
      }
      delay(10);
    }
  }

  //Conditions for stopping and starting the robot to follow the line
  if (button(3) == LOW) {
    start_mode = !start_mode;
    while (button(3) == LOW) {
      delay(100);
    }
    if (start_mode == true) {
      u8g.firstPage();
      do {
        u8g.setPrintPos(40, 29);
        u8g.print("START");
        u8g.setPrintPos(0, 59);
        u8g.print("3. STOP");
      } while ( u8g.nextPage() );
    }
  }
  /*
    #################################################### PID CONTROLLER ####################################################
    To be honest, I don't really understand the concept of PID. I'm also still learning about this.
    So I can't write a detailed description of the PID.
    I got the PID formula from : https://create.arduino.cc/projecthub/mjrobot/line-follower-robot-pid-control-android-setup-e5113a
    You can visit the link above to get a more detailed PID explanation.
    I am aware that maybe the application of the results of the PID Calculation in this program code may still have many shortcomings.
  */
  if (start_mode == true) {
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
}
