
char s[]="add";
void fn4(unsigned int)
{
Serial.println(s);  
}



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
   
    Serial.print(F("I received: "));
    Serial.println(incomingByte,DEC);
a:
Serial.print(F(""));
  }
}

/*
void test()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(100);
  digitalWrite(led1,LOW);
  delay(300);
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led2,LOW);
  delay(100);
  
}
*/
