#include<SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  mySerial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  if (Serial.available())
  {
    mySerial.write(Serial.read());
  }


}
