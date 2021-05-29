char incomingByte = 0; // for incoming serial data

void in() 
{
  // send data only when you receive data:
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    if ((incomingByte == 10 )||(incomingByte == 13 ))
      goto a;
   
    Serial.print("I received: ");
    Serial.println(incomingByte,DEC);
a:
Serial.print("");
  }
}


void test()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(100);
  
}
