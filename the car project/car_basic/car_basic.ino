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

//lights

int ifl = 22;          //indicator front left
int iflr = 23;        //indcator front left red
int iflg = 25;
int iflb = 24;         //indicator front left blue


int head = 26;         //headlamps
int head1 = 46;
int head2 = 47;
int head3 = 49;
int headr = 27;       //headlamp red
int headg = 29;
int headb = 28;


int ifr = 30;          //indicator front right
int ifrr = 31;        //indicator front right red green
int ifrg = 33;
int ifrb = 32;         //indicator front right blue

int ibl = 10;          //indicator back left
int iblr = 43;         //indicator back left red
int iblg = 45;         //indicator back left green
int iblb = 44;         //indicator back left blue


int ibr = 8;          //indicator back right
int ibrr = 35;         //indicator back right red
int ibrg = 37;         //indicator back right green
int ibrb = 36;         //indicator back right blue


int tail = 9;         //taillamps
int tailr = 39;        //taillamp red
int tailg = 41;        //taillamp green blue
int tailb = 40;



void setup() {
  Serial.begin(115200);
  // Serial1.begin(9600);
   pinMode(13, OUTPUT);digitalWrite(13,LOW);
   pinMode(12, OUTPUT);digitalWrite(12,LOW);
   pinMode(A0,OUTPUT);analogWrite(A0,0);
   pinMode(A1,OUTPUT);analogWrite(A1,0);
   

   
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


  pinMode(head, OUTPUT);
  pinMode(head1, OUTPUT);
  pinMode(head2, OUTPUT);
  pinMode(head3, OUTPUT);
  pinMode(headr, OUTPUT);
  pinMode(headg, OUTPUT);
  pinMode(headb, OUTPUT);


  pinMode(ifl, OUTPUT);
  pinMode(iflr, OUTPUT);
  pinMode(iflg, OUTPUT);
  pinMode(iflb, OUTPUT);

  pinMode(ifr, OUTPUT);
  pinMode(ifrr, OUTPUT);
  pinMode(ifrg, OUTPUT);
  pinMode(ifrb, OUTPUT);

  pinMode(ibl, OUTPUT);
  pinMode(iblr, OUTPUT);
  pinMode(iblg, OUTPUT);
  pinMode(iblb, OUTPUT);


  pinMode(ibr, OUTPUT);
  pinMode(ibrr, OUTPUT);
  pinMode(ibrg, OUTPUT);
  pinMode(ibrb, OUTPUT);

  pinMode(tail, OUTPUT);
  pinMode(tailr, OUTPUT);
  pinMode(tailg, OUTPUT);
  pinMode(tailb, OUTPUT);




soundoff();
}


/************************************************


                   LOOP

 
************************************************/

void loop(){
  
beep();inc();beep();
 
 soundoff(); shutdown1();
}

/************************************************


                   SOUND


************************************************/

void inc()
{int i=0;
for(int i=0;i<=255;i++){
  analogWrite(A0,i);delay(20);}
  for(int j=255;j>=0;j--){
analogWrite(A0,j);delay(20);}}
void sound()
{
  for (int n = 5; n > 0; n--)
  { analogWrite(buz, 255);
    delay(100);
    analogWrite(buz, 0);
    delay(100);
  }
}

void soundoff()
{
  digitalWrite(buz,LOW);
}

void alarm()
{
  digitalWrite(laser1, HIGH);
  analogWrite(buz, 150);
  delay(150);
  digitalWrite(laser1, LOW);
  analogWrite(buz, 0);
  delay(150);
  digitalWrite(laser2, HIGH);
  analogWrite(buz, 150);
  delay(150);
  digitalWrite(laser2, LOW);
  analogWrite(buz, 0);
  delay(150);

}

void siren()
{
  for (int lvl = 10; lvl <= 255; lvl++)
  {
    analogWrite(buz, lvl); delay(5);
  }
  delay(500);
  for (int lvl = 255; lvl >= 10; lvl--)
  { analogWrite(buz, lvl); delay(5);
  }
  delay(500);
  // digitalWrite(buz,HIGH);delay(750);
  analogWrite(buz, 0);

}
void beep()
{
  analogWrite(buz, 255 );
  delay(400);
  soundoff();
}
void siren1(int x)
{
  int n = x * 3;
  for (int i = 0; i < n; i++)
  {
    analogWrite(buz, 150);
    delay(500);
    soundoff();
    analogWrite(buz, 230);
    delay(500);
    soundoff();
  }
}


/************************************************


                   LIGHT


************************************************/

void lightaltbl()
{
  digitalWrite(laser1, HIGH);
  delay (500);
  digitalWrite(laser1, LOW);
  digitalWrite(laser2, HIGH);
  delay(500);
  digitalWrite(laser2, LOW);
}
void light()
{
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
}

void lightoff()
{
  digitalWrite(laser1, LOW);
  digitalWrite(laser2, LOW);
}


void lightbl()
{
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  delay (500);
  digitalWrite(laser1, LOW);
  digitalWrite(laser2, LOW);
}

void hfblink(int f, int t)
{
  int i = 1000 / f;    //interval = 1000/freq
  int n = (t * 1000) / i; //number=time/interval
  for (int v = 1; v <= n; v++)
  {
    digitalWrite(laser1, HIGH);    digitalWrite(buz, HIGH);
    delay(i / 2);
    digitalWrite(laser1, LOW); digitalWrite(buz, LOW);
    delay(i / 2);
  }
}

void hfblink1(int f, int t)
{
  int i = 1000 / f;  //interval = 1000/freq
  int n = t;            //number=time/interval
  for (int v = 1; v <= n; v++)
  {
    digitalWrite(laser1, HIGH);    digitalWrite(buz, HIGH);
    delay(i / 2);
    digitalWrite(laser1, LOW); digitalWrite(buz, LOW);
    delay(1000 - (i / 2));
  }
}


void hfblink2(int f, int t)
{
  int i = 1000 / f; //interval = 1000/freq
  int x;

  for (int n = 0; n <= t; n++)
  {
    x = x + n;
  }
  int n = x;            //number=time/interval
  for (int v = 1; v <= n; v++)
  {
    digitalWrite(laser1, HIGH);    digitalWrite(buz, HIGH);
    delay(i / 2);
    digitalWrite(laser1, LOW); digitalWrite(buz, LOW);
    delay(1000 - (i / 2));
  }
}

void check()
{
  float dis = meas();
  if (dist > 50) {
    ring(0.2);
  }
  if (dis < 50 && dis > 40)  {
    ring(0.5);
  }
  if (dis < 39 && dis > 30) {
    ring(0.8);
  }
  if (dis < 29 && dis > 20) {
    ring(1);
  }
  if (dis < 20 && dis > 15) {
    ring(2);
  }
  if (dis < 14 && dis > 10) {
    ring(5);
  }
  if (dis < 9 && dis > 5) {
    ring(10);
  }
}

void ring (float f)
{
  float i = 1000 / f;
  int n = 5;
  for (int a = 0; a <= n; a++)
  {
    blip();
    delay(i);
    if (f < 2)
    {
      accel();
    }
    else if (f > 4)
    {
      decel();
    }
  }
}
void blip()
{
  digitalWrite(laser1, HIGH);    digitalWrite(buz, HIGH);
  delay(100);
  digitalWrite(laser1, LOW); digitalWrite(buz, LOW);
}



void cdown( int t)
{
  int i = (t * 1000) / 10; //gap = t*1000/10
  int x;
  for (int n = 0; n <= t; n++)
  {
    x = x + n;
  }
  //long double n=(t*1000)/i;
  //int f=i/2;
  for (int v = 1; v <= x; v++)
  {
    int d = (i / v) / 2;
    digitalWrite(laser1, HIGH); digitalWrite(buz, HIGH);
    delay(d);
    digitalWrite(laser1, LOW); digitalWrite(buz, LOW);
    delay(d);
  }
}


/************************************************


                   MOTOR


************************************************/
int vel=20;
void accel() {
 digitalWrite(forw,HIGH);
}
void decel() { 
  analogWrite(back, vel);
}
void kill(){
 digitalWrite(forw,LOW); 
  digitalWrite(back, LOW); 
}




void movf()
{ int n = curvel();
  for (int x = n; x <= 255; x++)
  { analogWrite(forw, x);
  }

}

void movb()
{ int n = curvel();
  for (int x = n; x <= 255; x++)
  { analogWrite(back, x);
  }

}
int startmov()
{
  int i = 0;
  int a;
  if (i >= 0 && i <= 5)
  {
    for ( i = 0; i <= 255; i++)
    {
      analogWrite(forw, i);
      a = i;
    }
  }
  return a;
}
int curvel()
{
  int vel = startmov();

  return vel;
}






void turnr()
{ int x = turnvel();
  analogWrite(right, x);
}
void turnl()
{ int x = turnvel();
  analogWrite(left, x);
}

int turnvel()
{
  float av = meas();
  int l;
  if (av < 10 && av > 0)
  {
    l = turnfast();
  }
  if (av < 20 && av > 10)
  {
    l = turnslow();
  }
  return l;
}

int turnfast() {
  int q = 255;
  return q;
}

int turnslow()
{
  int q = 100;
  return q;
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
  /*  int count=0;
    Serial.print("av is   -- ");Serial.println(av);
    Serial.print("count is   -- ");Serial.println(count);
    Serial.println();
    Serial.println();

    delay(10000);
  */
  for (int k = 0; k <= 3; k++)
  {
    dist = nut();//  Serial.println(dist);
    if (k == 2)
    {
      av = dist;
    }
  }Serial.println(av);
  return av; 
}


// Serial.print("the 3rd value is ");  Serial.println(av);
/*   Serial.print("distance is ");Serial.println(dist);
   Serial.print("count is "); Serial.println(count);

   if (k==0)
   {
     Serial.print("first iteration  count must be 0");
      Serial.println();
     Serial.print("if executed once...count is -->> ");   Serial.println(count);

     //av=av+dist;
     count=count+1;
     Serial.print("if executed once...count is -->> ");   Serial.println(count);

   Serial.println();
   Serial.println();

   }

   Serial.print("distance is ");Serial.println(dist);
   Serial.print("count is "); Serial.println(count);

   if (k==1)
   {   Serial.print("second iteration  count must be 1");
       Serial.println();
       Serial.print("if executed once...count is -->> ");   Serial.println(count);

     av=av+dist;
     count=count+1;
     Serial.print("if executed once...count is -->> ");   Serial.println(count);

   Serial.println();
   Serial.println();

   }


   if(k>0&&dist<av+5&&dist>av-5)
   {
     count++ ;  Serial.print("else if executed..count is  -->> ");Serial.println(count);
     av=av+dist;  Serial.print("av is   -->> ");              Serial.println(av);
   Serial.println();
   Serial.println();
   Serial.println();
   }

  av=av/count;





  Serial.print("final count is ");  Serial.println(count);                                         //Serial.print(count );
  Serial.print("final average is "); Serial.print(av);                                           //Serial.print(av);
  Serial.println("  ");
  Serial.println("  ");
  //delay(1000);*/

/************************************************


                   servo


************************************************/
void scan()
{
  one.write(0);
  for (int i=0;i<=90;i+5)
  {   one.write(i);delay(100);
  }
one.write(0);beep();
}

 void scan1()
{
  one.write(20);meas();light();beep();lightoff();
  delay(1000);
   one.write(90);meas();light();beep();lightoff();
  delay(1000);
   one.write(180);meas();light();beep();lightoff();
  delay(1000);
  one.write(90);meas();light();beep();lightoff();
  delay(1000);
}

/************************************************


                   LIGHTING 


************************************************/

void test()
{
  headonly_on();
  delay(800);
  headon();

  tailonly_on();

  tailon_f();
  delay(1100);
  headon();
  delay(1100);

  for (int i = 0; i < 5; i++)
  {
    left_on();
    delay(600);
    left_off();
    delay(500);
  }

  headon();
  delay(1100);

  for (int j = 0; j < 5; j++)
  {
    right_on();
    delay(600);
    right_off();
    delay(500);
  }

  headon();
  delay(1100);
  brake();
  delay(1100);
  rev();
  delay(1100);

  for (int l = 0; l < 5; l++)
  {
    rev_left_on();
    delay(600);
    rev_left_off();
    delay(500);
  }

  rev();
  delay(1100);

  for (int k = 0; k < 5; k++)
  {
    rev_right_on();
    delay(600);
    rev_right_off();
    delay(500);
  }
  rev();
  delay(1100);
  brake();
lights_out();
  delay(5000);


}
void testrev()
{
  headon();tailon_f();delay(1000);headoff();tailoff();delay(1000);
  for (int a = 0; a < 5; a++)
  {
    xleft_on();
    delay(600);
    xleft_off();
    delay(500);
  }

  headoff();
  delay(1100);

  for (int b = 0; b < 5; b++)
  {
    xright_on();
    delay(600);
    xright_off();
    delay(500);
  }

  headoff();
  delay(1100);
  brake();
  delay(1100);
  xrev();
  delay(1100);

  for (int c = 0; c < 5; c++)
  {
    xrev_left_on();
    delay(600);
    xrev_left_off();
    delay(500);
  }

  xrev();
  delay(1100);

  for (int d = 0; d < 5; d++)
  {
   xrev_right_on();
    delay(600);
    xrev_right_off();
    delay(500);
  }
  xrev();
  delay(1100);
  brake();
  
  lights_out();
}

void testall()
{
  //front left indicator
  digitalWrite(ifl, HIGH);
  digitalWrite(iflr, LOW); 
  digitalWrite(iflg, LOW); 
  digitalWrite(iflb, LOW);
  delay(150); 
  digitalWrite(iflr, HIGH); 
  digitalWrite(iflg, HIGH); 
  digitalWrite(iflb, HIGH); 
  delay(150);
  
  digitalWrite(iflr, LOW); delay(150);
  digitalWrite(iflr, HIGH); delay(150);
  digitalWrite(iflg, LOW);delay(150);
  digitalWrite(iflg, HIGH);delay(150);
  digitalWrite(iflb, LOW); delay(150);
  digitalWrite(iflb, HIGH); delay(150);
  digitalWrite(ifl, LOW); delay(150);

//front right indicator
 digitalWrite(ifr, HIGH);
  digitalWrite(ifrr, LOW); 
  digitalWrite(ifrg, LOW); 
  digitalWrite(ifrb, LOW);
  delay(150); 
  digitalWrite(ifrr, HIGH); 
  digitalWrite(ifrg, HIGH); 
  digitalWrite(ifrb, HIGH); 
  delay(150);
  
  digitalWrite(ifrr, LOW); delay(150);
  digitalWrite(ifrr, HIGH); delay(150);
  digitalWrite(ifrg, LOW);delay(150);
  digitalWrite(ifrg, HIGH);delay(150);
  digitalWrite(ifrb, LOW); delay(150);
  digitalWrite(ifrb, HIGH); delay(150);
  digitalWrite(ifr, LOW); delay(150);

//headlamps
 digitalWrite(head, HIGH);
 digitalWrite(head1, HIGH);
  digitalWrite(head2, HIGH);
   digitalWrite(head3, HIGH);
   digitalWrite(headr, LOW); 
  digitalWrite(headg, LOW); 
  digitalWrite(headb, LOW);
  delay(150); 
  digitalWrite(headr, HIGH); 
  digitalWrite(headg, HIGH); 
  digitalWrite(headb, HIGH); 
  delay(150);
  
  digitalWrite(headr, LOW); delay(150);
  digitalWrite(headr, HIGH); delay(150);
  digitalWrite(headg, LOW);delay(150);
  digitalWrite(headg, HIGH);delay(150);
  digitalWrite(headb, LOW); delay(150);
  digitalWrite(headb, HIGH); delay(150);
  digitalWrite(head, LOW); delay(150);

//back right indicator
 digitalWrite(ibr, HIGH);
  digitalWrite(ibrr, LOW); 
  digitalWrite(ibrg, LOW); 
  digitalWrite(ibrb, LOW);
  delay(150); 
  digitalWrite(ibrr, HIGH); 
  digitalWrite(ibrg, HIGH); 
  digitalWrite(ibrb, HIGH); 
  delay(150);
  
  digitalWrite(ibrr, LOW); delay(150);
  digitalWrite(ibrr, HIGH); delay(150);
  digitalWrite(ibrg, LOW);delay(150);
  digitalWrite(ibrg, HIGH);delay(150);
  digitalWrite(ibrb, LOW); delay(150);
  digitalWrite(ibrb, HIGH); delay(150);
  digitalWrite(ibr, LOW); delay(150);

//back left indicator
 digitalWrite(ibl, HIGH);
  digitalWrite(iblr, LOW); 
  digitalWrite(iblg, LOW); 
  digitalWrite(iblb, LOW);
  delay(150); 
  digitalWrite(iblr, HIGH); 
  digitalWrite(iblg, HIGH); 
  digitalWrite(iblb, HIGH); 
  delay(150);
  
  digitalWrite(iblr, LOW); delay(150);
  digitalWrite(iblr, HIGH); delay(150);
  digitalWrite(iblg, LOW);delay(150);
  digitalWrite(iblg, HIGH);delay(150);
  digitalWrite(iblb, LOW); delay(150);
  digitalWrite(iblb, HIGH); delay(150);
  digitalWrite(ibl, LOW); delay(150);

//tail 
 digitalWrite(tail, HIGH);
  digitalWrite(tailr, LOW); 
  digitalWrite(tailg, LOW); 
  digitalWrite(tailb, LOW);
  delay(150); 
  digitalWrite(tailr, HIGH); 
  digitalWrite(tailg, HIGH); 
  digitalWrite(tailb, HIGH); 
  delay(150);
  
  digitalWrite(tailr, LOW); delay(150);
  digitalWrite(tailr, HIGH); delay(150);
  digitalWrite(tailg, LOW);delay(150);
  digitalWrite(tailg, HIGH);delay(150);
  digitalWrite(tailb, LOW); delay(150);
  digitalWrite(tailb, HIGH); delay(150);
  digitalWrite(tail, LOW); delay(150);

}


void testall1()
{
  //front left indicator
  digitalWrite(ifl, HIGH);
  digitalWrite(iflr, LOW); 
  digitalWrite(iflg, LOW); 
  digitalWrite(iflb, LOW);
 beep(); delay(150); soundoff();
  digitalWrite(iflr, HIGH); 
  digitalWrite(iflg, HIGH); 
  digitalWrite(iflb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(iflr, LOW); beep(); delay(150); soundoff();
  digitalWrite(iflr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(iflg, LOW);beep(); delay(150); soundoff();
  digitalWrite(iflg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(iflb, LOW); beep(); delay(150); soundoff();
  digitalWrite(iflb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ifl, LOW); beep(); delay(150); soundoff();

//front right indicator
 digitalWrite(ifr, HIGH);
  digitalWrite(ifrr, LOW); 
  digitalWrite(ifrg, LOW); 
  digitalWrite(ifrb, LOW);
  beep(); delay(150); soundoff(); 
  digitalWrite(ifrr, HIGH); 
  digitalWrite(ifrg, HIGH); 
  digitalWrite(ifrb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(ifrr, LOW); beep(); delay(150); soundoff();
  digitalWrite(ifrr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ifrg, LOW);beep(); delay(150); soundoff();
  digitalWrite(ifrg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(ifrb, LOW); beep(); delay(150); soundoff();
  digitalWrite(ifrb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ifr, LOW); beep(); delay(150); soundoff();

//headlamps
 digitalWrite(head, HIGH);
 digitalWrite(head1, HIGH);
  digitalWrite(head2, HIGH);
   digitalWrite(head3, HIGH);
   digitalWrite(headr, LOW); 
  digitalWrite(headg, LOW); 
  digitalWrite(headb, LOW);
  beep(); delay(150); soundoff(); 
  digitalWrite(headr, HIGH); 
  digitalWrite(headg, HIGH); 
  digitalWrite(headb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(headr, LOW); beep(); delay(150); soundoff();
  digitalWrite(headr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(headg, LOW);beep(); delay(150); soundoff();
  digitalWrite(headg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(headb, LOW); beep(); delay(150); soundoff();
  digitalWrite(headb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(head, LOW); beep(); delay(150); soundoff();

//back right indicator
 digitalWrite(ibr, HIGH);
  digitalWrite(ibrr, LOW); 
  digitalWrite(ibrg, LOW); 
  digitalWrite(ibrb, LOW);
  beep(); delay(150); soundoff();
  digitalWrite(ibrr, HIGH); 
  digitalWrite(ibrg, HIGH); 
  digitalWrite(ibrb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(ibrr, LOW); beep(); delay(150); soundoff();
  digitalWrite(ibrr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ibrg, LOW);beep(); delay(150); soundoff();
  digitalWrite(ibrg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(ibrb, LOW); beep(); delay(150); soundoff();
  digitalWrite(ibrb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ibr, LOW); beep(); delay(150); soundoff();

//back left indicator
 digitalWrite(ibl, HIGH);
  digitalWrite(iblr, LOW); 
  digitalWrite(iblg, LOW); 
  digitalWrite(iblb, LOW);
  beep(); delay(150); soundoff(); 
  digitalWrite(iblr, HIGH); 
  digitalWrite(iblg, HIGH); 
  digitalWrite(iblb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(iblr, LOW); beep(); delay(150); soundoff();
  digitalWrite(iblr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(iblg, LOW);beep(); delay(150); soundoff();
  digitalWrite(iblg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(iblb, LOW); beep(); delay(150); soundoff();
  digitalWrite(iblb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(ibl, LOW); beep(); delay(150); soundoff();

//tail 
 digitalWrite(tail, HIGH);
  digitalWrite(tailr, LOW); 
  digitalWrite(tailg, LOW); 
  digitalWrite(tailb, LOW);
  beep(); delay(150); soundoff(); 
  digitalWrite(tailr, HIGH); 
  digitalWrite(tailg, HIGH); 
  digitalWrite(tailb, HIGH); 
  beep(); delay(150); soundoff();
  
  digitalWrite(tailr, LOW); beep(); delay(150); soundoff();
  digitalWrite(tailr, HIGH); beep(); delay(150); soundoff();
  digitalWrite(tailg, LOW);beep(); delay(150); soundoff();
  digitalWrite(tailg, HIGH);beep(); delay(150); soundoff();
  digitalWrite(tailb, LOW); beep(); delay(150); soundoff();
  digitalWrite(tailb, HIGH); beep(); delay(150); soundoff();
  digitalWrite(tail, LOW); beep(); delay(150); soundoff();

}


void lights_out()
{
  headoff();
  tailoff();
}

void headon()
{
  digitalWrite(head, HIGH); //          headlight on
  digitalWrite(head1, HIGH); //          headlight on
  digitalWrite(head2, HIGH); //          headlight on
  digitalWrite(head3, HIGH); //          headlight on
  digitalWrite(headr, LOW); //
  digitalWrite(headg, LOW); //
  digitalWrite(headb, LOW); //


  digitalWrite(ifl, HIGH); //
  digitalWrite(iflr, LOW); //                left white on
  digitalWrite(iflb, LOW); //
  digitalWrite(iflg, LOW); //                left white on



  digitalWrite(ifr, HIGH); //
  digitalWrite(ifrr, LOW); //                 right white on
  digitalWrite(ifrb, LOW); //
  digitalWrite(ifrg, LOW); //

}


void headoff()
{
  digitalWrite(head, LOW); //
  digitalWrite(head1, LOW); //
  digitalWrite(head2, LOW); //
  digitalWrite(head3, LOW); //
  digitalWrite(headr, HIGH); //            headlight off
  digitalWrite(headg, HIGH); //            headlight off
  digitalWrite(headb, HIGH); //            headlight off


  digitalWrite(ifl, LOW); //
  digitalWrite(iflr, HIGH); //             left indi off
  digitalWrite(iflb, HIGH); //
  digitalWrite(iflg, HIGH); //             left indi off

  digitalWrite(ifr, LOW); //
  digitalWrite(ifrr, HIGH); //                 right indi off
  digitalWrite(ifrb, HIGH); //
  digitalWrite(ifrg, HIGH); //

}


void headonly_on()
{
  digitalWrite(head, HIGH); //                headlight on
  digitalWrite(head1, HIGH); //                headlight on
  digitalWrite(head2, HIGH); //                headlight on
  digitalWrite(head3, HIGH); //                headlight on
  digitalWrite(headr, LOW); //
  digitalWrite(headb, LOW); //
  digitalWrite(headg, LOW); //

}

void headonly_off()
{
  digitalWrite(head, LOW); //
  digitalWrite(head1, LOW); //
  digitalWrite(head2, LOW); //
  digitalWrite(head3, LOW); //
  digitalWrite(headr, HIGH); //                headlight off
  digitalWrite(headg, HIGH); //                headlight off
  digitalWrite(headb, HIGH); //                headlight off

}



void tailon_h() {

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //       red on                    tail red on
  digitalWrite(tailg, HIGH);            //       blue green off
  digitalWrite(tailb, HIGH);            //       blue green off


  analogWrite(ibl, 80);               //  left back half
  digitalWrite(iblr, LOW);            //   red on                           red on
  digitalWrite(iblg, HIGH);            //   green off
  digitalWrite(iblb, HIGH);            //   blue off

  analogWrite(ibr, 80);                //  left right half
  digitalWrite(ibrr, LOW);            //   red on                          red on
  digitalWrite(ibrg, HIGH);            //   green off
  digitalWrite(ibrb, HIGH);            //   blue off

}



void tailon_f() {

  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                  red on
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}

void tailonly_on()
{
  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

}
void tailonly_off() {

  digitalWrite(tail, LOW);       //   vcc active
  digitalWrite(tailr, HIGH);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


}

void tailoff() {

  digitalWrite(tail, LOW);       //   vcc active
  digitalWrite(tailr, HIGH);       //    red off                           tail red off
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, LOW);     //  vcc active                       left back
  digitalWrite(iblr, HIGH);     //left indi  red off               red off
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, LOW);          //         vcc active              right back
  digitalWrite(ibrr, HIGH);         //right indi red off                  red off
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}


void brake() {

  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                  red on
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}



void left_on() {
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off

  digitalWrite(ifr, HIGH); //     front right      vcc active
  digitalWrite(ifrr, LOW); //                      yellow on                white on
  digitalWrite(ifrg, LOW); //                      yellow on                white on
  digitalWrite(ifrb, LOW); //                       blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off


  analogWrite(ibr, 80); //    back right        vcc active
  digitalWrite(ibrr, LOW); //                      red on                red on
  digitalWrite(ibrb, HIGH); //                     blue off
  digitalWrite(ibrg, HIGH); //                     green off

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}

void left_off() {
  headon();
  tailon_h();
 
}

void right_on() {
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ifl, HIGH); //       front left     vcc active
  digitalWrite(iflr, LOW); //                     yellow on                 white on
  digitalWrite(iflg, LOW); //                     yellow on                 white on
  digitalWrite(iflb, LOW); //                       blue on

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  analogWrite(ibl, 80); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                red on
  digitalWrite(iblb, HIGH); //                   blue off
  digitalWrite(iblg, HIGH); //                   green off

}

void right_off() {

  headon();
  tailon_h();
}




void rev()
{
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    white on
  digitalWrite(iblb, LOW);     //left indi blue on
  digitalWrite(iblg, LOW);     //left indi green on


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}


void rev_left_on()
{
  headon();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off

  digitalWrite(ifr, HIGH); //     front right      vcc active
  digitalWrite(ifrr, LOW); //                      yellow on                white on
  digitalWrite(ifrg, LOW); //                      yellow on                white on
  digitalWrite(ifrb, LOW); //                       blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off


  digitalWrite(ibr, HIGH); //    back right        vcc active
  digitalWrite(ibrr, LOW); //                      red on                white on
  digitalWrite(ibrb, LOW); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}


void rev_left_off() {

  headon();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);               //    red on                     tailon
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

  digitalWrite(ifr, HIGH); //                   vcc active
  digitalWrite(ifrr, LOW); //                 yellow on                    white on
  digitalWrite(ifrg, LOW); //                 yellow on                    white on
  digitalWrite(ifrb, LOW); //                   blue on

  digitalWrite(ifl, HIGH); //                 vcc active
  digitalWrite(iflr, LOW); //                yellow on                      white on
  digitalWrite(iflg, LOW); //                yellow on                      white on
  digitalWrite(iflb, LOW); //                   blue on

  digitalWrite(ibr, HIGH); //                     vcc active
  digitalWrite(ibrr, LOW); //                 red on                      white on
  digitalWrite(ibrb, LOW); //                   blue on
  digitalWrite(ibrg, LOW); //                   green on

  digitalWrite(ibl, HIGH); //                     vcc active
  digitalWrite(iblr, LOW); //                 red on                        white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}



void rev_right_on()
{
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ifl, HIGH); //       front left     vcc active
  digitalWrite(iflr, LOW); //                     yellow on                 white on
  digitalWrite(iflg, LOW); //                     yellow on                 white on
  digitalWrite(iflb, LOW); //                       blue on

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}

void rev_right_off() {
  headon();
  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW); //                  red on                     tailon
  digitalWrite(tailg, HIGH); //                 blue green off
  digitalWrite(tailb, HIGH); //                 blue green off


  digitalWrite(ifr, HIGH); //     front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                    white on
  digitalWrite(ifrg, LOW); //                    yellow on                    white on
  digitalWrite(ifrb, LOW); //                      blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                     yellow on                   white on
  digitalWrite(iflg, LOW); //                     yellow on                   white on
  digitalWrite(iflb, LOW); //                    blue on

  digitalWrite(ibr, HIGH); //   back right        vcc active
  digitalWrite(ibrr, LOW); //                     red on                      white on
  digitalWrite(ibrb, LOW); //                      blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //   back left         vcc active
  digitalWrite(iblr, LOW); //                      red on                      white on
  digitalWrite(iblb, LOW); //                      blue on
  digitalWrite(iblg, LOW); //                     green on

}
// ****************************************************************************************

void xleft_on() {
  headoff();

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}

void xleft_off() {
  headoff();
  tailoff();
 
}

void xright_on() {
  headoff();

  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

}

void xright_off() {

  headoff();
  tailoff();
}

void xrev()
{
  headoff();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    white on
  digitalWrite(iblb, LOW);     //left indi blue on
  digitalWrite(iblg, LOW);     //left indi green on


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}


void xrev_left_on()
{
  headoff();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off


  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off



  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}


void xrev_left_off() {

  headoff();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);               //    red on                     tailon
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}



void xrev_right_on()
{
  headoff();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off


  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}

void xrev_right_off() {
  headoff();
  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW); //                  red on                     tailon
  digitalWrite(tailg, HIGH); //                 blue green off
  digitalWrite(tailb, HIGH); //                 blue green off

 digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}
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


void printcheck()
{ int x = 4;
  Serial.println("1 the value of x is -- >> "); Serial.println(x); Serial.println();
  Serial.println("2");
  Serial.println("3");
  Serial.println();
  delay(5000);

}


