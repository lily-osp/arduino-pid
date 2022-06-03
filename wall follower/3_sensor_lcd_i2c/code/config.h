#include <NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

//milis
const unsigned long eventInterval = 200;
unsigned long previousTime = 0;

//front | sensor 1
#define TRIGGER_PINF  2  // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PINF     3  // Arduino pin tied to echo pin on ping sensor.

//left  | sensor 2
#define TRIGGER_PINL  A0  // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PINL     A1  // Arduino pin tied to echo pin on ping sensor.

//right | sensor 3
#define TRIGGER_PINR  A2  // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PINR     A3  // Arduino pin tied to echo pin on ping sensor.

#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int dir;

#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

float P = 0.7 ;
float D = 0.5 ;
float I = 0.4 ;
float oldErrorP ;
float totalError ;
int offset = 5 ;

int wall_threshold = 13 ;
//int left_threshold = 10 ;
//int right_threshold = 10 ;
int front_threshold = 7 ;

boolean frontwall ;
boolean leftwall ;
boolean rightwall ;
boolean first_turn ;
boolean rightWallFollow ;
boolean leftWallFollow ;

int en1 = 3 ;
int en2 = 5 ;

int en3 = 6 ;
int en4 = 7 ;

int enA = 9 ;
int enB = 10 ;

int baseSpeed = 70 ;

int RMS ;
int LMS ;

NewPing sonarLeft(TRIGGER_PINL, ECHO_PINL, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonarRight(TRIGGER_PINR, ECHO_PINR, MAX_DISTANCE);
NewPing sonarFront(TRIGGER_PINF, ECHO_PINF, MAX_DISTANCE);

unsigned int pingSpeed = 30; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.

float oldLeftSensor, oldRightSensor, leftSensor, rightSensor, frontSensor, oldFrontSensor, lSensor, rSensor, fSensor;

//int TestNUM = 1  ;
