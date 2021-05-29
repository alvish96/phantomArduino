







void loop()
{
  //  brt();
  remote();
  in();

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

  present = millis() / 1000;
  for (int i = 1; i < 12; i++)
  {

    if (mod[i].flag == 1)
    {
      if (millis() > mod[i].total )
      {
        if ((i == 1) && (CRF == 1))
        {
          Serial.print(" motioncount = 0 ");
          motioncount = 0;
          lastmotion = millis() / 1000;
          minor = 0; fromhere = 0; CRF = 0;
          tune(4);
        }
        mod[i].SWoff();
        lastmotion = millis() / 1000;
        mod[i].down();
        Serial.print(" TIMER OFF ");
        priority = mod[i].prtemp;
        mod[i].debug();

      }
    }
    delay(30);
  }

  if (wait)
    goto skip;
  if (priority == 1)
    goto skip;

  gapstt(4);
  Serial.print(" not skipping  ");
skip:
  if (millis() > 4000)
    if ((checkmotion && motion()) == 1)
    {
      wait = 0;
      if (minor && fromhere)
        goto stay;

      if (brt() < limit)
      {
        if (motioncount == 1)
        {
          tune(2);
          mod[1].SWtimer(30, 's');
          minor = 1; fromhere = 1;
          CRF = 1;
        }
      }
stay:
      if ((motioncount > 3) && (fromhere == 1))
      {
        //        if (mod[1].state == mod[1].relayon)
        //        {
        tune(6);
        mod[1].SWon();
        motioncount = 0;
        minor = 0; fromhere = 0;
        //      }
      }

    }
  debug();

  //  Serial.println(motion());
}
