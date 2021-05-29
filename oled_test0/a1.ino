#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);


struct MyData {
  byte throttle;
  byte yaw;
  byte pitch;
  byte roll;
  byte AUX1;
  byte AUX2;
};



MyData data;

void setup() {
  Serial.begin(9600);

  //  Serial.println("OLED FeatherWing test");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  //  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  //  display.display();
  //  delay(1000);

  // Clear the buffer.
  display.setCursor(0, 0);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Type something");
  display.display();

  //  Serial.println("IO test");

  //
  //  // text display tests
  //  display.setTextSize(1);
  //  display.setTextColor(WHITE);
  //  display.setCursor(0,0);
  String s;//="ntialized with an Adafruit splashscreen";
  //  display.println(s);
  ////  display.setTextSize(0);
  ////  display.println("connected!");
  ////  display.println("IP: 10.0.1.23");
  ////  display.println("Sending val #0");
  //  display.setCursor(0,0);
  //  display.display(); // actually display all of the above
  //  display.startscrollleft(0x00, 0x0F);
  //  delay(3000);
}




int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse)
{
  val = constrain(val, lower, upper);
  if ( val < middle )
    val = map(val, lower, middle, 0, 128);
  else
    val = map(val, middle, upper, 128, 255);
  return ( reverse ? 255 - val : val );
}

void p(){
  data.throttle = mapJoystickValues( analogRead(A0), 13, 524, 1015, true );//y
  data.yaw      = mapJoystickValues( analogRead(A1),  1, 505, 1020, true );//x
display.clearDisplay();
Serial.println(data.throttle);
Serial.println(data.yaw);
display.setCursor(0, 0);
display.print(data.throttle);
display.setCursor(30, 0);
display.print(data.yaw);
display.display();
}

void loop() {
  p();
  display.setCursor(0, 0);
  String s;
  int i = 3;
  // when characters arrive over the serial port...
      
  if (Serial.available())
  {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    display.clearDisplay();
    
    // read all the available characters
    display.print("me: ");
    while (Serial.available() > 0)
    {
      // display each character to the LCDa
      char c = Serial.read();

      display.print(c);

      display.setTextSize(1);
      display.setTextColor(WHITE);
      if (i > 128) {
        c++;
      }
      //      if(c==0)
      //      {
      //      display.setCursor(i, 0);
      //      i += 6;
      //     }
      //      if (c==1)
      //      {
      //        i=0;
      //      display.setCursor(i, 6);
      //      i += 6;
      //
      //      }
      display.display();
      delay(80);
    }
    delay(2000);

    //    display.startscrollleft(0x00, 0x0A);
    display.clearDisplay();

  }
  //   yield();
}
