void flus()
{
  rg();

  if (entryflag)
  {
    if (millis() < (ontimer + 20000))
    {
      flag10 = 1;
      flagnxt = 0;
      goto d;
    }
    if (millis() < (ontimer + flushtime))
    {
      flag10 = 0;
      flagnxt = 1;
     
    goto d;
    }
    
    
    if ((ontimer + flushtime) < millis())
    {
      flag10=0;
      flagnxt=0;
      entryflag = 0;
      ontimer = 0;
      offtimer = millis();
      
  offtime = 900000; //15mins
    }
d:
    if (flag10)//first 10 seconds
    {
      wrtspd(255);
    }
    else if (flagnxt)//next 240 seconds
    {
      wrtspd(150);
    }


    //turn off for x minutes
    //so flag off
  }
}
void resetdata()
{
  offtime=0;
  ontimer=0;
  offtimer=0;
  entryflag=0;
}

void grnl()
{
  digitalWrite(red, 0);
  digitalWrite(grn, 1);
}
void redl()
{
  digitalWrite(grn, 0);
  digitalWrite(red, 1);
}
void rg()
{
  digitalWrite(red, 1);
  digitalWrite(grn, 1);
}
int readtemp()
{
  temp = analogRead(temppin);
  Serial.print(F("temp read signal ->"));
  Serial.print(temp);
  line();
  return temp;

}

void udpatespeed()
{
  rpm = readspd();
}


void wrtspd(int s)
{
  analogWrite(pwmpin, s);
  analogWrite(dup, s);
  Serial.print(F( "  pwm write signal -> "));
  Serial.print(s);
  //  line();
}

int readspd()
{
  int s = analogRead(reedpin);
  Serial.print(F("  tacho read signal -> "));
  Serial.print(s);
  //  line();
  return s;
}


void line()//1.83
{
  Serial.println();
}
