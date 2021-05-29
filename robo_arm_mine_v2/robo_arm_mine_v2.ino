#include <Servo.h>

Servo s1, s2, s3, s4;

void setup()
{
  s1.attach(8);
  s2.attach(9);
  s3.attach(10);
  s4.attach(11);
  Serial.begin(9600);

}
void loop() {
  one();
}

void one()
{int a=0,b=175,c=1000;
  for (int i = a; i <= b; i++) {
    s1.write(i);
    //s2.write(i);
    //s3.write(i);
    //s4.write(i);

    // delay(10);
    Serial.println();
    Serial.print("position is "); Serial.println(i);


  }
delay(c);
  for (int j = b; j >= a; j--) {
    s1.write(j);
    //s2.write(j);
    //s3.write(j);
    //s4.write(j);
    // delay(10);

    Serial.println();   Serial.print("position is "); Serial.println(j);
  }
}

void turn()
{
  s1.write(0); delay(1000);    Serial.println();   Serial.print("position is 0");

  s1.write(128); delay(1000);    Serial.println();   Serial.print("position is 128");

  s1.write(255); delay(1000);    Serial.println();   Serial.print("position is 255");

  s1.write(128); delay(1000);    Serial.println();   Serial.print("position is 128");

  s1.write(0); delay(1000);    Serial.println();   Serial.print("position is 0");

  delay(1000);

s2.write(0);delay(1000);    Serial.println();   Serial.print("position is 0");

  s2.write(128);delay(1000);    Serial.println();   Serial.print("position is 128"); 

  s2.write(255);delay(1000);    Serial.println();   Serial.print("position is 255"); 

  s2.write(128);delay(1000);    Serial.println();   Serial.print("position is 128");

  s2.write(0);delay(1000);    Serial.println();   Serial.print("position is 0"); 

  delay(1000);

s3.write(0);delay(1000);    Serial.println();   Serial.print("position is 0");

  s3.write(128);delay(1000);    Serial.println();   Serial.print("position is 128"); 

  s3.write(255);delay(1000);    Serial.println();   Serial.print("position is 255"); 

  s3.write(128);delay(1000);    Serial.println();   Serial.print("position is 128");

  s3.write(0);delay(1000);    Serial.println();   Serial.print("position is 0"); 

  delay(1000);

s4.write(0);delay(1000);    Serial.println();   Serial.print("position is 0");

  s4.write(128);delay(1000);    Serial.println();   Serial.print("position is 128"); 

  s4.write(255);delay(1000);    Serial.println();   Serial.print("position is 255"); 

  s4.write(128);delay(1000);    Serial.println();   Serial.print("position is 128");

  s4.write(0);delay(1000);    Serial.println();   Serial.print("position is 0"); 

  delay(1000);

}

void a()
{
  
  s1.write(0); delay(1000);    Serial.println();   Serial.print("position is 0");

 // s1.write(128); delay(1000);    Serial.println();   Serial.print("position is 128");

  s1.write(150); delay(1000);    Serial.println();   Serial.print("position is 255");

  //s1.write(128); delay(1000);    Serial.println();   Serial.print("position is 128");

  //s1.write(0); delay(1000);    Serial.println();   Serial.print("position is 0");

  //delay(1000);
}

