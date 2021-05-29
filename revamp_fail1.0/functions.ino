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

void fn4()
{
 if (look) Serial.println(F("ASSIGNING"));
  for (int i = 1; i < num + 1; i++)
  {
    data1[i] = mod[i].state;
    data2[i] = mod[i].prtemp;
    data10[i] = fn6(i);
    data11[i] = fn7(i);
  }
  data3 =  (present - lastmotion);
  data4 = brt();
  data5 = motioncount;
  data6 = checkmotion;
  data7 = priority;
  data8 = wait;
  data9 = ato;
  data12 = look;
  data13 = debugg;
  data14 = transmit ;
  data15 = digitalRead(pirpin);
if (look)Serial.println(F("ASSIGNMENT DONE"));
}

void fn5()
{
  if (transmit==1)
  {
    if (look)Serial.println(F("TRANSMITTING"));
    unsigned long x1 = millis();
    mySerial.write(255); //0
    for (int i = 1; i < num + 1; i++)   //1-11
      mySerial.write(data1[i]);
    for (int i = 1; i < num + 1; i++)   //12-22
      mySerial.write(data2[i]);

    mySerial.write(data3);//23
    mySerial.write(data4);//24
    mySerial.write(data5);//25
    mySerial.write(data6);//26
    mySerial.write(data7);//27
    mySerial.write(data8);//28
    mySerial.write(data9);//29
    for (int i = 1; i < num + 1; i++) //30-40
      mySerial.write(data10[i]);
    for (int i = 1; i < num + 1; i++)//41-51
      mySerial.write(data11[i]);

    mySerial.write(data12);//52
    mySerial.write(data13);//53
    mySerial.write(data14);//54
    mySerial.write(data15);//55


    mySerial.write(254);
      if (look)  Serial.println(F("TRANSMITTING DONE"));
      
    if (look) {
      Serial.print(F(" TRANSMIT TIME "));
      Serial.print((millis() - x1));
      Serial.println();
    }
  }
}


byte fn6(int i)
{
  unsigned int totalseconds = mod[i].timerdisp();
  seconds = totalseconds % 60;
  totalseconds = (totalseconds - seconds) / 60;
  minutes = totalseconds % 60;
  return minutes;
}

byte fn7(int i)
{
  unsigned int totalseconds = mod[i].timerdisp();
  seconds = totalseconds % 60;
  totalseconds = (totalseconds - seconds) / 60;
  minutes = totalseconds % 60;
  return seconds;
}

void fn8()
{
  if (look)
  {
    Serial.println();
    unsigned long x1 = millis();
    Serial.print(F(" "));
    for (int i = 1; i < num + 1; i++)                 //1-11
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data1 RELAY STATE "));
      Serial.print(data1[i]);
      Serial.println();
    }

    for (int i = 1; i < num + 1; i++) //11+1-11+11   12-22
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data2 PRIORITY TMP "));
      Serial.print(data2[i]);
      Serial.println();
    }

    Serial.print(F(" data3 COUNTDOWN "));
    Serial.print(data3);       //23
    Serial.print(F(" data4 BRIGTNESS "));
    Serial.print(data4);       //24
    Serial.print(F(" data5 MOTIONCOUNT "));
    Serial.print(data5);       //25
    Serial.print(F(" data6 CHECKMOTION "));
    Serial.print(data6);       //26
    Serial.print(F(" data7 PRIORITY "));
    Serial.print(data7);        //27
    Serial.print(F(" data8 WAIT "));
    Serial.print(data8);        //28
    Serial.print(F(" data9 AUTO "));
    Serial.print(data9);        //29

    for (int i = 1; i < num + 1; i++) //30-40
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data10 MINUTES "));
      Serial.print(data10[i]);
      Serial.println();
    }
    for (int i = 1; i < num + 1; i++) //41-51
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data11 SECONDS "));
      Serial.print(data11[i]);
      Serial.println();
    }
    Serial.print(F(" data12 LOOK "));
    Serial.print(data12);        //52
    Serial.print(F(" data13 DEBUG "));
    Serial.print(data13);        //53
    Serial.print(F(" data14 TRANSMIT "));
    Serial.print(data14);        //54
    Serial.print(F(" data15 MOTION "));
    Serial.print(data15);        //55
    Serial.println();
    
    Serial.println((millis() - x1) );

  }
}
void turnoff()
{
  for (int i = 1; i < 12; i++)
    mod[i].SWoff();
  sync();
}
void sync()
{
  priority = !checkmotion;
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
