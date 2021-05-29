//#include <SPI.h>
//#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
//
//Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
//
//void setup() {
//  Serial.begin(9600);
//
//  //  Serial.println("OLED FeatherWing test");
//  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
//
//  //  Serial.println("OLED begun");
//
//  // Show image buffer on the display hardware.
//  // Since the buffer is intialized with an Adafruit splashscreen
//  // internally, this will display the splashscreen.
//  //  display.display();
//  //  delay(1000);
//
//  // Clear the buffer.
//  display.clearDisplay();
//  display.display();
//
//  //  Serial.println("IO test");
//
//  //
//  //  // text display tests
//  //  display.setTextSize(1);
//  //  display.setTextColor(WHITE);
//  //  display.setCursor(0,0);
//  String s;//="ntialized with an Adafruit splashscreen";
//  //  display.println(s);
//  ////  display.setTextSize(0);
//  ////  display.println("connected!");
//  ////  display.println("IP: 10.0.1.23");
//  ////  display.println("Sending val #0");
//  //  display.setCursor(0,0);
//  //  display.display(); // actually display all of the above
//  //  display.startscrollleft(0x00, 0x0F);
//  //  delay(3000);
//}
//
//void loop() { 
//  display.setCursor(0, 0);
////  String s;
//  int i = 0;
//  // when characters arrive over the serial port...
//  if (Serial.available())
//  {
//   
//    display.clearDisplay();
//    // read all the available characters
//    while (Serial.available() > 0)
//    {
//      // display each character to the LCDa
// char c[50];
// for(i=0;i<50;i++)
// c[i]= Serial.read();
//      display.print(c);
//
//      display.setTextSize(1);
//      display.setTextColor(WHITE);
//
////      c[i]++;
//
////      if(c==0)
////      {
////      display.setCursor(i, 0);
////      i += 6;
////     }
////      if (c==1)
////      {
////        i=0;
////      display.setCursor(i, 6);
////      i += 6;
////        
////      }
//      display.display();
//      delay(10);
//    }
////     display.startscrollright(0x00, 0x0F);
////     delay(1000);
//    display.clearDisplay();
//   
//  }
//   yield();
//}
