
//receiving
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); //rx pin,tx pin

int recvchars[256];
boolean newdata = false;

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);

  //  recvchars[256] = {0};
  //  x();

}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);
  recvdata();
  if (Serial1.available())
    x();
}
void x()
{
  for (int i = 0; i < 10; i++)
  {
    Serial.print(i);
    Serial.println(" ");
    Serial.println(recvchars[i]);
    Serial.println();

    //    Serial.println();

  }
}
void recvdata() {
  static boolean recvinprogress = false;
  static byte ndx = 0;
  char startmarker = '<';
  char comma = ',';
  char endmarker = '>';
  char c;

  while (Serial1.available() > 0 && newdata == false) {
    c = Serial1.read();

    if (c == startmarker)recvinprogress = true;

    else if (c == endmarker) {
      recvinprogress = false;
      ndx = 0;
      newdata = true;
    }
    if (recvinprogress == true && c != comma) {
      recvchars[ndx] = c;
      ndx++;
    }


  }
}
