#include<IRremote.h>
#include <LiquidCrystal.h>
#include <DS3231.h>


#define lcdlyt 32
#define lcdcon 33
#define ldr A0
#define buz A1
#define irpin 2
#define lyt 12

bool l = 0, m = 1;
int i = 0,pre;

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

  lcd.print("*reset complete*"); delay(350);buzz();
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
  //buzz(2);
  //resetFunc();
}


void brightness() {
  ldrval = analogRead(A0);
  Serial.println(ldrval);
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print(ldrval);
  delay(1000);
}
