#define bl 6
#define wh 3

void setup() 
{
Serial.begine(9600);
pinMode(bl,OUTPUT);
pinMode(wh,OUTPUT);

 for (int i = 0; i < 256; i++)
  {
    analogWrite(pin, i);
    analogWrite(pin1, i);
   
    Serial.print(i);
    Serial.println();
    delay(35);
  }
  analogWrite(pin, 255);
  analogWrite(pin1, 255);

  delay(500);
  analogWrite(pin, 255);
  analogWrite(pin1, 255);

}


}

void loop() {

}
