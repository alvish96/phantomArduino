#include<IRremote.h>
#include <LiquidCrystal.h>
#include <DS3231.h>


#define lcdlyt 32
#define lcdcon 33
#define ldr 8
#define buz A1
#define irpin 2
#define lyt 12

bool l = 0, m = 1;
int i = 0;
unsigned long CODE_POWER_ON = 0x61D650AF;
unsigned long CODE_FF = 0x61D648B7;
unsigned long CODE_RW = 0x61D610EF;
unsigned long CODE_NEXT = 0x61D6F20D;
unsigned long CODE_BACK = 0x61D630CF;
unsigned long CODE_VERT = 0x61D69867;
unsigned long CODE_HORI = 0x61D6A25D;
unsigned long CODE_LISTEN = 0x61D67887;


unsigned long CODE_SELECT = 0x61D628D7;
unsigned long CODE_RIGHT = 0x61D69A65;
unsigned long CODE_LEFT = 0x61D6A857;
unsigned long CODE_UP = 0x61D6AA55;
unsigned long CODE_DOWN = 0x61D618E7;
unsigned long CODE_MENU = 0x61D632CD;
unsigned long CODE_EXIT = 0x61D6728D;
unsigned long CODE_SOURCE = 0x61D6D02F;
unsigned long CODE_ZOOM = 0x61D6F00F;
unsigned long CODE_VOLUP = 0x61D6708F;
unsigned long CODE_VOLDW = 0x61D612ED;
unsigned long CODE_PIC = 0x61D6629D;
unsigned long CODE_SOUND = 0x61D6EA15;
unsigned long CODE_FREEZE = 0x61D6DA25;
unsigned long CODE_PLAY = 0x61D6906F;
unsigned long CODE_MUTE = 0x61D652AD;

void(* resetFunc) (void) = 0; //declare reset function @ address 0



int ldrval;
IRrecv ir(irpin);
decode_results irresult;

const int rs = 22, en = 23, d4 = 28, d5 = 29, d6 = 30, d7 = 31;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DS3231  rtc(SDA, SCL);
Time  t;



void setup() {

  Serial.begin(9600);
  rtc.begin();
  lcd.begin(16, 2);

  lcd.print("*reset complete*"); longbuzz();
  delay(1000); lcd.clear();

  pinMode(lcdcon, OUTPUT);
  pinMode(lcdlyt, OUTPUT);

  pinMode(buz, OUTPUT);
  digitalWrite(lcdcon, 0);
  digitalWrite(lcdlyt, 1);
  analogWrite(buz, 0);

  ir.enableIRIn();  // Start the receiver
  i = 0;
  t = rtc.getTime();
}

void loop() {

  brightness();
 // irtest();

}


void test() {
  // set the cursor to (0,0):
  lcd.setCursor(0, 0);
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }

  // set the cursor to (16,1):
  lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen for the next loop:
  lcd.clear();

}

void brightness() {
  ldrval = analogRead(ldr);
  Serial.println(ldrval);
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print(ldrval);
  delay(1000);
}



void irtest()
{ tim();
  if (ir.decode(&irresult))
  { buzz();
    switch (irresult.value)
    {
      case 0x61D628D7:
        Serial.println("select"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("OK");
        lcdtimeout();
        break;

      case 0x61D69A65:
        Serial.println("CODE_RIGHT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RIGHT");
        lcdtimeout();

        break;

      case 0x61D6A857:
        Serial.println("CODE_LEFT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_LEFT");
        lcdtimeout();
        break;


      case 0x61D6AA55:
        Serial.println("CODE_UP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_UP");
        lcdtimeout();
        break;


      case 0x61D618E7:
        Serial.println("CODE_DOWN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_DOWN");
        lcdtimeout();
        break;


      case 0x61D632CD:
        Serial.println("CODE_MENU"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MENU");
        lcdtimeout();
        break;


      case 0x61D6728D:
        Serial.println("CODE_EXIT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_EXIT");
        lcdtimeout();
        break;


      case 0x61D6D02F:
        Serial.println("CODE_SOURCE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOURCE");
        lcdtimeout();
        break;


      case 0x61D6F00F:
        Serial.println("CODE_ZOOM"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_ZOOM");
        lcdtimeout();
        break;


      case 0x61D6708F:
        Serial.println("CODE_VOLUP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLUP");
        lcdtimeout();
        break;


      case 0x61D612ED:
        Serial.println("CODE_VOLDW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLDW");
        lcdtimeout();
        break;


      case 0x61D6629D:
        Serial.println("CODE_PIC"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PIC");
        lcdtimeout();
        break;


      case 0x61D6EA15:
        Serial.println("CODE_SOUND"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOUND");
        lcdtimeout();
        break;


      case 0x61D6DA25:
        Serial.println("CODE_FREEZE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_FREEZE");
        lcdtimeout();
        break;


      case 0x61D6906F:
        Serial.println("CODE_PLAY"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PLAY");

        lcdlightSW();
        lcdtimeout();
        break;


      case 0x61D652AD:
        Serial.println("CODE_MUTE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MUTE");
        // mute();

        lcdtimeout();
        break;


      case 0x61D648B7:
        Serial.println("CODE_FF"); lcd.clear(); lcd.setCursor(0, 0);   lcd.print("CODE_FF");
        lcdtimeout();
        break;


      case 0x61D610EF:
        Serial.println("CODE_RW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RW");
        lcdtimeout();
        break;

      case 0x61D6F20D:
        Serial.println("CODE_NEXT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_NEXT");
        lcdtimeout();
        break;

      case 0x61D630CF:
        Serial.println("CODE_BACK"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_BACK");
        lcdtimeout();
        break;

      case 0x61D69867:
        Serial.println("CODE_VERT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VERT");
        lcdtimeout();
        break;

      case 0x61D6A25D:
        Serial.println("CODE_HORI"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_HORI");
        lcdtimeout();
        break;

      case 0x61D650AF:
        lcd.clear(); lcd.setCursor(0, 0);
        Serial.println("CODE_POWER");
        lcd.clear(); lcd.setCursor(0, 0);
        lcd.print("CODE_POWER");
        lcd.setCursor(0, 1);
        lcd.print("CONFIRM ?");
        
        while(ir.decode(&irresult)) 
        {
        if( irresult.value == 0x61D628D7)
        { lcd.clear(); lcd.setCursor(0, 0);
          lcd.print("CONFIRMED!"); delay(500); buzz(); del(); longbuzz();
          lcd.setCursor(0, 0);    lcd.print("PRESS RESET ");
          lcd.setCursor(0, 1);    lcd.print("TO START AGAIN "); del();
          term();
        }else{
         lcd.clear(); lcd.setCursor(0, 0);
        lcd.print("ABORT!");
        return;
        }
        }
        lcdtimeout();
        break;

      case 0x61D67887:
        Serial.println("CODE_LISTEN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RESET");
        lcd.setCursor(0, 1);
        lcd.print("reset initiated");
        delay(1000);
        lcd.clear();



        Serial.println("Resetting in 1 second"); buzz(5); del();

        resetFunc();  //call reset
        lcdtimeout();
        break;



        /* delay(1000);
          lcd.clear();



          Serial.println("Resetting in 1 second"); buzz(5); del();
          void(* resetFunc) (void) = 0; //declare reset function @ address 0
          resetFunc();  //call reset
        */


        //  default:
        //   Serial.println("nothing");//      Serial.println("delay"); delay(1000);
        //       continue;

    }

    ir.resume(); //delay(10);

  }
}

//---------------------------------------------------------------------------------------------------
void lcdtimeout() {
  delay(1000);
  lcd.clear();
}
//---------------------------------------------------------------------------------------------------
void tim() {
  i++;
  int n = 7;
  if (i < n * 10) {

    lcd.clear();

    lcd.setCursor(8, 0);
    lcd.print(rtc.getTimeStr());

    lcd.setCursor(6, 1);
    lcd.print(rtc.getDateStr());
    delay(100);
  }

  if (i >= n * 10)
  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(rtc.getTemp()); lcd.print("'C");
    lcd.setCursor(8, 0);
    lcd.print(rtc.getTimeStr());

    lcd.setCursor(0, 1);
    lcd.print(rtc.getMonthStr());
    lcd.print("_");
    lcd.print(t.date, DEC);

    lcd.print("th ");
    lcd.print(rtc.getDOWStr());

    delay(100);

    if (i == 100) {
      i = 0;
    }
  }
}
//---------------------------------------------------------------------------------------------------
void term() {
  Serial.println("end prgm");
  b(5); buzz(3);
  exit(0);
}
//---------------------------------------------------------------------------------------------------
//void(* resetFunc) (void) = 0; //declare reset function @ address 0

//resetFunc();  //call reset
//---------------------------------------------------------------------------------------------------

void lcdlightSW()
{
  l = !l;
  digitalWrite(lcdlyt, l);
  lcd.setCursor(0, 1);
  if (l == 1)lcd.print("light on");
  if (l == 0)lcd.print("light off");
}
//---------------------------------------------------------------------------------------------------
/*void mute()
  {
  m = !m;
  lcd.setCursor(0, 1);
  if (m == 1) {
    //#define buz A1
    //    buz = A1;
    lcd.print("unmute");
    buzz();
  }
  else if (m == 0) {
    noTone(A1);
    lcd.print("mute");
  }
  }

*/
//---------------------------------------------------------------------------------------------------
void del() {
  delay(50);
}
//---------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------
void longbuzz(int n) {
  int del = 350;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}//---------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------
void longbuzz() {
  int del = 350, n = 1;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
//---------------------------------------------------------------------------------------------------
void b(int n) {
  int del = 50;
  digitalWrite(lyt, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(lyt, HIGH);
    delay(del);
    digitalWrite(lyt, LOW);
    delay(del);
  } digitalWrite(lyt, LOW);
}
//---------------------------------------------------------------------------------------------------
void b() {
  int del = 50, n = 1;
  digitalWrite(lyt, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(lyt, HIGH);
    delay(del);
    digitalWrite(lyt, LOW);
    delay(del);
  } digitalWrite(lyt, LOW);
}

//---------------------------------------------------------------------------------------------------
