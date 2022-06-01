/*                      \\\|///
                      \\  - -  //
                       (  @ @  )
  /--------------------oOOo-(_)-oOOo---------------------\
  |                                                      |
  |                                                      |
  |        line follower robot using PID control         |
  |                                                      |
  |  oleh :                                              |
  |         -saya                                        |
  |         -saya                                        |
  |         -saya                                        |
  |                            Oooo                      |
  \--------------------oooO----(   )---------------------/
                   (   )    ) /
                      \ (    (_/
                       \_)                            */

#include"config.h"
void setup() {
  Serial.begin(115200);
  for (int i = 2; i <= 13; i++) //For Motor Shield
    pinMode(i, OUTPUT);
  first_turn = false ;
  rightWallFollow = false ;
  leftWallFollow = false ;
}

void loop() {
  //========================================START========================================//
  ReadSensors();
  walls();
  if ( first_turn == false ) {
    pid_start();
  }
  else if (leftWallFollow == true ) {
    PID(true) ;
  }
  else if (rightWallFollow == true ) {
    PID(false) ;
  }
  if (leftwall == true && rightwall == false && frontwall == true ) {
    // turnright();
    PID(false) ;
    if ( first_turn == false ) {
      //right_threshold = right_threshold - offset ;
      //left_threshold = left_threshold + offset ;
      first_turn = true ;
      rightWallFollow = true ;
    }
  }
  if (leftwall == false && rightwall == true && frontwall == true ) {
    //  turnleft();
    PID(true) ;
    if ( first_turn == false ) {
      //      left_threshold = left_threshold - offset ;
      //      right_threshold = right_threshold + offset ;
      first_turn = true ;
      leftWallFollow = true ;
    }
  }
  if ( leftSensor == 0 || leftSensor > 100 && rightSensor == 0 || rightSensor > 100 && frontSensor == 0 || frontSensor > 100 ) {
    setDirection(STOP);
  }
  // read sensors & print the result to the serial monitor //
  Serial.print(" Left : ");
  Serial.print(leftSensor);
  Serial.print(" cm ");
  Serial.print(" Right : ");
  Serial.print(rightSensor);
  Serial.print(" cm ");
  Serial.print(" Front : ");
  Serial.print(frontSensor);
  Serial.println(" cm ");
  //measure error & print the result to the serial monitor
  Serial.print("error=");
  Serial.println(totalError);
}