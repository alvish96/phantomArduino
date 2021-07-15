#define pin0 30
#define pin1 14
#define pin2 23
#define pin3 16

class some
{
  private :


  public:
    byte pin;
    bool state;

    some(byte pinx)
    {
      this->pin = pinx;
    }

    void DI()   // declaration and initialisation
    {
      pinMode(pin, OUTPUT);

      Serial.print(F(" PIN "));
      Serial.print(pin);
    }
    void SW()
    {

      state = !state;

    }


};

some thing[4] = {pin0, pin1, pin2, pin3};

void InitSeq()
{
  //  thing[2].DI();
  thing[2].DI();
}


void setup()
{
  Serial.begin(9600);
  InitSeq();    //initialise sequence
}

void loop()
{




}
