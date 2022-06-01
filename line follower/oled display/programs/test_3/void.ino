void draw(void)
{
  // graphic commands to redraw the complete screen should be placed here
  u8g.setFont(u8g_font_unifont);

  u8g.setPrintPos(0, 10);
  u8g.print("OLED 128x64");

  Button_1 = digitalRead(Button_Pin_1);
  Button_2 = digitalRead(Button_Pin_2);
  Button_3 = digitalRead(Button_Pin_3);

  if (Button_1 == LOW) {
    u8g.setPrintPos(0, 25);
    u8g.print("Button1 Press");
  } else {
    u8g.setPrintPos(0, 25);
    u8g.print("Button1 UnPress");
  }

  if (Button_2 == LOW) {
    u8g.setPrintPos(0, 40);
    u8g.print("Button2 Press");
  } else {
    u8g.setPrintPos(0, 40);
    u8g.print("Button2 UnPress");
  }

  if (Button_3 == LOW) {
    u8g.setPrintPos(0, 55);
    u8g.print("Button3 Press");
  } else {
    u8g.setPrintPos(0, 55);
    u8g.print("Button3 UnPress");
  }
}
