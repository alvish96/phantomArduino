#define bl 6
#define wh 9

#define irpin 12
#include<IRremote.h>
IRrecv ir(irpin);
decode_results irresult;
bool rem = 1;

bool blsw, whsw, blctrl, whctrl, whp, blp, blspc, whspc, debug; //white pause , blue pause,whitespeedcontrol,bluespeed control

unsigned int upctrl, downctrl, rtctrl, ltctrl;
int blmax, blmin, whmax, whmin, blsp, whsp, blbr, whbr, spup, spdw, splt, sprt;



int i, j;
bool   dirup1,  dirdw1,  dirup2, dirdw2;


void(* resetFunc) (void) = 0; //declare reset function @ address 0



#define rel1 14
#define rel2 17
#define rel3 16
#define rel4 15

#define relayon 0
#define relayoff 1






void setup()
{

pinMode(rel1,OUTPUT);
pinMode(rel2,OUTPUT);
pinMode(rel3,OUTPUT);
pinMode(rel4,OUTPUT);


//  relay on == 0    rlay off ==1


digitalWrite(rel1,relayoff);
digitalWrite(rel2,relayoff);
digitalWrite(rel3,relayoff);
digitalWrite(rel4,relayoff);
//
//  delay(1000);
//digitalWrite(rel1,relayon);
//digitalWrite(rel2,relayon);
//digitalWrite(rel3,relayon);
//digitalWrite(rel4,relayon);
//  delay(1000);
//digitalWrite(rel1,relayoff);
//digitalWrite(rel2,relayoff);
//digitalWrite(rel3,relayoff);
//digitalWrite(rel4,relayoff);

  unsigned long baud = 115200;
  Serial.begin(baud);
  pinMode(bl, OUTPUT);
  pinMode(wh, OUTPUT);
  ir.enableIRIn();          // Start the receiver

  //DEFAULT VALUES
  debug = 1;
  blsw = 0;
  whsw = 0;
  blctrl = 0;
  whctrl = 0;
  blsp = 1;
  whsp = 1;
  blbr = 250;
  whbr = 0;
  blspc = 0;
  whspc = 0;


  blmin = 100;
  blmax = 200;
  whmin = 0;
  whmax = 256;
  i = whmin;
  j = blmin;

  upctrl = 50;
  downctrl = 50;
  rtctrl = 10;
  ltctrl = 10;

  spup = 3;
  spdw = 3;
  sprt = 1;
  splt = 1;



  i = j = 0;
  dirdw1 = 0;
  dirdw2 = 0;
  dirup1 = !dirdw1;
  dirup2 = !dirdw2;

//  startup3();
//  startup2();

}
