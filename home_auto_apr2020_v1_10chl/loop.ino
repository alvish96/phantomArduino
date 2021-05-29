
void loop()
{
  //Serial.println(millis()/1000);
  //  Serial.println(a1 + x1 / 1000);

  if (ft1 == 1)
  {

    if (millis() > (a1 + x1) )   //threshold for keeping light on
    {
      digitalWrite(s1, LOW);
      Serial.println("main light timer off");
      f1 = LOW; a1 = 0; x1 = 0; ft1 = 0;
      pf();
    }
  }

  else if (ft2 == 1)
  {

    if (millis() > (a2 + x2))
    {
      digitalWrite(s2, LOW);
      Serial.println("led light timer off");
      f2 = LOW; a2 = 0; x2 = 0; ft2 = 0;
      pf();
    }
  }

  else if (ft3 == 1)
  {

    if (millis() > (a3 + x3))
    {
      digitalWrite(s3, LOW);
      Serial.println("fan timer off");
      f3 = LOW; a3 = 0; x3 = 0; ft3 = 0;
      prflag = temp;
      pf();
    }
  }
  else if (ft4 == 1)
  {

    if (millis() > (a4 + x4))
    {
      digitalWrite(s4, LOW);
      Serial.println("exhaust timer off");
      f4 = LOW; a4 = 0; x4 = 0; ft4 = 0;
      prflag = temp;
      pf();
    }
  }

  else if (ft5 == 1)
  {

    if (millis() > (a11 + x11) )   //threshold for keeping light on
    {
      digitalWrite(s5 , LOW);
      Serial.println("SURROUND SOUND timer off");
      f5  = LOW; a5  = 0; x5  = 0; ft5  = 0;
      pf();
    }
  }
  else if (ft6  == 1)
  {

    if (millis() > (a6  + x6 ) )   //threshold for keeping light on
    {
      digitalWrite(s6 , LOW);
      Serial.println("PROJECTOR timer off");
      f6  = LOW; a6  = 0; x6  = 0; ft6  = 0;
      pf();
    }
  }
  else if (ft7  == 1)
  {

    if (millis() > (a7  + x7 ) )   //threshold for keeping light on
    {
      digitalWrite(s7 , LOW);
      Serial.println("CHARGER timer off");
      f7  = LOW; a7  = 0; x7  = 0; ft7  = 0;
      pf();
    }
  }
  else if (ft8  == 1)
  {

    if (millis() > (a8  + x8 ) )   //threshold for keeping light on
    {
      digitalWrite(s8 , LOW);
      Serial.println("SWITCH timer off");
      f8  = LOW; a8  = 0; x8  = 0; ft8  = 0;
      pf();
    }
  }

  
  else if (ft9  == 1)
  {

    if (millis() > (a9  + x9 ) )   //threshold for keeping light on
    {
      digitalWrite(s9 , LOW);
      Serial.println("SWITCH timer off");
      f9  = LOW; a9  = 0; x9  = 0; ft9  = 0;
      pf();
    }
  }

  else if (ft10 == 1)
  {

    if (millis() > (a10 + x10) )   //threshold for keeping light on
    {
      digitalWrite(s10, LOW);
      Serial.println("SWITCH timer off");
      f10 = LOW; a10 = 0; x10 = 0; ft10 = 0;
      pf();
    }
  }

  else if (ft11 == 1)
  {

    if (millis() > (a11 + x11) )   //threshold for keeping light on
    {
      digitalWrite(s11, LOW);
      Serial.println("SWITCH timer off");
      f11 = LOW; a11 = 0; x11 = 0; ft11 = 0;
      pf();
    }
  }

  //__________________________________________________________________________________________
  
  else if (ftres == 1)
  {
    if (millis() > (ares + xres))
    {
      resetFunc();
    }
  }

  //__________________________________________________________________________________________
  present = millis() / 1000;
  if (prflag == 1)
  {
    goto point;
  }
  gapstt(4);
  Serial.print(" not skipping");
point:
  //
  //  {
  //    checkmotion = 0;
  //  }

  if (checkmotion == 1)
  {
    if (motion() == 1)
    {
      if (brt() < limit)
      {
        SW1();
        delay(1000);
        //mf1 = 0;
        count = 0;
      }
    }

  }

  printvals();
  irtest();
}
