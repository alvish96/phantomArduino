
#define IRSensor A3 // connect ir sensor to arduino pin 2
#define LED A2



void setup()
{

Serial.begin(9600);

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
}

void loop()
{
  int statusSensor = digitalRead(IRSensor);

  if (statusSensor == 1)
  {
   Serial.println("LOW");
    digitalWrite(LED, LOW); // LED LOW
    
  }

else
{
  Serial.println("HIGH");
  digitalWrite(LED, HIGH); // LED High
   
}

}
