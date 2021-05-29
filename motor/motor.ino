//const int sp=2;
#include <Servo.h>
Servo one;
const int right=5;
const int left=6;
const int back=7;
const int forw=4;
//int ss=0;
void setup(){
  one.attach(3);
  pinMode(forw,OUTPUT);
pinMode(back,OUTPUT);
pinMode(left,OUTPUT);
pinMode(right,OUTPUT);

  //pinMode(sp,INPUT);
}
void loop(){
   
  //one.write();scan1();


    digitalWrite (forw,HIGH);
    delay (1000);
    digitalWrite (forw,LOW);
delay (1000);

      digitalWrite (back,HIGH);
    delay (1000);
    digitalWrite (back,LOW);
delay (1000);

    digitalWrite (left,HIGH);
    delay (1000);
    digitalWrite (left,LOW);
delay (1000);
    
        digitalWrite (right,HIGH);
    delay (1000);
    digitalWrite (right,LOW);
delay (1000);
    }







    
  void scan()
{
  one.write(0);
  delay(1000);
//digitalWrite(laser2,HIGH);
  for (int j=0;j<=180;j++)
  {   one.write(j);
  delay(50);
  }
  delay(1000);
one.write(0);//beep();
}





void scan1()
{
  one.write(20);
  delay(1000);
  // one.write(45);
  //delay(1000);
   one.write(90);
  delay(1000);
   //one.write(135);
  //delay(1000);
   one.write(180);
  delay(1000);
  one.write(90);
  delay(1000);
}


