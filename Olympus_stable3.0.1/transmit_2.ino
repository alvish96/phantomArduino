bool volt = 1; // voluntary flag
byte id;  //transmit id
void voltransmit()
{
  voltimer0();
  //  voltimer1();
}
void ASS() // ASSIGN DATA WITHOUT PRINTING STUFF
{
  bool a = timelook;
  bool b = look;
  timelook = 0;
  look = 0;
  fn4();
  timelook = a;
  look = b;
}

void TMD1() // TRANSMIT MOTION DATA AND MOTION COUNT AND STABILITY FLAG
{
  ASS();
  if (tmdf)
  {
    if (TMD && transmit)
    {
      mySerial.write(STC);
      mySerial.write(TMDon);
      mySerial.write(databool0[19]);
      mySerial.write(databyte0[2]);
      mySerial.write(ETC);
    }
    tmdf = 0;
  }
}
void TD1() // TRANSMIT CHECKMOTION DATA
{
  volsend(227, databool0[1]);
}
void TD2() // TRANSMIT STABILITY DATA
{
    volsend(226, databool0[22]);
}
void voltimer0()
{
  ASS();
  id = 229;
  if (volt)
  {
    mySerial.write(STC);
    mySerial.write(id);
    
    for (int i = 1; i < 11; i++)
    {
      mySerial.write(databyte4[i]);
      mySerial.write(databyte5[i]);
      mySerial.write(databyte6[i]);
    }
    mySerial.write(ETC);
  }
  id = 0;
}

void voltimer1() //SEND INDIVIDUAL TIME
{ id = 228;
  checktimer();
  if (timeroff == 0)
    if (volt)
    {
      mySerial.write(STC);
      mySerial.write(id);
      for (int i = 1; i < 12; i++)
      {
        if (mod[i].flag == 1)
        {
          fn4();
          mySerial.write(databyte1[i]);
          mySerial.write(databyte2[i]);
          mySerial.write(databyte3[i]);
        }
      }
      mySerial.write(ETC);
    }
  id = 0;
}

void volsend(byte id1, byte t)
{ id = id1;
  ASS();
  if (volt)
  {
    mySerial.write(STC);
    mySerial.write(id);

    mySerial.write(t);

    mySerial.write(ETC);
  }
  id = 0;
}
