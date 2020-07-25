
//////////////////////////////////////he
//
//SimpleKeyboardMorse.ino
//
//Developed by Milad Hajihassan
//
//https://github.com/milador/EasyMorseBlue
//
/////////////////////////////////////

#include "EasyMorseBlueHid.h"
#include "EasyMorseBlue.h"

EasyMorseBlue morse;

//Setup function

void setup() {
  //Initialize serial communications at 9600 bps
  Serial.begin(9600);
  morse.clear();
  initializeHidMorse("EasyMorse Keyboard");
  initialization();
}



//Initialization function

void initialization() {
  delay(500);

  //Initialization start message
  Serial.println("SimpleKeyboardMorse.ino testing.");
  delay(2000);
}

//Main loop function

void loop() {

  //H
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  //E
  morse.push(1);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  //L
  morse.push(1);
  delay(1000);
  morse.push(2);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
    
  //L
  morse.push(1);
  delay(1000);
  morse.push(2);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  //O
  morse.push(2);
  delay(1000);
  morse.push(2);
  delay(1000);
  morse.push(2);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  //Space
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(2);
  delay(1000);
  morse.push(2);
  delay(1000);
  enterKeyboardChar(morse.getChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();

  delay(2000);
}
