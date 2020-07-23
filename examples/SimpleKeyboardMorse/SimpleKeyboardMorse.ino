
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

#include "EasyMorseBlueHid.h"
#include "EasyMorseBlue.h"

EasyMorseBlue morse;

//Setup function

void setup() {
  //Initialize serial communications at 9600 bps
  Serial.begin(9600);
  morse.clear();
  initializeKeyboard("EasyMorse Keyboard");
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
    
    delay(50);
  }

  delay(2000);
}
