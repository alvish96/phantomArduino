#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5); //RX, TX, These pins will be used to send the data to another Arduino
int i = 0;
char dataArray[50] = "";
bool flag1 = false;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  byte n = Serial1.available();
  if (n != 0)
  {
    if (flag1 == false)
    {
      byte x = Serial1.read();
      if (x == 0x01)
      {
        Serial.print("Received Sensor 0: ");
        flag1 = true;
      }
    }
    else
    {
      byte x1 = Serial1.read();
      if (x1 != 0x02)
      {
        dataArray[i] = x1;
        i++;
      }
      else
      {
        dataArray[i] = 0x00;  //nul-byte
        Serial.println(dataArray);
        i = 0;
        flag1 = false;
      }
    }
  }
   Serial.println(dataArray);
}
