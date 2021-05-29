

void limit()
{
  if (blbr > 255) blbr = 255;
  if (whbr > 255) whbr = 255;
  if (blbr < 0) blbr = 0;
  if (whbr < 0) whbr = 0;
  if (whsp <= 0) whsp = 1;
  if (blsp <= 0) blsp = 1;
  if (whsp > 128) whsp = 128;
  if (blsp > 128) blsp = 128;
  execute();

}

void limit2()
{
  //  if (i < 0)i = 0;
  if (i < whmin)
  {
    i = whmin;
  }

  //  if (j < 0)j = 0;
  if (j < blmin)
  {
    j = blmin;
  }


  //  if (i > 255) i = 255;
  if (i > whmax)
  {
    i = whmax;
  }

  //  if (j > 255) j = 255;
  if (j > blmax)
  {
    j = blmax;
  }
}
void execute()
{
  if (blsw)  analogWrite(bl, blbr);
  if (whsw)  analogWrite(wh, whbr);
}

void mainloop()
{
  whiteloop();
  limit();
}

void whiteloop()
{

  if ((i < whmax) && (dirup1 == 1))
  {

    if (whp)
      goto skip1;
    i += whsp;
    limit2();
    whbr = i;
skip1: blueloop();
    if (i == whmax)
    {
      dirdw1 = 1;
      dirup1 = 0;
    }
  }
  if ((i > whmin) && (dirdw1 == 1))
  {

    if (whp)
      goto skip2;
    i -= whsp;
    limit2();
    whbr = i;
skip2: blueloop();
    if (i == whmin)
    {
      dirup1 = 1;
      dirdw1 = 0;
    }
  }


}

void blueloop()
{

  if ((j < blmax) && (dirup2 == 1))
  {

    if (blp)
      goto skip3;
    j += blsp;
    limit2();
    blbr = j;
skip3:    if (j == blmax)
    {
      dirdw2 = 1;
      dirup2 = 0;
    }
  }
  if ((j >= blmin ) && (dirdw2 == 1))
  {

    if (blp)
      goto skip4;
    j -= blsp;
    limit2();
    blbr = j;
skip4: if (j == blmin)
    {
      dirup2 = 1;
      dirdw2 = 0;
    }
  }


}




void bluesw()
{
  blsw = !blsw;
  if (!blsw)
    analogWrite(bl, blsw);
  if (blsw )
    analogWrite(bl, blbr);
}
void whitesw()
{
  whsw = !whsw;
  if (!whsw )
    analogWrite(wh, whsw);
  if (whsw)
    analogWrite(wh, whbr);
}

void bluectrl()
{
  blctrl = !blctrl;
}
void whitectrl()
{
  whctrl = !whctrl;
}
void bluepause()
{
  blp = !blp;
}
void whitepause()
{
  whp = !whp;
}

void whspsw()
{
  whspc = !whspc;
}
void blspsw()
{
  blspc = !blspc;
}


void up()
{
  if (blctrl == 1)
  {
    blbr += upctrl;
  }
  if (whctrl == 1)
  {
    whbr += upctrl;
  }
  if (whspc)
    whsp += spup;
  if (blspc)
    blsp += spup;

  limit();
}

void down()
{
  if (blctrl == 1)
  {
    blbr -= downctrl;
  }
  if (whctrl == 1)
  {
    whbr -= downctrl;
  }
  if (whspc)
    whsp -= spdw;
  if (blspc)
    blsp -= spdw;

  limit();
}

void right()
{
  if (blctrl == 1)
  {
    blbr += rtctrl;
  }
  if (whctrl == 1)
  {
    whbr += rtctrl;
  }
  if (whspc)
    whsp += sprt;
  if (blspc)
    blsp += sprt;

  limit();

}

void left()
{
  if (blctrl == 1)
  {
    blbr -= ltctrl;
  }
  if (whctrl == 1)
  {
    whbr -= ltctrl;
  }

  if (whspc)
    whsp -= splt;
  if (blspc)
    blsp -= splt;

  limit();
}
