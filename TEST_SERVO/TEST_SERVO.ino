#include <Servo.h>
Servo vert,hori;  // create servo object to control a servo
                // a maximum of eight servo objects can be created 
int pos = 0; int v=5; int laser = 12;   // variable to store the servo position
void setup()
{
  hori.attach(3);
  vert.attach(5);  // attaches the servo on pin 9,10 to the servo objects
  vert.write(45);
  hori.write(45);
  pinMode(laser, OUTPUT);
}

void loop()
{//digitalWrite(laser, HIGH);
if (pos==135)
{
  v+=10;
  vert.write(v);
}

if (v==135)
exit(1);
  
  for(pos = 45; pos <= 135; pos += 15)  // goes from 0 degrees to 180 degrees   
  {                                  // in steps of 10 degrees     
    vert.write(pos);     
    hori.write(pos);    // tell servo to go to position in variable 'pos'     
    delay(100);                       // waits 100ms for the servo to reach the position   
  }   
  for(pos =135; pos>=45; pos-=15)     // goes back from 180 degrees to 0 degrees
  {                               
    vert.write(pos);              // tell servo to go to position in variable 'pos'
    hori.write(pos);
    delay(100);                       // waits 100ms for the servo to reach the position
  }
}
