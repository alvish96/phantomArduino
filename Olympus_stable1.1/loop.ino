
void loop()
{
  brt();
  remote();
  in();



  present = millis() / 1000;
  for (int i = 1; i < 12; i++)
  {

    if (mod[i].flag == 1)
    {
      if (millis() > mod[i].total )
      {
        mod[i].SWoff();
        mod[i].down();
        Serial.print(" TIMER OFF ");
        priority = mod[i].prtemp;
        mod[i].debug();

      }
    }
    delay(30);
  }

  if (mod[0].flag == 1)
  {
    if (millis() > mod[0].total )
    {
      delay(100);
      // turnoff();
      resetFunc();
      delay(1000);
    }
  }




  if (priority == 1)
    goto skip;

  gapstt(4);
  Serial.print(" not skipping ");
skip:
  if (millis() > 3000)
    if ((checkmotion && motion()) == 1)
    {
      if (minor && fromhere)
        goto stay;

      if (brt() < limit)
      {
        if (motioncount == 1)
        {
          mod[1].SWtimer(30, 's');
          minor = 1;
          fromhere = 1;
        }
      }
stay:
      if ((motioncount > 3) && (fromhere == 1))
      {
        mod[1].SWon();
        motioncount = 0;
        minor = 0; fromhere = 0;
      }
    }

  //  Serial.println(brt());
  //  Serial.println(motioncount);
  //  Serial.println(priority);

  //  Serial.println(motion());
}
