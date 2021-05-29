#include <SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR

int sensorValue = 0; // variable to store the value coming from the sensor

int led = 3;
int led1 =4;

void setup() { // declare the ledPin as an OUTPUT:

pinMode(led, OUTPUT);
pinMode(led1, OUTPUT);
Serial.begin(9600); }

void loop()

{

Serial.println("");

sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if (sensorValue < 350)

{

Serial.println("LED light on");

digitalWrite(led,HIGH);digitalWrite(led1,HIGH);

delay(1000);

}


digitalWrite(led,LOW);digitalWrite(led1,LOW);

delay(sensorValue);

}
