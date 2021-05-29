#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>

int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
 // Serial.println("start");
  if (irrecv.decode(&results)) {
    
  //Serial.println("printing value");
    Serial.println(results.value,HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(1000);
  
}
