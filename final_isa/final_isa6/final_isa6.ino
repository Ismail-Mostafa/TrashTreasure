#include <glcd.h>
#include <Keypad.h>
#include <Servo.h> 
#include "fonts/allFonts.h"         
#include "bitmaps/metal.h"
#include "bitmaps/plastic.h"
#include "bitmaps/welcom.h"
#include "bitmaps/Trash.h"
#include "bitmaps/phone.h"
#include "bitmaps/glass.h"
int motor = 2;
int limit = 3;
Servo myservo;
int m1 = 48;
int m2 = 50;
int m3 = 52;
int i=0;
int j=0;
int flag=0;
int z;
int mat=0;
int mat_glass=0;
int mat_metal=0;
int mat_palstic=0;
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
char user[12][10];
///////////////////////////////////////////////
void metal2()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(200);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(80);
}
///////////////////////////////////////////
void glass2()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(2000);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(80);
}
////////////////////////////////////////////
void plastic2()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(3900);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(80);
}
/////////////////////////////////////////////
void setup()
{
GLCD.Init();
Serial.begin(9600);
Serial1.begin(9600);
v1r=analogRead(0);
v2r=analogRead(1);
v3r=analogRead(2);
v4r=analogRead(3);
pinMode(motor,OUTPUT);
pinMode(limit,INPUT);
myservo.attach(7);
myservo.write(80);
digitalWrite(motor,0);
pinMode(m1,INPUT);
pinMode(m2,INPUT);
pinMode(m3,INPUT);
GLCD.SelectFont(System5x7);
GLCD.DrawBitmap(Trash, 0,  0);
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
if(digitalRead(m1)==0 || digitalRead(m2)==0 || digitalRead(m3)==0)
{
flag=1;
}

if(e1>=200||e2 >= 200||e3 >= 200||e4>=200)
{
  delay(500);
  i=0;
  j++;
  weight=analogRead(8);
  if(flag==1)
  {
  flag=0;
  GLCD.DrawBitmap(metal, 0,  0);
  metal2();
  user[11][j]=5;
  mat_metal++;
  }
  else if(weight>200)
  {
  GLCD.DrawBitmap(glass, 0,  0);
  glass2();
  user[11][j]=3;
  mat_glass++; 
  }
    else
  {
  GLCD.DrawBitmap(plastic, 0,  0);
  plastic2(); 
  user[11][j]=2;
  mat_palstic++;
  }
  if(mat_metal==2||mat_palstic==2||mat_glass==2)
  {
  //Serial1.println("atd01147712152;");
  Serial1.println("at+cmgf=1");
  delay(600);
  Serial1.println("at+cmgs=\"01147712152\"");
 delay(300);
 Serial1.println("Trash Treasure 1 is full"); 
 delay(200);
 Serial1.write(26);
  mat_metal=4;
  mat_palstic=4;
  mat_glass=4;
  } 
  //GLCD.DrawBitmap(welcom, 0,  0);
  //delay(2000);
 GLCD.DrawBitmap(phone, 0,  0);
  delay(2000);
  GLCD.ClearScreen();
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
delay(1000);
GLCD.DrawBitmap(Trash, 0,  0);
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
  Serial.write(user[11][j]+48);
  Serial.println();
  }
  i=0;
  j=0;
  }  
}
  
}

