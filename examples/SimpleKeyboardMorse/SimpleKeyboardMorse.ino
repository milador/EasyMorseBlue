
//////////////////////////////////////
//
//SimpleKeyboardMorse.ino
//
//Developed by Milad Hajihassan
//
//https://github.com/milador/EasyMorseBlue
//
/////////////////////////////////////

#define MY_DEBUG 1
#define MY_TEST 1  //Testing mode = 0 , Production mode = 1
#define FACTORYRESET_ENABLE 0

#include "BluefruitRoutines.h"
#include "EasyMorseBlue.h"

EasyMorseBlue morse;

//Send Key Function to ranslate character to keyboard keycode and transmit

void sendKey(char charachter) {
  ble.print("AT+BleKeyboard=");
  ble.println(charachter);
}

//Setup function

void setup() {
  //Initialize serial communications at 9600 bps
  Serial.begin(9600);
  morse.clear();
  initializeBluefruit();
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
    
  //Testing mode
  if(MY_TEST==0){
    //Print Hello

    //H
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    Serial.print(morse.getChar()); 
    morse.clear();
    
    //E
    morse.push(1);
    delay(1000);
    Serial.print(morse.getChar()); 
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
    Serial.print(morse.getChar()); 
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
    Serial.print(morse.getChar()); 
    morse.clear();
  
    //O
    morse.push(2);
    delay(1000);
    morse.push(2);
    delay(1000);
    morse.push(2);
    delay(1000);
    Serial.print(morse.getChar()); 
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
    Serial.print(morse.getChar()); 
    morse.clear();

    delay(50);
  }
  //Production mode
  else 
  {
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
    sendKey(morse.getChar()); 
    morse.clear();
    
    //E
    morse.push(1);
    delay(1000);
    sendKey(morse.getChar()); 
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
    sendKey(morse.getChar()); 
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
    sendKey(morse.getChar()); 
    morse.clear();
  
    //O
    morse.push(2);
    delay(1000);
    morse.push(2);
    delay(1000);
    morse.push(2);
    delay(1000);
    sendKey(morse.getChar()); 
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
    sendKey(morse.getChar()); 
    
    morse.clear();
    delay(50);
  }
  delay(2000);
}
