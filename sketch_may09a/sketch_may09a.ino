
#include <Wire.h>

byte i2c_rcv;               // data received from I2C bus
unsigned long time_start;   // start time in mSec
int stat_LED;               // status of LED: 1 = ON, 0 = OFF
byte value_pot;             // potentiometer position


void setup()
{
  Wire.begin(0x18);
  pinMode(17, OUTPUT);
}

void loop()
{
//  digitalWrite(17, HIGH);
//  delay(1000); // Wait for 1000 millisecond(s)
//  digitalWrite(17, LOW);
//  delay(100); // Wait for 1000 millisecond(s)
}

// Arduino slave sketch


//
//void setup()
//{}
//void loop ()
//{}
