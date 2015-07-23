#include <glcd.h>
#include <Keypad.h>
#include "fonts/allFonts.h"         
#include "bitmaps/besm.h"
#include "bitmaps/allah.h"
#include "bitmaps/glcd.h"
int i=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','a',},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','#','d'}
};
byte rowPins[ROWS] = {53, 51, 49, 47}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {45, 43, 41, 39}; //connect to the column pinouts of the keypad



void setup()
{
  
  GLCD.Init();
  GLCD.SelectFont(System5x7);
  GLCD.DrawBitmap(besm, 0,  0);
 delay(1000);
 GLCD.DrawBitmap(allah, 0,  0);
  delay(1000);
 GLCD.DrawBitmap(glcd, 0,  0);
 
}
void loop()
{
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 char key = keypad.getKey();
 if(key)
 {
 GLCD.CursorTo(i, 1);
 GLCD.print(key);
 i++;
 delay(1000); 
 }
 
  
}
