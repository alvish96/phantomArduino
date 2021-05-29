// Basic Bluetooth test sketch 5b for the Arduino Mega. 
// simple communication with an Android device
//
// Uses serial with the host computer and Serial2 for communication with the Bluetooth module
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
 
char c = '0';
 
void setup() 
{
    // communication with the host computer
    Serial.begin(115200);  
 
    Serial.println("Do not power the BT module");
 
    // communication with the BT module on Serial2
    Serial2.begin(38400);
 
 
 
    Serial.println(" ");
    Serial.println("HC-05 started at 115200");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("Do not enter AT mode");
    Serial.println(""); 
}
 
 
void loop() 
{
    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial2.available() )   
    {  
         c = Serial2.read();
         Serial2.print(c);
         Serial.write( c ); 
    }
         Serial.println(); 
          Serial2.println();
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   
   { 
         c = Serial.read();
         Serial.print(c);
         Serial2.write( c ); 

   }
         Serial.println(); 
          Serial2.println();
}
