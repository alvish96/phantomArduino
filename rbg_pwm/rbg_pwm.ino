int b = 2, g = 3, r = 4;
//bgr
int maxx = 255;
int minn = 0;
int del = 10;
int secc = 1000/3;
#define lcdvcc 31
void setup() {
  pinMode(lcdvcc, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT); // put your setup code here, to run once:
  analogWrite(r, maxx);
  analogWrite(g, maxx);
  analogWrite(b, maxx);
  digitalWrite(lcdvcc,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  a1();
  a2();
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
