//03 Test OLED and Buttons
#include "config.h"

void setup(void)
{
  pinMode(Button_Pin_1, INPUT_PULLUP);
  pinMode(Button_Pin_2, INPUT_PULLUP);
  pinMode(Button_Pin_3, INPUT_PULLUP);
}

void loop(void)
{
  // picture loop (Loop for display on OLED)
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(500);
}
