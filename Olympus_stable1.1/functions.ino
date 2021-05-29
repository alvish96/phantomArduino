void turnoff()
{
  for (int i=1;i<12;i++)
  mod[i].SWoff();
}


void AUTO() //
{
  checkmotion = !checkmotion;
  priority = !priority;
  Serial.println(" MOTION SWITCH ");
  //  lcd.setCursor(0, 1);
  if (checkmotion == 1)Serial.println("motion switch on");
  if (checkmotion == 0)Serial.println("motion switch off");
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

void buzz(int n)
{
  if (mute == 0)
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

void mutesw()
{
  mute = !mute;
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


void gapstt(int gap)
{ Serial.println((present - lastmotion));
  if ((present - lastmotion) > (gap * 60))
  {
    turnoff();
    //resetFunc();
  }
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
/*
  int brt()
  {
  ldrval = analogRead(A7);
  delay(100);
  // Serial.println(ldrval);
  return ldrval;
  }


  int brt3()
  {
  if (deepc)
  { Serial.println();
    Serial.println();
    Serial.println();
  }
  int n = smooth;
  for (int i = n; i > 0; i--)
  {
    last[i] = last[i - 1];
    if (deepc)  {
      Serial.println();
      Serial.print("transfer  ");
      Serial.print(i);
      Serial.print("  value  ");
      Serial.print(last[i]);
      Serial.println();
    }
  }
  if (deepc) {
    Serial.println();
    Serial.println();
    Serial.println();
  }
  last[0] = analogRead(ldr) / 10;
  total = 0;
  for (int j = 0; j < n; j++)
  {
    total += last[j];
    if (deepc) {
      Serial.println();
      Serial.print("number  ");
      Serial.print(j);
      Serial.print("  value  ");
      Serial.print(last[j]);
      Serial.print("  total  ");
      Serial.print(total);
      Serial.println();
    }
  }
  if (deepc) {
    Serial.println();
    Serial.println();
    Serial.println();
  }
  average = total / n;
  if (deepc) {
    Serial.println("average");
    Serial.println("end of one cycle");
  }
  return average;
  }
*/



/*
  void deftype(int x)
  {
  mod[x].definetype(0);
  }
  void setinitial(int x)
  {
  mod[x].SWoff();
  mod[x].state = mod[x].relayoff;
  }
  void initialise(int x)
  {
  mod[x].initialise();
  }

*/
