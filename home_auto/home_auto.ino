


#include <Servo.h>

Servo myservo;  // create servo object to control a servo


#define m1a  6     // L298N  1 motor 6
#define m1b  7      // L298N  2 motor 7

#define m2a  8      // L298N  1 motor 8
#define m2b  9       // L298N  2 motor 9
#define buz 12   //buzzer

int val;
int de1 = 700;//for big tray
int de2 = 90;// for small tray
int de3 = 1;//for grab and drop
//---------------------------------------------------------------------------------------------------


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //pinMode(ENA_m1, OUTPUT);
  //pinMode(ENA_m2, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(buz, LOW);

  myservo.attach(10);  // attaches the servo on pin 9 to the servo object  10
}
//---------------------------------------------------------------------------------------------------
void term() {
  Serial.println("end prgm");
  b(5); buzz(3);
  exit(0);
}
//---------------------------------------------------------------------------------------------------
void(* resetFunc) (void) = 0; //declare reset function @ address 0

//resetFunc();  //call reset
//---------------------------------------------------------------------------------------------------

void del() {
  delay(50);
}
void buzz(int n) {
  int del = 10;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
void buzz() {
  int del = 10, n = 1;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
void b(int n) {
  int del = 50;
  digitalWrite(13, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(13, HIGH);
    delay(del);
    digitalWrite(13, LOW);
    delay(del);
  } digitalWrite(13, LOW);
}
void b() {
  int del = 50, n = 1;
  digitalWrite(13, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(13, HIGH);
    delay(del);
    digitalWrite(13, LOW);
    delay(del);
  } digitalWrite(13, LOW);
}

//---------------------------------------------------------------------------------------------------
void loop() {
  test2();
  delay(5000);
  term();
}


//---------------------------------------------------------------------------------------------------
void test1()
{ drop(); buzz(); del();
  godown(); buzz();
  goup(); buzz(); del();
  grab(); buzz();
  secure(); buzz(); del();
  releas(); buzz();
}
//---------------------------------------------------------------------------------------------------
void test2() {
  serv(20); buzz(); del();
  releas(); buzz(); del();
  serv(50); buzz(); del();
  drop(); buzz(); del();
  serv(110); buzz(); del();
  godown(); buzz(); del();
  serv(50); buzz(2); del();
  goup(); buzz(); del();
  grab(); buzz(); del();
  serv(20); buzz(); del();
  secure(); buzz(); del();

}
//---------------------------------------------------------------------------------------------------
void serv(int n)
{
  myservo.write(n);  // servo (value between 0 and 180)
}


void godown() {
  digitalWrite(m1a, HIGH);  Serial.println("m2-->\t"); b(2);
  digitalWrite(m1b, LOW);
  delay(de1);
  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
}


void goup() {
  digitalWrite(m1a, LOW);  Serial.println("m2<--\t"); b(2);
  digitalWrite(m1b, HIGH);
  delay(de1);
  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
}

void grab() {
  digitalWrite(m1a, LOW);  Serial.println("m2<--\t"); b(2);
  digitalWrite(m1b, HIGH);
  delay(de3);
  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
}
void drop()
{
  digitalWrite(m1a, HIGH);  Serial.println("m2-->\t"); b(2);
  digitalWrite(m1b, LOW);
  delay(de3);
  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
}

void secure() {
  digitalWrite(m2a, LOW);  Serial.println("m2<--\t"); b(2);
  digitalWrite(m2b, HIGH);
  delay(de2);
  digitalWrite(m2a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m2b, LOW);
}

void releas() {
  digitalWrite(m2a, HIGH);  Serial.println("m2-->\t"); b(2);
  digitalWrite(m2b, LOW);
  delay(de2);

  digitalWrite(m2a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m2b, LOW);
}



//---------------------------------------------------------------------------------------------------

void testm1()
{
  int dey = 800;
  int del = 800;


  analogWrite(m1a, 0);  Serial.println("m1-->\t"); b(2);
  analogWrite(m1b, 0);
  delay(dey); buzz(1);
  delay(1000);
  buzz(3);
  analogWrite(m1a, 0);  Serial.println("m1-->\t"); b(2);
  analogWrite(m1b, 255 );
  delay(dey); buzz(3);
  delay(1000);
  analogWrite(m1a, 0);  Serial.println("m1-->\t"); b(2);
  analogWrite(m1b, 0);
  delay(dey); buzz(1);

  /*


    digitalWrite(m1a,LOW);  Serial.println("m1 off");b(2);
    digitalWrite(m1b,HIGH);
    delay(dey);b(5);

    digitalWrite(m1a,LOW);  Serial.println("m1<--\t");b(2);
    digitalWrite(m1b,HIGH);
    delay(dey);
    digitalWrite(m1a,LOW);  Serial.println("m1 off");b(2);
    digitalWrite(m1b,LOW);

  */
}
//---------------------------------------------------------------------------------------------------
void test() {


  digitalWrite(m1a, HIGH);  Serial.println("m2-->\t"); b(2);
  digitalWrite(m1b, LOW);
  delay(de1);

  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
  delay(1000); b(5);

  digitalWrite(m1a, LOW);  Serial.println("m2<--\t"); b(2);
  digitalWrite(m1b, HIGH);
  delay(de1);
  digitalWrite(m1a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m1b, LOW);
  delay(1000); b(5);
  //--------------------------------------------------------------
  delay(1000); Serial.println("delay"); b(5); buzz();
  //--------------------------------------------------------------
  digitalWrite(m2a, HIGH);  Serial.println("m2-->\t"); b(2);
  digitalWrite(m2b, LOW);
  delay(de2);

  digitalWrite(m2a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m2b, LOW);
  delay(1000); b(5);

  digitalWrite(m2a, LOW);  Serial.println("m2<--\t"); b(2);
  digitalWrite(m2b, HIGH);
  delay(de2);
  digitalWrite(m2a, LOW);  Serial.println("m2off\t"); b(2);
  digitalWrite(m2b, LOW);
  delay(1000); b(5);
  //--------------------------------------------------------------
  buzz();
}
//---------------------------------------------------------------------------------------------------
