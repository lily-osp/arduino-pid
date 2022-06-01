//----------------------------- wall follow  control -------------------------------//
/*
  #################################################### PID CONTROLLER ####################################################
  To be honest, I don't really understand the concept of PID. I'm also still learning about this.
  So I can't write a detailed description of the PID.
  I got the PID formula from : https://create.arduino.cc/projecthub/mjrobot/line-follower-robot-pid-control-android-setup-e5113a
  You can visit the link above to get a more detailed PID explanation.
  I am aware that maybe the application of the results of the PID Calculation in this program code may still have many shortcomings.
*/
void PID( boolean left ) {
  if (left == true ) {
    float errorP = leftSensor - rightSensor - offset ;
    float errorD = errorP - oldErrorP;
    float errorI = (2.0 / 3) * errorI + errorP ;

    totalError = P * errorP + D * errorD + I * errorI ;

    oldErrorP = errorP ;

    RMS = baseSpeed + totalError ;
    LMS = baseSpeed - totalError ;

    //  if(RMS < -255) RMS = -255; if(RMS > 255)RMS = 255 ;
    //  if(LMS < -255) LMS = -255;  if(LMS > 255)LMS = 255 ;

    if (RMS < 0) {
      RMS = map(RMS , 0 , -255, 0, 255);
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(RIGHT);
    }
    else if (LMS < 0) {
      LMS = map(LMS , 0 , -255, 0, 255);
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(LEFT);
    }
    else {
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(FORWARD);
    }
  }
  else {
    float errorP = leftSensor - rightSensor + offset ;
    float errorD = errorP - oldErrorP;
    float errorI = (2.0 / 3) * errorI + errorP ;

    totalError = P * errorP + D * errorD + I * errorI ;

    oldErrorP = errorP ;

    RMS = baseSpeed + totalError ;
    LMS = baseSpeed - totalError ;

    //  if(RMS < -255) RMS = -255; if(RMS > 255)RMS = 255 ;
    //  if(LMS < -255) LMS = -255;  if(LMS > 255)LMS = 255 ;


    if (RMS < 0) {
      RMS = map(RMS , 0 , -255, 0, 255);
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(RIGHT);
    }
    else if (LMS < 0) {
      LMS = map(LMS , 0 , -255, 0, 255);
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(LEFT);
    }
    else {
      analogWrite(enA , RMS);
      analogWrite(enB , LMS);
      setDirection(FORWARD);
    }
  }
}
