
//1.8

/*
  unsigned int data3;         //present-lastmotion
  int data4;  //brt
  byte data5, data10[num], data11[num],limit //mtncnt  // minutes // seconds
  lastmotion secondmotion firstmotion lastm
  // map(val, 0, 1023, 0, 255);

  reqcode[0] = 248;
  reqcode[1] = 249;
  reqcode[2] = 250;
  reqcode[3] = 251;
  reqcode[4] = 252;
  reqcode[10] = 247;

  case reqcode[0] : event(0); break;
      case reqcode[1] : event(1); break;
      case reqcode[2] : event(2); break;
      case reqcode[3] : event(3); break;
      case reqcode[4] : event(4); break;
      case reqcode[10]: event(10); break;

*/



void fn4()//1.8
{
  assignt = 1;
  if (look) Serial.println(F("ASSIGNING"));

  databool0[0] =  0;
  databool0[1] =  checkmotion;
  databool0[2] =  minor;
  databool0[3] =  fromhere;
  databool0[4] =  CRF;
  databool0[5] =  wait;
  databool0[6] =  ato;
  databool0[7] =  priority;
  databool0[8] =  temp;
  databool0[9] =  mute;
  databool0[10] = look;
  databool0[11] = transmit;
  databool0[12] = flag2;
  databool0[13] = timeroff;
  databool0[14] = debugg;
  databool0[15] = deepc;
  databool0[16] = req;
  databool0[17] = rem;
  databool0[18] = all0;
  databool0[19] = motionstate;
  databool0[20] = testing;
  databool0[21] = TMD;
  for (int i = 1; i < num + 1; i++)
  {
    databool1[i] = mod[i].state;
    databool2[i] = mod[i].flag;
    databool3[i] = mod[i].relaytype;
    databool4[i] = mod[i].prtemp;
  }

  databyte0[1] = brt();
  databyte0[2] = motioncount;

  fn9();
  fn10((present - lastm), 1);
  fn10(present,           2);
  fn10(lastmotion,        3);
  fn10(lastm,             4);
  fn10(secondmotion,      5);
  fn10(firstmotion,       6);

  //  digitalRead(pirpin);

  if (look)Serial.println(F("ASSIGNMENT DONE"));
}



void onReq()
{
  while ((mySerial.available() > 0) && recv == true)
  {
    datax = mySerial.read();
    if (look){Serial.print(F(" ")); Serial.print(datax);Serial.print(F(" "));}
    if (datax == reqcod)
    {
      sent = 0;
      req = 1;
    }
    else if (datax == cbyte)
    {
      scon = 1;
      //do control from here
    }
    else
    {
      req = 0;
      scon = 0;
    }

    datanx = mySerial.read();
    if (look){Serial.print(F(" ")); Serial.print(datanx);Serial.print(F(" "));}
    if (scon)
    {
      switch (datanx)
      {
        case 233 : TMD = 1; break;
        case 234 : TMD = 0; break;
        case 210 : concode = 1; break;
        case 211 : concode = 2 ; break;
        case 212 : concode = 3 ; break;
        case 213 : concode = 4 ; break;
        case 214 : concode = 5 ; break;
        case 215 : concode = 6 ; break;
        case 216 : concode = 7 ; break;
        case 217 : concode = 8 ; break;
        case 218 : concode = 9 ; break;
        case 219 : concode = 10; break;
        case 220 : concode = 11 ; break;
        case 221 : concode = 12 ; break;
        case 222 : concode = 30 ; break;
        default: concode = 0;
      }
      serialcontrol();
    }
    if (req)
      switch (datanx)
      {

        case 240 : event(5); break;//hr
        case 241 : event(6); break;//mi
        case 242 : event(7); break;//se

        case 243 : event(8); break;//hr
        case 244 : event(9); break;//mi
        case 245 : event(10); break;//se

        case 246 : event(11); break;

        case 247 : event(30); break;

        case 248 : event(0); break;
        case 249 : event(1); break;
        case 250 : event(2); break;
        case 251 : event(3); break;
        case 252 : event(4); break;


      }

  }
  //  event);
  recv = true;
  flushdata();
  delay(5);
}

void event(byte a)
{
  if (req == 1 )
  {
    senddata(a);
    mySerial.flush();//Waits for the transmission of outgoing serial data to complete.
    req = 0;
  }
}

void senddata(byte a)//1.8    //senddata
{
  fn4(); //assign before sending
  if (sent == 0)
    if (transmit == 1)
    {
      if (look)Serial.println(F("TRANSMITTING"));
      unsigned long x1 = millis();
      mySerial.write(STC); // start of transmission   0
      switch (a)
      {
        case 0: senddb0(); break;
        case 1: senddb1(); break;
        case 2: senddb2(); break;
        case 3: senddb3(); break;
        case 4: senddb4(); break;

        case 5: senddb5(); break;//hr
        case 6: senddb6(); break;//mi
        case 7: senddb7(); break;//se

        case 8: senddb8(); break;//hr
        case 9: senddb9(); break;//mi
        case 10: senddb10(); break; //se

        case 11: senddb11(); break;

        case 30: sendall(); break;
      }
      mySerial.write(ETC); //end of transmission  69
      sent = 1;
      //     sflush();

      if (look)  Serial.println(F("TRANSMITTING DONE"));
      if (look)
      {
        Serial.print(F(" TRANSMIT TIME "));
        Serial.print((millis() - x1));
        Serial.print(F(" ms "));
        line();
      }
    }
}
void sflush()
{
  //   mySerial.flush();//Waits for the transmission of outgoing serial data to complete.
}
void sendall()
{
  for (int i = 0; i < 5; i++)
  {
    senddata(i);
    sent = 0;
  }
  sent = 1;
}


void senddb0()
{
  mySerial.write(248);
  for (int i = 1; i < 31 ; i++)
  {
    mySerial.write(databool0[i]);     //20bits 0-19    1-20
    if (deepc) Serial.print(databool0[i]);
  }
  sflush();
}
void senddb1()
{
  mySerial.write(249);
  for (int i = 1; i < num + 1; i++)     //11bits 0-10    21-32
  {
    mySerial.write(databool1[i]);
    if (deepc) Serial.print(databool1[i]);
  }
  sflush();
}
void senddb2()
{
  mySerial.write(250);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    33-44
  {
    mySerial.write(databool2[i]);
    if (deepc) Serial.print(databool2[i]);
  }
  sflush();
}
void senddb3()
{
  mySerial.write(251);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    45-56
  {
    mySerial.write(databool3[i]);
    if (deepc) Serial.print(databool3[i]);
  }
  sflush();
}
void senddb4()
{
  mySerial.write(252);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databool4[i]);
    if (deepc) Serial.print(databool4[i]);
  }
  sflush();
}

void senddb5()
{
  mySerial.write(240);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte1[i]);
    if (deepc) Serial.print(databyte1[i]);
  }
  sflush();
}
void senddb6()
{
  mySerial.write(241);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte2[i]);
    if (deepc) Serial.print(databyte2[i]);
  }
  sflush();
}
void senddb7()
{
  mySerial.write(242);
  for (int i = 1; i < num + 1 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte3[i]);
    if (deepc) Serial.print(databyte3[i]);
  }
  sflush();
}

void senddb8()
{
  mySerial.write(243);
  for (int i = 1; i < 11 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte4[i]);
    if (deepc) Serial.print(databyte4[i]);
  }
  sflush();
}
void senddb9()
{
  mySerial.write(244);
  for (int i = 1; i < 11 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte5[i]);
    if (deepc) Serial.print(databyte5[i]);
  }
  sflush();
}
void senddb10()
{
  mySerial.write(245);
  for (int i = 1; i < 11 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte6[i]);
    if (deepc) Serial.print(databyte6[i]);
  }
  sflush();
}

void senddb11()
{
  mySerial.write(246);
  for (int i = 1; i < 21 ; i++)    //11bits 0-10    57-68
  {
    mySerial.write(databyte0[i]);
    if (deepc) Serial.print(databyte0[i]);
  }
  sflush();
}

void flushdata()
{
  bool x = 0;
  if (x)
    for (int i = 0; i < 50; i++)
    {
      databool0[i] = 0;
      databool1[i] = 0;
      databool2[i] = 0;
      databool3[i] = 0;
      databool4[i] = 0;
    }
}


void fn9() //assigntime data
{
  int x;
  for (int i = 1; i < 12; i++)
  {
    if (timelook)
    {
      Serial.print(F(" i "));
      Serial.print(i);
    }
    x = (mod[i].total / 1000) - (millis() / 1000);
    if (mod[i].flag == HIGH)
    {
      if (x < 50000)
      {
        mod[i].se = x % 60;
        x = (x - mod[i].se) / 60;
        mod[i].mi = x % 60;
        x = (x - mod[i].mi) / 60;
        mod[i].hr = x % 60;
        if (assignt)
        {
          databyte1[i] = mod[i].hr;
          databyte2[i] = mod[i].mi;
          databyte3[i] = mod[i].se;
        }
      }
    }

    else
    {
      mod[i].hr = mod[i].se = mod[i].mi = 0;
    }
    if (timelook)
    {
      Serial.print(F(" hr "));
      Serial.print(mod[i].hr);
      Serial.print(F(" mi "));
      Serial.print(mod[i].mi);
      Serial.print(F(" se "));
      Serial.print(mod[i].se);
      line();
    }
  }
}

void fn10(unsigned long x, byte x1)  //x=time in seconds  x1=assign to
{
  if (assignt)
  {
    if (x < 50000)
    {
      databyte6[x1] = x % 60;
      x = (x - databyte6[x1]) / 60;
      databyte5[x1] = x % 60;
      x = (x - databyte5[x1]) / 60;
      databyte4[x1] = x % 60;
    }
    else
    {
      databyte4[x1] =  databyte5[x1] = databyte6[x1] = 0;
    }

    if (timelook)
    {
      Serial.print(F(" hr "));
      Serial.print( databyte4[x1]);
      Serial.print(F(" mi "));
      Serial.print(databyte5[x1]);
      Serial.print(F(" se "));
      Serial.print(databyte6[x1]);
      line();
    }
  }
}
