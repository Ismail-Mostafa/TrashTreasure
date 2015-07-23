#include <glcd.h>
#include <Keypad.h>
#include "fonts/allFonts.h"         
#include "bitmaps/metal.h"
#include "bitmaps/plastic.h"
#include "bitmaps/welcom.h"
#include "bitmaps/Trash.h"
#include "bitmaps/phone.h"
int i=0;
int j=0;
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
char user[10][12];
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
GLCD.DrawBitmap(welcom, 0,  0);
//   delay(1000);
//GLCD.DrawBitmap(Trash, 0,  0);
//   delay(1000);
// GLCD.DrawBitmap(phone, 0,  0);
 
}
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void loop()
{
  //GLCD.ClearScreen();   
  

v1=analogRead(0);
v2=analogRead(1);
v3=analogRead(2);
v4=analogRead(3);
weight=analogRead(8);
e1=v1-v1r;
if(e1<0)
e1=v1r-v1;
e2=v2-v2r;
if(e2<0)
e2=v2r-v2;
e3=v3-v3r;
if(e3<0)
e3=v3r-v3;
e4=v4-v4r;
if(e4<0)
e4=v4r-v4;
 if(e1>=50||e2 >= 50||e3 >= 50||e4>=50)
{
  i=0;
  j++;
  //GLCD.DrawBitmap(welcom, 0,  0);
 // delay(2000);
//  GLCD.DrawBitmap(phone, 0,  0);
//  delay(2000);
//  GLCD.ClearScreen();
   while(i<11)
  {
    char key = keypad.getKey();
    if(key)
   {
   user[i][j]=key;
   GLCD.CursorTo(i, 1);
   GLCD.print(key);
   i++;
   }
  }

}
if (Serial.available()) {
int inByte = Serial.read();
  if(inByte=='g')
  {
  for(j=1;j<10;j++)
  {
  Serial.print("user=");
  Serial.write(j+48);
  Serial.println();
  for(i=0;i<12;i++)
  {
  Serial.write(user[i][j]);  
  }
  Serial.print("score=");
  Serial.write(user[12][j]);
  Serial.println();
  }
  i=0;
  j=0;
  }  
}
  
}

