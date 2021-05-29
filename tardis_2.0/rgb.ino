
void colo(byte x1, byte x2, byte x3)//1.1
{
  analogWrite(r, x1); analogWrite(g, x2); analogWrite(b, x3);
}
void color(int x)
{
inten=250;
  rinten = inten;
  binten = inten;
  ginten = inten;
  if (ledf)
    switch (x)
    {

      case 0:  colo(maxx,   maxx,    maxx);    break;  //black
      case 1:  colo(rinten, maxx,    maxx);    break; //red
      case 2:  colo(maxx,   ginten,  maxx);    break; //gre
      case 3:  colo(maxx,   maxx,    binten);  break; //blu
      case 4:  colo(rinten, ginten,  maxx);    break; //yllw
      case 5:  colo(rinten, maxx,    binten);  break; //magenta
      case 6:  colo(maxx,   ginten,  binten);  break; //cyan
      case 7:  colo(rinten, ginten,  binten);  break; //white
      case 8:  colo(maxx,   maxx,    maxx);    break;
      case 9:  colo(maxx,   maxx,    maxx);    break;
      case 10: colo(maxx,   maxx,    maxx);    break;

    }
  else if (!ledf)
  {
    colo(maxx, maxx, maxx); //analogWrite(r, maxx); analogWrite(g, maxx); analogWrite(b, maxx);
  }
}
void MLED() //MOTION LED
{
  if (MSL)
  {
    if (databool0[19])
      color(1);
    else
      color(6);
  }
}


void cw()
{
  for (int i = 1; i < 9; i++)
  {
    color(i);
    delay(400);
  }
}
