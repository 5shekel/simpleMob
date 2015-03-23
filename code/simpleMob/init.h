//init code

// pin 5 - Serial clock out (SCLK)
// pin 4 - Serial data out (DIN)
// pin 3 - Data/Command select (D/C)
// pin 2 - LCD reset (RST) 

#define DEBOUNCE 50
#define KEY_TIME 1000  // time until letter is set
#define SLOW_DEL 1000  // time to keep c key pressed until starintg fast del
#define FAST_DEL 100   // time betwin del to del in continuous del
#define TEXT_LINES 3

#define KEY1_PIN 8
#define KEY2_PIN 7
#define KEY3_PIN 6
#define KEY4_PIN 12
#define KEY5_PIN 15
#define KEY6_PIN 17
#define KEY7_PIN 11
#define KEY8_PIN 14
#define KEY9_PIN 16
#define KEY0_PIN 13
#define KEYC_PIN 10
#define KEYSND_PIN 9
#define KEYUP_PIN 18
#define KEYDOWN_PIN 19
//#define KEYSTR_PIN   // *
//#define KEYNUM_PIN   // #

#define DEL_KEY  10
#define SND_KEY  11
#define UP_KEY   12
#define DOWN_KEY 13
#define STAR_KEY 14
#define NUM_KEY  15
#define NO_KEY   99

#define TEXT_MAX_LENGTH TEXT_LINES*14

#define NO_LETTER 255


#define IDLE 0
#define KEY_PRESSED 1
#define TEMP_ADD 2

byte lang;
byte letterCounter=0; // counter
byte keyPsd = NO_KEY;
byte pKeyPsd;
char hText[TEXT_LINES][15];
char eText[TEXT_MAX_LENGTH+1];
byte tempLetter;
unsigned long keyTimer;
byte state = IDLE;



/*
byte keyPins[] = {
  KEY0_PIN, 
  KEY1_PIN, 
  KEY2_PIN, 
  KEY3_PIN,
  KEY4_PIN, 
  KEY5_PIN, 
  KEY6_PIN, 
  KEY7_PIN, 
  KEY8_PIN, 
  KEY9_PIN, 
  KEYC_PIN, 
  KEYSND_PIN, 
  KEYUP_PIN,
  KEYDOWN_PIN,
  //  KEYSTR_PIN, 
  //  KEYNUM_PIN, 
};
*/
