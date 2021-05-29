#define minspd 115
#define maxspd 255
#define midspd 192
#define pwmpin 9
#define dup 10
#define reedpin A5
#define temppin A2
#define knob A4
#define sw A3
#define red A0
#define grn 13

byte spd;
int rpm;
int temp;
bool AUTO;
bool f = 0;

unsigned long offtimer, offtime, ontimer, flushtime;
bool entryflag, flag10, flagnxt;




void setup()
{
  AUTO = 0;
  Serial.begin(115200);
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);

  pinMode(pwmpin, OUTPUT);
  pinMode(dup, OUTPUT);
  pinMode(sw, INPUT);
  pinMode(knob, INPUT);
  pinMode(reedpin, INPUT);
  pinMode(temppin, INPUT);
  analogWrite(pwmpin, minspd);
  analogWrite(dup, minspd);
  digitalWrite(red, 0);
  digitalWrite(grn, 0);
  ontimer = 0;
  offtimer = 0;
  flushtime = 300000; //5mins
}



void loop()
{
  contr();
}

void contr()
{
  int a = analogRead(knob);
  if (a > 950)
    AUTO = 1;

  if (AUTO)
  {

    grnl();
    if (a > 1020)
    {
      if (((offtimer + offtime) < millis()) && entryflag == 0)
      {
        ontimer = millis();
        entryflag = 1;
      }
      else if ((offtimer + offtime) > millis())
        wrtspd(20);
      flus();
      goto a;
    }
    //    offtime=0;
    resetdata();

    autospd();
    AUTO = 0;
a: goto END;
  }
  if (!AUTO)
  {
    //    offtime=0;
    resetdata();
    redl();
    //    map(value, fromLow, fromHigh, toLow, toHigh)
    //y = map(x, 1, 50, 50, 1);

    Serial.print(F( " knob signal -> "));
    Serial.print(a);
    byte val = map(a, 0, 1024, 255, 110);
    Serial.print(F( "  mapped signal -> "));
    Serial.print(val);

    wrtspd(val);
    line();
  }
END: delay(5);
}


void autospd()
{ f = 0;
  int x = readtemp();
  ctrl(20, 30, x, minspd);
  ctrl(30, 40, x, midspd);
  ctrl(40, 50, x, 220);
  ctrl(50, 90, x, maxspd);
  if (f)goto x;

  wrtspd(midspd);
x: delay(0);
}
void ctrl(int low, int high, int tmp, byte s)
{
  while (tmp > low && tmp < high)
  {
    wrtspd(s); f = 1;
  }
}
