#include <DS3231.h>

DS3231  rtc(SDA, SCL);
Time t;

int R1 = 32;
int R2 = 7;


const int OnHour1 = 02;
const int OnMin1 = 7;
const int OffHour1 = 02;
const int OffMin1 = 8;

const int OnHour2 = 02;
const int OnMin2 = 9;
const int OffHour2 = 02;
const int OffMin2 = 10;
bool f = 0;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(R1, OUTPUT);
  digitalWrite(R1, 0);

  pinMode(R2, OUTPUT);
  digitalWrite(R2, 1);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" :: ");
  Serial.print(t.min);
  Serial.print(" :: ");
  Serial.print(t.sec);
  Serial.println();
  delay (1000);
  relay1();

}


void R1on()
{
  digitalWrite(R1, 1);
  Serial.println("\t relay1 on");
}
void R2on()
{
  digitalWrite(R2, LOW);
  Serial.println("\t relay2 on");
}

void R1off()
{
  digitalWrite(R1, 0);
  Serial.println("\t relay1 off");
}
void R2off()
{
  digitalWrite(R2, 1);
  Serial.println("\t relay2 off");
}



void relay1()
{

  f = 0;
  if (t.hour > OnHour1 && t.hour < OffHour1)
    R1on();

  if (OnHour1 == OffHour1 && OnHour1 == t.hour)
  {
    if (t.min >= OnMin1 && t.min < OffMin1)
      R1on();
    else R1off();
  }

  else if (t.hour == OnHour1)
  {
    if (t.min >= OnMin1 && t.min < OffMin1)
      R1on();
    else R1off();
  }
  else if (t.hour == OffHour1)
  {
    if (t.min < OffMin1)
      R1on();
    else   R1off();
  }
  else R1off();



  Serial.println("\t seperation");

  if (OnHour1 == OnHour2 &&t.hour==OnHour1)    //|| OffHour1==OffHour2)
  {
    if (OffMin1 < OnMin2 && t.min < OnMin2)
    {
      f = 1;
      goto x;
    }
  }

  if (t.hour > OnHour2 && t.hour < OffHour2)
    R1on();

  if (OnHour2 == OffHour2 && OnHour2 == t.hour)
  {
    if (t.min >= OnMin2 && t.min < OffMin2)
      R1on(); else R1off();
  }

  else if (t.hour == OnHour2)
  {
    if (t.min >= OnMin2 && t.min < OffMin2)
      R1on();
    else R1off();
  }
  else if (t.hour == OffHour2)
  {
    if (t.min < OffMin2)
      R1on();
    else   R1off();
  }
  else R1off();

x:
  if ( f==1)
  Serial.println("\t jump executed");

}



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
