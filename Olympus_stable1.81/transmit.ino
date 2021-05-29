//1.8
/*
const int num = 11;
bool data1[num];             // state
bool data2[num];              //temp
unsigned int data3;         //present-lastmotion
int data4;  //brt
byte data5, data10[num], data11[num]; limit //mtncnt  // minutes // seconds
lastmotion secondmotion firstmotion lastm


bool databool0[13];
bool databool1[num];  //state
bool databool2[num];  //flag
bool databool3[num];  //relaytype
bool databool4[num];  //prtemp


void fn4()//1.8
{
  if (look) Serial.println(F("ASSIGNING"));
  
  databool0[0] = checkmotion;
  databool0[1] = motionstate;
  databool0[2] = minor;
  databool0[3] = fromhere;
  databool0[4] = CRF;
  databool0[5] = wait;
  databool0[6] = ato;
  databool0[7] = priority;
  databool0[8] = temp;
  databool0[9] = mute;
  databool0[10] = look;
  databool0[11] = transmit;
  databool0[12] = flag2;
  databool0[13] = timeroff;
  databool0[14] = debugg;
  for (int i = 1; i < num + 1; i++)
  {
    databool1[i] = mod[i].state;
    databool2[i] = mod[i].flag;
    databool3[i] = mod[i].relaytype;
    databool4[i] = mod[i].prtemp;








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

  void fn5()//1.8
  {
    if (transmit == 1)
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

  void fn8()//1.8
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
  }*/
