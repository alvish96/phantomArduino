/*case 0:    analogWrite(r, maxx);   analogWrite(g, maxx);   analogWrite(b, maxx);    break; //black
  case 1:    analogWrite(r, rinten); analogWrite(g, maxx);   analogWrite(b, maxx);    break; //red
  case 2:    analogWrite(r, maxx);   analogWrite(g, ginten); analogWrite(b, maxx);    break; //gre
  case 3:    analogWrite(r, maxx);   analogWrite(g, maxx);   analogWrite(b, binten);    break; //blu
  case 4:    analogWrite(r, rinten); analogWrite(g, ginten); analogWrite(b, maxx);    break; //yllw
  case 5:    analogWrite(r, rinten); analogWrite(g, maxx);   analogWrite(b, binten);    break; //magenta
  case 6:    analogWrite(r, maxx);   analogWrite(g, ginten); analogWrite(b, binten);    break; //cyan
  case 7:    analogWrite(r, rinten); analogWrite(g, ginten); analogWrite(b, binten);    break; //white
  case 8:    analogWrite(r, maxx);   analogWrite(g, maxx);   analogWrite(b, maxx);    break;
  case 9:    analogWrite(r, maxx);   analogWrite(g, maxx);   analogWrite(b, maxx);    break;
  case 10:   analogWrite(r, maxx);   analogWrite(g, maxx);   analogWrite(b, maxx);    break;


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

*/


void colo(byte x1, byte x2, byte x3)//1.1
{
  analogWrite(r, x1); analogWrite(g, x2); analogWrite(b, x3);
}
void color(int x)
{
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
void cwl()
{
  for (int i = 1; i < 9; i++)
  {
    color(i);
    delay(400);
  }
}
void a1()
{
  for (int i = maxx; i > minn; i--)
  {
    analogWrite(r, i);
    delay(del);
  }

  delay(secc);
  for (int i = minn; i < maxx ; i++)
  {
    analogWrite(r, i);
    delay(del);
  }
  delay(secc);
  for (int j = maxx; j > minn; j--)
  {
    analogWrite(g, j);
    delay(del);
  }
  delay(secc);
  for (int i = minn; i < maxx ; i++)
  {
    analogWrite(g, i);
    delay(del);
  }
  delay(secc);
  for (int k = maxx; k > minn; k--)
  {
    analogWrite(b, k);
    delay(del);
  }
  delay(secc);
  for (int i = minn; i < maxx ; i++)
  {
    analogWrite(b, i);
    delay(del);
  }
}

void a2()
{
  for (int i = maxx; i > minn; i--)
  {
    analogWrite(r, i);
    analogWrite(g, i);
    analogWrite(b, i);
    delay(del);
  }
  delay(secc);
  for (int i = minn; i < maxx ; i++)
  {
    analogWrite(r, i);
    analogWrite(g, i);
    analogWrite(b, i);
    delay(del);
  }

}
