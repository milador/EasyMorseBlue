# EasyMorseBlue
A light weight Morse code library for Bluefruit bluetooth modules to be used as a method of Communication along adaptive switches in open-source Assistive Technology projects.

This is a light weight morse library based on morse2go project with addition of direct keyboard and mouse support. 

# Morse code mapping ( Keyboard mode )
 <table style="width:100%">
  <tr>
    <th>Morse code</th>
    <th>Result</th>
  </tr>
    <tr>
    <td>.-</td>
    <td>a</td>
  </tr>
    <tr>
    <td>-...</td>
    <td>b</td>
  </tr>
    <tr>
    <td>---.</td>
    <td>c</td>
  </tr>
    <tr>
    <td>-..</td>
    <td> d</td>
  </tr>
    <tr>
    <td>.</td>
    <td> e</td>
  </tr>
    <tr>
    <td>..-.</td>
    <td> f</td>
  </tr>
    <tr>
    <td>--.</td>
    <td> g</td>
  </tr>
    <tr>
    <td>....</td>
    <td> h</td>
  </tr>
    <tr>
    <td>..</td>
    <td> i</td>
  </tr>
    <tr>
    <td>.---</td>
    <td> j</td>
  </tr>
    <tr>
    <td>-.-</td>
    <td>k</td>
  </tr>
    <tr>
    <td>.-..</td>
    <td>l</td>
  </tr>
    <tr>
    <td>----</td>
    <td>m</td>
  </tr>
    <tr>
    <td>-.</td>
    <td>n</td>
  </tr>
    <tr>
    <td>---</td>
    <td>o</td>
  </tr>
    <tr>
    <td>.--.</td>
    <td>p</td>
  </tr>
    <tr>
    <td>--.-</td>
    <td>q</td>
  </tr>
    <tr>
    <td>.-.</td>
    <td>r</td>
  </tr>
    <tr>
    <td>...</td>
    <td>s</td>
  </tr>
    <tr>
    <td>-</td>
    <td>t</td>
  </tr>
    <tr>
    <td>..-</td>
    <td>u</td>
  </tr>
    <tr>
    <td>...-</td>
    <td>v</td>
  </tr>
    <tr>
    <td>.--</td>
    <td>w</td>
  </tr>
    <tr>
    <td>-..-</td>
    <td>x</td>
  </tr>
    <tr>
    <td>-.--</td>
    <td>y</td>
  </tr>
    <tr>
    <td>--..</td>
    <td>z</td>
  </tr>
    <tr>
    <td>.----</td>
    <td>1</td>
  </tr>
    <tr>
    <td>..---</td>
    <td>2</td>
  </tr>
    <tr>
    <td>...--</td>
    <td>3</td>
  </tr>
    <tr>
    <td>....-</td>
    <td>4</td>
  </tr>
    <tr>
    <td>.....</td>
    <td>5</td>
  </tr>
    <tr>
    <td>-....</td>
    <td>6</td>
  </tr>
    <tr>
    <td>--...</td>
    <td>7</td>
  </tr>
    <tr>
    <td>---..</td>
    <td>8</td>
  </tr>
    <tr>
    <td>----.</td>
    <td>9</td>
  </tr>
    <tr>
    <td>-----</td>
    <td>0</td>
  </tr>
    <tr>
    <td>-.....</td>
    <td> \</td>
  </tr>
    <tr>
    <td>--..-</td>
    <td> /</td>
  </tr>
    <tr>
    <td>..-...</td>
    <td> [</td>
  </tr>
    <tr>
    <td>-.-...</td>
    <td> ]</td>
  </tr>
    <tr>
    <td>.-...-</td>
    <td> <</td>
  </tr>
    <tr>
    <td>--..-.</td>
    <td> ></td>
  </tr>
    <tr>
    <td>...--.</td>
    <td> (</td>
  </tr>
    <tr>
    <td>-..--.</td>
    <td> )</td>
  </tr>
    <tr>
    <td>-.---.</td>
    <td>}</td>
  </tr>
    <tr>
    <td>..---.</td>
    <td>{</td>
  </tr>
    <tr>
    <td>.-.-.-</td>
    <td> .</td>
  </tr>
    <tr>
    <td>--..--</td>
    <td>,</td>
  </tr>
    <tr>
    <td>..--.</td>
    <td> _</td>
  </tr>
    <tr>
    <td>...-..</td>
    <td>|</td>
  </tr>
    <tr>
    <td>..--..</td>
    <td> ?</td>
  </tr>
    <tr>
    <td>.-..--</td>
    <td> !</td>
  </tr>
    <tr>
    <td>...-.</td>
    <td>;</td>
  </tr>
    <tr>
    <td>-.-.-.</td>
    <td>:</td>
  </tr>
    <tr>
    <td>---.</td>
    <td> -</td>
  </tr>
    <tr>
    <td>-...-.</td>
    <td> $</td>
  </tr>
    <tr>
    <td>.--.-.</td>
    <td> %</td>
  </tr>
    <tr>
    <td>--.--</td>
    <td>"</td>
  </tr>
    <tr>
    <td>.---.</td>
    <td> @</td>
  </tr>
    <tr>
    <td>..-..-</td>
    <td> '</td>
  </tr>
    <tr>
    <td>.-.--.</td>
    <td> `</td>
  </tr>
    <tr>
    <td>-.-..-</td>
    <td> ^</td>
  </tr>
    <tr>
    <td>--...-</td>
    <td>~</td>
  </tr>
    <tr>
    <td>-.---</td>
    <td> #</td>
  </tr>
    <tr>
    <td>-..--</td>
    <td> &</td>
  </tr>
    <tr>
    <td>.--..</td>
    <td> +</td>
  </tr>
    <tr>
    <td>.--.-</td>
    <td> =</td>
  </tr>
    <tr>
    <td>.-...</td>
    <td> *</td>
  </tr>
    <tr>
    <td>..--</td>
    <td> Space</td>
  </tr>
    <tr>
    <td>.-.-</td>
    <td> Enter</td>
  </tr>
    <tr>
    <td>----</td>
    <td>Backspace </td>
  </tr>
   <tr>
    <td>---..-.</td>
    <td>Tab </td>
  </tr>
    <tr>
    <td>..-.-</td>
    <td>Shift</td>
  </tr>
    <tr>
    <td>-.-.-</td>
    <td>Ctrl</td>
  </tr>
    <tr>
    <td>.-.--</td>
    <td>Alt</td>
  </tr>
    <tr>
    <td>----..</td>
    <td>Arrow Up</td>
  </tr>
    <tr>
    <td>------</td>
    <td>Arrow Down </td>
  </tr>
    <tr>
    <td>----.-</td>
    <td>Arrow Left</td>
  </tr>
    <tr>
    <td>-----.</td>
    <td>Arrow Right</td>
  </tr>
    <tr>
    <td>---..-</td>
    <td>PgUp</td>
  </tr>
    <tr>
    <td>---.-.</td>
    <td>PgDown</td>
  </tr>
    <tr>
    <td>....-.</td>
    <td>Home</td>
  </tr>
    <tr>
    <td>-.-..</td>
    <td>End</td>
  </tr>
    <tr>
    <td>-..-..</td>
    <td>NumLock</td>
  </tr>
    <tr>
    <td>...-.-</td>
    <td> ScrollLock</td>
  </tr>
    <tr>
    <td>..-.-.</td>
    <td>CapsLock</td>
  </tr>
    <tr>
    <td>..-..</td>
    <td>ESC</td>
  </tr>
    <tr>
    <td>.-..-</td>
    <td>Insert</td>
  </tr>
    <tr>
    <td>-..-.</td>
    <td>Delete</td>
  </tr>
    <tr>
    <td>-....-</td>
    <td>PrtScn</td>
  </tr>
 
  <tr>
    <td>--.----</td>
    <td>F1</td>
  </tr>
  <tr>
    <td>--..---</td>
    <td>F2</td>
  </tr>
  <tr>
    <td>--...--</td>
    <td>F3</td>
  </tr> 
  <tr>
    <td>--....-</td>
    <td>F4</td>
  </tr>    
  <tr>
    <td>--.....</td>
    <td>F5</td>
  </tr>    
  <tr>
    <td>---....</td>
    <td>F6</td>
  </tr>     
  <tr>
    <td>----...</td>
    <td>F7</td>
  </tr>    
 <tr>
    <td>-----..</td>
    <td>F8</td>
  </tr>     
  <tr>
    <td>------.</td>
    <td>F9</td>
  </tr>      
  <tr>
    <td>-------</td>
    <td>F10</td>
  </tr>   
  <tr>
    <td>.------</td>
    <td>F11</td>
  </tr>
  <tr>
    <td>..-----</td>
    <td>F12</td>
  </tr>    
 </table> 

# Morse code mapping ( Mouse mode )

 <table style="width:100%">
  <tr>
    <th>Morse code</th>
    <th>Result</th>
  </tr>
    <tr>
    <td>-</td>
    <td>Move Up</td>
  </tr>
  <tr>
    <td>--</td>
    <td>Move Down</td>
  </tr>
  <tr>
    <td>..</td>
    <td>Move Left</td>
  </tr>
  <tr>
    <td>...</td>
    <td>Move Right</td>
  </tr>
  <tr>
    <td>.-</td>
    <td>Left Click</td>
  </tr>
  <tr>
    <td>.--</td>
    <td>Right Click</td>
  </tr>
    <tr>
    <td>..-</td>
    <td>Double Left Click</td>
  </tr>
  <tr>
    <td>..--</td>
    <td>Double Right Click</td>
  </tr>  
  <tr>
    <td>-.</td>
    <td>Left Click & Hold/Release</td>
  </tr>  
  <tr>
    <td>-..</td>
    <td>Right Click & Hold/Release</td>
  </tr>  
</table> 


# Usage 

  1. Download and extract this repository as EasyMorse under Arduino libraries subdirectory. 
  
  2. Download and Install Bluefruit Arduino library according to the Adafruit instructions: 
  
  https://learn.adafruit.com/adafruit-feather-32u4-bluefruit-le/installing-ble-library

  3. Include EasyMorseBlue class in your sketch for using morse functions
```
#include "EasyMorseBlue.h"
```
  4. Include EasyMorseBlueBlue class in your sketch for using keyboard and mouse action functions
```
#include "EasyMorseHid.h"
```
  5. Initialize EasyMorse morse class
```
EasyMorseBlue morse;
```
  6. Initialize Bluefruit HID Keyboard if you are using EasyMorseBlueBlue class
```
initializeKeyboard();
```
  7. Initialize Bluefruit HID Mouse if you are using EasyMorseBlueBlue class
```
initializeMouse();
```
  8. Initialize time variables for morse code
```
unsigned MS_MIN_DD = 50;
unsigned MS_MAX_DD =5000;
unsigned MS_END =5000;
unsigned MS_CL =5000;
```

  9. Clear morse stack before each usage (Each dot or dash push) (EasyMorseBlue)
```
morse.clear();
```
  10. Push Dot (1) or Dash (2) to the stack: (EasyMorseBlue)
```
morse.push(1);
morse.push(2);
```

  11. Get the output character: (EasyMorseBlue)
```
morse.getChar(); 
```
  12. Get the Bluefruit output character key code: (EasyMorseBlue)
```
morse.getBlueChar(); 
```
  13. Get the Bluefruit output modifier key code: (EasyMorseBlue)
```
morse.getBlueModifier(); 
```
  14. Get the mouse action: (EasyMorseBlue)
```
int* mouseAct;
mouseAct=morse.getMouse();
```

  15. Enter character key: (EasyMorseHid)
```
enterKeyboardChar(char charachter);
```
  16. Enter character and modifier key code: (EasyMorseHid)
```
enterKeyboard(uint8_t modifierCode, uint8_t charachterCode);
```
  17. Release keyboard action: (EasyMorseHid)
```
clearKeyboard();
```
  18. Enter mouse action: (EasyMorseHid)
```
enterMouse(int button,int xValue,int yValue);
```
  19. Release mouse action: (EasyMorseHid)
```
clearMouse();
```

# Methods 
 <table style="width:100%">
  <tr>
    <th>Method</th>
    <th>Return Type</th>
    <th>Explanation</th>
   <th>Class</th>
  </tr>
    <tr>
    <td>pointer</td>
    <td>int</td>
    <td>Pointer to top of the stack</td>
    <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>dotDash[MAXDD]</td>
    <td>int</td>
    <td>Stack of dot and dashes</td>
   <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>clear()</td>
    <td>void</td>
    <td>Clear the stack</td>
   <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>push(int)</td>
    <td>void</td>
    <td>Push a dot or dash to the stack </td>
   <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>pop()</td>
    <td>void</td>
    <td>Pop last dot or dash from the stack</td>
   <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>getCharNum()</td>
    <td>long</td>
    <td>Get number value of character. Example: .- = 12</td>
   <td>EasyMorseBlue</td>
  </tr>
    <tr>
    <td>getChar()</td>
    <td>char</td>
    <td>Get the resulting character</td>
     <td>EasyMorseBlue</td>
  </tr>
  <tr>
    <td>getBlueChar()</td>
    <td>int</td>
    <td>Get the resulting Bluefruit character code</td>
   <td>EasyMorseBlue</td>
  </tr>  
   <tr>
    <td>getBlueModifier()</td>
    <td>int</td>
    <td>Get the resulting Bluefruit modifier code</td>
    <td>EasyMorseBlue</td>
  </tr>  
  <tr>
    <td>getMouse()</td>
    <td>int*</td>
    <td>Get the resulting mouse action </td>
   <td>EasyMorseBlue</td>
  </tr>  
   <tr>
    <td>initializeMouse()</td>
    <td>void</td>
    <td>Initialize mouse function</td>
   <td>EasyMorseHid</td>
  </tr> 
    <tr>
    <td>initializeKeyboard()</td>
    <td>void</td>
    <td>Initialize keyboard function</td>
   <td>EasyMorseHid</td>
  </tr> 
     <tr>
    <td>enterMouse(int button,int xValue,int yValue)</td>
    <td>void</td>
    <td>Mouse action function</td>
   <td>EasyMorseHid</td>
  </tr> 
   <tr>
    <td>clearMouse()</td>
    <td>void</td>
    <td>Release Mouse action function</td>
   <td>EasyMorseHid</td>
  </tr> 
  <tr>
  <td>enterKeyboard(uint8_t modifierCode, uint8_t charachterCode)</td>
    <td>void</td>
    <td>Enter Keyboard charachter and modifier function</td>
   <td>EasyMorseHid</td>
  </tr> 
  <td>enterKeyboardChar(char charachter)</td>
    <td>void</td>
    <td>Enter Keyboard charachter function</td>
   <td>EasyMorseHid</td>
  </tr> 
   <td>clearKeyboard()</td>
    <td>void</td>
    <td>Release Keyboard charachter function</td>
   <td>EasyMorseHid</td>
  </tr> 
</table> 
