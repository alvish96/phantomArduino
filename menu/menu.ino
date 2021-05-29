


int a[20];
int b1, b2, b3, b4, b5, b6, b7, b8;
char sw[5];


class menu
{
  public:
    int tim[20];
    bool flag[7];
};

int OnHour1 = a[0], OnMin1 = a[1];
int OffHour1 = b1, OffMin1 = b2;

int OnHour2 = a[2], OnMin2 =  a[3];
int OffHour2 = b3, OffMin2 =  b4;

int OnHour3 = a[4], OnMin3 = a[5];
int OffHour3 = b5, OffMin3 = b6;

int OnHour4 = a[6], OnMin4 =  a[7];
int OffHour4 = b7, OffMin4 =  b8;

int h, m, s;
bool r1, RSwitch1;
bool r2, RSwitch2;
bool R1T1, R1T2, R2T1, R2T2;
bool debug ;
bool arr2[7];

/*
   obj.flag[0];
  debug = obj.flag[0];                 //debug switch
  RSwitch1 = obj.flag[1];               //relay 1 switch
  RSwitch2 = obj.flag[2];               //relay 2 switch


  R1T1 = obj.flag[3];                   //relay 1 timer 1 switch
  R1T2 = obj.flag[4];                   //relay 1 timer 2 switch
  R2T1 = obj.flag[5];                   //relay 2 timer 1 switch
  R2T2 = obj.flag[6];                   //relay 2 timer 2 switch



*/


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  p();
  delay(1000);

}

void p()
{
  bool up, dw, sel, bk, one, two, tre, fur;

  menu obj;

  obj.opt[i]
  /*
     //display  menu of 4
    // option 1 relay switch --default on on
    --->1.relay1 ok--->  1.on  2.off
              bck<--
    --->2.relay2 ok--->  1.on  2.off
             bck<--

    //option 2 timer switch  ->t1  t2  t3  t4
    --->t1 ok---> 1.hr ok--->0-24
                  bck<--
                2.min ok-->0-60
                  bck<--


    //option 3 debug switch --default=0


    //option 4 reset all values to preset

  */


  a1 = obj.tim[1];
  a2 = obj.tim[2];
  b1 = obj.tim[3];
  b2 = obj.tim[4];

  a3 = obj.tim[5];
  a4 = obj.tim[6];
  b3 = obj.tim[7];
  b4 = obj.tim[8];

  a5 = obj.tim[9];
  a6 = obj.tim[10];
  b5 = obj.tim[11];
  b6 = obj.tim[12];

  a7 = obj.tim[13];
  a8 = obj.tim[14];
  b7 = obj.tim[15];
  b8 = obj.tim[16];

  debug = obj.flag[0];                  //debug switch
  RSwitch1 = obj.flag[1];               //relay 1 switch
  RSwitch2 = obj.flag[2];               //relay 2 switch

  R1T1 = obj.flag[3];                   //relay 1 timer 1 switch
  R1T2 = obj.flag[4];                   //relay 1 timer 2 switch
  R2T1 = obj.flag[5];                   //relay 2 timer 1 switch
  R2T2 = obj.flag[6];                   //relay 2 timer 2 switch

  Serial.println(obj.tim[0]);
  for (int i = 0; i < 20; i++)
  {
    Serial.print("_____");
  }

}
