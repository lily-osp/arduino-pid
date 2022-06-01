//02 sensor multiplexer test
#include "config.h"
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) //output
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }
  pinMode(zInput, INPUT); //Z as an input
  //header:
  Serial.println("Y0\tY1\tY2\tY3\tY4\tY5\tY6\tY7");
  Serial.println("---\t---\t---\t---\t---\t---\t---\t---");
}

void loop()
{
  for (byte pin = 0; pin <= 7; pin++) //Loop through all eight pins/channel.
  {
    selectMuxPin(pin);               //Select one at a time
    int inputValue = analogRead(A0); //read Z
    Serial.print(String(inputValue) + "\t");
  }
  Serial.println();
  delay(1000);
}
/*
  The selectMuxPin function sets the S0, S1, and S2 pins
  accordingly, given a pin from 0-7.
*/
void selectMuxPin(byte pin)
{
  for (int i = 0; i < 3; i++)
  {
    if (pin & (1 << i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}
