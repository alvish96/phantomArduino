#include<IRremote.h>
#define irpin 6
//#define G A7
//#define ldr A0
#define s1 2
#define s2 3
#define s3 4
#define s4 5

bool f1, f2, f3, f4;


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
//---------------------------------------------------------------------------------------------------

void SW1()
{
  f1 = !f1;
  digitalWrite(s1, f1);
  Serial.println("MAIN LIGHT");
  //  lcd.setCursor(0, 1);
  if (f1 == 1)Serial.println("light on");
  if (f1 == 0)Serial.println("light off");
}

void SW2()
{
  f2 = !f2;
  digitalWrite(s2, f2);
  Serial.println("LED LIGHT");
  //  lcd.setCursor(0, 1);
  if (f2 == 1)Serial.println("light on");
  if (f2 == 0)Serial.println("light off");
}

void SW3()
{
  f3 = !f3;
  digitalWrite(s3, f3);
  Serial.println("FAN");
  //  lcd.setCursor(0, 1);
  if (f3 == 1)Serial.println("fan on");
  if (f3 == 0)Serial.println("fan off");
}

void SW4()
{
  f4 = !f4;
  digitalWrite(s4, f4);
  Serial.println("SWITCH");
  //  lcd.setCursor(0, 1);
  if (f4 == 1)Serial.println("switch on");
  if (f4 == 0)Serial.println("switch off");
}

void SW5(int i)
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

void SW6(int i)
{
  bool f = 0;
  unsigned long startMillis = millis();
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
void l()
{

}

//---------------------------------------------------------------------------------------------------
