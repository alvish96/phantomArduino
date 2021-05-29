/*
  Adafruit Arduino - Lesson 10. Simple Sounds
*/
#include <NewTone.h>
#include<IRremote.h>
int buz = 7;
byte paus = 90;
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

void b(byte x, byte y, byte z = 80)
{
  NewTone(buz, tones[x]);
  delay(z);
  NewTone(buz, tones[y]);
  delay(z + 20);
  noNewTone();
}
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
void blip(byte x, int c = 50)
{
  NewTone(buz, tones[x]);
  delay(c );
  noNewTone();
}

void setup()
{
  /*  for (int i = 0; i < numTones; i++)
    {
      tone(buz, tones[i]);
      delay(1000);
    noTone(buz);
    delay(1000);
    }
    noTone(buz);
  */
//  d(8);
//  delay(1000);
  d(11);
  //  c(7);
//  delay(2000);
//  d(9);

}

void loop()
{
  //  d(6);
  //    delay(1000);
}
void c(int a1)
{
  for (int i = 0; i <= a1; i++)
  {

    switch (i)
    {
      case 1: a(0, 5, 9); break;
      case 2: b(4, 8);    break;
      case 3: a(5, 0, 5);    break;
      case 4: b(8, 4); break;
      case 5: a(8, 4, 3); break;
      case 6: b(2, 7); break;
      case 7: a(3, 4, 8); break;
      case 8: a(0, 5, 9, 300); break;
      case 9: a(9, 5, 0, 300); break;
      

    }
    delay(1000);
  }
}
void d(int i)
{

  switch (i)
  {
    case 1: a(0, 5, 0);

      break;
    case 2: b(4, 8);
      break;
    case 3: a(5, 0, 5);
      break;
    case 4: b(8, 4); break;
    case 5: a(8, 4, 3); break;
    case 6: b(2, 7); break;
    case 7: a(3, 4, 8); break;
    case 8: a(0, 5, 9, 300); break;
    case 9: a(9, 5, 0, 300); break;
    case 10: b(9, 3, 30); break;
    case 11: blip(4);break;
  }
  delay(1000);

}
