

/*update log
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

   major update 1.5

   testing serial data transfer pins
   added secondary remote

   key update 1.7
   sram reduction from 90% to 36% using serial.print(F(""));

   update 1.8
   serial data transfer complete
   implemented



*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 6); //rx pin,tx pin // orange rx // yellow tx


const int num = 11;
byte minutes, seconds;

bool data1[num];             // state
bool data2[num];              //temp
unsigned int data3;         //present-lastmotion
int data4;  //brt
byte data5, data10[num], data11[num]; //mtncnt  // minutes // seconds
bool data6, data7, data8, data9; //chkmtn // pr // wait // ato
bool data12 = 0, data13, data14, data15; //look // debugg // transmit //motion()



bool debugg = 0;
#define ldr A7
//int ldrval = 0;
#define smooth 10
byte last[smooth] = {0};
byte  average = 0, limit = 35;
int brttot = 0;
bool flag2=0;

//unsigned int mark1,mark2;

#define irpin 12
#include<IRremote.h>
IRrecv ir(irpin);
decode_results irresult;


#define pirpin 10
int pirval = 0;
bool motionstate = 0; //no motion
byte motioncount = 0; //motion count is zero
bool checkmotion = 1; // checkmotion
bool minor = 0, fromhere = 0, CRF = 0, wait = 0, ato = 0; //COUNTER RESET FLAG

bool priority, temp, mute, look, transmit; //v
int duration = 0;

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
unsigned int lastm, secondmotion, firstmotion;
