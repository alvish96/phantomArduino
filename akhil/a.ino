
//#include <LiquidCrystal.h>
//int sensorValue;
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//void setup(){  lcd.begin(16, 2);
//Serial.begin(9600);                            // sets the serial port to 9600
// }
//void loop()
//
//
//{
//  sensorValue = analogRead(0);       // read analog input pin 0
//Serial.print("AirQua=");
//Serial.print(sensorValue, DEC);               // prints the value read
//Serial.println(" PPM");
//lcd.setCursor(0,0);
//lcd.print("ArQ=");
//lcd.print(sensorValue,DEC);
//lcd.print(" PPM");
//lcd.println("       "); 
//lcd.print("  ");
//delay(100);                                   // wait 100ms for next reading
//}
//
//float temp;
//int tempPin = 0;
//
//void setup() {
//   Serial.begin(9600);
//}
//
//void loop() {
//   temp = analogRead(tempPin);
//   // read analog volt from sensor and save to variable temp
//   temp = temp * 0.48828125;
//   // convert the analog volt to its temperature equivalent
//   Serial.print("TEMPERATURE = ");
//   Serial.print(temp); // display temperature value
//   Serial.print("*C");
//   Serial.println();
//   delay(1000); // update sensor reading each one second
//}
