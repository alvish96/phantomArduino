/*update log
 * sensor not working properly 
 * pir disabled
 * phone ir blaster working 
 * 
 * #NEW UPDATES
 * projector off timer with 1 minute delay
*/





#include<IRremote.h>
//---------------------------------------------------------------------------------------------------
#define s1 4              //mainlight
#define s2 11           //led light
#define s3 7            //fan
#define s4 8            //exhaust


#define s5  A0          //surround
#define s6  A1          //small sound
#define s7  A2          //projector 
#define s8  A3          //switch
#define s9  A5          //switch  
#define s10 A4          //switch
#define s11 9           //switch

#define buz  3

#define ldr A7
#define irpin 12
#define pirPin 10
//---------------------------------------------------------------------------------------------------

int calibrationTime = 30;
long unsigned int lowIn;
int pause = 1000;
long unsigned int lastmotion = 0, present = 0;

boolean lockLow = true;
boolean takeLowTime, temp;

//---------------------------------------------------------------------------------------------------


void(* resetFunc) (void) = 0; //declare reset function @ address 0
IRrecv ir(irpin);
decode_results irresult;
int ldrval = 0;
#define ron HIGH
#define roff LOW
#define r1on LOW
#define r1off HIGH
//---------------------------------------------------------------------------------------------------

int pre;
int m;
//bool f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, ft1, ft2, ft3, ft4, ftres;
//bool f11 = 0, f21 = 0, f31 = 0, f41 = 0, f51 = 0, f61 = 0, ft11, ft21, ft31, ft41, ft51, ft61;

//unsigned long a1, a2, a3, a4, ares = 0;
//unsigned long a11, a21, a31, a41, a51, a61;
//unsigned long x1, x2, x3, x4, xres;
//unsigned long x11, x21, x31, x41, x51, x61;

bool f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, fres;
bool ft1, ft2, ft3, ft4, ft5, ft6, ft7, ft8, ft9, ft10, ft11, ftres;

bool mute,pron,proff;

unsigned long a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ares;
unsigned long x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, xres;

int count;
int a, b, x;
int limit = 350;
bool checkmotion, debug;
bool mf1, motn, prflag;
//---------------------------------------------------------------------------------------------------
int maxfancount, fancount = 0, flow = 15, wait = 5;
bool flowflag , waitflag;

unsigned long waitstt = 0, waitdur = 0, flowstt = 0, flowdur = 0;

//---------------------------------------------------------------------------------------------------


/*
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



  unsigned long CODE_POWER_ON = 0x61D650AF;   //23
  unsigned long CODE_FF = 0x61D648B7;         //17
  unsigned long CODE_RW = 0x61D610EF;         //18
  unsigned long CODE_NEXT = 0x61D6F20D;       //19
  unsigned long CODE_BACK = 0x61D630CF;       //20
  unsigned long CODE_VERT = 0x61D69867;       //21
  unsigned long CODE_HORI = 0x61D6A25D;       //22
  unsigned long CODE_LISTEN = 0x61D67887;     //24
 
  
  power     5E7DB3DC
  home     F874E0F8
  option      F574DC41
  ok        76A77416

  vol down   8453B5A5
  vol up     8753BA5C
  back       EB58E7B6  DE3AA631


  up         52120F2  6212287
  down       DE3AA631
  left        8753BA5C  EA58E625
  right       69893291


*/
//---------------------------------------------------------------------------------------------------
