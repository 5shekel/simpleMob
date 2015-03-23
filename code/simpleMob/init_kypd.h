
const byte ROWS = 5; //four rows
const byte COLS = 4; //three columns

//i use letters and convert them later to array location -> char-97
// '~' is unused
// keypad will only send last char in array ('c' in 'clear_c')

//terminal 1
char keys[ROWS][COLS] = {
{'~','dwn_n','~','~'}  ,  
{'up_m','~','send_l','clear_k'}  ,  
{'*p','7h','4e','1b'}  ,  
{'0a','8i','5f','2c'}  ,
{'#o','9j','6g','3d'}
};

byte rowPins[ROWS] = {
  10,9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  2,3,4,5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
