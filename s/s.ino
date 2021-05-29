#include <Servo.h>
Servo ver1,hor1;  // create servo object to control a servo
                // a maximum of eight servo objects can be created 
int pos1= 0;
//int pos1= 0;
// variable to store the servo position
void setup()
{
  hor1.attach(9);
  ver1.attach(10);  // attaches the servo on pin 9,10 to the servo objects
  ver1.write(0);
  hor1.write(0);
}
/*void loop()
{
ver1.write(posv);
hor1.write(posh);
delay(1000);
  posv++;
  posh--;
  
  }
*/
void loop()
{
  for(pos1= 0; pos1< 180; pos1+= 10)  // goes from 0 degrees to 180 degrees   
  {                                  // in steps of 10 degrees     
    ver1.write(pos1);     
    hor1.write(pos1);    // tell servo to go to position in variable 'pos'     
    delay(100);                       // waits 100ms for the servo to reach the position   
  }   
  for(pos1= 180; pos1>=1; pos1-=10)     // goes back from 180 degrees to 0 degrees
  {                               
    ver1.write(pos1);              // tell servo to go to position in variable 'pos'
    hor1.write(pos1);
    delay(100);                       // waits 100ms for the servo to reach the position
  }
}

