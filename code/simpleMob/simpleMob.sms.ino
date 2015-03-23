
//an atempt to replicate old phone hardware/software
//more at github.com/5shekel


//library used 
#include "PCD8544.h"//consider replace with modern lib for LCD
#include "Keypad.h"


#include "init.h"  //initliazers
#include "init_kypd.h"  //initliazers
#include "drawing.h" // some graphics
#include "letterSwitch.h" //pre keypad 3key swithcer

PCD8544 lcd = PCD8544(14,11,12,13);
#define DEBUG 0

void setup() {
  Serial.begin (57600);
  lcd.init(55);
  /*
  for (int i=0; i<sizeof(keyPins); i++) {
   pinMode      (keyPins[i], OUTPUT);  
   digitalWrite (keyPins[i], HIGH);
   pinMode      (keyPins[i], INPUT);
   }
   */
  setLanguage (ENGLISH);
  drawArrows();
  lcd.display();
}

void loop() {

  switch (state) {
  case IDLE:
    //    if ((millis()/500)%2==0) drawCursor(true);
    //    else drawCursor(false);
    recieveText();
    keyPsd = getPressedKey();
    if (keyPsd != NO_KEY) {
      if(DEBUG) Serial.println("got key");
      delay (DEBOUNCE);
      state = KEY_PRESSED;
      tempLetter = NO_LETTER;
    }
    break;

  case KEY_PRESSED:
    if(DEBUG) Serial.println("key pressed");
    switch (keyPsd) {

    case SND_KEY:
      if(DEBUG) Serial.println("sent send");
      sendText();
      setLanguage (lang);
      while (keyPsd == getPressedKey());
      delay (DEBOUNCE);
      state = IDLE;
      break;

    case UP_KEY:
      if(lang == ENGLISH) 
        setLanguage (HEBREW);
      else setLanguage (ENGLISH);
      
      while (keyPsd == getPressedKey());
      delay (DEBOUNCE);
      state = IDLE;
      break;

    case DOWN_KEY:
      setLanguage (ENGLISH);
      while (keyPsd == getPressedKey());
      delay (DEBOUNCE);
      state = IDLE;
      break;

    case DEL_KEY:
      delLetter();
      keyTimer = millis();
      while (keyPsd == getPressedKey()) {
        if (millis()-keyTimer > SLOW_DEL) {
          delLetter();
          keyTimer = millis();
          break;
        }
      }
      while (keyPsd == getPressedKey()) {
        if (millis()-keyTimer > FAST_DEL) {
          delLetter();
          keyTimer = millis();
        }
      }
      delay (DEBOUNCE);
      state = IDLE;
      break;

    default: 
      tempLetter = nextTempLetter(keyPsd);
      showTempLetter();
      while (keyPsd == getPressedKey());
      delay (DEBOUNCE);
      pKeyPsd = keyPsd;
      keyTimer = millis();
      state = TEMP_ADD;
      break;
    }
    break;

  case TEMP_ADD:

    keyPsd = getPressedKey();
    if (keyPsd != NO_KEY) {
      if(DEBUG) Serial.println("temp add");
      delay (DEBOUNCE);
      if (keyPsd != pKeyPsd) {
        addTempLetter(tempLetter);
        tempLetter = NO_LETTER;
      }
      state = KEY_PRESSED;
    } 
    else if (millis() - keyTimer > KEY_TIME) {
      addTempLetter(tempLetter);
      state = IDLE;
    }
    break;
  }

}


byte getPressedKey() {
  char key = keypad.getKey();
  if (key){
    if(DEBUG) Serial.println(key);
    if(DEBUG) Serial.println(byte(key)-97);
    return byte(key)-97;

  }
  else{ 
    return NO_KEY;
  }
}


/*
byte getPressedKey() {
 byte k=0;
 while (k<sizeof(keyPins)) {
 if (digitalRead (keyPins[k]) == LOW) break;
 k++;
 }
 if (k==sizeof(keyPins)) return NO_KEY;
 else return k;
 }
 */

void drawArrows() {
  lcd.drawbitmap (71, 30, arrows_bmp, 13, 18, BLACK);
}

void drawSend() {
  if (lang == HEBREW)
    lcd.drawbitmap (30, 40, hsend_bmp, 23, 8, BLACK);
  else if (lang == ENGLISH)
    lcd.drawbitmap (30, 40, esend_bmp, 23, 8, BLACK);
}

void drawOK() {
  if (lang == HEBREW)
    lcd.drawbitmap (30, 40, hok_bmp, 23, 8, BLACK);
  else if (lang == ENGLISH)
    lcd.drawbitmap (30, 40, eok_bmp, 23, 8, BLACK);
}

void drawCursor(boolean col) {
  if (state == IDLE) {
    int x, y;
    x=(letterCounter%14)*6;
    y=(letterCounter/14)*8;
    if (lang == HEBREW)
      x = 81-x;
    if (col)
      lcd.drawrect (x, y, 2, 8, BLACK);
    else
      lcd.drawrect (x, y, 2, 8, WHITE);
    lcd.display();
  }
}


void showTempLetter () {
  if (letterCounter < TEXT_MAX_LENGTH-1) {
    int x, y;
    x=(letterCounter%14)*6;
    if (lang == HEBREW)
      x = 78-x;
    y=(letterCounter/14)*8;
    lcd.drawchar (x,y,tempLetter);
    lcd.display();
  }
}

void addTempLetter (byte l) {
  if (letterCounter < TEXT_MAX_LENGTH-1) {
    if (lang == HEBREW)
      hText[letterCounter/14][letterCounter%14] = tempLetter;
    else
      eText[letterCounter] = tempLetter;
    letterCounter++;
    showText();
  }
}

void delLetter () {
  if (letterCounter > 0) letterCounter--;
  if (lang == HEBREW)
    hText[letterCounter/14][letterCounter%14] = 0x20;
  else
    eText[letterCounter] = 0x20;
  showText();
}

void showText () {
  if (lang == HEBREW)
    lcd.drawstring (78,0, *hText);
  else
    lcd.drawstring (0,0, eText);
  lcd.display();
}

void setLanguage (byte l) {
  lcd.setLanguage (l);
  lang = l;
  if (l == HEBREW) {
    for (int l=0; l<TEXT_LINES; l++) {
      for (int i=0; i< 14; i++)
        hText[l][i]=0x20;
      hText[l][14] = 0x0a;
    }
    hText[TEXT_LINES-1][14] = 0x00;
  } 
  else {
    for (int i=0; i<TEXT_MAX_LENGTH; i++) {
      eText[i]=0x20;
      eText[TEXT_MAX_LENGTH] = 0x00;
    }
  }
  letterCounter = 0;
  drawSend();
  showText();
}

void sendText() {
  if(DEBUG) Serial.print("send");
  if (lang == HEBREW) {
    Serial.write ('h');
    for (int i=0; i<TEXT_LINES; i++)
      for (int j=0; j<15; j++)
        Serial.write (hText[i][j]);
  } 
  else {
    Serial.write ('e');
    for (int i=0; i<sizeof (eText); i++)
      Serial.write (eText[i]);
  }
}

void recieveText() {
  if (Serial.available() > 0) {
    lcd.clear();
    byte lan = Serial.read();
    if (lan == 'h') {
      char hebText[TEXT_LINES][15];
      for (int i=0; i<TEXT_LINES; i++)
        for (int j=0; j<15; j++) {
          while (Serial.available() == 0);
          hebText[i][j] = Serial.read();
        }
      lcd.setLanguage (HEBREW);
      lcd.drawstring (78,0, *hebText);

    } 
    else {
      char enText[TEXT_MAX_LENGTH+1];
      for (int i=0; i<sizeof (eText); i++) {
        while (Serial.available() == 0);
        enText[i] = Serial.read();
      }
      lcd.setLanguage (ENGLISH);
      lcd.drawstring (0,0, enText);

    }
    drawOK();
    lcd.display();
    while (getPressedKey() != SND_KEY);
    delay (DEBOUNCE);
    while (getPressedKey() == SND_KEY);
    delay (DEBOUNCE);
    // Serial.flush(); //broken on ard 1.0
    while (Serial.available()) Serial.read();
    lcd.setLanguage (lang);
    showText();
    drawSend();
    drawArrows();
    lcd.display();
  }
}






