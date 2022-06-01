//--------------------------------- control ---------------------------------//

void pid_start() {

  float errorP = leftSensor - rightSensor ;
  float errorD = errorP - oldErrorP;
  float errorI = (2.0 / 3.0) * errorI + errorP ;

  totalError = P * errorP + D * errorD + I * errorI ;
  oldErrorP = errorP ;
  RMS = baseSpeed + totalError ;
  LMS = baseSpeed - totalError ;

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