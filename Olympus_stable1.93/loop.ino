
void loop()
{
  remote();
  onReq();
  present = millis() / 1000;
  for (int i = 0; i < 12; i++)
  {

    if (mod[i].flag == 1)
    {
      if (millis() > mod[i].total )
      {
        if ((i == 10) || (i == 2) || (i == 1) )
        {
          if (CRF == 1)
          {
            Serial.print(F(" motioncount = 0 "));
            motioncount = 0;
            lastmotion = millis() / 1000;                   updatemotion();//1.81
            minor = 0; fromhere = 0; CRF = 0;
            priority = mod[i].prtemp;
            tune(4);
          }
        }
        if (i == 0)
        {
          delay(100);
          resetFunc();
          delay(100);
        }
        else
        {
          mod[i].SWoff();
          lastmotion = millis() / 1000;                   updatemotion(); //1.81
          mod[i].down();
          Serial.print(F(" TIMER OFF "));
          priority = mod[i].prtemp;
          mod[i].debug();
        }
      }
    }
    delay(30);
  }
  setall0(); //1.88
  if (all0) //
    if ((present - lastm) > (resettimer * 60)) //1.84
      resetFunc(); //1.85
  //  resetmotion();


  if (wait)
    goto skip;
  if (priority)
    goto skip;

  gapstt2(4);//1.82
  if (debugg) Serial.print(F(" MODE:AUTO "));//1.71


skip:
  if (checkmotion == 0 && priority == 1)
  {
    Serial.print(F(" MODE:MANUAL "));//1.71
    resetmotion();//1.82
  }
  if (checkmotion == 1 && priority == 1)
    Serial.print(F(" MODE:SEMI "));//1.71

  if (millis() > duration)//1.91
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
          resetmotion();//1.81
          if (lightmode == 2) goto x3;
          else if (lightmode == 1) goto x2;
          else if (lightmode == 0)
x1: {
            mod[10].SWtimer(30, 's');
            delay(300);
            if ((analogRead(ldr) / 10) < limit)
            {
              mod[10].SWoff();
x2: mod[2].SWtimer(30, 's');
              delay(500);
              if ((analogRead(ldr) / 10) < limit)//1.91
              {
                mod[2].SWoff();
x3: mod[1].SWtimer(30, 's');
              }
            }
            minor = 1; fromhere = 1;
            CRF = 1;
          }
        }
      }
stay:

      if (motioncount == 2) flag2 = 0;
      if ((motioncount == 3) && (fromhere == 1))
      {
        if (flag2 == 0)
        {
          mod[1].SWtimer(30, 's');
          mod[10].SWoff();
          mod[2].SWoff();
          flag2 = 1;
        }
      }
      if ((motioncount > 3) && (fromhere == 1))
      {
        flag2 = 0;
        tune(6);
        mod[1].SWon();
        motioncount = 0;
        minor = 0; fromhere = 0;
      }
    }
  checktimer();
  if (timeroff == 1)
  {
    sync();
  }
  debug();

}
