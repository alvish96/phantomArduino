#include <DS3231.h>

DS3231  rtc(SDA, SCL);
Time t;
int f, g;
int R1 = 8;
int R2 = 7;
int a = 6, c = 6;
int b = 6, d = 6;
int period = 20;            //compensation period

int input;

int h, m, s;

bool r1, RSwitch1;
bool r2, RSwitch2;
bool R1T1, R1T2, R2T1, R2T2;
bool debug ;
int a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8;
int tim[17] = {0, 8, 30, 15, 30, 18, 0, 22, 0, 8, 30, 15, 30, 18, 0, 22, 0};
bool flag[7] = {1, 1, 1, 1, 1, 1, 1};
//
//int a1 = 8  , a2 = 30, b1 = 15, b2 = 30;          //timer 1 relay 1
//int a3 = 18, a4 = 0 , b3 = 22, b4 = 0;            //timer 2 relay 1
//int a5 =  a1, a6 = a2 + 1, b5 = b1, b6 = b2 + 1;  //timer 1 relay 2
//int a7 = a3, a8 = a4 + 1, b7 = b3, b8 = b4 + 1;   //timer 2 relay 2
//
//int OnHour1 = a1, OnMin1 = a2;
//int OffHour1 = b1, OffMin1 = b2;
//
//int OnHour2 = a3, OnMin2 =  a4;
//int OffHour2 = b3, OffMin2 =  b4;
//
//int OnHour3 = a5, OnMin3 = a6;
//int OffHour3 = b5, OffMin3 = b6;
//
//int OnHour4 = a7, OnMin4 =  a8;
//int OffHour4 = b7, OffMin4 =  b8;


int OnHour1, OnMin1;
int OffHour1 , OffMin1 ;

int OnHour2 = a3, OnMin2 ;
int OffHour2 = b3, OffMin2 ;

int OnHour3 , OnMin3 ;
int OffHour3 , OffMin3 ;

int OnHour4 , OnMin4 ;
int OffHour4 , OffMin4 ;




//
//class menu
//{
//  public:
//    int tim[20];
//    bool flag[7]; //= {1, 1, 1, 1, 1, 1, 1};
//};
//int tim[20];
//bool flag[7];

//menu obj;




void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  rtc.begin();
  pinMode(R1, OUTPUT);
  digitalWrite(R1, 0);

  pinMode(R2, OUTPUT);
  digitalWrite(R2, 0);
  //  setrQ();



  mainmenu();
  flags();
  setval();
  digitalWrite(R1, 1);
  digitalWrite(R2, 1);
}


void setval()
{



  a1 =  tim[1] ;
  a2 =  tim[2] ;
  b1 =  tim[3] ;
  b2 =  tim[4] ;

  //r1t2
  a3 =  tim[5] ;
  a4 =  tim[6] ;
  b3 =  tim[7] ;
  b4 =  tim[8] ;

  //r2t1
  a5 =  tim[9] ;
  a6 =  tim[10] ;
  b5 =  tim[11] ;
  b6 =  tim[12] ;

  //r2t2
  a7 =  tim[13] ;
  a8 =  tim[14] ;
  b7 =  tim[15] ;
  b8 =  tim[16] ;


  debug =  flag[0] ;                //debug switch
  RSwitch1 =  flag[1] ;             //relay 1 switch
  RSwitch2 =  flag[2];             //relay 2 switch

  R1T1 =  flag[3] ;                 //relay 1 timer 1 switch
  R1T2 =  flag[4] ;                 //relay 1 timer 2 switch
  R2T1 =  flag[5] ;                 //relay 2 timer 1 switch
  R2T2 =  flag[6] ;




  OnHour1 = a1, OnMin1 = a2;
  OffHour1 = b1, OffMin1 = b2;

  OnHour2 = a3, OnMin2 =  a4;
  OffHour2 = b3, OffMin2 =  b4;

  OnHour3 = a5, OnMin3 = a6;
  OffHour3 = b5, OffMin3 = b6;

  OnHour4 = a7, OnMin4 =  a8;
  OffHour4 = b7, OffMin4 =  b8;

  //
  //  debug =  flag[0] ;                //debug switch
  //  RSwitch1 =  flag[1] ;             //relay 1 switch
  //  RSwitch2 =  flag[2] ;             //relay 2 switch
  //
  //  R1T1 =  flag[3] ;                 //relay 1 timer 1 switch
  //  R1T2 =  flag[4] ;                 //relay 1 timer 2 switch
  //  R2T1 =  flag[5] ;                 //relay 2 timer 1 switch
  //  R2T2 =  flag[6] ;                 //relay 2 timer 2 switch












}
void flags()
{
  for (int i = 1; i < 17; i++)
  {
    Serial.print(" tim ");
    Serial.println( tim[i]);
  }
  for (int j = 0; j < 7; j++)
  {
    Serial.print(" flag ");
    Serial.println( flag[j]);
  }
}
void setrQ()
{


  digitalWrite(R2, 0); digitalWrite(R1, 0);
  delay(50);
  digitalWrite(R2, 1); digitalWrite(R1, 1);
  delay(100);

  digitalWrite(R2, 0); digitalWrite(R1, 0);
  delay(50);
  digitalWrite(R2, 1); digitalWrite(R1, 1);
  delay(500);

  digitalWrite(R2, 0); digitalWrite(R1, 0);
  //  digitalWrite(R2, 0);
  delay(300);
  digitalWrite(R2, 1); digitalWrite(R1, 1);
  digitalWrite(R1, 1); digitalWrite(R1, 1);
  //  delay(100);
}


void setr()
{
  digitalWrite(R2, 0);  digitalWrite(R1, !0);
  delay(50);
  digitalWrite(R2, 1);  digitalWrite(R1, 0);
  delay(100);

  digitalWrite(R2, 0); digitalWrite(R1, !0);
  delay(50);
  digitalWrite(R2, 1); digitalWrite(R1, 0);
  delay(500);

  digitalWrite(R2, 0); digitalWrite(R1, 1);
  //  digitalWrite(R2, 0);
  delay(300);
  digitalWrite(R2, 1); digitalWrite(R1, 0);
  digitalWrite(R1, 1);
  //  delay(100);
}



void compensate()
{
  h = 11; m = 1; s = 1;
  //Start drift compensation RTC
  if (t.hour == h && t.min == m && t.sec == s)
  {
    //run daily at exactly the same time
    delay(period);
    rtc.setTime(h, m, s);
  }
}


void loop()
{
  inf();
}


void inf()
{


  for (;;)
  {
    if (Serial.available() > 0)
    {
      input = Serial.parseInt();
      if (input == 0)
        mainmenu();
    }
    Serial.println();
    compensate();
    t = rtc.getTime();
    delay (1000);
    prints();


    if (RSwitch1 == 1) {
      if (f == 2) goto a;
      rel1a(); if (f == 1) goto n;
a:
      rel1b(); //if (f == 1)continue;
    }
n:
    if (RSwitch2 == 1)
    {
      if (g == 2) goto c;
      rel2a(); if (g == 1)continue;
c:
      rel2b(); //if (g == 1)continue;
    }
  }
}
void prints() {

  Serial.print(t.hour);
  Serial.print(" :: ");
  Serial.print(t.min);
  Serial.print(" :: ");
  Serial.print(t.sec);


  if (debug == 1 || RSwitch1 == 1)
  {
    if (R1T1 == 0)Serial.print("|R1Timer1 OFF|");
    if (R1T1 == 1)
    {
      Serial.print(" |R1T1 From ");
      Serial.print(a1);
      Serial.print(":");
      Serial.print(a2);
      Serial.print(" |To ");
      Serial.print(b1);
      Serial.print(":");
      Serial.print(b2);
    }
    if (R1T2 == 0)Serial.print("|R1Timer2 OFF|");
    if (R1T2 == 1)
    {
      Serial.print(" |R1T2 ");
      Serial.print("From ");
      Serial.print(a3);
      Serial.print(":");
      Serial.print(a4);
      Serial.print(" |To ");
      Serial.print(b3);
      Serial.print(":");
      Serial.print(b4);
      Serial.print("| ");
    }
  }

  if (debug == 1 || RSwitch2 == 1)
  {
    if (R2T1 == 0)Serial.print("|R2Timer1 OFF|");
    if (R2T1 == 1)
    {
      Serial.print(" |R2T1 From ");
      Serial.print(a5);
      Serial.print(":");
      Serial.print(a6);
      Serial.print(" |To ");
      Serial.print(b5);
      Serial.print(":");
      Serial.print(b6);
    }
    if (R2T2 == 0)Serial.print("|R2Timer2 OFF|");
    if (R2T2 == 1)
    {
      Serial.print(" |R2T2 ");
      Serial.print("From ");
      Serial.print(a7);
      Serial.print(":");
      Serial.print(a8);
      Serial.print(" |To ");
      Serial.print(b7);
      Serial.print(":");
      Serial.print(b8);
      Serial.print("| ");

    }
  }
  if (RSwitch1 == 0)
  {
    Serial.print(" |Relay 1 Switched OFF| ");
  }

  if (RSwitch1 == 1)
  {
    bool r1 = digitalRead(R1);
    Serial.print(" | R1 ");
    if (r1 == 0)
      Serial.print("ON");
    else if (r1 == 1)
      Serial.print("OFF");
  }
  if (RSwitch2 == 0)
  {
    Serial.print(" |Relay 2 Switched OFF| ");
  }
  if (RSwitch2 == 1)
  {
    bool r2 = digitalRead(R2);
    Serial.print(" | R2 ");
    if (r2 == 0)
      Serial.print("ON");
    else if (r2 == 1)
      Serial.print("OFF");
  }

  if (debug == 1) {
    Serial.print(" |a=");
    Serial.print(a);
    Serial.print(" |b=");
    Serial.print(b);

    Serial.print(" |c=");
    Serial.print(c);
    Serial.print(" |d=");
    Serial.print(d);

    Serial.print(" |f=");
    Serial.print(f);
    Serial.print(" |g=");
    Serial.print(g);
  }
}

void R1on()
{
  digitalWrite(R1, 0);
  if (debug == 1) Serial.print("|Rel1 on");
}
void R2on()
{
  digitalWrite(R2, 0); r2 = 0;
  if (debug == 1) Serial.print("|Rel2 on");
}

void R1off()
{
  digitalWrite(R1, 1);
  if (debug == 1)Serial.print("|Rel1 off");
}
void R2off()
{
  digitalWrite(R2, 1);
  if (debug == 1)Serial.print("|Rel2 off");
}



void rel1a()
{
  if (R1T1 == 1)

  {
    //  if (f==2) goto z1;
    //  if (digitalRead(R1) == 0 && f == 2) goto z1;


    if (t.hour > OnHour1 && t.hour < OffHour1)      a = 1;

    else if (OnHour1 == t.hour && OffHour1 == t.hour)
    {
      a = 2;
      goto x;
    }
    else if (t.hour == OnHour1)
    {
      a = 3;
      goto x;
    }
    else if (t.hour == OffHour1)
    {
      a = 4;
      goto x;
    }
    else if (t.hour < OnHour1 || t.hour > OffHour1) a = 5;

x:

    //----------------------------------------------------------
    if (a == 1)
    {
      R1on(); f = 1;
    }
    //----------------------------------------------------------
    else if (a == 2)
    {
      if (t.min >= OnMin1 && t.min < OffMin1)
      {
        R1on(); f = 1;
      }
      else {
        R1off(); f = 0;
      }
    }
    //----------------------------------------------------------
    else if (a == 3)
    {
      if (t.min >= OnMin1)
      {
        R1on(); f = 1;
      }
      else {
        R1off();
        f = 0;
      }
    }
    //----------------------------------------------------------
    else if (a == 4)
    {
      if (t.min < OffMin1)
      {
        R1on(); f = 1;
      }
      else {
        R1off();
        f = 0;
      }
    }
    //----------------------------------------------------------
    else if (a == 5)
    {
      R1off(); f = 0;
    }
    //----------------------------------------------------------
    else {
      R1off();
      f = 0;
    }
    //z1: delay(1);
  }
}


void rel1b() {

  if (R1T2 == 1) {


    //  if (digitalRead(R1) == 0 && f == 1) goto z2;
    if (t.hour > OnHour2 && t.hour < OffHour2)      b = 1;

    else if (OnHour2 == t.hour && OffHour2 == t.hour)
    {
      b = 2;
      goto y;
    }
    else if (t.hour == OnHour2)
    {
      b = 3;
      goto y;
    }
    else if (t.hour == OffHour2)
    {
      b = 4;
      goto y;
    }
    else if (t.hour < OnHour2 || t.hour > OffHour2 || t.hour < OnHour1 || t.hour > OffHour1) b = 5;

y:
    //  if (b == 1 || b == 2 || b == 3 || b == 4) f = 2;
    //----------------------------------------------------------
    if (b == 1)
    {
      R1on(); f = 2;
    }
    //----------------------------------------------------------
    else if (b == 2)
    {
      if (t.min >= OnMin2 && t.min < OffMin2)
      {
        R1on(); f = 2;
      }
      else {
        R1off();
        f = 0;
      }
    }
    //----------------------------------------------------------
    else if (b == 3)
    {
      if (t.min >= OnMin2)
      {
        R1on(); f = 2;
      }
      else {
        R1off();
        f = 0;
      }
    }
    //----------------------------------------------------------
    else if (b == 4)
    {
      if (t.min < OffMin2)
      {
        R1on(); f = 2;
      }
      else {
        R1off();
        f = 0;
      }
    }
    //----------------------------------------------------------
    else if (b == 5)
    {
      R1off(); f = 0;
    }
    //----------------------------------------------------------
    else {
      R1off();
      f = 0;
    }

    //_____________________________________________________________________________________________________________________________________________
    //z2: delay(1);
  }
}

//**************************************************************************************************************************************
//**************************************************************************************************************************************
//**************************************************************************************************************************************
//**************************************************************************************************************************************
void rel2a()
{

  if (R2T1 == 1)
  {
    //  if (f==2) goto z1;
    //  if (digitalRead(R1) == 0 && f == 2) goto z1;


    if (t.hour > OnHour3 && t.hour < OffHour3)      c = 1;

    else if (OnHour3 == t.hour && OffHour3 == t.hour)
    {
      c = 2;
      goto x5;
    }
    else if (t.hour == OnHour3)
    {
      c = 3;
      goto x5;
    }
    else if (t.hour == OffHour3)
    {
      c = 4;
      goto x5;
    }
    else if (t.hour < OnHour3 || t.hour > OffHour3) c = 5;

x5:

    //  if (c == 1 || c == 2 || c == 3 || c == 4) g = 1;
    //----------------------------------------------------------
    if (c == 1)
    {
      R2on(); g = 1;
    }
    //----------------------------------------------------------
    else if (c == 2)
    {
      if (t.min >= OnMin3 && t.min < OffMin3)
      {
        R2on(); g = 1;
      }
      else {
        R2off(); g = 0;
      }
    }
    //----------------------------------------------------------
    else if (c == 3)
    {
      if (t.min >= OnMin3)
      {
        R2on(); g = 1;
      }
      else {
        R2off();
        g = 0;
      }
    }
    //----------------------------------------------------------
    else if (c == 4)
    {
      if (t.min < OffMin3)
      {
        R2on(); g = 1;
      }
      else {
        R2off();
        g = 0;
      }
    }
    //----------------------------------------------------------
    else if (c == 5)
    {
      R2off(); g = 0;
    }
    //----------------------------------------------------------
    else {
      R2off();
      g = 0;
    }
    //z1: delay(1);
  }
}


void rel2b() {
  if (R1T1 == 1)
  {
    //  if (digitalRead(R1) == 0 && f == 1) goto z2;
    if (t.hour > OnHour4 && t.hour < OffHour4)      d = 1;

    else if (OnHour4 == t.hour && OffHour4 == t.hour)
    {
      d = 2;
      goto y5;
    }
    else if (t.hour == OnHour4)
    {
      d = 3;
      goto y5;
    }
    else if (t.hour == OffHour4)
    {
      d = 4;
      goto y5;
    }
    else if (t.hour < OnHour4 || t.hour > OffHour4 || t.hour < OnHour3 || t.hour > OffHour3) d = 5;

y5:
    //  if (d == 1 || d == 2 || d == 3 || d == 4) g = 2;
    //----------------------------------------------------------
    if (d == 1)
    {
      R2on(); g = 2;
    }
    //----------------------------------------------------------
    else if (d == 2)
    {
      if (t.min >= OnMin4 && t.min < OffMin4)
      {
        R2on(); g = 2;
      }
      else {
        R2off();
        g = 0;
      }
    }
    //----------------------------------------------------------
    else if (d == 3)
    {
      if (t.min >= OnMin4)
      {
        R2on(); g = 2;
      }
      else {
        R2off();
        g = 0;
      }
    }
    //----------------------------------------------------------
    else if (d == 4)
    {
      if (t.min < OffMin4)
      {
        R2on(); g = 2;
      }
      else {
        R2off();
        g = 0;
      }
    }
    //----------------------------------------------------------
    else if (d == 5)
    {
      R2off(); g = 0;
    }
    //----------------------------------------------------------
    else {
      R2off();
      g = 0;
    }

    //_____________________________________________________________________________________________________________________________________________
    //z2: delay(1);

  }
}
//**************************************************************************************************************************************
//**************************************************************************************************************************************
//**************************************************************************************************************************************
//**************************************************************************************************************************************
