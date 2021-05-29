
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int paus = 300;

void a(int x, int y, int z, int c = 90)
{
  NewTone(buz, tones[x]);
  delay(c);
  NewTone(buz, tones[y]);
  delay(c);
  NewTone(buz, tones[z]);
  delay(c);
  noNewTone(buz);
}
void b(byte x, byte y, byte z = 80)
{
  NewTone(buz, tones[x]);
  delay(z);
  NewTone(buz, tones[y]);
  delay(z + 20);
  noNewTone();
}

void tune(int x)
{
  switch (x)
  {
    case 1: a(0, 5, 9); break;
    case 2: b(4, 8);    break;
    case 3: a(5, 0, 5);    break;
    case 4: b(8, 4); break;
    case 5: a(8, 4, 3); break;
    case 6: b(2, 7); break;
    case 7: a(3, 4, 8); break;
    case 8: a(0, 5, 9, 300); break;// startup tone
    case 9: a(9, 5, 0, 300); break;// end tone
      case 10: b(9, 3,30); break;

    default:
      break;
  }
}



//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void buzz(int n)
{
  if (mute == 0)
  {
    int del = 10;
    digitalWrite(buz, LOW);
    for (int i = 0; i < n; i++)
    {
      digitalWrite(buz, HIGH);
      delay(del);
      digitalWrite(buz, LOW);
      delay(del + 60);
    } digitalWrite(buz, LOW);
  }
}

void mutesw()
{
  mute = !mute;
}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
