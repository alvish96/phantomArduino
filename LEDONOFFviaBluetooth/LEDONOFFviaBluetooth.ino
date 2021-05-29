/*
  Arduino Turn LED On/Off using Serial Commands
  Created April 22, 2015
  Hammad Tariq, Incubator (Pakistan)

  It's a simple sketch which waits for a character on serial
  and in case of a desirable character, it turns an LED on/off.

  Possible string values:
  a (to turn the LED on)
  b (tor turn the LED off)
*/
//#define BLYNK_PRINT Serial
//#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
char junk;
String inputString = "";

SoftwareSerial SerialBLE(10, 11); // RX, TX
unsigned long stt = 0;
unsigned long a1=900,a2=1800,a3=3600;

const int mainpwr = 8;
const int nytlyt = 9;
const int rumlyt= 13;


const int fan = 12;
bool f1 = LOW, f2 = LOW, f3 = LOW;

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);
  SerialBLE.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  pinMode(rumlyt, OUTPUT);//room light
  pinMode(fan, OUTPUT);//fan
  pinMode(nytlyt, OUTPUT);//night light
  pinMode(mainpwr, OUTPUT);//main
}

void loop()
{ if ( f1 == HIGH)
  { Serial.println("enterd loop 1");
    if (millis() > (stt + a1*1000))
    {

      digitalWrite(fan, LOW);
      Serial.println("fan is off after 15 mins");
      f1 = LOW; stt = 0;
    }
  }

  else if ( f2 == HIGH)
  { Serial.println("enterd loop 2");
    if (millis() > (stt + a2*1000))
    {

      digitalWrite(fan, LOW);
      Serial.println("fan is off after 30 mins");
      f2 = LOW; stt = 0;
    }
  }

  else if ( f3 == HIGH)
  { Serial.println("enterd loop 3");
    if (millis() > stt + a3*1000)
    {
      digitalWrite(fan, LOW);
      Serial.println("fan is off after 60 mins");

      f3 = LOW; stt = 0;
    }
  }
  if (SerialBLE.available())
  {
    while (SerialBLE.available())
    {
      char inChar = (char)SerialBLE.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    SerialBLE.println(inputString);
    while (SerialBLE.available() > 0)
    {
      junk = SerialBLE.read() ;  // clear the serial buffer
    }


    if (inputString == "a") {       //in case of 'a' turn the LED on
      digitalWrite(rumlyt, HIGH);
      Serial.println("Room light is on");
    } else if (inputString == "b") { //incase of 'b' turn the LED off
      digitalWrite(rumlyt, LOW);
      Serial.println("Room light is off");
    }

    else if (inputString == "c") {
      digitalWrite(fan, HIGH);//f1=HIGH;f2=HIGH;f3=HIGH;
      Serial.println("Fan is on");
    } else if (inputString == "d") { //incase of 'b' turn the LED off
      digitalWrite(fan, LOW);f1=LOW;f2=LOW;f3=LOW;
      Serial.println("Fan is off");
    }

    else if (inputString == "e") {       //in case of 'a' turn the LED on
      digitalWrite(nytlyt, HIGH);
      Serial.println("Night light is on");
    } else if (inputString == "f") { //incase of 'b' turn the LED off
      digitalWrite(nytlyt, LOW);
      Serial.println("Night light is off");
    }

    else if (inputString == "g") {       //in case of 'a' turn the LED on
      digitalWrite(mainpwr, HIGH);
      Serial.println("Mains is on");
    } else if (inputString == "h") { //incase of 'b' turn the LED off
      digitalWrite(mainpwr, LOW);
      Serial.println("Mains is off");
    }

    else if (inputString == "i") {
      stt=0;       //in case of 'a' turn the LED on
      digitalWrite(fan, HIGH);
      Serial.println("fan is on for 15 mins");
      stt = millis(); Serial.println("set millis");
      f1 = HIGH; Serial.println("f1 high");
    }
    else if (inputString == "j") {       //in case of 'a' turn the LED on
      stt=0;
      digitalWrite(fan, HIGH);
      Serial.println("fan is on for 30 mins");
      stt = millis(); Serial.println("set millis");
      f2 = HIGH; Serial.println("f2 high");
    }

    else if (inputString == "k") {       //in case of 'a' turn the LED on
      stt=0;
      digitalWrite(fan, HIGH);
      Serial.println("fan is on for 60 mins");
      stt = millis(); Serial.println("set millis");
      f3 = HIGH; Serial.println("f3 high");
    }



    else if (inputString == "l") {      //in case of 'a' turn the LED on
      //digitalWrite(mainpwr, LOW);
      Serial.println("everything off");
      digitalWrite(nytlyt, LOW);
      digitalWrite(fan, LOW);
      digitalWrite(rumlyt, LOW);

    }



    inputString = "";
  }
}

/*void f1()
  }

  void g1(unsigned long x, double a)
  {
    //stt = millis();
    if (millis() > stt + a)
    {
      digitalWrite(12, LOW); Serial.println("Fan is off");
      stt = 0;
    }
  }
*/
