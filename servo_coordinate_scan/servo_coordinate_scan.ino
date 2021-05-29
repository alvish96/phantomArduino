#include <Servo.h>
Servo vert, hori;
int posv = 0;
int posh = 0;

int a = 0, b = 0;

int l = 10;
int q = 170;
int del = 40;


void setup()
{
  hori.attach(9);
  vert.attach(10);
  vert.write(0);
  hori.write(0);
  Serial.begin(9600);
}


void loop() {
  test();
  delay(1000);
}


void test() {
  hori.write(l); delay(1000);
  vert.write(l); delay(1000);
  vert.write (q / 2); delay(1000);
  hori.write(q / 2); delay(1000);
  vert.write (q); delay(1000);
  hori.write(q); delay(1000);
  vert.write (q / 2); delay(1000);
  hori.write(q / 2); delay(1000);
  for (a = l; a < q; a++)
  {
    hori.write(a);
    vert.write(a);
    Serial.println(a);
    delay(del);
  }
  delay(1000);
  for (b = q; b > l; b--)
  {
    hori.write(b);
    vert.write(b);
    Serial.println(b);
    delay(del);
  }

}
