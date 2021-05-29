void fn2()
{
  duration = 60;
  turnoff();
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



void turnoffex()
{
  for (int i = 1; i < 12; i++)
    mod[i].SWoff();
  sync();
}

void turnoff()
{
  for (int i = 1; i < 12; i++)
    if (mod[i].state == mod[i].relayon)
      mod[i].SW();
  sync();
}

void sync()
{
  priority = !checkmotion; Serial.print("   sync!  ");
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
  initialise();   //call initialise function for each switch
  setinitial();   //set initial values for each switch
}



void deftype()  //v
{
  for (int i = 1; i < 12; i++)
  {
    if (i < 5)
      mod[i].definetype(1);
    if (i > 4)
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
  {
    Serial.print((present - lastm));
  }

  if ((present - lastm) > (gap * 60))
  {
    tune(9);
    turnoff();
    wait = 1;
    resetmotion();
    //resetFunc();
  }
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
