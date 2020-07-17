
//////////////////////////////////////
//
//BluetoothMouseMorse.ino
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
int* mouseAct;
//Send Key Function to ranslate character to keyboard keycode and transmit



//***PERFORM MOUSE ACTIONS FUNCTION***//

void mouseAction(int button,int xValue,int yValue) {

  /*
    switch (button) {
      case 0:
        break;
      case 1:
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("L"); 
        break;
      case 2:
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("R"); 
        break;
      case 3:
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("L,doubleclick"); 
        break;        
      case 4:
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("R,doubleclick"); 
        break;
      case 5:             
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("L,hold,200"); 
        break;
      case 6:
        ble.print(F("AT+BLEHIDMOUSEBUTTON="));
        ble.println("R,hold,200"); 
        break;                           
  };
  */
  
  ble.print(F("AT+BLEHIDMOUSEBUTTON="));
  ble.print(String(xValue));
  ble.print(String(","));
  ble.println(String(yValue));

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
   
    //Right
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    morse.push(1);
    delay(1000);
    mouseAct=morse.getMouse();
    //mouseAction((int)mouseAct[0],(int)mouseAct[1],(int)mouseAct[2]); 
    
    morse.clear();
    delay(2000);
}
