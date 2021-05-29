#include <Servo.h>

Servo base, plat,wing;

void setup()
{
  base.attach(8);
plat.attach(9);
 /* j2.attach(8);
  j3.attach(11);
  */
  Serial.begin(9600);

}
void loop() {
 one();
 turn();
}

void one()
{
  for (int i=0; i<=256;i+=5){
  base.write(i);delay(100);
  }

  for (int j=255; j>=0;j-=5){
  base.write(j);delay(100);
  }
}

void turn()
{
  for (int i=0; i<=256;i+=5){
  plat.write(i);delay(100);
  }

  for (int j=255; j>=0;j-=5){
  plat.write(j);delay(100);
  }
}
