//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void splfan(int hr,int fl,int wt)   //setter
{
  maxfancount = ((hr * 3) + 1);
  fancount = 0;
  flow = fl;
  wait = wt;
  flowflag = 1;
  waitflag = !flowflag;
  starter();
}

void starter()       //starter
{
  if (fancount < maxfancount)
  {
    fancount++;

    if (waitflag == 1)
    {
      waitstt = 0;
      waitdur = 0;
      waitdur = wait * 60000;
      waitstt = millis();
      flowflag = !waitflag;
    }

    if (flowflag == 1)
    {
      flowstt = 0;
      flowdur = 0;
      flowdur = flow * 60000;
      flowstt = millis();
      waitflag = !flowflag;//not waiting
    }

  }

}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
