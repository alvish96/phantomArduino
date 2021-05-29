
class Led {
  private:
    byte pin;
  public:
    Led(byte pin) {
      // Use 'this->' to make the difference between the
      // 'pin' attribute of the class and the 
      // local variable 'pin' created from the parameter.
      this->pin = pin;
      init();
    }

    void init() {
      pinMode(pin, OUTPUT);
      // Always try to avoid duplicate code.
      // Instead of writing digitalWrite(pin, LOW) here,
      // call the function off() which already does that
      off();
    }

    void on() {
      digitalWrite(pin, HIGH);
    }

    void off() {
      digitalWrite(pin, LOW);
    }
}; // don't forget the semicolon at the end of the class


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
class Button {
private:
 byte down_at;
 byte down;
 
public:
 Button();
 byte downFor();
 void resetDown();
 bool isDown();
 void turnOn();
 void turnOff();
};

Button::Button()
{
 this->down_at = 0;
 this->down = 0;
}

// Find the number of beats the button has been down for. Function can compute max.
//8 sec down before rolling over.
byte Button::downFor()
{
 byte time;
 if (this->down_at > sc_beat)
 {
  time = (sc_beat + 256) - this->down_at;
 }
 else
 {
   time = sc_beat - this->down_at;
 }
 return time;
}

bool Button::isDown()
{
 return (bool)this->down;
}

void Button::resetDown()
{
 this->down_at = sc_beat;
 this->down = 1;
}
 
void Button::turnOn()
{
 if (!this->down)
 {
   this->down_at = sc_beat;
   this->down = 1;
 }
 return;
}

void Button::turnOff()
{
 this->down = 0;
 return;
}

//-----------------------------------------------------------------------------------------------------
