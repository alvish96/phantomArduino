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
