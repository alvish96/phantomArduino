#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); //RX, TX, These pins will be used to send the data to another Arduino

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  unsigned int ValSensor0 = analogRead(A0); //R1 pot
  unsigned int ValSensor1 = analogRead(A1); // R2 pot

  //read figures in serial monitor
  Serial.print("handle Sensor 0: ");
  Serial.println(ValSensor0, DEC);
  Serial.print("handle Sensor 1: ");
  Serial.println(ValSensor1, DEC);
  //--send R1 value to NANO------
  mySerial.write(0x01); //R1 Pot Data is next one
  mySerial.print(ValSensor0, DEC);
  mySerial.write(0x02);  //end-of-message
  delay(1000);
}
