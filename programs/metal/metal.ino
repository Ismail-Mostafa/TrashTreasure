
#include <Servo.h> 
int motor = 2;
int limit = 3;
Servo myservo;
int m1 = 48;
int m2 = 50;
int m3 = 52;
///////////////////////////////////////////////
void metal()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(200);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
///////////////////////////////////////////
void glass()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(2000);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
////////////////////////////////////////////
void plastic()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(3900);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
/////////////////////////////////////////////
void setup()
{
pinMode(motor,OUTPUT);
pinMode(limit,INPUT);
myservo.attach(7);
myservo.write(70);
digitalWrite(motor,0);
pinMode(m1,INPUT);
pinMode(m2,INPUT);
pinMode(m3,INPUT);
}
//////////////////////////////////////////////
void loop()
{
if(digitalRead(m1)==0 || digitalRead(m2)==0 || digitalRead(m3)==0)
{
metal();  
}

}
