//---------------------------------------------------------------------------------------------------
void SW1t(int ma1)
{
  a1 = 0;
  x1 = 0;
  x1 = ma1 * 60000;
  digitalWrite(s1, HIGH);
  //    Serial.println("fan is on for 5 mins");
  a1 = millis();
  //  Serial.println("set millis");
  f1 = HIGH; ft1 = HIGH;
  Serial.println("main light timer on");
}

void SW2t(int ma2)
{
  a2 = 0;
  x2 = 0;
  x2 = ma2 * 60000;
  digitalWrite(s2, HIGH);
  //    Serial.println("light is on for 5 mins");
  a2 = millis();
  //  Serial.println("set millis");
  f2 = HIGH; ft2 = HIGH;
  Serial.println("led timer on");
}
void SW3t(int ma3)
{
  a3 = 0;
  x3 = 0;
  x3 = ma3 * 60000;
  digitalWrite(s3, HIGH);
  //    Serial.println("light is on for 5 mins");
  a3 = millis();
  //  Serial.println("set millis");
  f3 = HIGH; ft3 = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("fan timer on");
  Serial.println("priority set");
}

void SW4t(int ma4)
{
  a4 = 0;
  x4 = 0;
  x4 = ma4 * 60000;
  digitalWrite(s4, HIGH);
  //    Serial.println("light is on for 5 mins");
  a4 = millis();
  //  Serial.println("set millis");
  f4 = HIGH; ft4 = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("Exhaust timer on");
  Serial.println("priority set");
}

//__________________________________________________________________________________________
void SW5t(int ma5)
{
  a5 = 0;
  x5  = 0;
  x5  = ma5  * 60000;
  digitalWrite(s5 , HIGH);
  //    Serial.println("fan is on for 5 mins");
  a5  = millis();
  //  Serial.println("set millis");
  f5  = HIGH; ft5  = HIGH;
  Serial.println("surround sound timer on");
}

void SW6t (int ma6 )
{
  a6  = 0;
  x6  = 0;
  x6  = ma6  * 60000;
  digitalWrite(s6 , HIGH);
  //    Serial.println("light is on for 5 mins");
  a6  = millis();
  //  Serial.println("set millis");
  f6  = HIGH; ft6  = HIGH;
  Serial.println("PROJECTOR timer on");
}
void SW7t (int ma7 )
{
  a7  = 0;
  x7  = 0;
  x7  = ma7  * 60000;
  digitalWrite(s7 , HIGH);
  //    Serial.println("light is on for 5 mins");
  a7  = millis();
  //  Serial.println("set millis");
  f7  = HIGH; ft7  = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("CHARGER timer on");
  Serial.println("priority set");
}

void SW8t (int ma8 )
{
  a8  = 0;
  x8  = 0;
  x8  = ma8  * 60000;
  digitalWrite(s8 , HIGH);
  //    Serial.println("light is on for 5 mins");
  a8  = millis();
  //  Serial.println("set millis");
  f8  = HIGH; ft8  = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("SWITCH timer on");
  Serial.println("priority set");
}

void SW9t (int ma9 )// 1 IS OFF 0 IS ON
{
  a9  = 0;
  x9  = 0;
  x9  = ma9  * 60000;
  f9  =pron; ft9  = HIGH;
  digitalWrite(s9 ,pron);
   a9  = millis();
  
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("PROJECTOR timer on");
  Serial.println("priority set");
}

void SW10t(int ma10)
{
  a10 = 0;
  x10 = 0;
  x10 = ma10 * 60000;
  digitalWrite(s10, HIGH);
  //    Serial.println("light is on for 5 mins");
  a10 = millis();
  //  Serial.println("set millis");
  f10 = HIGH; ft10 = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("SWITCH timer on");
  Serial.println("priority set");
}

void SW11t(int ma11)
{
  a11 = 0;
  x11 = 0;
  x11 = ma11 * 60000;
  digitalWrite(s11, HIGH);
  //    Serial.println("light is on for 5 mins");
  a11 = millis();
  //  Serial.println("set millis");
  f11 = HIGH; ft11 = HIGH;
  temp = prflag;
  prflag = 1; //setting priority to timer
  Serial.println("SWITCH timer on");
  Serial.println("priority set");
}
