//arduino voltmeter

/**
  Copy the following code into the Arduino IDE. Compile and run it.
**/




/*


   input to 100k
   middle to A0
   10k to ground
   both grounds must be connected



*/















float vPow = 4.7;    //amount of power supple into arduino. Should be 5V, but through USB cable usually less than 5
float r1 = 98600;  //1000 kOhm resistor [change this if used a different resistor value]
float r2 = 9600;   //10 kOhm resister [change this if used a different resistor value]<br>

void setup() {
  Serial.begin(9600);    //speed = 9600

  // Send ANSI terminal codes
  Serial.print("\x1B");
  Serial.print("[2J");
  Serial.print("\x1B");
  Serial.println("[H");
  // End ANSI terminal codes

  Serial.println("--------------------");
  Serial.println("DC VOLTMETER");
  Serial.print("Maximum Voltage: ");
  Serial.print((int)(vPow / (r2 / (r1 + r2))));
  Serial.println("V");
  Serial.println("--------------------");
  Serial.println("");

  delay(2000);   //wait 2000 ms before starting
}

void loop() {
  float v = (analogRead(7) * vPow) / 1024.0;   //when reading analog values, divide by 1024
  float v2 = v / (r2 / (r1 + r2));

  // Send ANSI terminal codes
  Serial.print("\x1B");
  // End ANSI terminal codesr</p><p>   Serial.print("Voltage (Volts) = ");
  Serial.println(v2);


}







































/*
   int analogInput = 1;
  float Vout = 0.00;
  float Vin = 0.00;
  float R1 = 100000.00; // resistance of R1 (100K)
  float R2 = 10000.00; // resistance of R2 (10K)
  int val = 0;
  void setup(){
   pinMode(analogInput, INPUT); //assigning the input port
   Serial.begin(9600); //BaudRate
  }
  void loop(){

   val = analogRead(analogInput);//reads the analog input
   Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out i.e. V+, here 5.00
   Vin = Vout / (R2/(R1+R2)); // formula for calculating voltage in i.e. GND
   if (Vin<0.09)//condition
   {
     Vin=0.00;//statement to quash undesired reading !
  }
  Serial.print("\t Voltage of the given source = ");
  Serial.print(Vin);
  delay(1000); //for maintaining the speed of the output in serial moniter
  }





*/
































/*#include <LiquidCrystal.h>   // LIBRARY TO ACCESS THE LCD DISPLAY
  LiquidCrystal lcd( 4, 5, 6, 7,8 ,9 );
  float input_volt = 0.0;
  float temp=0.0;
  float r1=9600.0;    //r1 value
  float r2=98600.0;      //r2 value

  void setup()
  {
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
   lcd.begin(16, 2);       //// set up the LCD's number of columns and rows
   lcd.print("DC DIGI VOLTMETER");
  }

  void loop()
  {
    int analogvalue = analogRead(A0);
    temp = (analogvalue * 5.0) / 1024.0;       // FORMULA USED TO CONVERT THE VOLTAGE
    input_volt = temp / (r2/(r1+r2));
  if (input_volt < 0.1)
   {
     input_volt=0.0;
   }
    Serial.print("v= ");                 // prints the voltage value in the serial monitor
    Serial.println(input_volt);
    lcd.setCursor(0, 1);
    lcd.print("Voltage= ");               // prints the voltage value in the LCD display
    lcd.print(input_volt);
    delay(300);
  }

*/




















/*
  DC Voltmeter
  An Arduino DVM based on voltage divider concept
  T.K.Hareendran
  /
  //#include
  //6LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
  #define analogInput A0
  float vout = 0.0;
  float vin = 0.0;
  float R1 = 98600.0; // resistance of R1 (100K) -see text!
  float R2 = 9600.0; // resistance of R2 (10K) - see text!
  int value = 0;
  void setup(){
   pinMode(analogInput, INPUT);
  //   lcd.begin(16, 2);
   Serial.begin(9600);
   Serial.print("DC VOLTMETER");
  }
  void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // see text
   vin = vout / (R2/(R1+R2));
   if (vin<0.09) {
   vin=0.0;//statement to quash undesired reading !
  }
  //Serial.setCursor(0, 1);
  Serial.print("INPUT V= ");
  Serial.println(vin);
  delay(500);
  }
*/
