#include <IRremote.h>
int pushButton = 2;
int a =6;
int b=A0;
//#define PIN
//#define G A7
IRrecv irrecv(a);
decode_results results;

void setup()
{ 
  pinMode(13, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
  digitalWrite(b, 0);
  digitalWrite(13, 1);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
//Serial.println("prog");
  if (irrecv.decode(&results)) {
      digitalWrite(13, 0);
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    
  }
}
