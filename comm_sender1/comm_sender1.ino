
//sending
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5,6); //rx pin,tx pin

void setup() {
  // put your setup code here, to run once:
mySerial.begin(9600);
}
int otp=1;
int a[]={1,5,125};

void loop() {
  // put your main code here, to run repeatedly:
if(otp==1){
  senddata();
  otp=0;
}
}

void senddata(){
   int i;
   mySerial.print("<");
   for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
      mySerial.print(a[i]);
      mySerial.print(",");
   
   }
   mySerial.print(">");
}
