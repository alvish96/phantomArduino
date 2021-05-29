#include <DS3231.h>

DS3231  rtc(SDA, SCL);
Time t;

int R1 = 7;
int R2 = 8;
int a = 6;
int b = 6;
int period = 20;            //compensation period

int OnHour1 = 21;
int OnMin1 = 50;
int OffHour1 = 21;
int OffMin1 = 51;

int OnHour2 = 21;
int OnMin2 = 52;
int OffHour2 = 21;
int OffMin2 = 53;

int h, m, s;
bool r1;
bool r2;


void setup() {
  Serial.begin(9600);
  rtc.begin();
  pinMode(R1, OUTPUT);
  digitalWrite(R1, 0);

  pinMode(R2, OUTPUT);
  digitalWrite(R2, 0);
  setr();
}

void setr() 
{
  digitalWrite(R2, 0);
  delay(50);
  digitalWrite(R2, 1);
  delay(100);

  digitalWrite(R2, 0);
  delay(50);
  digitalWrite(R2, 1);
  delay(500);

  digitalWrite(R2, 0);
  //  digitalWrite(R2, 0);
  delay(300);
  digitalWrite(R2, 1);
  digitalWrite(R1, 1);
  //  delay(100);
}


void comp()
{
  h = 11; m = 1; s = 1;
  //Start drift compensation RTC
  if (t.hour == h && t.min == m && t.sec == s)
  {
    //run daily at exactly the same time
    delay(period);
    rtc.setTime(h, m, s);
  }
}


void loop() {
  comp();
  t = rtc.getTime();
  delay (1000);
  p();
  ry();
  Serial.println();


}
void p() {

  Serial.print(" | Ontime is ");
  Serial.print(OnHour1);
  Serial.print(":");
  Serial.print(OnMin1);
  Serial.print(" | Offtime is ");
  Serial.print(OffHour1);
  Serial.print(":");
  Serial.print(OffMin1);
  Serial.print(" | ");
  Serial.print(t.hour);
  Serial.print(" :: ");
  Serial.print(t.min);
  Serial.print(" :: ");
  Serial.print(t.sec);

  bool b = digitalRead(R1);
  Serial.print(" | R1 ");
  if (b == 0)
    Serial.print("ON");
  else if (b == 1)
    Serial.print("OFF");


  bool c = digitalRead(R2);
  Serial.print(" | R2 ");
  if (c == 0)
    Serial.print("ON");
  else if (c == 1)
    Serial.print("OFF");

  Serial.print("\t a = ");
  Serial.print(a);

}
void R1on()
{
  digitalWrite(R1, 0);
  Serial.print("\t relay1 on");
}
void R2on()
{
  digitalWrite(R2, 0); r2 = 0;
  Serial.print("\t relay2 on");
}

void R1off()
{
  digitalWrite(R1, 1);
  Serial.print("\t relay1 off");
}
void R2off()
{
  digitalWrite(R2, 1);
  Serial.print("\t relay2 off");
}



void ry()
{
  
  if (t.hour > OnHour2 && t.hour < OffHour2)      b = 1;

  else if (OnHour2 == t.hour && OffHour2 == t.hour)
  {
    b = 2;
    goto y;
  }
  else if (t.hour == OnHour2)
  {
    b = 3;
    goto y;
  }
  else if (t.hour == OffHour2)
  {
    b = 4;
    goto y;
  }
  else if (t.hour < OnHour2 || t.hour > OffHour2) b = 5;

y:
  //----------------------------------------------------------
  if (b == 1)
  {
    R1on();
  }
  //----------------------------------------------------------
  else if (b == 2)
  {
    if (t.min >= OnMin2 && t.min < OffMin2)
    {
      R1on();
    }
//    else R1off();
  }
  //----------------------------------------------------------
  else if (b == 3)
  {
    if (t.min >= OnMin2)
    {
      R1on();
    }
//    else R1off();
  }
  //----------------------------------------------------------
  else if (b == 4)
  {
    if (t.min < OffMin2)
    {
      R1on();
    }
//    else R1off();
  }
  //----------------------------------------------------------
  else if (b == 5)
  {
    R1off();
  }
  //----------------------------------------------------------
//  else R1off();









  

  if (t.hour > OnHour1 && t.hour < OffHour1)      a = 1;

  else if (OnHour1 == t.hour && OffHour1 == t.hour)
  {
    a = 2;
    goto x;
  }
  else if (t.hour == OnHour1)
  {
    a = 3;
    goto x;
  }
  else if (t.hour == OffHour1)
  {
    a = 4;
    goto x;
  }
  else if (t.hour < OnHour1 || t.hour > OffHour1) a = 5;

x:
  //----------------------------------------------------------
  if (a == 1)
  {
    R1on();
  }
  //----------------------------------------------------------
  else if (a == 2)
  {
    if (t.min >= OnMin1 && t.min < OffMin1)
    {
      R1on();
    }
    else R1off();
  }
  //----------------------------------------------------------
  else if (a == 3)
  {
    if (t.min >= OnMin1)
    {
      R1on();
    }
    else R1off();
  }
  //----------------------------------------------------------
  else if (a == 4)
  {
    if (t.min < OffMin1)
    {
      R1on();
    }
    else R1off();
  }
  //----------------------------------------------------------
  else if (a == 5)
  {
    R1off();
  }
  //----------------------------------------------------------
//  else R1off();
}


//
//
//void relay1()
//{
//  if (t.hour > OnHour1 && t.hour < OffHour1)
//  {
//    R1on();
//  }
//  else if (t.hour == OnHour1)
//  {
//    if (t.min >= OnMin1 && t.min < OffMin1)
//    {
//      R1on();
//    }
//    else //if (t.min >= OffMin1)
//    {
//      R1off();
//    }
//  }
//  else if (t.hour == OffHour1)
//  {
//    if (t.min <= OffMin1)
//    {
//      R1on();
//    }
//    else
//    {
//      R1off();
//    }
//  }




//
//  if (t.hour > OnHour2 && t.hour < OffHour2)
//  {
//    R1on();
//  }
//  else if (t.hour == OnHour2)
//  {
//    if (t.min >= OnMin2 && t.min < OffMin2)
//    {
//      R1on();
//    }
//    else //if (t.min <= OffMin1)
//    {
//      R1off();
//    }
//  }
//  else if (t.hour == OffHour2)
//  {
//    if (t.min <= OffMin2)
//    {
//      R1on();
//    }
//    else
//    {
//      R1off();
//    }
//  }
//}




void hrchk()
{
  if (t.hour >= OnHour1 && t.hour < OffHour1)
  {
    R1on();
  }



  else if (t.hour >= OnHour2 && t.hour < OffHour2)
  {
    R1on();
  }

  else
  {
    R1off();
  }
}



/*
  //set time   upload 10 seconds before set time
  // DS3231_Serial_Easy
  // Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
  // web: http://www.RinkyDinkElectronics.com/
  //
  // A quick demo of how to use my DS3231-library to
  // quickly send time and date information over a serial link
  //
  // To use the hardware I2C (TWI) interface of the Arduino you must connect
  // the pins as follows:
  //
  // Arduino Uno/2009:
  // ----------------------
  // DS3231:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
  //          SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
  //
  // Arduino Leonardo:
  // ----------------------
  // DS3231:  SDA pin   -> Arduino Digital 2 or the dedicated SDA pin
  //          SCL pin   -> Arduino Digital 3 or the dedicated SCL pin
  //
  // Arduino Mega:
  // ----------------------
  // DS3231:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA pin
  //          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL pin
  //
  // Arduino Due:
  // ----------------------
  // DS3231:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA1 (Digital 70) pin
  //          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL1 (Digital 71) pin
  //
  // The internal pull-up resistors will be activated when using the
  // hardware I2C interfaces.
  //
  // You can connect the DS3231 to any available pin but if you use any
  // other than what is described above the library will fall back to
  // a software-based, TWI-like protocol which will require exclusive access
  // to the pins used, and you will also have to use appropriate, external
  // pull-up resistors on the data and clock signals.
  //

  #include <DS3231.h>

  // Init the DS3231 using the hardware interface
  DS3231  rtc(SDA, SCL);

  void setup()
  {
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}

  // Initialize the rtc object
  rtc.begin();

  // The following lines can be uncommented to set the date and time
  rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(11, 44, 00);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(9, 2, 2018);   // Set the date to January 1st, 2014
  }

  void loop()
  {
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");

  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());

  // Wait one second before repeating :)
  delay (1000);
  }*/
