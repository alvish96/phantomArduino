#define bl 3
#define wh 6

void setup()
{
  Serial.begin(9600);
  pinMode(bl, OUTPUT);
  pinMode(wh, OUTPUT);
  startup3();
startup2();
}


void fromto(int d, int a, int b, int c, int j = 1)
{

  if (a < b)
  {
    for (int i = a; i < b; i += j)
    {
      analogWrite(d, i);
      Serial.print(i);
      Serial.println();
      delay(c);
    }
  }
  else

  {
    for (int i = a; i > b; i -= j)
    {
      analogWrite(d, i);
      Serial.print(i);
      Serial.println();
      delay(c);
    }
  }
}

void fromto2(int a, int b, int c, int d, int del = 10, int jum = 1)
{
  for (int i = c; i < d; i += jum)
  {
    analogWrite(a, i);
    analogWrite(b, 255 - i);
    delay(del);
  }
  for (int i = d; i >c; i -= jum)
  {
    analogWrite(a, i);
    analogWrite(b, 255 - i);
    delay(del);
  }

}
void startup1(int del = 5, int jump = 1)
{
  fromto(6, 0, 255, del, jump);
  fromto(6, 255, 0, del, jump);
  fromto(3, 0, 255, del, jump);
  fromto(3, 255, 0, del, jump);
}

void startup2()
{
  analogWrite(bl, 255);
  delay(500);
  for (int i = 0; i < 255; i++)
  {
    analogWrite(wh, i);
    analogWrite(bl, 255 - i);

    Serial.print(i);
    Serial.println();
    delay(35);
  }
  delay(1000);
  analogWrite(wh, 255);
  analogWrite(bl, 255);

  delay(1000);
  analogWrite(wh, 40);
  analogWrite(bl, 0);
}
void startup3()
{
  fromto2(6,3,0,255,10,1);
}


void loop()
{
//  startup1(1, 5);
//  startup3();

}
