
// Subroutines for reading the conditions of the buttons
bool button(int btn_num) {
  bool Button_Result;
  if (btn_num == 1) Button_Result = digitalRead(Button_Pin_1);
  if (btn_num == 2) Button_Result = digitalRead(Button_Pin_2);
  if (btn_num == 3) Button_Result = digitalRead(Button_Pin_3);
  return Button_Result;
}

// Subroutines to get error values for several conditions
void check_Error() {
  check_Sensor(); //--> Calling the check_Sensor () subroutine

  //Filling the error value
  if (bin_Sensor == 0b00000001) error = 13;
  if (bin_Sensor == 0b00000011) error = 11;
  if (bin_Sensor == 0b00000010) error = 9;
  if (bin_Sensor == 0b00000110) error = 7;
  if (bin_Sensor == 0b00000100) error = 5;
  if (bin_Sensor == 0b00001100) error = 3;
  if (bin_Sensor == 0b00001000) error = 1;
  if (bin_Sensor == 0b00011000) error = 0;
  if (bin_Sensor == 0b00010000) error = -1;
  if (bin_Sensor == 0b00110000) error = -3;
  if (bin_Sensor == 0b00100000) error = -5;
  if (bin_Sensor == 0b01100000) error = -7;
  if (bin_Sensor == 0b01000000) error = -9;
  if (bin_Sensor == 0b11000000) error = -11;
  if (bin_Sensor == 0b10000000) error = -13;
}

// Subroutine to make the right motor move forward
void right_Forward() {
  digitalWrite(Motor_R, LOW);
}

// Subroutine to make the right motor move backward
void right_Backward() {
  digitalWrite(Motor_R, HIGH);
}

// Subroutine to make the left motor move forward
void left_Forward() {
  digitalWrite(Motor_L, LOW);
}

// Subroutine to make the left motor move backward
void left_Backward() {
  digitalWrite(Motor_L, HIGH);
}

// Subroutines for the calibration process
void calibration() {
  //----------------------------------------Configuration and initial display of the calibration process
  calibration_process = 1;

  u8g.firstPage();
  do {
    u8g.setPrintPos(20, 29);
    u8g.print("CALIBRATION");
    u8g.setPrintPos(0, 59);
    u8g.print("1. Done");
  } while ( u8g.nextPage() );

  for (byte i = 0; i <= 7; i++) {
    HighRef[i] = 0;
    LowRef[i] = 1023;
  }

  while (calibration_mode == true) {
    if (button(1) == LOW) {
      calibration_process++;
      while (button(1) == LOW) {
        delay(100);
      }
    }

    //Conditions to get the highest and lowest reference value of the line
    if (calibration_process == 1) {
      read_Sensor();
      for (byte i = 0; i <= 7; i++) {
        if (Sensor_ADC_0[i] > HighRef[i]) HighRef[i] = Sensor_ADC_0[i];
        if (Sensor_ADC_0[i] < LowRef[i]) LowRef[i] = Sensor_ADC_0[i];
      }
    }

    //Conditions for obtaining the reference result value
    if (calibration_process == 2) {
      for (byte i = 0; i <= 7; i++) {
        ResultRef[i] = HighRef[i] + LowRef[i];
        ResultRef[i] = ResultRef[i] / 2;
      }

      u8g.firstPage();
      do {
        u8g.setPrintPos(20, 29);
        u8g.print("CALIBRATION");
        u8g.setPrintPos(20, 44);
        u8g.print("IS COMPLETE");
      } while ( u8g.nextPage() );

      delay(1000);

      calibration_process = 3;
    }

    //Conditions for checking sensors based on the results of the calibration
    if (calibration_process == 3) {
      check_Sensor();
      u8g.firstPage();
      do {
        u8g.setPrintPos(16, 14);
        u8g.print("CHECK SENSOR");
        u8g.setPrintPos(33, 29);
        printBinaryByte(bin_Sensor);
        u8g.setPrintPos(0, 59);
        u8g.print("1. BACK");
      } while ( u8g.nextPage() );
      delay(10);
    }

    //Conditions for returning to the void loop (calibration process is complete)
    if (calibration_process == 4) {
      calibration_mode == false;
      return;
    }
  }
}

// Subroutines to check sensors based on the calibration result value (ResultRef)
void check_Sensor() {
  read_Sensor(); //-->

  //Specifies a bit_Sensor array for HIGH or LOW
  for (byte i = 0; i <= 7; i++) {
    if (Sensor_ADC_0[i] > ResultRef[i]) {
      bit_Sensor[i] = HIGH;
    } else {
      bit_Sensor[i] = LOW;
    }
  }

  //inserting the bit_Sensor array into the bin_Sensor binary
  for (byte i = 0; i <= 7; i++) {
    bitWrite(bin_Sensor, i, bit_Sensor[7 - i]);
  }
}

// Subroutines to read sensor values in the form of ADC values
void read_Sensor() {
  for (byte pin = 0; pin <= 7; pin++) {
    selectMultiplexerPin(pin); //--> Select one at a time
    Sensor_ADC_0[pin] = analogRead(A0); //--> and read Z
  }
}

// Subroutines to determine which pins or channels to read from the 4051 multiplexer
void selectMultiplexerPin(byte pin) {
  for (int i = 0; i < 3; i++) {
    if (pin & (1 << i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}

// Subroutine for displaying sensors in binary form on an OLED Display
void printBinaryByte(byte value)  {
  for (byte mask = 0x80; mask; mask >>= 1)  {
    u8g.print((mask & value) ? '1' : '0');
  }
}
