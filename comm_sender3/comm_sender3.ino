
//sending
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); //rx pin,tx pin
int otp = 1;
unsigned int a[] = {1, 5, 125,127,128,255,256,500,1024};
 

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);

  // put your main code here, to run repeatedly:
  if (otp == 1)
  {
    senddata();
    
    otp = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//  if (otp == 1)
//  {
//    senddata();
//    otp = 0;
//  }

//    senddata();
}

void senddata() {
  int i;
  mySerial.print("<");
  for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    mySerial.write(a[i]);
    mySerial.print(",");

  }
  mySerial.print(">");
}
