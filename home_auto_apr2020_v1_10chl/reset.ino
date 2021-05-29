void reset(int mares)
{
  ares = 0;
  xres = 0;
  xres = mares * 1000;
  ares = millis();
  //  f5 = HIGH;
  ftres = HIGH;
  Serial.println();
  Serial.println("Reset initiated 20 seconds");/*
  a5 = 0;
  x5 = 0;
  x5 = ma5 * 1000;
  a5 = millis();
  //  f5 = HIGH;
  ft5 = HIGH;
  Serial.println();
  Serial.println("Reset initiated 20 seconds");*/
}

//---------------------------------------------------------------------------------------------------

void wait(int n)
{
  delay(n * 60000);
}

//---------------------------------------------------------------------------------------------------
void RESW() // SW5()
{
  checkmotion = !checkmotion;
  prflag = !prflag;
  //  ft1 = !ft1;
  //  ft2=0;
  //  ft3=0;
  //  ft4=0;
  //
  Serial.println("MOTION SWITCH");
  //  lcd.setCursor(0, 1);
  if (checkmotion == 1)Serial.println("motion switch on");
  if (checkmotion == 0)Serial.println("motion switch off");

}
//---------------------------------------------------------------------------------------------------

void fan()
{
  SW3();
  
}
