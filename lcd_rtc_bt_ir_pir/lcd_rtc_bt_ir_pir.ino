#include<IRremote.h>
#include <LiquidCrystal.h>
#include <DS3231.h>


#define lcdlyt 32
#define lcdcon 33

#define ldr A0
#define buz A1
#define irpin 2
#define lyt 12

//---------------------------------------------------------------------------------------------------

#define ENL 11
#define lpos 34
#define lneg 35
int lytlevel = 255 ,mode;
bool light,lightflag;


//---------------------------------------------------------------------------------------------------

#define relay0 46
#define relay1 12
//#define lpos 34
//#define lneg 35
//int lytlevel = 255 ,mode;

bool light0;

//---------------------------------------------------------------------------------------------------

unsigned long milli = 0;          //milli
int delaytime = 5;
bool f1 ;                       // flag for btness
bool l , m = 1;                          //lcdlyt  l conf file


//---------------------------------------------------------------------------------------------------


int i = 0, pre;                            //pre for loop ir input
int ambv = 600 ; bool amb, ov = 0;            //ov is overwrite/ ambientval ambv/
bool exitloop = 0;


//---------------------------------------------------------------------------------------------------
unsigned long CODE_POWER_ON = 0x61D650AF;   //23    1641435311
unsigned long CODE_FF = 0x61D648B7;         //17  1641433271
unsigned long CODE_RW = 0x61D610EF;         //18  1641418991
unsigned long CODE_NEXT = 0x61D6F20D;       //19  1641476621
unsigned long CODE_BACK = 0x61D630CF;       //20  1641427151
unsigned long CODE_VERT = 0x61D69867;       //21  1641453671
unsigned long CODE_HORI = 0x61D6A25D;       //22  1641456221
unsigned long CODE_LISTEN = 0x61D67887;     //24  1641445511


unsigned long CODE_SELECT = 0x61D628D7;     //1 1641425111

unsigned long CODE_RIGHT = 0x61D69A65;      //2 1641454181
unsigned long CODE_LEFT = 0x61D6A857;       //3 1641457751
unsigned long CODE_UP = 0x61D6AA55;         //4 1641458261
unsigned long CODE_DOWN = 0x61D618E7;       //5 1641421031
unsigned long CODE_MENU = 0x61D632CD;       //6 1641427661
unsigned long CODE_EXIT = 0x61D6728D;       //7 1641443981
unsigned long CODE_SOURCE = 0x61D6D02F;     //8 1641467951
unsigned long CODE_ZOOM = 0x61D6F00F;       //9 1641476111
unsigned long CODE_VOLUP = 0x61D6708F;      //10  1641443471
unsigned long CODE_VOLDW = 0x61D612ED;      //11  1641419501
unsigned long CODE_PIC = 0x61D6629D;        //12  1641439901
unsigned long CODE_SOUND = 0x61D6EA15;      //13  1641474581
unsigned long CODE_FREEZE = 0x61D6DA25;     //14  1641470501
unsigned long CODE_PLAY = 0x61D6906F;       //15  1641451631
unsigned long CODE_MUTE = 0x61D652AD;       //16  1641435821
//---------------------------------------------------------------------------------------------------

void(* resetFunc) (void) = 0; //declare reset function @ address 0

//---------------------------------------------------------------------------------------------------

bool power;
int ldrval;

//---------------------------------------------------------------------------------------------------

IRrecv ir(irpin);
decode_results irresult;

//---------------------------------------------------------------------------------------------------

const int rs = 22, en = 23, d4 = 28, d5 = 29, d6 = 30, d7 = 31;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//---------------------------------------------------------------------------------------------------

DS3231  rtc(SDA, SCL);
Time  t;






















//---------------------------------------------------------------------------------------------------
//mario

int f = 10;                //set frames per second (fps)
int s;

byte mario11[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00001,
  B00000,

};
byte mario12[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};
byte mario13[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,

};
byte mario14[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110
};

byte mario15[8] = {
  B00000,
  B00000,
  B11000,
  B00000,
  B11000,
  B11100,
  B11000,
  B10000,

};

byte mario16[8] = {
  B00000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
  B10000,
  B00000
};

byte mario21[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte mario22[8] = {
  B00111,
  B00111,
  B00111,
  B00000,
  B00001,
  B00011,
  B00011,
  B00001
};

byte mario23[8] = {
  B00000,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,

};

byte mario24[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11001,
  B00000,
  B10000
};
byte mario25[8] = {
  B00000,
  B00000,
  B11100,
  B10000,
  B11100,
  B11110,
  B11100,
  B11000,

};

byte mario26[8] = {
  B11111,
  B11111,
  B10110,
  B11110,
  B11110,
  B11110,
  B00000,
  B00000,
};

byte mario31[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,

};


byte mario32[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B00111,
  B00000
};


byte mario33[8] = {
  B00000,
  B00000,
  B00111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111,

};

byte mario34[8] = {
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00111,
  B00111
};

byte mario35[8] = {
  B00000,
  B00000,
  B10000,
  B11110,
  B11000,
  B11110,
  B11111,
  B11110,

};

byte mario36[8] = {
  B11100,
  B11110,
  B11100,
  B11000,
  B11000,
  B10000,
  B00000,
  B10000,
};

byte mario41[8] = {
  B00000,
  B00011,
  B00111,
  B00111,
  B01111,
  B01111,
  B01111,
  B00011,

};


byte mario42[8] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00011
};

byte mario43[8] = {
  B00000,
  B11000,
  B11111,
  B11100,
  B11111,
  B11111,
  B11111,
  B11110,
};

byte mario44[8] = {
  B11100,
  B11110,
  B11110,
  B11110,
  B11100,
  B11100,
  B11110,
  B10000
};


byte mario51[8] = {
  B00000,
  B00001,
  B00011,
  B00011,
  B00111,
  B00111,
  B00111,
  B00001,
};

byte mario52[8] = {
  B11111,
  B11111,
  B11011,
  B00111,
  B01111,
  B11111,
  B11100,
  B01110,
};

byte mario53[8] = {
  B00000,
  B11100,
  B11111,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte mario54[8] = {
  B11111,
  B11111,
  B11110,
  B11111,
  B11111,
  B01111,
  B00000,
  B00000,
};



byte mario55[8] = {
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
};


byte mario56[8] = {
  B11000,
  B11000,
  B10000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
};


byte mario61[8] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00011,
  B00011,
  B00011,
};

byte mario62[8] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B01111,
  B11111,
  B11000,
  B00000,
};



byte mario63[8] = {
  B00000,
  B00000,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte mario64[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
  B11110,
};

byte mario65[8] = {
  B00000,
  B00000,
  B00000,
  B10000,
  B00000,
  B10000,
  B11000,
  B10000,
};


byte mario66[8] = {
  B00000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte clean[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte coin1[8] = {

  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B01000,
  B10001,
  B10010,
};

byte coin2[8] = {

  B10010,
  B10010,
  B10010,
  B10010,
  B10001,
  B01000,
  B00111,
  B00000,
};


byte coin3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B01000,
  B00100,
  B10100,
};

byte coin4[8] = {
  B10100,
  B10100,
  B10100,
  B00100,
  B00100,
  B01000,
  B10000,
  B00000,
};
