#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI | Initialize u8g

//button
#define Button_Pin_1 5
#define Button_Pin_2 6
#define Button_Pin_3 7

//Variable for line sensors with multiplexer 4051
int Sensor_ADC_0[8];
bool bit_Sensor[8];
byte bin_Sensor = 0b00000000;

//Reference variable for the line sensor in order to determine the white and black lines or colors
int HighRef[8];
int LowRef[8];
int ResultRef[8];

//PIN declaration for the 4051 multiplexer
const int selectPins[3] = {2, 3, 4}; // S0->2, S1->3, S2->4
const int zInput = A0;               //--> Connect common (Z) to A0 (analog input)

//Variable for Menu or Mode
bool calibration_mode = false;
bool sensor_check_mode = false;
bool start_mode = false;

int calibration_process = 1; //--> Variable for the sequence of the calibration process

//Variable PIN for the L298N motor driver
int Motor_L = 11;     //--> D11->IN4 (To adjust the direction of the left motor rotation)
int Motor_L_PWM = 10; //--> D10->IN3 (To set the left motor PWM value)
int Motor_R_PWM = 9;  //--> D9 ->IN2 (To set the right motor PWM value)
int Motor_R = 8;      //--> D8 ->IN1 (To adjust the direction of the right motor rotation)

int PWM_Speed = 200; //--> Variable for the PWM value

//----------------------------------------Configuration variables for KP, KI and KD values
/*Actually there are several methods to determine the value of KP, KI and KD. You can find it on the internet.
  Motor speed, distance between sensor and motor, distance between right motor and left motor and others are some things that can be taken into account in determining the values of KP, KI and KD in line follower robots.
  My way to determine the value of KP, KI and KD is by manual or "Trial and Error".*/
int Kp = 10;
int Ki = 2;
int Kd = 100;

int error, last_error; //--> Variable to hold error value of the line sensor
