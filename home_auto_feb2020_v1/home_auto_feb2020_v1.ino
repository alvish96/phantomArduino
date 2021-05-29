#include<IRremote.h>
#define irpin 6
//#define G A7
#define ldr A1
#define s1 2
#define s2 3
#define s3 4
#define s4 5

int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
long unsigned int lastmotion = 0, present = 0;

boolean lockLow = true;
boolean takeLowTime,temp;

int pirPin = 8;
int ledPin = 13;


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
int count;

int a, b, x;
int limit = 350;

bool checkmotion;

bool mf1, motn, prflag;






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

  pinMode(ldr, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  Serial.print("calibrating sensor ");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
  checkmotion = 1; prflag = 0;
}
//---------------------------------------------------------------------------------------------------

void loop()
{
  //Serial.println(millis()/1000);
  //  Serial.println(a1 + x1 / 1000);

  if (ft1 == 1)
  {

    if (millis() > (a1 + x1) )   //threshold for keeping light on
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
      prflag = temp;
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
      prflag = temp;
      pf();
    }
  }


  else if (ft5 == 1)
  {
    if (millis() > (a5 + x5))
    {
      resetFunc();
    }
  }


  /*


    //
    //  if (motion() == HIGH)
    //  {
    //    count++;
    //  }


    //  if (count < 2)
    //  {
    //    Serial.println("mf");
    //    Serial.println(mf);
    //    SW5();
    //  }

    if (checkmotion == 1)
    {
    if ( motion() == 1)
    {
    //      count++;
      if (brt() < limit)
      {
        SW1t(1); mf1 = 0;
        count = 0;
      }
      //Serial.println(count);
    }
    }*/
  present = millis() / 1000;
  if (prflag == 1)
  {
    goto point;
  }
  gapstt(4);
  Serial.print(" not skipping");
point:
  //
  //  {
  //    checkmotion = 0;
  //  }

  if (checkmotion == 1)
  {
    if (motion() == 1)
    {
      if (brt() < limit)
      {
        SW1();
        delay(500);
        //mf1 = 0;
        count = 0;
      }
      /*if (brt() > limit)
      {
        digitalWrite(s1, roff);
        digitalWrite(s2, roff);
      }*/
    }

  }


  //
  //prevcount+=count;
  //if (prevcount==count)
  //checkmotion=1



  printvals();
  irtest();

}

//---------------------------------------------------------------------------------------------------

void gapstt(int gap)
{
  if ((present - lastmotion) > (gap * 60))
  {
    resetFunc();
  }
}

int brt()
{
  ldrval = analogRead(ldr);
  delay(100);
  // Serial.println(ldrval);
  return ldrval;
}



//---------------------------------------------------------------------------------------------------

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
void printvals()
{

  Serial.println();
  Serial.print(" Gap - ");
  Serial.print(present - lastmotion);
  Serial.print(" || Count - ");
  Serial.print(count);
  Serial.print(" || brightness - ");
  Serial.print(brt());
  Serial.print(" || priority - ");
  Serial.print(prflag);

}
bool motion()
{
  motn = 0;
  if (digitalRead(pirPin) == HIGH)
  {
    digitalWrite(ledPin, HIGH);   //the led visualizes the sensors output pin state
    motn = 1;
    if (lockLow) {
      //makes sure we wait for a transition to LOW before any further output is made:
      lockLow = false;
      Serial.println();
      count++;
      Serial.print("motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pirPin) == LOW)
  {
    digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state

    if (takeLowTime)
    {
      lowIn = millis();          //save the time of the transition from high to LOW
      takeLowTime = false;       //make sure this is only done at the start of a LOW phase
    }
    //if the sensor is low for more than the given pause,
    //we assume that no more motion is going to happen
    if (!lockLow && millis() - lowIn > pause) {
      //makes sure this block of code is only executed again after
      //a new motion sequence has been detected
      lockLow = true;
      Serial.println();
      Serial.print("motion ended at ");     //output
      lastmotion = (millis() - pause) / 1000;
      Serial.print(lastmotion);
      Serial.println(" sec");
      delay(50);
    }
  }
  return motn;
}
int freq()
{
  int t = ((millis() / 1000) - ((millis() - 60000) / 1000));
  int f = count / t;
  return f;
}
void countreset()
{
  int a = millis() / 1000;

}

//---------------------------------------------------------------------------------------------------

void wait(int n)
{
  delay(n * 1000);
  resetFunc();
}

//---------------------------------------------------------------------------------------------------

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

void SW5()
{
  checkmotion = !checkmotion;
  prflag = 1;
  //  ft1 = !ft1;
  //  ft2=0;
  //  ft3=0;
  //  ft4=0;
  //
  Serial.println("MOTION SWITCH");
  //  lcd.setCursor(0, 1);
  if (checkmotion == 1)Serial.println("motion switch on");
  if (checkmotion == 0)Serial.println("motion switch off");

}
//---------------------------------------------------------------------------------------------------
void SW1t(int ma1)
{
  a1 = 0;
  x1 = 0;
  x1 = ma1 * 60000;
  digitalWrite(s1, HIGH);
  //    Serial.println("fan is on for 5 mins");
  a1 = millis();
  //  Serial.println("set millis");
  f1 = HIGH; ft1 = HIGH;
  Serial.println("main light timer on");
}

void SW2t(int ma2)
{
  a2 = 0;
  x2 = 0;
  x2 = ma2 * 60000;
  digitalWrite(s2, HIGH);
  //    Serial.println("light is on for 5 mins");
  a2 = millis();
  //  Serial.println("set millis");
  f2 = HIGH; ft2 = HIGH;
  Serial.println("led timer on");
}
void SW3t(int ma3)
{
  a3 = 0;
  x3 = 0;
  x3 = ma3 * 60000;
  digitalWrite(s3, HIGH);
  //    Serial.println("light is on for 5 mins");
  a3 = millis();
  //  Serial.println("set millis");
  f3 = HIGH; ft3 = HIGH;
  temp=prflag;
  prflag = 1; //setting priority to timer
  Serial.println("fan timer on");
  Serial.println("priority set");
}

void SW4t(int ma4)
{
  a4 = 0;
  x4 = 0;
  x4 = ma4 * 60000;
  digitalWrite(s4, HIGH);
  //    Serial.println("light is on for 5 mins");
  a4 = millis();
  //  Serial.println("set millis");
  f4 = HIGH; ft4 = HIGH;
  temp=prflag;
  prflag = 1; //setting priority to timer
  Serial.println("Exhaust timer on");
  Serial.println("priority set");
}
//---------------------------------------------------------------------------------------------------
void reset(int ma5)
{
  a5 = 0;
  x5 = 0;
  x5 = ma5 * 1000;
  a5 = millis();
  //  f5 = HIGH;
  ft5 = HIGH;
  Serial.println();
  Serial.println("Reset initiated 20 seconds");
}

//---------------------------------------------------------------------------------------------------
void incsw1(int ta1)
{
  x1 += (ta1 * 60000);
  Serial.println("added time main light");
}
void decsw1(int ta2)
{
  if (x1 > 10000)
  { x1 -= (ta2 * 60000);
    Serial.println("removed time main light");
  }
}


void incsw2(int ta3)
{
  x2 += (ta3 * 60000);
  Serial.println("added time led main");
}
void decsw2(int ta4)
{
  if (x2 > 10000)
  { x2 -= (ta4 * 60000);
    Serial.println("removed time led main");
  }
}

void incsw3(int ta5)
{
  x3 += (ta5 * 60000);
  Serial.println("added time fan");
}
void decsw3(int ta6)
{
  if (x3 > 10000)
  { x3 -= (ta6 * 60000);
    Serial.println("removed time fan");
  }
}

void incsw4(int ta7)
{
  x4 += (ta7 * 60000);
  Serial.println("added time exhaust");
}
void decsw4(int ta8)
{
  if (x4 > 10000)
  { x4 -= (ta8 * 60000);
    Serial.println("removed time exhaust");
  }
}

//---------------------------------------------------------------------------------------------------

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
