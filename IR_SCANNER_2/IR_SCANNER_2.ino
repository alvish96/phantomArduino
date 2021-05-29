#include <IRremote.h>
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long val1= 0x61D650AF;
unsigned long val2= 0x61D652AD;
#define led 13
bool state=0;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
pinMode(led,OUTPUT);

}




void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
 
  sw2();delay(500);
  }
}


void sw1()
{
  if (results.value == val1 )
{digitalWrite(led,HIGH);    Serial.println("led on");}
  else if(results.value == val2 )
{digitalWrite(led,LOW);Serial.println("led off");}

else {digitalWrite(led,LOW);     Serial.println("invalid code");}
  }

void sw2(){
    if (results.value == val1 )
    state=!state;
    digitalWrite(led,state);
    if(state==HIGH)  Serial.println("led on");
//if(state==LOW)
else Serial.println("led off");
    }

