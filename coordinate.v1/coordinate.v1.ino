#include <Servo.h>
Servo one, two; //servos for measuring distance 
Servo servx,servy; //servos for turn and pointing 
float a1,a2,av; //a1 is x coordinate ,a2 is y coordinate
float x,y,t;// coordinate calculation variable 
boolean q,w,u,v,ij=0;//variables for found function
float l1,l2,l3,s=1; //distance from sensor 1 and 2 respetively 

int laser1=2,laser2=4;  //lasers for distance measeure  
int laser3;// laser for pointing
const int trig1=7,echo1=8;//variables for distance measure from sensor 1
const int trig2=7,echo2=8;//variables for distance measure from sensor 2 
float duration1,dist1;
float duration2,dist2;
int buz=11; //buzzer for sound on finding the object 

float x1=0,y1=0; //angle of turn in turn servo 
float dpdx=0.55,dpdy=0.55; //distance per degree 

void setup(){
Serial.begin(9600);
pinMode(trig1,OUTPUT);
pinMode(13,HIGH);
pinMode(echo1,INPUT);
pinMode(trig2,OUTPUT);
pinMode(13,HIGH);
pinMode(echo2,INPUT);

pinMode(laser1,OUTPUT);
pinMode(laser2,OUTPUT);

one.attach(3);
two.attach(5);
//servx.attach();
//servy.attach();
pinMode(buz,OUTPUT);
   
}

void loop()
{/*scan1();
 boolean e=found();

 Serial.println();
 Serial.print("    ");Serial.print(e);
 Serial.print("    ");
*/

meas1();
}

void complete()
{
  scan1();
  l1=meas1();
  delay(750);
  scan2();
  l2=meas2();
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
  boolean u=found1();
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
  boolean u=found2();
  if(u==true)
 {  digitalWrite(buz,HIGH);
   delay(400);
 digitalWrite(buz,LOW);
  break;
  }
}
}

void scan()
{
  ij=0;
  digitalWrite(laser1,HIGH);
  digitalWrite(laser2,HIGH);
  for(int i=0;i<=90;i++)
  {
    if (ij==1){goto nxt;}
    one.write(i);

    u = found1();
    if (u==true)
    {
    digitalWrite(buz,HIGH);
    delay(400);
    digitalWrite(buz,LOW);
    ij=1;
    break;
  }
  
 nxt: two.write(180-i);
  v=found2();
  if (v==true)
  {
    digitalWrite(buz,HIGH);
    delay(400);
    digitalWrite(buz,LOW);
  break;
  }
}
}

float meas1()
{
  float av1=0;
  for (int k=0;k<5;k++)
  {
    digitalWrite (trig1,HIGH);
    digitalWrite (13,HIGH);
    delay(15);
    digitalWrite (trig1,LOW);
    duration1=pulseIn(echo1,HIGH);
    dist1=duration1/58;   //   Serial.print("  ");Serial.print(dist1);Serial.println();
    av1=av1+dist1;
  }
  av1=av1/5;
  //Serial.println(av);
  return av1;
}


float meas2()
{
  float av2=0;
  for (int m=0;m<5;m++)
  {
    digitalWrite (trig2,HIGH);
    digitalWrite (13,HIGH);
    delay(15);
    digitalWrite (trig2,LOW);
    duration2=pulseIn(echo2,HIGH);
    dist2=duration2/58;      // Serial.print("  ");Serial.print(dist);Serial.println();
    av2=av2+dist2;
  }
  av2=av2/5;
  //Serial.println(av);
  return av2;
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
  
boolean found1()
{
float g=meas1();           //   Serial.print(g);
if (g>0 && g<50)
{w=1;}
else w=0;
return w;
}
boolean found2()
{
float h=meas2();           //   Serial.print(g);
if (h>0 && h<50)
{q=1;}
else q=0;
return q;
}

void turn()
{
 x1=a1/dpdx;
 y1=a2/dpdy;
  servx.write(x1);
  servy.write(y1);
  delay(400);
  digitalWrite(laser3,HIGH);
  digitalWrite (buz,HIGH);
  delay(400);
}
