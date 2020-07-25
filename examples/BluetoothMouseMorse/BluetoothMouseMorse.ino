
//////////////////////////////////////
//
//BluetoothMouseMorse.ino
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
int* mouseAct;
//Send Key Function to ranslate character to keyboard keycode and transmit


//Setup function

void setup() {
  //Initialize serial communications at 9600 bps
  Serial.begin(9600);
  morse.clear();
  initializeHidMorse("EasyMorse Mouse");
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
    
    //Right
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    mouseAct=morse.getMouse();
    enterMouse(mouseAct[0],mouseAct[1],mouseAct[2]); 
    delay(50);
    clearMouse();
    
    
    /*
    //Right Click
    morse.push(1);
    delay(1000);
    morse.push(2);
    delay(1000);

    mouseAct=morse.getMouse();
    enterMouse(mouseAct[0],mouseAct[1],mouseAct[2]); 
    delay(50);
    clearMouse();
    */
    morse.clear();
    delay(3000);
}
