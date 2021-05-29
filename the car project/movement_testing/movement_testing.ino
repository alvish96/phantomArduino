

#include <Servo.h>
Servo one;

int buz = 12;
int laser1 = 52;
int laser2 = 48;
const int trig = 51, echo = 50, vcc = 53;
float duration, dist;

const int forw = 4;
const int back = 7;
const int left = 6;
const int right = 5;



void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT); digitalWrite(13, LOW);
  pinMode(trig, OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(echo, INPUT);
  pinMode (laser1, OUTPUT);
  pinMode (laser2, OUTPUT);
  pinMode (buz, OUTPUT);
  one.attach(3);

  pinMode(forw, OUTPUT);
  pinMode(back, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);


  //light pins

  one.write(0);
}


/************************************************


                   LOOP


************************************************/

void loop()
{
  basic();
/*

  one.write(0);
  delay(2000);

  one.write(90);
  delay(2000);

  one.write(180);
  delay(2000);

  one.write(0);
  deci();
  turn_around();
  // testing();
  shutdown1();
*/}



/************************************************


                   TESTING


************************************************/

void testing() {

  accel();
  delay(3000);
  kill();
  delay(3000);
  movs();
  delay(3000);
  kill();
}

void basic()
{

one.write(90);
  accel();delay(400);
  int b=meas();
  if(b<30)
  {
    kill();
    rev();delay(500);
    kill();
  shutdown1();
  }
  
}
void test1()
{
//f1:{ accel();     check();}

/*f2:( movf();   check(););
f3: (movm();   check(););
f4: (movs();   check(););
f5: (kill(); check(););
*/
}

/*
void check()
{
  float dis = meas();
  if (dist > 50) {
    goto f1;
  }
  if (dis <= 50 && dis >= 40)  {
    goto f2;
  }
  if (dis <= 39 && dis >= 30) {
    goto f3;
  }
  if (dis <= 29 && dis >= 20) {
    goto f4;
  }
  if (dis <= 20 && dis >= 15) {
    goto f5;
  }
  if (dis <= 14 && dis >= 10) {
    
  }
  if (dis <= 9 && dis >= 5) {
    goto turn;
}  }*/


void deci()
{
  int n[2] = {0, 0};

  one.write(180);
  n[0] = meas();
  one.write(0);
  n[1] = meas();

  Serial.print(n[0]);  Serial.println("   ");  Serial.println(n[1]);

  if (n[0] > n[1] && n[0] > 20)
  {
    go_left();  Serial.print("going left");
  }
  else if (n[0] < n[1] && n[1] > 20)
  {
    go_right(); Serial.print("going right");
  }
  else 
  {
    turn_around(); Serial.print("about turn");
  }

  
}
void go_left() {
  tl();
  delay(1000);
  track();

}
void go_right() {
  tr();
  delay(1000);
  track();

}
void turn_around() {
  rev(); delay(400); kill();
  tl(); rev(); delay(500); kill();track();
  tr(); movs(); delay(500); kill();track();
  tl(); rev(); delay(500); kill();track();
  tr(); movs(); delay(500); kill();track();
  
  
}

void tl() {
  digitalWrite(left, HIGH);
}
void tr() {
  digitalWrite(right, HIGH);
}
void track() {
  digitalWrite(left, LOW);
  digitalWrite(right, LOW);

}


/************************************************


                   MOTOR


************************************************/

void accel() {
  digitalWrite(forw, HIGH);
}
void movf()
{
  analogWrite(forw, 200);
}
void movm() {
  analogWrite(forw, 100);
}
void movs() {
  analogWrite(forw, 80);
}

void rev() {
  int vel = 80;
  analogWrite(back, vel);
}
void kill() {
  digitalWrite(forw, LOW);
  digitalWrite(back, LOW);
}


/************************************************


                   USS


************************************************/





float nut()
{
  digitalWrite(trig, HIGH);
  digitalWrite(vcc, HIGH);
  delay(100);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration / 58;
  return dist;
}

float meas()
{
  float av = 0;
  for (int k = 0; k <= 3; k++)
  {
    dist = nut();//  Serial.println(dist);
    if (k == 2)
    {
      av = dist;
    }
  } Serial.println(av);
  return av;
}


/************************************************


                   servo


************************************************/
void scan()
{
  one.write(0);
  for (int i = 0; i <= 90; i + 5)
  { one.write(i); delay(100);
  }
  one.write(0);
  //beep();
}
/*
  void scan1()
  {
  one.write(20); meas(); light(); beep(); lightoff();
  delay(1000);
  one.write(90); meas(); light(); beep(); lightoff();
  delay(1000);
  one.write(180); meas(); light(); beep(); lightoff();
  delay(1000);
  one.write(90); meas(); light(); beep(); lightoff();
  delay(1000);
  }*/
/************************************************


                   MISC


************************************************/
void shutdown1()
{
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println ("                   *************************");
  Serial.println ("                         end of program ");
  Serial.println ("                   *************************");
  while (1);
}




