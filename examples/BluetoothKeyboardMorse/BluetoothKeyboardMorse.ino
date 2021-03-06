
//////////////////////////////////////
//
//BluetoothKeyboardMorse.ino
//
//Developed by Milad Hajihassan
//
//https://github.com/milador/EasyMorseBlue
//
/////////////////////////////////////

#define MY_TEST 1  //Testing mode = 0 , Production mode = 1

#include "EasyMorseBlueHid.h"
#include "EasyMorseBlue.h"
EasyMorseBlue morse;

//Send Key Function to ranslate character to keyboard keycode and transmit


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
  Serial.println("BluetoothKeyboardMorse.ino testing.");
  delay(2000);
}

//Main loop function

void loop() {
  //Type Hello
  
  //H
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  //E
  morse.push(1);
  delay(1000);
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
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
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
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
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
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
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear(); 
  
  //!
  morse.push(1);
  delay(1000);
  morse.push(2);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  morse.push(1);
  delay(1000);
  enterKeyboard(2,morse.getBlueChar()); 
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
  enterKeyboard(morse.getBlueModifier(),morse.getBlueChar()); 
  delay(100);//de-bounce
  clearKeyboard();
  morse.clear();
  
  delay(2000);
}
