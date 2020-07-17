

#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "BluefruitConfig.h"
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

//Debug output routines
#if (MY_DEBUG)
  #define MESSAGE(m) Serial.println(m);
  #define FATAL(m) {MESSAGE(m); while (1);}
#else
  #define MESSAGE(m) {}
  #define FATAL(m) while (1);
#endif

void initializeBluefruit (void) {
  //Initialize Bluetooth
  if ( !ble.begin(MY_DEBUG))
  {
    FATAL(F("NO BLE?"));
  }
  //Rename device
  if (! ble.sendCommandCheckOK(F( "AT+GAPDEVNAME=EasyMorseBlue Keyboard" )) ) {
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