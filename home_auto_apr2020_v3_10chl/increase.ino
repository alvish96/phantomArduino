void incsw1(int ta1)
{
  x1 += (ta1 * 60000);
  Serial.println("added time main light");
}
void decsw1(int ta2)
{
  if (x1 > 10000)
  { x1 -= (ta2 * 60000);
    Serial.println("removed time main light");
  }
}


void incsw2(int ta3)
{
  x2 += (ta3 * 60000);
  Serial.println("added time led main");
}
void decsw2(int ta4)
{
  if (x2 > 10000)
  { x2 -= (ta4 * 60000);
    Serial.println("removed time led main");
  }
}

void incsw3(int ta5)
{
  x3 += (ta5 * 60000);
  Serial.println("added time fan");
}
void decsw3(int ta6)
{
  if (x3 > 10000)
  { x3 -= (ta6 * 60000);
    Serial.println("removed time fan");
  }
}

void incsw4(int ta7)
{
  x4 += (ta7 * 60000);
  Serial.println("added time exhaust");
}
void decsw4(int ta8)
{
  if (x4 > 10000)
  { x4 -= (ta8 * 60000);
    Serial.println("removed time exhaust");
  }
}
