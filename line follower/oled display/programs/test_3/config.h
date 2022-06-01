#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI | Initialize u8g

#define Button_Pin_1 5
#define Button_Pin_2 6
#define Button_Pin_3 7

bool Button_1;
bool Button_2;
bool Button_3;
