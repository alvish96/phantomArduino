bool xi = 1;
void PRALL()
{
  //  RP = 1;
  unsigned long x3 = millis() / 1000;

  if (xi)
  {
    line();
    Serial.print(F(" PRINTING DATA SET RP "));
    Serial.print(RP);
    line();
    xi = 1;
    line();

    if (RP)
    {
      Serial.print(F(" FLAGS "));
      line();
    }
p0:   for (int i = 1; i < 31; i++)
    {
      if (RP)
      {
        Serial.print(databool0[i]);
        Serial.print(F(" "));
      }
    }
    line();
p1:    if (RP)
    {
      Serial.print(F(" FLAGS VERTICAL STACK "));
      line();
    }
    for (int i = 1; i < 12; i++)
    {
      if (RP)
      {

        Serial.print(databool1[i]); Serial.print(F(" "));
        Serial.print(databool2[i]); Serial.print(F(" "));
        Serial.print(databool3[i]); Serial.print(F(" "));
        Serial.print(databool4[i]); Serial.print(F(" "));
        line();
      }
    }
    line();
p2:    if (RP)
    {
      Serial.print(F(" BYTE DATA "));
      line();
    }
    for (int i = 1; i < 21; i++)
    {
      if (RP)
      {

        Serial.print(databyte0[i]); Serial.print(F(" "));
      }
    }
    line();
p3:    for (int i = 1; i < 12; i++)
    {
      if (RP)
      {
        Serial.print(F("TIMER-"));
        Serial.print(i);
        Serial.print(F("--> "));
        Serial.print(databyte1[i]); Serial.print(F(" "));
        Serial.print(databyte2[i]); Serial.print(F(" "));
        Serial.print(databyte3[i]); Serial.print(F(" "));
        line();
      }
    }
    line();
p4: for (int i = 1; i < 11; i++)
    {
      if (RP)
      {
        Serial.print(F("TIMER-"));
        Serial.print(i);
        Serial.print(F("--> "));
        Serial.print(databyte4[i]); Serial.print(F(" "));
        Serial.print(databyte5[i]); Serial.print(F(" "));
        Serial.print(databyte6[i]); Serial.print(F(" "));
        line();
      }
    }
    line();
p5:  if (RP)
    {
      Serial.print(F(" SHREDDING DATA "));

    }
    for (int i = 1; i < 31; i++)
    {
      if (RP)
      {
        //        line();
        //        Serial.print(i);
        Serial.print(F(" "));
        Serial.print(shred[i]);
        shred[i] = 0;
      }
    }
    line();
  }
  //  delay(1000);
}
