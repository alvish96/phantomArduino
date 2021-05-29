
void colo(byte x1, byte x2, byte x3)//1.1
{
  analogWrite(r, x1); analogWrite(g, x2); analogWrite(b, x3);
}
void color(int x)
{

  rinten = inten;
  binten = inten;
  ginten = inten;
  if (ledf)
    switch (x)
    {

      case 0:  colo(maxx,   maxx,    maxx);    break;  //black
      case 1:  colo(rinten, maxx,    maxx);    break; //red
      case 2:  colo(maxx,   ginten,  maxx);    break; //gre
      case 3:  colo(maxx,   maxx,    binten);  break; //blu
      case 4:  colo(rinten, ginten,  maxx);    break; //yllw
      case 5:  colo(rinten, maxx,    binten);  break; //magenta
      case 6:  colo(maxx,   ginten,  binten);  break; //cyan
      case 7:  colo(rinten, ginten,  binten);  break; //white
      case 8:  colo(maxx,   maxx,    maxx);    break;
      case 9:  colo(maxx,   maxx,    maxx);    break;
      case 10: colo(maxx,   maxx,    maxx);    break;

    }
  else if (!ledf)
  {
    colo(maxx, maxx, maxx); //analogWrite(r, maxx); analogWrite(g, maxx); analogWrite(b, maxx);
  }
}

unsigned long mark1 = 0, mark2 = 0;

bool tflag;
bool pre1, pre2;
void MLED() //MOTION LED
{
  inten = 250;
  unsigned long present;

  if (MSL)
  {
    present = (millis() / 1000);
    bool debu = 0;
    if (!databool0[1])
    {
      color(4);
      goto x1;
    }

    pre1 = databool0[19];

    if (pre2 == 1 && pre1 == 0)
    {
      mark1 = present;
      tflag = 1;
    }
    if ((mark1 + 6) < present)
      tflag = 0;

    pre2 = pre1;


    if (databool0[19])
    {
      color(1);
      goto x1;
    }

    if (tflag)
    {
      if ((mark1 + 6) > present)
      {
        byte x = inten;
        inten = 254;
        color(5);
        inten = x;
        goto x1;
      }
    }
    if (!databool0[19])
    {
      color(6);
    }
x1: delay(1);
    if (debu)
    { line();
      Serial.print(F(" PRESENT "));
      Serial.print(present);

      Serial.print(F(" MARK1 "));
      Serial.print(mark1);

      Serial.print(F(" TFLAG "));
      Serial.print(tflag);

      Serial.print(F(" data "));
      Serial.print(databool0[19]);

      Serial.print(F(" pre1 "));
      Serial.print(pre1);

      Serial.print(F(" pre2 "));
      Serial.print(pre2);
      line();
    }
  }

}

void MLED1() //MOTION LED
{ inten = 250;
  if (MSL)
  {
    if (databool0[19])
      color(1);
    else if (!databool0[19])
      color(6);
    else if (databool0[1])
      color(4);
  }
}
void MLED2() //MOTION LED
{ inten = 250;
  unsigned long present;
  unsigned long mark1 , mark2;
  bool flag;
  if (MSL)
  {
    present = millis() / 1000;

    if (!databool0[1])
    {
      color(4);
    }


    else if (databool0[1])
    {
      if (flag)
      {
        if ((mark1 + 6) > present)
        {
          color(2);
          goto x1;
        }
        if ((mark1 + 6) < present)
          flag = 0;
      }
      if (databool0[19])
      {
        color(1);
        mark1 = present;
        goto x1;
      }

      else if (databool0[22])
        color(7);
      else if (!databool0[22])
      {
        if (!databool0[19])
        {
          color(6);
          flag = 1;
        }
      }

    }
x1: delay(1);


  }
  //  databool0[22]=0;
}



void cw()
{
  for (int i = 1; i < 9; i++)
  {
    color(i);
    delay(400);
  }
}
