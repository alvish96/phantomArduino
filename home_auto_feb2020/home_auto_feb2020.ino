#include<IRremote.h>
#define irpin 6
//#define G A7
//#define ldr A0
#define s1 2
#define s2 3
#define s3 4
#define s4 5




unsigned long CODE_POWER_ON = 0x61D650AF;   //23
unsigned long CODE_FF = 0x61D648B7;         //17
unsigned long CODE_RW = 0x61D610EF;         //18
unsigned long CODE_NEXT = 0x61D6F20D;       //19
unsigned long CODE_BACK = 0x61D630CF;       //20
unsigned long CODE_VERT = 0x61D69867;       //21
unsigned long CODE_HORI = 0x61D6A25D;       //22
unsigned long CODE_LISTEN = 0x61D67887;     //24


unsigned long CODE_SELECT = 0x61D628D7;     //1
unsigned long CODE_RIGHT = 0x61D69A65;      //2
unsigned long CODE_LEFT = 0x61D6A857;       //3
unsigned long CODE_UP = 0x61D6AA55;         //4
unsigned long CODE_DOWN = 0x61D618E7;       //5
unsigned long CODE_MENU = 0x61D632CD;       //6
unsigned long CODE_EXIT = 0x61D6728D;       //7
unsigned long CODE_SOURCE = 0x61D6D02F;     //8
unsigned long CODE_ZOOM = 0x61D6F00F;       //9
unsigned long CODE_VOLUP = 0x61D6708F;      //10
unsigned long CODE_VOLDW = 0x61D612ED;      //11
unsigned long CODE_PIC = 0x61D6629D;        //12
unsigned long CODE_SOUND = 0x61D6EA15;      //13
unsigned long CODE_FREEZE = 0x61D6DA25;     //14
unsigned long CODE_PLAY = 0x61D6906F;       //15
unsigned long CODE_MUTE = 0x61D652AD;       //16

void(* resetFunc) (void) = 0; //declare reset function @ address 0
IRrecv ir(irpin);
decode_results irresult;
int ldrval = 0;
#define ron HIGH
#define roff LOW
int pre;
int m;
bool f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, ft1, ft2, ft3, ft4, ft5;
unsigned long a1, a2, a3, a4, a5 = 0;
//unsigned long x1 = 5 * 60000, x2 = 15 * 60000, x3 = 30 * 60000, x4 = 45 * 60000, x5;
unsigned long x1, x2, x3, x4, x5;
//---------------------------------------------------------------------------------------------------
void setup()
{

  Serial.begin(9600);
  ir.enableIRIn();          // Start the receiver
  //  pinMode(G, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  //  digitalWrite(G, LOW);
  digitalWrite(s1, roff);
  digitalWrite(s2, roff);
  digitalWrite(s3, roff);
  digitalWrite(s4, roff);


}
//---------------------------------------------------------------------------------------------------

void loop()
{
  //Serial.println(millis()/1000);
  //  Serial.println(a1 + x1 / 1000);

  if (ft1 == 1)
  {

    if (millis() > (a1 + x1))
    {
      digitalWrite(s1, LOW);
      Serial.println("main light timer off");
      f1 = LOW; a1 = 0; x1 = 0; ft1 = 0;
      pf();
    }
  }

  else if (ft2 == 1)
  {

    if (millis() > (a2 + x2))
    {
      digitalWrite(s2, LOW);
      Serial.println("led light timer off");
      f2 = LOW; a2 = 0; x2 = 0; ft2 = 0;
      pf();
    }
  }

  else if (ft3 == 1)
  {

    if (millis() > (a3 + x3))
    {
      digitalWrite(s3, LOW);
      Serial.println("fan timer off");
      f3 = LOW; a3 = 0; x3 = 0; ft3 = 0;
      pf();
    }
  }
  else if (ft4 == 1)
  {

    if (millis() > (a4 + x4))
    {
      digitalWrite(s4, LOW);
      Serial.println("exhaust timer off");
      f4 = LOW; a4 = 0; x4 = 0; ft4 = 0;
      pf();
    }
  }

  else if (ft5 == 1)
  {

    if (millis() > (a5 + x5))
    {
      resetFunc();
      //      digitalWrite(s4, LOW);
      Serial.println("exhaust timer off");
      //      f4 = LOW;a4=0;x4=0;ft4=0;
      //      pf();
    }
  }
  irtest();

}

//---------------------------------------------------------------------------------------------------
/*
  void brightness()
  {
  ldrval = analogRead(ldr);
  Serial.println(ldrval);
  //  delay(100);
  //  lcd.setCursor(0, 1);
  //  lcd.print(ldrval);
  delay(1000);
  }
*/
void pf()
{
  Serial.println(f1);
  Serial.println(f2);
  Serial.println(f3);
  Serial.println(f4);
  Serial.println();
  Serial.println(x1);
  Serial.println(x2);
  Serial.println(x3);
  Serial.println(x4);
  Serial.println();
}
void wait(int n)
{
  delay(n * 1000);
  resetFunc();
}
void SW1()
{
  f1 = !f1;
  digitalWrite(s1, f1);
  Serial.println("MAIN LIGHT");
  //  lcd.setCursor(0, 1);
  if (f1 == 1)Serial.println("light on");
  if (f1 == 0)Serial.println("light off");
  x1 = 0;
}

void SW2()
{
  f2 = !f2;
  digitalWrite(s2, f2);
  Serial.println("LED LIGHT");
  //  lcd.setCursor(0, 1);
  if (f2 == 1)Serial.println("light led on");
  if (f2 == 0)Serial.println("light led off");
  x2 = 0;
}

void SW3()
{
  f3 = !f3;
  digitalWrite(s3, f3);
  Serial.println("FAN");
  //  lcd.setCursor(0, 1);
  if (f3 == 1)Serial.println("fan on");
  if (f3 == 0)Serial.println("fan off");
  x3 = 0;
}

void SW4()
{
  f4 = !f4;
  digitalWrite(s4, f4);
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f4 == 1)Serial.println("switch on");
  if (f4 == 0)Serial.println("switch off");
  x4 = 0;
}
//---------------------------------------------------------------------------------------------------
void SW1t(int m)
{
  a1 = 0;
  x1 = 0;
  x1 = m * 60000;
  digitalWrite(s1, HIGH);
  //    Serial.println("fan is on for 5 mins");
  a1 = millis();
  Serial.println("set millis");
  f1 = HIGH; ft1 = HIGH;
  Serial.println("f1 high");
}

void SW2t(int m)
{
  a2 = 0;
  x2 = 0;
  x2 = m * 60000;
  digitalWrite(s2, HIGH);
  //    Serial.println("light is on for 5 mins");
  a2 = millis();
  Serial.println("set millis");
  f2 = HIGH; ft2 = HIGH;
  Serial.println("f2 high");
}
void SW3t(int m)
{
  a3 = 0;
  x3 = 0;
  x3 = m * 60000;
  digitalWrite(s3, HIGH);
  //    Serial.println("light is on for 5 mins");
  a3 = millis();
  Serial.println("set millis");
  f3 = HIGH; ft3 = HIGH;
  Serial.println("f3 high");
}

void SW4t(int m)
{
  a4 = 0;
  x4 = 0;
  x4 = m * 60000;
  digitalWrite(s4, HIGH);
  //    Serial.println("light is on for 5 mins");
  a4 = millis();
  Serial.println("set millis");
  f4 = HIGH; ft4 = HIGH;
  Serial.println("f4 high");
}

void reset(int m)
{
  a5 = 0;
  x5 = 0;
  x5 = m * 1000;
  //  digitalWrite(s4, HIGH);
  //    Serial.println("light is on for 5 mins");
  a5 = millis();
  Serial.println("set millis");
  f5 = HIGH; ft5 = HIGH;
  Serial.println("f5 high");
}


void incsw1(int t)
{
  x1 += (t * 60000);
  Serial.println("added time main light");
}
void decsw1(int t)
{
  if (x1 > 10000)
  { x1 -= (t * 60000);
    Serial.println("removed time main light");
  }
}


void incsw2(int t)
{
  x2 += (t * 60000);
  Serial.println("added time led main");
}
void decsw2(int t)
{
  if (x2 > 10000)
  { x2 -= (t * 60000);
    Serial.println("removed time led main");
  }
}

void incsw3(int t)
{
  x3 += (t * 60000);
  Serial.println("added time fan");
}
void decsw3(int t)
{
  if (x3 > 10000)
  { x3 -= (t * 60000);
    Serial.println("removed time fan");
  }
}

void incsw4(int t)
{
  x4 += (t * 60000);
  Serial.println("added time exhaust");
}
void decsw4(int t)
{
  if (x4 > 10000)
  { x4 -= (t * 60000);
    Serial.println("removed time exhaust");
  }
}



/*
  void abc(int i)
  {
  unsigned long startMillis = millis();
  Serial.println("FAN "); Serial.println(i);
  unsigned long x = millis() - startMillis;
  if (x < i * 60 * 1000)
  {
    Serial.println(x);
    Serial.println();
    digitalWrite(s3, HIGH);
  }
  else digitalWrite(s3, LOW);

  }

  void abcd(int i)
  {
  bool f = 0;
  unsigned long startMillis = 0;
  startMillis = millis();
  Serial.println("SWITCH "); Serial.println(i);
  x: if (millis() - startMillis < i * 60000)
  {
    f = 1;
    digitalWrite(s4, HIGH);
    Serial.print(" ");  Serial.print(millis() - startMillis);
  }
  else
  {
    f = 0;
    digitalWrite(s4, LOW);
  }
  irtest();
  if (f == 1)
    goto x;

  }



  void timer(int a, int b)
  {
  unsigned long startmillis = millis();
  Serial.println("TIMER"); Serial.println(b);
  while (millis() - startmillis < b * 60000 )
  {
    digitalWrite(a, HIGH);
    //    Serial.println(millis());
    //    Serial.println(startmillis);

    Serial.print(" ");  Serial.print((millis() - startmillis) * 10 );
  }
  digitalWrite(a, LOW);
  }

*/
//---------------------------------------------------------------------------------------------------
