///////////////////////////////////////////
// RTC data and time setter              //
//                                       //
// This sample program allows the user   //
// to set the date and time of an DS3231 //
// using I2C.                            //
//                                       //
// Code by LsHallo                       //
// January 26, 2017                      //
// Java based and able to set            //
// seconds accurately.                   //
///////////////////////////////////////////

#include <Wire.h>
#include <DS3232RTC.h>
#include <Time.h>
#include <TimeLib.h>

#define delayTime 100

//The "S" before every variable is to avoid interference with the libraries Time and TimeLib
byte Ssecond = 0;
byte Sminute = 0;
byte Shour = 0;
byte Smonthday = 0;
byte Smonth = 0;
byte Syear = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  if(setTimeDS() == 1) {
    Serial.print("\n------------------------------\nTime set succesfully!\n");
    Serial.print(F("Time after time set: "));
    printTimeLib();
    
    Serial.println(F("Time set finished\n------------------------------"));
    delay(delayTime);
  } else {
    Serial.println(F("Time set process skipped"));
  }
  Serial.print(F("Code will now print time every 5 seconds..."));
  delay(delayTime);
  Serial.print("\n");
}

void loop() {
  delay(5000);
  Serial.println(F("CALLTIME"));
  Serial.print(F("Time on Ard.: "));
  printTimeLib();
  Serial.println(F("------------------------------"));
}

int setTimeDS() {
  Serial.println(F("Skip time set(Y/N)?"));
  unsigned char runs = 0;
  while(!Serial.available() && runs < 255) {delay(10); runs++;}
  if(runs >= 80 || Serial.read() != 'N') {
    Serial.println(F("Skipping time set process..."));
    return 0;
  }

  //Serial.println("TIME BEFORE: ");
  //printTimeLib();

  delay(25);
  
  Serial.println(F("YEAR"));
  while(!Serial.available()) delay(10);
  Syear = Serial.read();
  Serial.print(F("Year: "));
  Serial.println(Syear);

  //Security delay
  delay(delayTime);
  
  Serial.println(F("MONTH"));
  while(!Serial.available()) delay(10);
  Smonth = Serial.read();
  Serial.print(F("Month: "));
  Serial.println(Smonth);

  //Security delay
  delay(delayTime);
  
  Serial.println(F("MONTHDAY"));
  while(!Serial.available()) delay(10);
  Smonthday = Serial.read();
  Serial.print(F("Day: "));
  Serial.println(Smonthday);

  //Security delay
  delay(delayTime);
  
  Serial.println(F("HOUR"));
  while(!Serial.available()) delay(10);
  Shour = Serial.read();
  Serial.print(F("Hour: "));
  Serial.println(Shour);

  //Security delay
  delay(delayTime);
  
  Serial.println(F("MINUTE"));
  while(!Serial.available()) delay(10);
  Sminute = Serial.read();
  Serial.print(F("Minute: "));
  Serial.println(Sminute);

  //Security delay
  delay(delayTime);
  
  Serial.println(F("SECOND"));
  while(!Serial.available()) delay(10);
  Ssecond = Serial.read();
  Serial.print(F("Second: "));
  Serial.println(Ssecond);
  Serial.println(F(" "));

  setTime(Shour, Sminute, Ssecond, Smonthday, Smonth, Syear);
  RTC.set(now());
  Serial.print(F("Setting time to: "));
  printTimeLib();
  return 1;
}

void printTimeLib() {
  time_t tm = RTC.get();
  setTime(tm);
  
  leadingZero(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  leadingZero(day());
  Serial.print("-");
  leadingZero(month());
  Serial.print("-");
  Serial.println(year());
}

//Following two methods from: http://playground.arduino.cc/Code/time
void digitalClockDisplay(){
  //digital clock display of the time
  Serial.print(hour());
  Serial.print(":");
  if(minute() < 10) {
    Serial.print('0');
  }
  Serial.print(minute());
  if(second() < 10) {
    Serial.print('0');
  }
  Serial.print(":");
  Serial.print(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print("-");
  Serial.print(month());
  Serial.print("-");
  Serial.println(year()); 
}

void printDigits(int digits){
  //utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void leadingZero(int number) {
  if(number < 10) {
    Serial.print('0');
  }
  Serial.print(number);
}

