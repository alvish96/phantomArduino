void timeprint(bool b)
{
  if (b)
  {
    Serial.print(F("|"));
    Serial.print(thour);       Serial.print(F(":"));
    Serial.print(tmin);       Serial.print(F(":"));
    Serial.print(tsec);       Serial.print(F("|"));
  }
  else
  {

  }
}

void fn2()
{
  duration1 = 60;
  turnoff();
}
void test()
{
  if (testing)
  {
    mute = 1;
    checkmotion = 0;
  }
  else if (!testing)
  {
    mute = 0;
    checkmotion = 1;
  }

}

void fn3(byte x, byte y = 1)
{
  y = y * 60;
  if (mod[x].state == mod[x].relayoff)
  {
    mod[x].SW();
    mod[x].mark1 = millis() / 1000;
  }
  else if (mod[x].state == mod[x].relayon)
  {
    mod[x].mark2 = millis() / 1000;
    if ((mod[x].mark2) - (mod[x].mark1) > y)
      mod[x].SWtimer(1);
    else
      mod[x].SW();
  }
}

void line()//1.83
{
  if (debugg)Serial.println();
}
void spacer()//1.90
{
  if (debugg)
  {
    Serial.print(F(" *************************************************************************************************** "));
    line();
    Serial.print(F(" *************************************************************************************************** "));
    line();

  }
}

void turnoffex()
{
  for (int i = 1; i < 12; i++)
    mod[i].SWoff();
  sync();
}

void turnoff()
{ SF = 0; TD2();
  for (int i = 1; i < 12; i++)
    if (mod[i].state == mod[i].relayon)
      mod[i].SWoff();
  line();//1.83
  sync();
}

void sync()
{
  priority = !checkmotion; Serial.print("  sync!  ");
}

void checktimer()
{
  byte x = 0;
  for (int i = 1; i < 12; i++)
  {
    x += mod[i].flag;
  }
  if (x == 0) timeroff = HIGH;
  else timeroff = LOW;
}

void AUTO() //
{
  ato = 1;
  checkmotion = !checkmotion;
  priority = !checkmotion;
  motioncount = 0; //1.71
  //  if (checkmotion == 1)//1.82
  resetmotion();//1.72

  Serial.println(F(" MOTION SWITCH "));
  //  lcd.setCursor(0, 1);
  if (checkmotion == 1)Serial.println(F("motion switch on"));
  if (checkmotion == 0)Serial.println(F("motion switch off"));
}

int brt()
{
  int n = smooth;
  for (int i = n; i > 0; i--)
  {
    last[i] = last[i - 1];
  }
  last[0] = analogRead(ldr) / 10;
  brttot = 0;
  for (int j = 0; j < n; j++)
  {
    brttot += last[j];
  }
  average = brttot / n;
  return average;
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------




void sequence()
{
  // definepin();
  deftype();    //define relay type normal or flipped
  line();//1.83
  initialise();   //call initialise function for each switch
  line();//1.83
  setinitial();   //set initial values for each switch
  line();//1.83
}
void sequence1()//1.90
{
  for (int i = 1; i < 12; i++)
  {
    Serial.print(F(" SWITCH "));
    Serial.print(i);
    if (i < 5 )
      mod[i].definetype(1);
    if (i > 4 && i < 12)
      mod[i].definetype(0);
    mod[i].SWoff();
    mod[i].state = mod[i].relayoff;
    mod[i].initialise();

  }
  spacer();
}



void deftype()  //v
{
  for (int i = 1; i < 12; i++)
  {
    if (i < 5 )
      mod[i].definetype(1);
    if (i > 4 && i < 11)
      mod[i].definetype(0);
    if (i == 11)
      mod[i].definetype(0);
  }
}

void setinitial() //v
{
  for (int i = 1; i < 12; i++)
  {
    mod[i].SWoff();
    mod[i].state = mod[i].relayoff;
  }
}


void initialise()  //v
{
  for (int i = 0; i < 12; i++)
    mod[i].initialise();
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void updatemotion()
{
  lastm = secondmotion;
  secondmotion = firstmotion;
  firstmotion = lastmotion;
}
void resetmotion()
{
  lastmotion = millis() / 1000;
  firstmotion = lastmotion;
  secondmotion = lastmotion;
  lastm = lastmotion;
}
void gapstt(int gap)
{

  Serial.print((present - lastmotion));
  if ((present - lastmotion) > (gap * 60))
  {
    tune(9);
    turnoff();
    wait = 1;
    //resetFunc();
  }
}

void gapstt2(int gap)
{
  if (debugg)
    Serial.print((present - lastm));
  if ((present - lastm) > (gap * 60))
  {
    resetmotion();//1.82
    tune(9);
    turnoff();
    wait = 1;

  }

  //  if ((present - lastm) > (20 * 60)) //1.84
  //    resetFunc(); //1.85
  //  resetmotion();
}

void setall0()//1.88
{
  byte z = 0;
  for (int i = 1; i < 12; i++)
  {
    if (mod[i].state == mod[i].relayon)
      z += 1;
  }
  if (z > 0)
    all0 = 0;//false some are on
  if (z == 0)
    all0 = 1;//true all are off
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
