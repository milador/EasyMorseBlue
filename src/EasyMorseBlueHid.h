

#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "EasyMorseBlueConfig.h"
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

#define MY_DEBUG 1
#define FACTORYRESET_ENABLE 0

//Debug output routines
#if (MY_DEBUG)
  #define MESSAGE(m) Serial.println(m);
  #define FATAL(m) {MESSAGE(m); while (1);}
#else
  #define MESSAGE(m) {}
  #define FATAL(m) while (1);
#endif

//***INITIALIZE BLUETOOTH MOUSE FUNCTION***//

void initializeMouse (String name) {
	String strNameCmd = "AT+GAPDEVNAME="+name; 
	int strNameLen = strNameCmd.length() + 1; 
	char charNameCmd[strNameLen];
	strNameCmd.toCharArray(charNameCmd, strNameLen);
	if ( !ble.begin(MY_DEBUG))
	{
	FATAL(F("NO BLE?"));
	}
	//Rename device
	if (! ble.sendCommandCheckOK(charNameCmd)) {
	FATAL(F("err:rename fail"));
	}
	//Enable HID keyboard
	if(!ble.sendCommandCheckOK(F( "AT+BleHIDEn=On" ))) {
	FATAL(F("err:enable Kb"));
	}
	//Add or remove service requires a reset
	if ( FACTORYRESET_ENABLE )
	{
	/* Perform a factory reset to make sure everything is in a known state */
	if ( ! ble.factoryReset() ){
	  FATAL(F("err:SW reset"));
	}
	}
}

//***PERFORM MOUSE ACTIONS FUNCTION***//

void enterMouse(int button,int xValue,int yValue) {

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
  
  
  ble.print(F("AT+BLEHIDMOUSEMOVE="));
  ble.print(String(xValue));
  ble.print(String(","));
  ble.println(String(yValue));

}

//***CLEAR MOUSE FUNCTION***//

void clearMouse(void) {
  ble.println(F("AT+BLEHIDMOUSEBUTTON=0"));
}

//***INITIALIZE BLUETOOTH KEYBOARD FUNCTION***//

void initializeKeyboard (String name) {
	String strNameCmd = "AT+GAPDEVNAME="+name; 
	int strNameLen = strNameCmd.length() + 1; 
	char charNameCmd[strNameLen];
	strNameCmd.toCharArray(charNameCmd, strNameLen);
  if ( !ble.begin(MY_DEBUG))
  {
    FATAL(F("NO BLE?"));
  }
  //Rename device
  if (! ble.sendCommandCheckOK(charNameCmd) ) {
    FATAL(F("err:rename fail"));
  }
  //Enable HID keyboard
  if(!ble.sendCommandCheckOK(F( "AT+BleHIDEn=On" ))) {
    FATAL(F("err:enable Kb"));
  }
  //Add or remove service requires a reset
  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    if ( ! ble.factoryReset() ){
      FATAL(F("err:SW reset"));
    }
  }

}

//***ENTER KEYBOARD ACTIONS FUNCTION***//

void enterKeyboard(uint8_t modifierCode, uint8_t charachterCode) {
  ble.print(F("AT+BLEKEYBOARDCODE="));
  if (modifierCode<0x10)ble.print("0");
  ble.print(modifierCode,HEX);
  ble.print(F("-00-"));
  if (charachterCode<0x10)ble.print("0");
  ble.print(charachterCode,HEX);
  ble.println(F("-00-00-00-00"));
}

//***ENTER KEYBOARD CHAR ACTIONS FUNCTION***//

void enterKeyboardChar(char charachter) {
  ble.print("AT+BleKeyboard=");
  ble.println(charachter);
}

//***CLEAR KEYBOARD FUNCTION***//

void clearKeyboard() {
  ble.println(F("AT+BLEKEYBOARDCODE=00-00"));
}
