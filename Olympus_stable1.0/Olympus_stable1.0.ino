








#define ldr A7
int ldrval = 0;
int brtval[4] = {0};
#define smooth 10
//const int smooth = 10;
byte last[smooth] = {0};
byte  average = 0, limit = 35;
int brttot = 0;



#define irpin 12
#include<IRremote.h>
IRrecv ir(irpin);
decode_results irresult;


#define pirpin 10
int pirval = 0;
bool motionstate = 0; //no motion
int motioncount = 0; //motion count is zero
bool checkmotion = 1; // checkmotion
bool minor=0,fromhere=0;

bool priority, temp, mute, deepc; //v



#define buz  3

#define r 30
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
