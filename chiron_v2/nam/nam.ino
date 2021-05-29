#include <Servo.h>

Servo vert, hort;
int minm = 100;
int maxm = 205;
int incr=20;
int decr=20;
void setup() {
  vert.attach(8);
  hort.attach(11);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //hturn();
  vturn();
}


void hturn()
{
  for (int i = minm; i <= maxm; i += incr)
  {
    hort.write(i);
    delay(100);
  }

  for (int j = maxm; j >= minm; j -= decr)
  {
    hort.write(j);
    delay(100);
  }
}

.

void vturn()
{
  for (int i = minm; i <= maxm; i += incr)
  {
    hort.write(i);
    delay(100);
  }
delay(1000);
  for (int j = maxm; j >= minm; j -= decr)
  {
    hort.write(j);
    delay(100);
  }
}
