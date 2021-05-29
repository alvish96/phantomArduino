
void SWtimer(int seco, char c = 'm');


class Switch
{
  private:


  public:
    bool prtemp = 0;
    byte relay, hr, mi, se;
    bool relayon, relayoff;
    bool state , flag , relaytype , alt, alt2;                 //3.1 addition of alternating flag
    unsigned long mark, period, total, totalalt;          //3.1
    unsigned int mark1, mark2, mark3;                     //3.2

    //    unsigned long x, y, z;
    unsigned long ontimer, offtimer;        //3.2

    Switch(byte relay)
    {
      this->relay = relay;
    }

    void initialise()
    {
      Serial.print(F(" RELAY PIN "));
      Serial.print(relay);
      debug();
      pinMode(relay, OUTPUT);
      digitalWrite(relay, relayoff);
      line();
    }

    void definetype(bool x )
    {
      relaytype = x;
      Serial.print(F("  "));
      Serial.print(x);
      if (relaytype == 1) // normal
      {
        Serial.print(F("  RELAY TYPE NORMAL  "));
        relayon = 1;
        relayoff = 0;
      }
      else      //flip
      {
        Serial.print(F("  RELAY TYPE FLIP    "));
        relayon = 0;
        relayoff = 1;
      }
      //      line();
    }


    void SWon()
    {
      digitalWrite(relay, relayon);
      if (debugg) Serial.print(F("  RELAY ON   "));
      flag = LOW;
      period = 0;
      priority = prtemp;
    }
    void SWoff()
    {
      if (state == relayon)
      {
        if (ato == 0)
          priority = prtemp;
        if (ato == 1)
        {
          priority = priority;
        }
      }
      digitalWrite(relay, relayoff);
      if (debugg) Serial.print(F("  RELAY OFF  "));
      flag = LOW;
      period = 0;
      priority = prtemp;
    }

    void SW()
    {
      if (state == relayon)
      {
        if (ato == 0)
          priority = prtemp;
        if (ato == 1)
        {
          sync();
        }
      }
      state = !state;
      digitalWrite(relay, state);
      debug();
      if (state == relayon)Serial.println(F(" ON "));
      if (state == relayoff)Serial.println(F(" OFF "));
      period = 0;
      flag = LOW;
    }


    void SWtimer(int seco, char c = 'm')
    {
      tune(12);
      mark = 0;
      period = 0;
      if (c == 's')
        period = seco * 1000;
      else if (c == 'm')
        period = seco * 60000;
      else if (c == 'h')
        period = seco * 3600000;
      state = relayon;
      digitalWrite(relay, state);
      mark = millis();
      total = period + mark;
      prtemp = priority;
      priority = 1;

      flag = HIGH;
      Serial.print(F(" TIMER ON "));
      debug();
    }

    void SWtimerAlt(int alto, int altoend, char c = 'm')      //3.1 alternating timer  mod[3].SWtimerAlt(15,3,'m');
    {

      tune(12);
      mark = 0;
      period = 0;
      if (c == 's')
        period = alto * 1000;
      else if (c == 'm')
        period = alto * 60000;
      else if (c == 'h')
        period = alto * 3600000;

      state = relayon;
      digitalWrite(relay, state);
      mark = millis();
      totalalt = (mark + (altoend * 3600000));
      total = period + mark;
      prtemp = priority;
      priority = 1;

      alt = HIGH;
      flag = HIGH;
      Serial.print(F("ALTERNATING TIMER ON "));
      debug();

    }
    void SWtimerAlt2(int ont, int offt, int fullt, char c1 = 's', char c2 = 's', char c3 = 'h')     //3.2   mod[3].SWtimerAlt2(15,10,3,'s','s','h');
    {
      tune(12);
      mark = 0;
      unsigned long n = 0;

      if (c1  == 's')
        n = 1000;
      else if (c1  == 'm')
        n = 60000;
      else if (c1 == 'h')
        n = 3600000;


      ontimer = ont * n;
      if (c2  == 's')
        n = 1000;
      else if (c2  == 'm')
        n = 60000;
      else if (c2 == 'h')
        n = 3600000;

      offtimer = offt * n;
      if (c3 == 's')
        n = 1000;
      else if (c3  == 'm')
        n = 60000;
      else if (c3 == 'h')
        n = 3600000;

      state = relayon;
      digitalWrite(relay, state);
      mark = millis();
      total = (mark + (fullt * n));
      mark1 = millis();
      mark2 = mark1 + ontimer;
      mark3 = mark2 + offtimer;
      prtemp = priority;
      priority = 1;

      alt2 = HIGH;
      flag = HIGH;
      Serial.print(F("ALTERNATING TIMER 2 ON "));
      debug();
    }                                                                                                   //3.2


    void down()
    {
      state = relayoff;
      mark , mark1, mark2, mark3 = 0;
      period = 0;
      flag = 0;
      alt = 0;    //3.1
      alt2 = 0;   //3.2
    }

    void debug()
    {
      if (debugg)
        switch (relay)
        {
          case 30: Serial.print(F(" RESET       ")); break;
          case 4:  Serial.print(F("  MAIN LIGHT  ")); break;
          case 11: Serial.print(F(" LED LIGHT   ")); break;
          case 7:  Serial.print(F("  FAN         ")); break;
          case 8:  Serial.print(F("  EXHAUST     ")); break;
          case 14: Serial.print(F(" BT SPEAKER  ")); break;
          case 15: Serial.print(F(" SWITCH MR   ")); break;
          case 16: Serial.print(F(" SWITCH COOL ")); break;
          case 17: Serial.print(F(" SWITCH ADN  ")); break;
          case 19: Serial.print(F(" PROJECTOR   ")); break;
          case 18: Serial.print(F(" NIGHT LIGHT ")); break;
          case 9:  Serial.print(F("  5LED        ")); break;

        }
    }

};







Switch mod[12] = {r, rel1, rel2, rel3, rel4, rel5, rel6, rel7, rel8, rel9, rel10, rel11};


void setup()
{
  test();  //  mute=0;  checkmotion = 1;
  tune(8);
  Serial.begin(115200);
  mySerial.begin(9600);
  debugg = 1;
  debug1(); //1.89
  ir.enableIRIn();          // Start the receiver

  pinMode(ldr, INPUT);  //v
  pinMode(pirpin, INPUT); //v
  pinMode(buz, OUTPUT);   //v
  //  pinMode(led1, OUTPUT);   //v
  //  pinMode(led2, OUTPUT);   //v

  //sequence();

  sequence1();// 1.90
  brttot = 0;
  temp = 0;
  sync();
  duration = 60000;  // wait duration before motion sensor turns on after board reset
  lightmode = 2;// 0. nightlight->led light-> mainlight
  //               1.  nightlight ->mainlight
  //               2.  mainlight
  resettimer = 20; //time interval at which board will reset itself when everything is off
  all0 = 1; //1.88
  //-------------------------commmm
  fn4();
  req = 0;
  look = 1;//used to print transmission related status
  deepc = 1; // print transmission values
  transmit = 1; //flag for transmit
  sent = 0; // status of transmission
  timelook = 1; //display timer information being assigned
  TMD = 1;
  SF = 0;
  TMD1();
  TP = 1; // PRINT TIME DATA
  thour = tmin = tsec = 0;
}
