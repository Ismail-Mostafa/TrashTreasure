
#include <Servo.h> 
int motor = 2;
int limit = 3;
Servo myservo;
void metal()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
void glass()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(1800);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
void plastic()
{
digitalWrite(motor,1);
while(digitalRead(limit)==1);
delay(3700);
digitalWrite(motor,0);
delay(500);
myservo.write(180);
delay(2000);
myservo.write(70);
}
void setup()
{
pinMode(motor,OUTPUT);
pinMode(limit,INPUT);
myservo.attach(7);
digitalWrite(motor,0);
  
}
void loop()
{
metal();
delay(2000);
glass();
delay(2000);
plastic();
delay(2000);
}
