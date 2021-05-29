
void fromto(int d, int a, int b, int c, int j = 1)
{

  if (a < b)
  {
    for (int i = a; i < b; i += j)
    {
      analogWrite(d, i);
      if (debug)
      { Serial.print(i);
        Serial.println();
      }  delay(c);
    }
  }
  else

  {
    for (int i = a; i > b; i -= j)
    {
      analogWrite(d, i);
      if (debug)
      { Serial.print(i);
        Serial.println();
      }   delay(c);

    }
  }
}

void fromto2(int a, int b, int c, int d, int del = 10, int jum = 1)


{
  for (int i = c; i < d; i += jum)
  {
    analogWrite(a, i);
    analogWrite(b, 255 - i);
    delay(del);
  }
  for (int i = d; i > c; i -= jum)
  {
    analogWrite(a, i);
    analogWrite(b, 255 - i);
    delay(del);
  }

}

void check()
{
  fromto(6, 0, 255, 10, 1);
}
void startup1(int del = 5, int jump = 1)
{
  fromto(6, 0, 255, del, jump);
  fromto(6, 255, 0, del, jump);
  fromto(3, 0, 255, del, jump);
  fromto(3, 255, 0, del, jump);
}

void startup2()
{
  analogWrite(bl, 255);
  delay(500);
  for (int i = 0; i < 255; i++)
  {
    analogWrite(wh, i);
    analogWrite(bl, 255 - i);

    if (debug)
    { Serial.print(i);
      Serial.println();
    }
    delay(35);
  }
  delay(1000);
  analogWrite(wh, 255);
  analogWrite(bl, 255);

  delay(1000);
  analogWrite(wh, 0);
  analogWrite(bl, 0);
}
void startup3()
{
  fromto2(6, 3, 0, 255, 10, 1);
}

void turnoff()
{
  blsw = 0;
  whsw = 0;
  blctrl = 0;
  whctrl = 0;
  blsp = 1;
  whsp = 1;
  limit();
}
void debugg()
{
  if (debug)
  {
    Serial.print(F("i  = "));
    Serial.print(i);
    //    delay(10);
    Serial.print(F(" j  = "));
    Serial.print(j);
    Serial.print(F(" dirup1  = "));
    Serial.print(dirup1);
    Serial.print(F(" dirdw1  = "));
    Serial.print(dirdw1);
    Serial.print(F(" dirup2  = "));
    Serial.print(dirup2);
    Serial.print(F(" dirdw2  = "));
    Serial.print(dirdw2);
    Serial.print(F(" blp = "));
    Serial.print(blp);
    Serial.print(F(" whp = "));
    Serial.print(whp);
    Serial.print(F(" whbr = "));
    Serial.print(whbr);
    Serial.print(F(" blbr = "));
    Serial.print(blbr);
    Serial.print(F(" whctrl = "));
    Serial.print(whctrl);
    Serial.print(F(" blctrl = "));
    Serial.print(blctrl);
    Serial.print(F(" blsp = "));
    Serial.print(blsp);
    Serial.print(F(" whsp = "));
    Serial.print(whsp);
    Serial.print(F(" whspc = "));
    Serial.print(whspc);
    Serial.print(F(" blspc = "));
    Serial.print(blspc);






    Serial.println();
    delay(10);
  }
}
