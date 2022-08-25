#include<Wire.h>

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println ("This is the nano with address 0x11");
  Wire.begin(0x11);
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(400);     
}
