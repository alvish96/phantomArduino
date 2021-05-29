
void SW1()
{
  f1 = !f1;
  digitalWrite(s1, f1);
  Serial.println("MAIN LIGHT");
  //  lcd.setCursor(0, 1);
  if (f1 == 1)Serial.println("light on");
  if (f1 == 0)Serial.println("light off");
  x1 = 0;
}

void SW2()
{
  f2 = !f2;
  digitalWrite(s2, f2);
  Serial.println("LED LIGHT");
  //  lcd.setCursor(0, 1);
  if (f2 == 1)Serial.println("light led on");
  if (f2 == 0)Serial.println("light led off");
  x2 = 0;
}

void SW3()
{
  f3 = !f3;
  digitalWrite(s3, f3);
  Serial.println("FAN");
  //  lcd.setCursor(0, 1);
  if (f3 == 1)Serial.println("fan on");
  if (f3 == 0)Serial.println("fan off");
  x3 = 0;
}

void SW4()
{
  f4 = !f4;
  digitalWrite(s4, f4);
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f4 == 1)Serial.println("exhaust on");
  if (f4 == 0)Serial.println("exhaust off");
  x4 = 0;
}
//__________________________________________________________________________________________

void SW5 ()
{
  f5  = !f5 ;
  digitalWrite(s5 , f5 );
  Serial.println("SURROUND SOUND");
  //  lcd.setCursor(0, 1);
  if (f5  == 1)Serial.println("surround sound on");
  if (f5  == 0)Serial.println("surround sound off");
  x5  = 0;
}

void SW6 ()
{
  f6  = !f6 ;
  digitalWrite(s6 , f6 );
  Serial.println("PROJECTOR");
  //  lcd.setCursor(0, 1);
  if (f6  == 1)Serial.println("PROJECTOR on");
  if (f6  == 0)Serial.println("PROJECTOR off");
  x6  = 0;
}

void SW7 ()
{
  f7  = !f7 ;
  digitalWrite(s7 , f7 );
  Serial.println("CHARGER");
  //  lcd.setCursor(0, 1);
  if (f7  == 1)Serial.println("CHARGER on");
  if (f7  == 0)Serial.println("CHARGER off");
  x7  = 0;
}

void SW8 ()
{
  f8  = !f8 ;
  digitalWrite(s8 , f8 );
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f8  == 1)Serial.println("ADDN switch on");
  if (f8  == 0)Serial.println("ADDN switch off");
  x8  = 0;
}

void SW9 ()// 1 IS OFF 0 IS ON
{ 
  if (f9 == pron)
  {
    SW9t(1);
goto ennd;
  }
  
  if (f9 == proff)
  {
    f9  = !f9 ;
    digitalWrite(s9 , f9 );
    Serial.println(" PROJECTOR SWITCH ON");
goto ennd;
  }
ennd:
  if (f9  == pron)Serial.println("PROJECTOR ON");
  if (f9  == proff)Serial.println("PROJECTOR OFF");
  x9  = 0;
}

//void SW9 ()
//{
//  f9  = !f9 ;
//  digitalWrite(s9 , f9 );
//  Serial.println("SWITCH");
//  //  lcd.setCursor(0, 1);
//  if (f9  == 1)Serial.println("ADDN switch on");
//  if (f9  == 0)Serial.println("ADDN switch off");
//  x9  = 0;
//}

void SW10()
{
  f10 = !f10;
  digitalWrite(s10, f10);
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f10 == 1)Serial.println("ADDN switch on");
  if (f10 == 0)Serial.println("ADDN switch off");
  x10 = 0;
}
void SW11()
{
  f11 = !f11;
  digitalWrite(s11, f11);
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f11 == 1)Serial.println("ADDN switch on");
  if (f11 == 0)Serial.println("ADDN switch off");
  x11 = 0;
}
