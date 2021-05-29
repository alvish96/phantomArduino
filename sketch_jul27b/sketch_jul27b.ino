#include <Servo.h>
Servo one,two;

int laser1 = 2;
int laser2 = 4;

int buz = 11;
int lvl;
const int trig=7,echo =8;
float duration, dist;

int pos=0;

const int a=6;
const int b=9;
const int c=10;
const int d=12;


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

meas();
if(dist < 10 && dist>0)
{serv();}
else if(dist>10&&dist<20)
{lightbl();}
else if(dist>20&&dist<30)
{siren();}
else if(dist>30&&dist<40)
{motor();}

}


void meas()
{
  digitalWrite (trig,HIGH);
  digitalWrite (13,HIGH);
  delay(15);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  dist = duration/58;
  Serial.print(duration);
  Serial.print("  <- time    and   distance ->  ");
  Serial.println(dist);
  delay(10);
}

void lightbl()
{
digitalWrite(laser1, HIGH);
delay (500);
digitalWrite(laser1, LOW);
digitalWrite(laser2, HIGH);
delay(500);
digitalWrite(laser2,LOW);
}
void light()
{
  digitalWrite(laser1,HIGH);
  digitalWrite(laser2,HIGH);
}

void lightoff()
{
  digitalWrite(laser1,LOW);
  digitalWrite(laser2,LOW);
}


void sound()
{
  for(int n=5;n>0;n--) 
  {analogWrite(buz,150);
  delay(100);
  analogWrite(buz,0);
delay(100);
}}
void alarm()
{
 digitalWrite(laser1,HIGH);
  analogWrite(buz,150);
  delay(150);
  digitalWrite(laser1,LOW);
  analogWrite(buz,0);
  delay(150);
  digitalWrite(laser2,HIGH);
  analogWrite(buz,150);
  delay(150);
  digitalWrite(laser2,LOW);
  analogWrite(buz,0);
  delay(150);

}

void siren()
{
  for(int lvl=10;lvl<=255;lvl++)
  {
  analogWrite(buz,lvl);delay(5);
  }
  delay(500);
  for (int lvl=255;lvl>=10;lvl--)
  {analogWrite(buz,lvl);delay(5);
  }
  delay(500);
 // digitalWrite(buz,HIGH);delay(750);
  analogWrite(buz,0);
  
}



void serv()
{
  light();delay(750);
  one.write(15);
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
delay(500);
lightoff();
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


