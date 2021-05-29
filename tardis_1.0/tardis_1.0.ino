
/*1.1
  tardis 1.0
*/

const int num = 12;
bool databool0[30];   //flags     248
bool databool1[num];  //state     249
bool databool2[num];  //timerflag 250
bool databool3[num];  //relaytype 251
bool databool4[num];  //prtemp    252

byte databyte0[20]; //byte data   246
byte databyte1[num];//hour        240
byte databyte2[num];//minute      241
byte databyte3[num];//second      242

byte databyte4[10];//hr           243
byte databyte5[10];//min          244
byte databyte6[10];//sec          245

//--------------------
float duration, dist;
#define trig 35
#define echo 34
//-------------------

const int r = 4;
#define g 3
const int b = 2;
#define ledvcc 31
bool ledf = 0;
byte inten = 200;
byte rinten, binten, ginten;
int maxx = 255;
int minn = 0;
int del = 10;
int secc = 1000 / 3;
//-------------------

bool segm = 0;
#define segA 25//connecting segment A to PIN2
#define segB 27// connecting segment B to PIN3
#define segC 22// connecting segment C to PIN4
#define segD 23// connecting segment D to PIN5
#define segE 26// connecting segment E to PIN6
#define segF 24// connecting segment F to PIN7
#define segG 28// connecting segment G to PIN8
int COUNT = 0; //count integer for 0-9 increment

//--------------------
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Time.h>
#include <DS1307RTC.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
bool oled = 1;

#include <DS3231.h>
DS3231  rtc(SDA, SCL);
//--------------------


#include <SD.h>
File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno 53 MEGA

//--------------------
#define irpin 5
#include<IRremote.h>
IRrecv ir(irpin);
decode_results irresult;

//--------------------
int i = 0;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(115200);
  //-----------------------
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //-----------------------
  pinMode(ledvcc, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  analogWrite(r, maxx);
  analogWrite(g, maxx);
  analogWrite(b, maxx);
  digitalWrite(ledvcc, 1);
  //-----------------------
  for (int i = 22; i < 29; i++)
  {
    pinMode(i, OUTPUT);// taking all pins from 2-8 as output
    digitalWrite(i, 1 ); // taking all pins from 2-8 as output
  }

  //------------------

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  //display.display();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  //--------------------
  rtc.begin();
  pinMode(pinCS, OUTPUT);
  //--------------------
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }

  //--------------------

  ir.enableIRIn();
  //--------------------

  //  setall();
  //initial conditions----------------
  segm = 0;
}

void loop()
{
//    timex1();
    remote();
  //    receive();
      seg();
  //    col();
//  cwl();
  //  save();
  //  timeprint();

  //  a1();
  //  a2();
  //  delay(100);

}
