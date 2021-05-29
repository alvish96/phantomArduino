unsigned long tim;
int h, m, s;

void timetrans(bool a , bool b)
{ TID = 202;

  tmElements_t tm;
  if (millis() > (tim + 1000))
    if (RTC.read(tm))
    {
      tim = millis();
      h = tm.Hour;
      m = tm.Minute;
      s = tm.Second;
      if (b)
      {
        line();
        Serial.print(h);       Serial.print(F(" "));
        Serial.print(m);       Serial.print(F(" "));
        Serial.print(s);       Serial.print(F(" "));
        line();
      }

      if (a && volt)
      {int d=10;
        if ((h || m || s) > 60) goto z2;
        Serial1.write(TID);
        Serial1.write(h);delay(d);
        Serial1.write(m);delay(d);
        Serial1.write(s);delay(d);
        Serial1.flush();
z2: delay(0);
      }
    }
    
    else
    {
      if (RTC.chipPresent())
      {
        spacer();
        Serial.print(F("DS1307 stopped,run set time"));
        spacer();
      }
      else
      {
        spacer();
        Serial.print(F("DS1307 read error,check circuit"));
        spacer();
      }
    }
}
