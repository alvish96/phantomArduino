#include<SoftwareSerial.h>
SoftwareSerial ser(11, 12); //tx,rx
#define led 9
#define tym 0

String s;



void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  ser.begin(9600);
  //Serial.println("");
}

void loop()
{
  if (ser.available())

{
  
  }
  
  }




