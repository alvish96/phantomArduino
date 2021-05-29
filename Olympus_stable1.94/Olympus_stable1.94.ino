
#define verdisp 1.94
#define testing 0
/*
  1.91 lightmode
  1.90  sequence1 reprogram
  1.89  version display
  1.88  all0
  1.87 audio
  1.86 REMOTE SWITCH

   1.85 reset board after 20 mins
   1.84 reset motion after 20 mins

   1.83
   1.82

   update 1.81
   addtional minor bug fixes
   resetmotion and update motion additions


   update log 1.8
   data transfer

    1.72
    minor bug fixes
    seems stable now

   key update 1.7
   sram reduction from 90% to 36% using serial.print(F(""));

   major update 1.5

   testing serial data transfer pins
   added secondary remote

  1.0-1.5
   sensor working properly
   pir enabled
   phone ir blaster working

   #NEW UPDATES
   projector off timer with 1 minute delay

   turnoff instead of reset after timeout
   delayed motion sense initiation 2seconds

   minor bug fixes
   date - 27 1300hr

   need more fixing
   minor bug with priority and checkmotion using timer and ato
   if ato ==1
   errors occur


   update 240 am 28 june
   most bugs fixed
   working as expected

   key changes





*/
//-----------------------------------------------------------------------------------------------
//-----------------------------------comm section------------------------------------------------
//sending  //1.8

#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); //rx pin,tx pin  // orange rx // yellow tx
int datax, datanx;
bool recv = true;
bool req, look, transmit, sent;
byte STC=255,ETC=201;   //Start Transmission Code  // End Transmission Code 
byte reqcod = 231; //request transmission
byte cbyte = 232,concode;  //control byte sent  |control code
bool scon; //serial control 
bool assignt,timelook,TMD;    //Transmit Motion Data


const int num = 12;
bool databool0[30];   //flags     248
bool databool1[num];  //state     249
bool databool2[num];  //timerflag 250
bool databool3[num];  //relaytype 251
bool databool4[num];  //prtemp    252

byte databyte0[20]; //byte data   246
byte databyte1[num];//hour        240
byte databyte2[num];//minute      241
byte databyte3[num];//second      242

byte databyte4[10];//hr           243
byte databyte5[10];//min          244
byte databyte6[10];//sec          245
/*
REQUEST CODE           reqcode  231
CONTROL BYTE           cbyte    232
switching              TMDon    233 
                       TMDoff   234


{{{    to swtich TMD 
      1.send control byte
      2.send switch command   }}}




//#define led1 5// or
//#define led2 6

*/
//-----------------------------------------------------------------------------------------------
bool debugg = 0;
#define ldr A7
#define smooth 10
byte last[smooth] = {0};
byte  average = 0, limit = 35;
byte mi, se;
int brttot = 0;

//unsigned int mark1,mark2;

#define irpin 12
#include<IRremote.h>
IRrecv ir(irpin);
decode_results irresult;
bool rem = 1;

byte lightmode; // 0. nightlight->led light-> mainlight
//                   1.  nightlight ->mainlight
//                    2.  mainlight


#define pirpin 10
int pirval = 0;
bool motionstate = 0; //no motion
byte motioncount = 0; //motion count is zero
bool checkmotion = 1; // checkmotion
bool minor = 0, fromhere = 0, CRF = 0, wait = 0, ato = 0; //COUNTER RESET FLAG
bool all0; //1.88
int resettimer ; //1.88

bool priority, temp, mute, deepc, flag2 = 0, timeroff = 0; //v
unsigned long duration, duration1;

#include <NewTone.h>
#define buz 3

#define r 0
#define rel1 4//main light
#define rel2 11// led light
#define rel3 7//fan
#define rel4 8//exhaust
#define rel5 14// switch 1
#define rel6 15//switch 2
#define rel7 16//switch 3
#define rel8 17//switch 4
#define rel9 19 //projector
#define rel10 18 //bluetooth
#define rel11 9 //switch 5



void(* resetFunc) (void) = 0; //declare reset function @ address 0
unsigned long present, lastmotion;
unsigned long lastm, secondmotion, firstmotion;
