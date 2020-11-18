//ATMN 321 -- Saturday 1:30pm
//Jesse Sapirstein -- N01185396
//FINAL PROJECT --- ARDUINO PROGRAM

#include <avr/wdt.h>
#include <IRremote.h>
#include <Keypad.h>

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the
//row and columns just as appears on the keypad

char keymap[numRows][numCols] =
{
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

//Code that shows the the keypad connections to the arduino terminals

byte rowPins[numRows] = { 48, 47, 44, 43 }; //Rows 0 to 3
byte colPins[numCols] = { 40, 39, 36, 35 }; //Columns 0 to 3

//initializes an instance of the Keypad class

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

//CALL LIBRARIES, DECLARE SUBROUTINES, AND INITIALIZE VARIABLES

int RECV_PIN = 7;
int startPin = 2;
int stopPin = 5;
int limit1Pin = 4;
int limit2Pin = 3;
int motor1 = 8;
int motor2 = 11;
int r = 9;
int y = 10;
int g = 12;
int startPB;
int stopPB;
int limit1;
int limit2;
char keypressed;
int IRcode;
char val;
char state = 'a';
int operatorID;
int partCount;
int boxCount;
int palletCount;
int sensorState;
int lastsensorState;
char currkey;
void checkState();
void ONpin();
void OFFpin();
void cascade();
void flasher();
void checkAll();
void sendVar();
void badID();
void IR();
void goodPart();
void palletFlash();

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  //Set I/O

  Serial.begin(9600);

  irrecv.enableIRIn();

  pinMode(startPin, INPUT_PULLUP);
  pinMode(stopPin, INPUT_PULLUP);
  pinMode(limit1Pin, INPUT_PULLUP);
  pinMode(limit2Pin, INPUT_PULLUP);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop()
{
  //Check for input

  checkAll();

  //Evaluate state logic

  checkState();

  //Print current state to serial

  Serial.println(state);
}
