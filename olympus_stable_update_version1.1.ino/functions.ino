/*void RESW() 
{
  checkmotion = !checkmotion;
  prflag = !prflag;
  
  Serial.println("MOTION SWITCH");
  //  lcd.setCursor(0, 1);
  if (checkmotion == 1)Serial.println("motion switch on");
  if (checkmotion == 0)Serial.println("motion switch off");

}

*/

void gapstt(int gap)
{
  if ((present - lastmotion) > (gap * 60))
  {
    resetFunc();
  }
}


void RESW(){}

void mutesw()
{
  mute = !mute;
}

int brt()
{
  ldrval = analogRead(A7);
  delay(100);
  // Serial.println(ldrval);
  return ldrval;
}

void buzz(int n) 
{ 
  if(mute==0) 
{
  int del = 10;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
}
