//sending
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); //rx pin,tx pin
int otp = 1;
int a[] = {1, 5, 125};
int ax = 100;


void setup() {
  // put your setup code here, to run once:
  mySerial.begin(115200);



}

void loop() {
  // put your main code here, to run repeatedly:
  senddata2();
}

void senddata() {
  int i;
  mySerial.print("<");
  for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  {
    mySerial.print(a[i]);
    mySerial.print(",");

  }
  mySerial.print(">");

}


void senddata2() {
  int i;
  mySerial.print("<");
  mySerial.print(ax);
  mySerial.print(",");
  mySerial.print(">");

}
