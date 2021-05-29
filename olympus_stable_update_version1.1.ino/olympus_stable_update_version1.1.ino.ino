#include<IRremote.h>
#define r 30
#define rel1 4//main light
#define rel2 11// led light
#define rel3 7//fan
#define rel4 8//exhaust
#define rel5 14// surround
#define rel6 15// small sound
#define rel7 16//projector
#define rel8 17//switch
#define rel9 19
#define rel10 18
#define rel11 9

#define buz  3
#define ldr A7
#define irpin 12
#define pirpin 10

void SWtimer(int seco,char c='m');


void(* resetFunc) (void) = 0; //declare reset function @ address 0

IRrecv ir(irpin);
decode_results irresult;
int pirval = 0;
bool motionstate=0; //no motion
int motioncount=0; //motion count is zero
bool motionflag=1; // checkmotion on
bool mute=0;
int ldrval = 0;
int limit = 350;
bool priority,temp; 
unsigned long present,lastmotion;



















int count;
int a, b, x;

bool checkmotion, debug;
bool mf1, motn, prflag;
