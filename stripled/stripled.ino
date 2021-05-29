#define pin 3
#define pin1 6
#define pin2 11
#define pin3 12
unsigned long b;
bool f, f1;
unsigned long t, prev, current;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  for (int i = 0; i < 256; i++)
  {
    analogWrite(pin, i);
    analogWrite(pin1, i);
    analogWrite(pin2, i);
    analogWrite(pin3, i);
    Serial.print(i);
    Serial.println();
    delay(35);
  }
  analogWrite(pin, 255);
  analogWrite(pin1, 255);
  analogWrite(pin2, 255);
  analogWrite(pin3, 255);
  delay(500);
  analogWrite(pin, 20);
  analogWrite(pin1,40);
  analogWrite(pin2, 80);
  analogWrite(pin3, 160);
digitalWrite(6,1);
digitalWrite(7,0);
}

void loop()
{
  //  fn1(50);
//  fn2();
  //  fn3();
  //  aa();
}
void aa()
{
  analogWrite(pin, 64);
  analogWrite(pin1, 128);
  analogWrite(pin2, 180);
  digitalWrite(pin3, 1);

}
void newa()
{
  fn1(80);
}

void fn1(int del)
{
  //  int del = 50;
  digitalWrite(pin, 1);
  delay(del);
  digitalWrite(pin, 0);
  delay(del);
}


void fn2()
{
  int ulim = 16;
  int llim = 0;
  int del = 1000;
  int x = 500;
  for (int i = llim; i < ulim; i++)
  {
    analogWrite(pin, i);
    Serial.print(i);
    Serial.println();
    delay(x);
  }

  delay(del);

  for (int i = ulim; i > llim; i--)
  {
   
    analogWrite(pin, i);
    Serial.print(i);
    Serial.println();
    delay(x);
  }
  delay(del);

}

void fn3()
{
  current = millis();
  //  t =  current - prev;
  t = millis();
  Serial.print(t);
  Serial.println();
  a(35, 9);
  a(50, 10);
  a(200, 11);
  prev = current;
}


void a(int x, int y)
{ int n = 5;
  if (f == 0)
  {
    if (t % x < n)
      //    if(t%x==0)
      //    if (t > (x - 5) && t < (x + 5))
    {
      for (int i = 0; i < 256; i++)
      {
        analogWrite(y, i);
        Serial.print(i);
        Serial.println();
        if (i == 255)
          f = 1;
      }
    }
  }
  if (f == 1)
  {
    if (t % x < n)
      //    if(t%x==0)
      //    if (t > (x - 5) && t < (x + 5))
    {
      for (int i = 255; i > 0 ; i--)
      {
        analogWrite(y, i);
        Serial.print(i);
        Serial.println();
        if (i == 1)
          f = 0;
      }
    }
  }

}
