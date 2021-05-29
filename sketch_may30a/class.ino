class Module
{
  private :
    byte relay;

  public:

    bool state , flag;
    unsigned long mark , period, total;

    Module(byte relay)
    {
      this->relay = relay;
      init();
    }


    void init()
    {
      Serial.print("relay pin ");
      Serial.println(relay);
      pinMode(relay, OUTPUT);
      digitalWrite(relay, relayoff);
    }

    void SWoff()
    {
      digitalWrite(relay, relayoff);
    }

    void SWon()
    {
      digitalWrite(relay, relayon);
      flag = LOW;
      period = 0;
    }


    void SW()
    {
      state = !state;
      digitalWrite(relay, state);
      debug();
      if (state == 1)Serial.println(" ON");
      if (state == 0)Serial.println(" OFF");
      period = 0;
      flag = LOW;
    }

    void SWtimer(int seco, char c = 'm')
    {
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
      temp = priority;
      priority = 1;
      flag = HIGH;
      Serial.print(" TIMER ON ");
      debug();
    }


    void down()
    {
      state = LOW;
      mark = 0;
      period = 0;
      flag = 0;
    }

    void debug()
    {
      switch (relay)
      {
        case 30: Serial. println(" RESET "); break;
        case 4: Serial. println(" MAIN LIGHT "); break;
        case 11: Serial. println( " LED LIGHT "); break;
        case 7: Serial. println(" FAN "); break;
        case 8: Serial. println(" EXHAUST "); break;
        case 14: Serial. println("  "); break;
        case 15: Serial. println("  "); break;
        case 16: Serial. println("  "); break;
        case 17: Serial. println("  "); break;
        case 19: Serial. println(" PROJECTOR "); break;
        case 18: Serial. println(" BT SPEAKER "); break;
        case 9: Serial. println("  "); break;

      }
    }

};
void SWtimer(int seco,char c='m');

Module mod[20];
//Module mod[12] = {r, rel1, rel2, rel3, rel4, rel5, rel6, rel7, rel8, rel9, rel10, rel11};

void setup()
{
  Serial.begin(9600);
  ir.enableIRIn();

}
