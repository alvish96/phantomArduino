#include <Servo.h>
Servo one,two;

int laser1 = 2;
int laser2 = 4;

int buz = 11;

 long trig=7,echo =8;
long duration, dist;

int pos=0;

const int a=11;
const int b=10;
const int c=9;
const int d=6;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(echo,INPUT);
  // put your setup code here, to run once:
pinMode (laser1, OUTPUT);
pinMode (laser2, OUTPUT);
pinMode (buz,OUTPUT);

one.attach(3);
two.attach(5);

pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
pinMode(d,OUTPUT);}

void loop() {
  // put your main code here, to run repeatedly:

/*meas();
if(dist < 10 && dist>0)
{serv();}
else if(dist>10&&dist<20)
{light();}
else if(dist>20&&dist<30)
{sound();}
else if(dist>30&&dist<40)
{motor();}
*/
motor();
delay(1000);}


void meas()
{
  digitalWrite (trig,HIGH);
  digitalWrite (13,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  dist = duration/58;
  Serial.print(duration);
  Serial.println(dist);
  delay(100);
}

void light()
{
digitalWrite(laser1, HIGH);
delay (500);
digitalWrite(laser1, LOW);
digitalWrite(laser2, HIGH);
delay(500);
digitalWrite(laser2,LOW);
}

void sound()
{
  for(int n=5;n>0;n--) 
  {digitalWrite (buz,HIGH);
  delay(100);
  digitalWrite (buz,LOW);
delay(100);
}}

void serv()
{one.write(15);
two.write(165);
delay(1000);
  for (pos=15;pos<=165;pos+=10)
  {
    one.write(pos);
    two.write(165-pos);
    delay(100);
  }
for (pos=165;pos>=15;pos-=10)
{
  one.write(pos);
two.write(165-pos);
delay(100);
}delay(1000);
  one.write(90);
two.write(90);

}

void motor(){
  digitalWrite(a,HIGH);
  delay(500);
  digitalWrite(a,LOW);
  delay(500);

    digitalWrite(b,HIGH);
  delay(500);
  digitalWrite(b,LOW);
  delay(500);

    digitalWrite(c,HIGH);
  delay(500);
  digitalWrite(c,LOW);
  delay(500);

    digitalWrite(d,HIGH);
  delay(500);
  digitalWrite(d,LOW);
  delay(500);

}


