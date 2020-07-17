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
    {0,12,"a",4},                           //a
    {1,2111,"b",5},                         //b
    {2,2121,"c",6},                         //c
    {3,211,"d",7},                          //d
    {4,1,"e",8},                            //e
    {5,1121,"f",9},                         //f
    {6,221,"g",10},                         //g
    {7,1111,"h",11},                        //h
    {8,11,"i",12},                          //i
    {9,1222,"j",13},                        //j
    {10,212,"k",14},                        //k
    {11,1211,"l",15},                       //l
    {12,22,"m",16},                         //m
    {13,21,"n",17},                         //n
    {14,222,"o",18},                        //o
    {15,1221,"p",19},                       //p
    {16,2212,"q",20},                       //q
    {17,121,"r",21},                        //r
    {18,111,"s",22},                        //s
    {19,2,"t",23},                          //t
    {20,112,"u",24},                        //u
    {21,1112,"v",25},                       //v
    {22,122,"w",26},                        //w
    {23,2112,"x",27},                       //x
    {24,2122,"y",28},                       //y
    {25,2211,"z",29},                       //z
    {26,12222,"1",30},                      //1
    {27,11222,"2",31},                      //2
    {28,11122,"3",32},                      //3
    {29,11112,"4",33},                      //4
    {30,11111,"5",34},                      //5
    {31,21111,"6",35},                      //6
    {32,22111,"7",36},                      //7
    {33,22211,"8",37},                      //8
    {34,22221,"9",38},                      //9
    {35,22222,"0",39},                      //0
    {36,211111,"'\'",49},                   //'\'
    {37,22112,"/",55},                      ///
    {38,112111,"[",47},                     //[
    {39,212111,"]",48},                     //]
    {40,121112,"<",},                       //<  ---------
    {41,221121,">",},                       //>  ---------
    {42,111221,"(",},                       //(  ---------
    {43,211221,")",},                       //)  ---------
    {44,212221,"}",},                       //}  ---------
    {45,112221,"{",},                       //{  ---------
    {46,121212,".",55},                     //.
    {47,221122,",",54},                     //,
    {48,11221,"_",},                        //_  ---------
    {49,111211,"|",},                       //|  ---------
    {50,112211,"?",},                       //?  ---------
    {51,121122,"!",},                       //!  ---------
    {52,11121,";",51},                      //
    {53,212121,":",},                       //  ---------
    {54,2221,"-",},                         //-  ---------
    {55,211121,"$",},                       //$  ---------
    {56,122121,"%",},                       //%  ---------
    {57,22122,"*",},                        //"  ---------
    {58,12221,"@",},                        //@  ---------
    {59,112112,"'",52},                     //'
    {60,121221,"`",},                       //`  ---------
    {61,212112,"^",},                       //^  ---------
    {62,221112,"~",53},                     //~
    {63,21222,"#",},                        //#  ---------
    {64,21122,"&",},                        //&  ---------
    {65,12211,"+",87},                      //+
    {66,12212,"=",46},                      //=
    {67,12111,"*",85},                      //*
    {68,1122," ",44},                       //Space
    {69,1212,"*",40},                       //Enter
    {70,2222,"*",42},                       //Backspace 
    {71,2221121,"*",43},                    //Tab 	
    {72,11212,"*",107},                     //Shift
    {73,21212,"*",106},                     //Ctrl
    {74,12122,"*",108},                     //Alt
    {75,222211,"*",82},                     //Arrow Up
    {76,222222,"*",81},                     //Arrow Down 
    {77,222212,"*",80},                     //Arrow Left
    {78,222221,"*",79},                     //Arrow Right
    {79,222112,"*",75},                     //PgUp
    {80,222121,"*",78},                     //PgDown
    {81,111121,"*",74},                     //Home
    {82,21211,"*",77},                      //End
    {83,211211,"*",83},                     //NumLock
    {84,111212,"*",71},                     //ScrollLock
    {85,112121,"*",57},                     //CapsLock
    {86,11211,"*",41},                      //ESC
    {87,12112,"*",73},                      //Insert
    {88,21121,"*",76},                      //Delete
    {89,211112,"*",70},                     //PrtScn
	{90,2212222,"*",58},                    //F1
    {91,2211222,"*",59},                    //F2
    {92,2211122,"*",60},                    //F3
    {93,2211112,"*",61},                    //F4
    {94,2211111,"*",62},                    //F5
    {95,2221111,"*",63},                    //F6
    {96,2222111,"*",64},                    //F7
    {97,2222211,"*",65},                    //F8
    {98,2222221,"*",66},                    //F9
    {99,2222222,"*",67},                    //F10
    {100,1222222,"*",68},                   //F11
    {101,1122222,"*",69}                   //F12

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
  int mult = 1;
  int i;
  long charNum = 0;
  
  for (i = pointer-1; i > -1; i--) {
    charNum = charNum + (dotDash[i] * mult);
    mult = mult * 10;
  }
  return charNum;
}

//Get the resulting character 
char EasyMorseBlue::getChar() {  
  int mult = 1;
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


//Get the resulting Ascii code 
int EasyMorseBlue::getBlueChar() {  
  int mult = 1;
  int j;
  int blueOut = 0;
  long charNum = getCharNum();
  //Search for Ascii code based on character number
  for(uint8_t j = 0; j < sizeof(charDictionary)/sizeof(charStruct); ++j) {
    if(charNum == charDictionary[j].numCode)
    {
      blueOut= charDictionary[j].blueCode;
    }
  }
  return blueOut;
}


//Get the resulting mouse action 
int* EasyMorseBlue::getMouse() {  
  int mult = 1;
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
