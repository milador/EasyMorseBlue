//EasyMorseBlue Library
//EasyMorseBlue.cpp
//Written by: Milad Hajihassan
//Version 1.0 (16/7/2020)
//Based on : https://github.com/morse2go/morse2go

#include <stdlib.h>
#include "Arduino.h"
#include "EasyMorseBlue.h"

//Morse to character dictionary 
 const charStruct charDictionary[] {

    {12,"a",4,0},                          //a
    {2111,"b",5,0},                        //b
    {2221,"c",6,0},                        //c
    {211,"d",7,0},                         //d
    {1,"e",8,0},                           //e
    {1121,"f",9,0},                        //f
    {221,"g",10,0},                        //g
    {1111,"h",11,0},                       //h
    {11,"i",12,0},                         //i
    {1222,"j",13,0},                       //j
    {212,"k",14,0},                        //k
    {1211,"l",15,0},                       //l
    {2222,"m",16,0},                       //m
    {21,"n",17,0},                         //n
    {222,"o",18,0},                        //o
    {1221,"p",19,0},                       //p
    {2212,"q",20,0},                       //q
    {121,"r",21,0},                        //r
    {111,"s",22,0},                        //s
    {2,"t",23,0},                          //t
    {112,"u",24,0},                        //u
    {1112,"v",25,0},                       //v
    {122,"w",26,0},                        //w
    {2112,"x",27,0},                       //x
    {2122,"y",28,0},                       //y
    {2211,"z",29,0},                       //z
    {12222,"1",30,0},                      //1
    {11222,"2",31,0},                      //2
    {11122,"3",32,0},                      //3
    {11112,"4",33,0},                      //4
    {11111,"5",34,0},                      //5
    {21111,"6",35,0},                      //6
    {22111,"7",36,0},                      //7
    {22211,"8",37,0},                      //8
    {22221,"9",38,0},                      //9
    {22222,"0",39,0},                      //0
	{1212,"",40,0},                        //Enter
    {11211,"",41,0},                       //ESC	
    {22,"",42,0},                          //Backspace 
    {2221121,"",43,0},                     //Tab 	
    {1122," ",44,0},                       //Space	
    {2221,"-",45,0},                       //-	
    {12212,"=",46,0},                      //=	
    {122111,"[",47,0},                     //[
    {211222,"]",48,0},                     //]	
    {222211,"\\",49,0},                    //"\"
    {21222,"#",50,0},                      //#
    {211112,";",51,0},                     //;	
    {112112,"'",52,0},                     //"	
    {221222,"`",53,0},                     //`
    {211111,",",54,0},                     //,	
    {122222,".",55,0},                     //.	
    {111122,"/",56,0},                     ///
    {112121,"",57,0},                      //CapsLock	
	{2212222,"",58,0},                     //F1
    {2211222,"",59,0},                     //F2
    {2211122,"",60,0},                     //F3
    {2211112,"",61,0},                     //F4
    {2211111,"",62,0},                     //F5
    {2221111,"",63,0},                     //F6
    {2222111,"",64,0},                     //F7
    {2222211,"",65,0},                     //F8
    {2222221,"",66,0},                     //F9
    {2222222,"",67,0},                     //F10
    {1222222,"",68,0},                     //F11
    {1122222,"",69,0},                     //F12	
    {221221,"",70,0},                      //PrtScn
    {221211,"",71,0},                      //ScrollLock
    {121121,"",72,0}, 					   //Pause
	{21211,"",73,0},                       //Insert
    {1111111,"",74,0},                     //Home
    {111112,"",75,0},                      //PgUp
    {212211,"",76,0},                      //Delete
    {1112111,"",77,0},                     //End
    {111211,"",78,0},                      //PgDown	
    {12121,"",79,0},                       //Arrow Right
    {121211,"",80,0},                      //Arrow Left
    {12211,"",81,0},                       //Arrow Down 
    {12112,"",82,0},                       //Arrow Up
    {2221112,"",83,0},                     //NumLock
    {12111,"*",85,0},                      //*
    {12211,"+",87,0},                      //+
    {2121,"",0,1},                         //Ctrl	
    {221112,"",0,2},                       //Shift
    {22122,"",0,4}                         //Alt

};

//Morse to mouse action dictionary
 const mouseStruct mouseDictionary[] {
    {0,2},                                       //Up
    {1,22},                                      //Down
    {2,11},                                      //Left
    {3,111},                                     //Right
    {4,12},                                      //Left Click
    {5,122},                                     //Right Click
    {6,112},                                     //Double Left Click
    {7,1122},                                    //Double Right Click
    {8,21},                                      //Left Click & Hold/Release
    {9,211}                                      //Right Click& Hold/Release
 };

// --------------- Functions ------------------

EasyMorseBlue::EasyMorseBlue() {
  clear();
}

void EasyMorseBlue::clear() {
  for (int i=0; i < MAXDD; i++)
    dotDash[i] = 0;
  pointer = 0;
}

void EasyMorseBlue::push(int c) {
  if (pointer < MAXDD)
    dotDash[pointer++] = c;  
}

void EasyMorseBlue::pop() {
  if (pointer >= 0) {
    dotDash[pointer] = 0;
    pointer--;
  } 
}

//Get number value of character. Example: .- = 12
long EasyMorseBlue::getCharNum() {
  long mult = 1L;
  int i;
  long charNum = 0;
  long long charNum1 = 0;
  for (i = pointer-1; i > -1; i--) {
    charNum = charNum + (dotDash[i] * mult);
    mult = mult * 10;
  }
  return charNum;
}

//Get the resulting character 
char EasyMorseBlue::getChar() {  
  int j;
  char charOut;
  long charNum = getCharNum();

  //Search for character based on character number
  for(uint8_t j = 0; j < sizeof(charDictionary)/sizeof(charStruct); ++j) {
    if(charNum == charDictionary[j].numCode)
    {
      charOut= charDictionary[j].lowerChar[0];
    }
  }
  return charOut;
}


//Get the resulting bluefruit char code 
int EasyMorseBlue::getBlueChar() {  
  int j;
  int codeOut = 0;
  long charNum = getCharNum();
  //Search for Ascii code based on character number
  for(uint8_t j = 0; j < sizeof(charDictionary)/sizeof(charStruct); ++j) {
    if(charNum == charDictionary[j].numCode)
    {
      codeOut= charDictionary[j].blueCharCode;
    }
  }
  return codeOut;
}

//Get the resulting bluefruit modifier code 
int EasyMorseBlue::getBlueModifier() {  
  int j;
  int codeOut = 0;
  long charNum = getCharNum();
  //Search for Ascii code based on character number
  for(uint8_t j = 0; j < sizeof(charDictionary)/sizeof(charStruct); ++j) {
    if(charNum == charDictionary[j].numCode)
    {
      codeOut= charDictionary[j].blueModifierCode;
    }
  }
  return codeOut;
}

//Get the resulting mouse action 
int* EasyMorseBlue::getMouse() {  
  int j;
  static int mouseAction[4];
  mouseAction[0]= 0;
  mouseAction[1]= 0;
  mouseAction[2]= 0;
  mouseAction[3]= 0;
  long charNum = getCharNum();
  //Output mouse action 
  for(uint8_t j = 0; j < sizeof(mouseDictionary)/sizeof(mouseStruct); ++j) {
    if(charNum == mouseDictionary[j].numCode)
    {
        switch (mouseDictionary[j].num) {
          case 0:
            mouseAction[2]=-MOUSE_MOVE;
          break;
          case 1:
            mouseAction[2]=MOUSE_MOVE;
          break;
          case 2:
            mouseAction[1]=-MOUSE_MOVE;
          break;      
          case 3:
            mouseAction[1]=MOUSE_MOVE;
          break; 
          case 4:
            mouseAction[0]=1;
          break;     
          case 5:
            mouseAction[0]=2;
          break;
          case 6:
            mouseAction[0]=3;
          break;      
          case 7:
            mouseAction[0]=4;
          break; 
          case 8:
            mouseAction[0]=5;
          break;
          case 9:
            mouseAction[0]=6;
          break;                            
        default:
        break;
      }
    }
  }
  
  return mouseAction;
}
