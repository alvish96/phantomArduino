#include <Servo.h>
Servo one, two;
float a1,a2,av;
float x,y,t;
boolean w,v,u;
float l1,l2,s=1;

int laser1=2,laser2=4;
const int trig=7,echo=8;
float duration,dist;
int buz=11;

void setup(){
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(13,HIGH);
pinMode(echo,INPUT);

pinMode(laser1,OUTPUT);
pinMode(laser2,OUTPUT);

one.attach(3);
two.attach(5);

pinMode(buz,OUTPUT);
   
}

void loop()
{/*scan1();
 boolean e=found();

 Serial.println();
 Serial.print("    ");Serial.print(e);
 Serial.print("    ");
*/
complete();
}

void complete()
{
  scan1();
  l1=meas();
  delay(750);
  scan2();
  l2=meas();
  float a1=calcx();
  float a2=calcy();
 Serial.println();
 Serial.println("the coordinates of the object are ");
  Serial.print(a1);
  Serial.print(",");
 Serial.print(a2);
delay(5000);  
 }

void scan1()
{
  //one.write(0);
    digitalWrite(laser1,HIGH);
  for (int i=0;i<=90;i++)
  {
    one.write(i);//delay(100);
  boolean u=found();
  if(u==true)
  { digitalWrite(buz,HIGH);
   delay(400);
 digitalWrite(buz,LOW);
  break;
  }
  }
}

void scan2()
{
//  one.write(0);
digitalWrite(laser2,HIGH);
  for (int j=180;j>=90;j--)
  {
    two.write(j);
  boolean u=found();
  if(u==true)
 {  digitalWrite(buz,HIGH);
   delay(400);
 digitalWrite(buz,LOW);
  break;
  }
}
}
float meas()
{
  float av=0;
  for (int k=0;k<5;k++)
  {
    digitalWrite (trig,HIGH);
    digitalWrite (13,HIGH);
    delay(15);
    digitalWrite (trig,LOW);
    duration=pulseIn(echo,HIGH);
    dist=duration/58;      // Serial.print("  ");Serial.print(dist);Serial.println();
    av=av+dist;
  }
  av=av/5;
  //Serial.println(av);
  return av;
}

float calcx()
{
  x=((l1*l1)-(l2*l2)+(s*s))/(s*2);
  return x;
}

float calcy()
{
   t=((l1*l1)-(x*x));
  y=sqrt(t);
  return y;
}
  
boolean found()
{
float g=meas();           //   Serial.print(g);
if (g>0 && g<50)
{w=1;}
else w=0;
return w;
}

