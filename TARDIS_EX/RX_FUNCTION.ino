

void rx()
{
  flushdata();
  bool a1 = 0;
  bool goahead = 0, spcase;
  byte recvcode, len, spid;
  byte datalen = Serial1.available();
  if (RDP && datalen > 0)
  {
    line();
    a1 = 1;
    Serial.print(" ________________________________________________________________________________________________________ ");
    line();
    Serial.print(" INCOMING LENGTH ");
    Serial.print(datalen);
    line();
  }
  while (Serial1.available() > 0)
  {
    if (RDP) {
      Serial.print(" i ");
      Serial.print(i);
    }
    datax = Serial1.read();
    if (RDP)
    {
      Serial.print(" CURRENT BYTE ");
      Serial.print(datax);
    }
    if (datax == STC)//start transmission
    {
      i = 0;
      if (RDP)
      {
        line();
        Serial.print(" START TRANSMISSION CODE ");
      }
      goto inc;
    }
    else if (datax == ETC)//end transmission
    {
      assign(datax, i, 0); if (RDP)
      {
        Serial.print(" END TRANSMISSION CODE "); line();
      }
    }
    while (i == 1)
    {
      recvcode = datax;
      if (RDP)
      {
        line();
        Serial.print(" RECVCODE ");
        Serial.print(recvcode);
      }

      if ((recvcode == 233) || (recvcode == 229) || (recvcode == 228) || (recvcode == 227)||(recvcode == 226))
      {
        spcase = 1;
        spid = recvcode;
        goto inc;
      }

      len = check(recvcode);
      if (RDP)
      {
        line();
        Serial.print(" CALC LEN ");
        Serial.print(len);
        line();
      }

      if (len == (datalen - 3))
      {
        goahead = 1;
        if (RDP)Serial.print(" GOAHEAD ");
        line();
        goto inc;
      }
      else if (len != (datalen - 3))
      {
        goahead = 0;
        if (RDP)Serial.print(" NOT-GOAHEAD ");
        line();
        goto sh;
      }      //terminate      //shred
    }
    if ((goahead == 1) && (i > 1))
    {
      if(datax<201)
      assign(datax, i - 1, recvcode);
      goto inc;
    }
    if (spcase)
    {
      if (RDP)
      {
        Serial.print(" SPCASE ");
        Serial.print(spcase);
        Serial.print(" ");
      }
      switch (spid)
      {
        case 233:
          databool0[19] = datax;
          databyte0[2] = Serial1.read();
          break;

        case 229:
          voltimer0();
          break;
        
        case 226:        
          databool0[22]=  datax;
          break;

        case 227:
          databool0[1] = datax;
          break;

      }
      spcase = 0;
      goto inc;
    }
sh:  assign(datax, i, 0);  //shredding data
inc: i++;
    if (RDP)
    {
      Serial.print(" I++ ");
      line();
    }
  }

  i = 0;

  if (RDP && a1)
  {
    PRALL();
    a1 = 0;
    Serial.print("________________________________________________________________________________________________________");
    line();
  }
}

void voltimer0()
{
  for (int i = 1; i < 11; i ++)
  {
    databyte4[i] = datax;
    databyte5[i] = Serial1.read();
    databyte6[i] = Serial1.read();
  }
}
