#include <Servo.h> 
 
Servo vert,hori;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int laser = 12; 
int buzzer = 11;

void setup() 
{ 
  hori.attach(9);
  vert.attach(10);  // attaches the servo on pin 9 to the servo object 
  pinMode(laser,OUTPUT);
  pinMode(buzzer,OUTPUT);
} 
 
 
void loop() 
{ 
  digitalWrite(laser,HIGH);
  analogWrite(buzzer,1);
  for(pos = 0; pos < 180; pos += 10)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    vert.write(pos);
    hori.write(pos);    // tell servo to go to position in variable 'pos' 
    delay(100);                       // waits 15ms for the servo to reach the position 
  } 
  digitalWrite(laser,LOW);
  analogWrite(buzzer, 0);
  for(pos = 180; pos>=1; pos-=10)     // goes from 180 degrees to 0 degrees 
  {                                
    vert.write(pos);              // tell servo to go to position in variable 'pos' 
    hori.write(pos);
    delay(100);                       // waits 15ms for the servo to reach the position 
  } 
}
