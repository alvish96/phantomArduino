void rel2a()
{

  //  if (f==2) goto z1;
  //  if (digitalRead(R1) == 0 && f == 2) goto z1;


  if (t.hour > OnHour3 && t.hour < OffHour3)      c = 1;

  else if (OnHour3 == t.hour && OffHour3 == t.hour)
  {
    c = 2;
    goto x5;
  }
  else if (t.hour == OnHour3)
  {
    c = 3;
    goto x5;
  }
  else if (t.hour == OffHour3)
  {
    c = 4;
    goto x5;
  }
  else if (t.hour < OnHour3 || t.hour > OffHour3) c = 5;

x5:

  //  if (c == 1 || c == 2 || c == 3 || c == 4) g = 1;
  //----------------------------------------------------------
  if (c == 1)
  {
    R2on(); g = 1;
  }
  //----------------------------------------------------------
  else if (c == 2)
  {
    if (t.min >= OnMin3 && t.min < OffMin3)
    {
      R2on(); g = 1;
    }
    else {
      R2off(); g = 0;
    }
  }
  //----------------------------------------------------------
  else if (c == 3)
  {
    if (t.min >= OnMin3)
    {
      R2on(); g = 1;
    }
    else {
      R2off();
      g = 0;
    }
  }
  //----------------------------------------------------------
  else if (c == 4)
  {
    if (t.min < OffMin3)
    {
      R2on(); g = 1;
    }
    else {
      R2off();
      g = 0;
    }
  }
  //----------------------------------------------------------
  else if (c == 5)
  {
    R2off(); g = 0;
  }
  //----------------------------------------------------------
  else {
    R2off();
    g = 0;
  }
  //z1: delay(1);
}


void rel2b() {

  //  if (digitalRead(R1) == 0 && f == 1) goto z2;
  if (t.hour > OnHour4 && t.hour < OffHour4)      d = 1;

  else if (OnHour4 == t.hour && OffHour4 == t.hour)
  {
    d = 2;
    goto y5;
  }
  else if (t.hour == OnHour4)
  {
    d = 3;
    goto y5;
  }
  else if (t.hour == OffHour4)
  {
    d = 4;
    goto y5;
  }
  else if (t.hour < OnHour4 || t.hour > OffHour4 || t.hour < OnHour3 || t.hour > OffHour3) d = 5;

y5:
  //  if (d == 1 || d == 2 || d == 3 || d == 4) g = 2;
  //----------------------------------------------------------
  if (d == 1)
  {
    R2on(); g = 2;
  }
  //----------------------------------------------------------
  else if (d == 2)
  {
    if (t.min >= OnMin4 && t.min < OffMin4)
    {
      R2on(); g = 2;
    }
    else {
      R2off();
      g = 0;
    }
  }
  //----------------------------------------------------------
  else if (d == 3)
  {
    if (t.min >= OnMin4)
    {
      R2on(); g = 2;
    }
    else {
      R2off();
      g = 0;
    }
  }
  //----------------------------------------------------------
  else if (d == 4)
  {
    if (t.min < OffMin4)
    {
      R2on(); g = 2;
    }
    else {
      R2off();
      g = 0;
    }
  }
  //----------------------------------------------------------
  else if (d == 5)
  {
    R2off(); g = 0;
  }
  //----------------------------------------------------------
  else {
    R2off();
    g = 0;
  }

  //_____________________________________________________________________________________________________________________________________________
  //z2: delay(1);

}
