#include <glcd.h>
#include <Keypad.h>
#include "fonts/allFonts.h"         
#include "bitmaps/metal.h"
#include "bitmaps/plastic.h"
#include "bitmaps/welcom.h"
#include "bitmaps/Trash.h"
#include "bitmaps/phone.h"
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
//////////////////////////////////////////////////////////////
int v1,v2,v3,v4;
int v1r,v2r,v3r,v4r;
int e1,e2,e3,e4;
int weight;

void setup()
{
  
  GLCD.Init();
Serial.begin(9600); 
v1r=analogRead(0);
v2r=analogRead(1);
v3r=analogRead(2);
v4r=analogRead(3);
GLCD.SelectFont(System5x7);
//  GLCD.DrawBitmap(metal, 0,  0);
// delay(1000);
// GLCD.DrawBitmap(plastic, 0,  0);
//  delay(1000);
// GLCD.DrawBitmap(welcom, 0,  0);
//   delay(1000);
// GLCD.DrawBitmap(Trash, 0,  0);
//   delay(1000);
// GLCD.DrawBitmap(phone, 0,  0);
 
}
void loop()
{
  //GLCD.ClearScreen();   
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 char key = keypad.getKey();
 if(key)
 {
 GLCD.CursorTo(i, 1);
 GLCD.print(key);
 i++;
 delay(1000); 
 }
 v1=analogRead(0);
v2=analogRead(1);
v3=analogRead(2);
v4=analogRead(3);
weight=analogRead(8);
e1=v1-v1r;
e2=v2-v2r;
e3=v3-v3r;
e4=v4-v4r;
Serial.println(e1);
Serial.println(e2);
Serial.println(e3);
Serial.println(e4);
Serial.println(weight);
delay(2000);
 
  
}
