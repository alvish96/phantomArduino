#include <DS3231.h> //rtc library 
DS3231  rtc(SDA, SCL);
Time t;
//------------------------------------------------------------------------
#include <Servo.h>

#define MAX_SIGNAL 2000
#define MIN_SIGNAL 1000
#define MOTOR_PIN 9
Servo motor;

//------------------------------------------------------------------------
#include "DHT.h"//DHT sensor Library
#define DHTPIN 12 //Define sensor pin(pin 12)
#define DHTTYPE DHT11 //What sensor use
DHT dht(DHTPIN, DHTTYPE);//Create sensor object

//------------------------------------------------------------------------
#include <LiquidCrystal.h>//LCD Library 

const int rs = 22, en = 23, d4 = 28, d5 = 29, d6 = 30, d7 = 31;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//------------------------------------------------------------------------
// Include the GSM library
//#include <GSM.h>
// initialize the library instance
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);


//------------------------------------------------------------------------
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4; //sd pin select
//------------------------------------------------------------------------
const int swon = 1;
const int swoff = 0;

int tempval;
int humidval;
int templowlimit=20;
int temphighlimit=28;
int humidlowlimit=83;
int humidhighlimit=88;
const int heatsw = 6;
const int humidsw = 7;
//------------------------------------------------------------------------

// make a string for assembling the data to log:
String dataString = "";

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void setup()
{ dht.begin();

  mySerial.begin(9600);   // Setting the baud rate of GSM Module
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)


  Serial.println("GSM initialized");
  delay(100);

  pinMode(heatsw, OUTPUT);
  pinMode(humidsw, OUTPUT);
  digitalWrite(heatsw, swoff);
  digitalWrite(humidsw, swoff);


  motor.writeMicroseconds(MIN_SIGNAL);



  rtc.begin();
  //---------------------------------------------------------------------------------------------------
  lcd.begin(16, 2);

  //---------------------------------------------------------------------------------------------------
  Serial.print("Initializing SD card...");  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present"); // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  //---------------------------------------------------------------------------------------------------
}


//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void loop() {
  valacquire();
  mainprog();
  sd();//calling sd function

}
void valacquire()
{
  humidval = dht.readHumidity();//humidity value
  tempval = dht.readTemperature();//temperature value
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void sd()
{

  int sensor = analogRead(DHTPIN);
  dataString += String(sensor);
  dataString += " , ";

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void period()
{
  t = rtc.getTime();
}

void mainprog()
{


  if (tempval < templowlimit)
  {
    increasetemp();
    alerttemp();
  }
  else if (tempval > temphighlimit)
  {
    decreasetemp();
    alerttemp();
  }
  if (humidval < humidlowlimit)
  {
    increasehumid();
    alerthumid();
  }
  else if (humidval > humidhighlimit)
  {
    decreasehumid();
    alerthumid();
  }

  if (tempval > templowlimit)
  {
    digitalWrite(heatsw, swoff);
    //  turnoff heater
  }
  if (tempval < temphighlimit)
  {
    motor.writeMicroseconds(MIN_SIGNAL);
    //turn off fan
  }
  if (humidval > humidlowlimit)
  {
    digitalWrite(humidsw, swoff);
    //  turnoff humidifier
  }
  if (humidval < humidhighlimit)
  {
    digitalWrite(humidsw, swoff);
    //  turnoff humidifier
  }
  else if (tempval > templowlimit && tempval < temphighlimit && humidval > humidlowlimit && humidval < humidhighlimit)
  {
    donothing();
    //turn off everything
  }

}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void donothing()
{
  digitalWrite(heatsw, swoff);
  //  turnoff heater
  motor.writeMicroseconds(MIN_SIGNAL);
  //turn off fan
  digitalWrite(humidsw, swoff);
  //  turnoff humidifier
}


//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void increasetemp()
{
  //turn on heater switch relay
  digitalWrite(heatsw, swon);
}

void decreasetemp()
{
  //turn on fan
  motor.writeMicroseconds(MAX_SIGNAL);
}
void decreasehumid()
{
  //turn on heater switch relay
  digitalWrite(heatsw, swon);
  //turn on fan
  motor.writeMicroseconds(MAX_SIGNAL);
}

void increasehumid()
{
  //turn on humidifier switch relay
  digitalWrite(humidsw, swon);
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

void alerttemp()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 100 milli seconds
  mySerial.println("AT+CMGS=\"+xxxxxxxxxxx\"\r"); // Replace x with mobile number
  delay(100);
  mySerial.println("ALERT !!! CONTROLLING TEMPERATURE ");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


void alerthumid()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 100 milli seconds
  mySerial.println("AT+CMGS=\"+xxxxxxxxxxx\"\r"); // Replace x with mobile number
  delay(100);
  mySerial.println("ALERT !!! CONTROLLING HUMIDITY ");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
