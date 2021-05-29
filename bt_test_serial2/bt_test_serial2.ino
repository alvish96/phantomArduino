// Basic Bluetooth test sketch 5b for the Arduino Mega. 
// simple communication with an Android device
//
// Uses serial with the host computer and serial1 for communication with the Bluetooth module
//
//  Pins
//  BT VCC to Arduino 5V out. Disconnect before running the sketch
//  BT GND to Arduino GND
//  BT RX (through a voltage divider) to Arduino TX1 (pin 18)
//  BT TX  to Arduino RX1 (no need voltage divider)   (pin 19)
//
// When text is entered in to the serial monitor on the computer the
// Arduino will relay it to the Bluetooth module.
// When text is entered in to a Bluetooth terminal on the Android device 
// it will be sent to the Arduino and be displayed in the serial monitor
//
 #include<string.h>
String s;
 
void setup() 
{
    // communication with the host computer
    Serial.begin(115200);  
 
    Serial.println("Do not power the BT module");
 
    // communication with the BT module on serial1
    Serial2.begin(38400);
 
 
 
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println(""); 
}
 
 
void loop() 
{
    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial2.available() )   
    {  {s="";}
    
         s = ((byte)Serial2.read());
         (byte)Serial.write(s); 
         Serial2.print(s);
    
 Serial.println();
 Serial2.println();
    }
 
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   
   { 
         s = ((byte)Serial.read());
         (byte)Serial.write(s); 
         Serial2.write( s ); 
         Serial.print(s);
 
 Serial.println();
 Serial2.println();
   
   }
 
 
}
