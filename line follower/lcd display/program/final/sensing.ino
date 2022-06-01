//========================================================================
// Subroutines to get error values for several conditions
void check_Error() {
  check_Sensor(); //--> Calling the check_Sensor () subroutine

  //----------------------------------------Filling the error value
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
  //----------------------------------------
}
//========================================================================

//========================================================================
// Subroutines to check sensors based on the calibration result value (ResultRef)
void check_Sensor() {
  read_Sensor(); //-->
  //----------------------------------------Specifies a bit_Sensor array for HIGH or LOW
  for (byte i = 0; i <= 7; i++) {
    if (Sensor_ADC_0[i] > ResultRef[i]) {
      bit_Sensor[i] = HIGH;
    } else {
      bit_Sensor[i] = LOW;
    }
  }
  //----------------------------------------

  //----------------------------------------inserting the bit_Sensor array into the bin_Sensor binary
  for (byte i = 0; i <= 7; i++) {
    bitWrite(bin_Sensor, i, bit_Sensor[7 - i]);
  }
  //----------------------------------------
}
//========================================================================

//========================================================================
// Subroutines to read sensor values in the form of ADC values
void read_Sensor() {
  for (byte pin = 0; pin <= 7; pin++) {
    selectMultiplexerPin(pin); //--> Select one at a time
    Sensor_ADC_0[pin] = analogRead(A0); //--> and read Z
  }
}
//========================================================================

//========================================================================
// Subroutines to determine which pins or channels to read from the 4051 multiplexer
void selectMultiplexerPin(byte pin) {
  for (int i = 0; i < 3; i++) {
    if (pin & (1 << i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
//========================================================================

//========================================================================
// Subroutine for displaying sensors in binary form on an Display
void printBinaryByte(byte value)  {
  for (byte mask = 0x80; mask; mask >>= 1)  {
    lcd.setCursor(0, 1);
    lcd.print((mask & value) ? '1' : '0');
  }
}
//========================================================================
