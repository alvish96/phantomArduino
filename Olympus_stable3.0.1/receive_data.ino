
void rxt()
{
  byte datalen = mySerial.available();

  if ( datalen > 0)
  {
    i = 0;
    line();
    Serial.print(" INCOMING LENGTH ");
    Serial.print(datalen);
    line();
    while (mySerial.available() > 0)
    {
      Serial.print(" i ");
      Serial.print(i);

      datax = mySerial.read();
      delay(5);
      Serial.print(" CURRENT BYTE ");
      Serial.print(datax);
      i++;
      line();
      
    }
  }
}
