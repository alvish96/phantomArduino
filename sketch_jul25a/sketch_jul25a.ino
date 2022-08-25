#include <SoftwareSerial.h>
SoftwareSerial s(9,10);

#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int Voltage_Sensor = A5;
int Temp_Sensor = A1;

#include <dht.h>  
#define outPin 8
dht DHT; 

const int analogchannel = A0; //Connect current sensor with A0 of Arduino
int sensitivity = 180; // use 100 for 20A Module and 66 for 30A Module
int adcvalue= 0;
int offsetvoltage = 2500; 
double Voltage = 0; //voltage measuring
double ecurrent = 0;// Current measuring

void setup() {
    
    lcd.begin(16, 2);
    
    s.begin(115200);
    Serial.begin(9600);
    
    pinMode(Voltage_Sensor, INPUT);
    pinMode(Temp_Sensor, INPUT);
    pinMode(analogchannel, INPUT);

    pinMode(16, INPUT);
    pinMode(18, OUTPUT);
digitalWrite(18, HIGH);

delay(2000);
}

void loop() {


//**********************************************************************************************
    float T_Value=0.0,Samples_t=0.0;
  for (int y = 0; y < 150; y++){ 
  float T_Value=analogRead(Temp_Sensor);
  Samples_t = Samples_t + T_Value;  
  delay (3);
  }
  T_Value=Samples_t/150.0;
  T_Value=(T_Value*500)/1023;
  
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Temperature");
    lcd.setCursor(4, 1);
    lcd.print(T_Value);
    lcd.print(" C");
    
     int Virtual_A = T_Value;
     String Data_a = "A";
     String stringOne =  Data_a + Virtual_A;
     stringOne = stringOne + 'N';
     s.print(stringOne);

     if(T_Value > 39){
      digitalWrite(18, LOW);
      digitalWrite(11, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.print(T_Value);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Over Heat Fault");
      while(1);
      }

      
      

//**********************************************************************************************
     delay(2000);
//**********************************************************************************************
    int Volt_Value = analogRead(Voltage_Sensor);
    float Cal_Volt_Value = Volt_Value / 36.2;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Voltage");
    lcd.setCursor(5, 1);
    lcd.print(Cal_Volt_Value);
     
    int Virtual_B = Cal_Volt_Value;
     String Data_b = "B";
     String stringTwo =  Data_b + Virtual_B;
     stringTwo = stringTwo + 'N';
     s.print(stringTwo);

     if(Cal_Volt_Value > 13){
      digitalWrite(18, LOW);
      digitalWrite(11, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage ");
    lcd.print(Cal_Volt_Value);
    lcd.setCursor(0, 1);
    lcd.print("Over V Fault");
      while(1);
      }
       if(Cal_Volt_Value < 5){
       digitalWrite(18, LOW);
      digitalWrite(11, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voltage ");
    lcd.print(Cal_Volt_Value);
    lcd.setCursor(0, 1);
    lcd.print("Under V Fault");
      while(1);
      }

//**********************************************************************************************
    delay(2000);
//**********************************************************************************************
float T2_Value=0.0,Samples_t2=0.0;
  for (int y = 0; y < 350; y++){ 
adcvalue = analogRead(analogchannel);//reading the value from the analog pin
 Voltage = (adcvalue / 1024.0) * 5000; // Gets you mV
 ecurrent = ((Voltage - offsetvoltage) / sensitivity);
  Samples_t2 = Samples_t2 + ecurrent;
  }


T2_Value=Samples_t2/350.0;

 ecurrent = T2_Value*1000;


  
if(digitalRead(16) == HIGH){
  ecurrent = ecurrent*3;
  }
  
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("    Current    ");
 lcd.setCursor(4,1);
 lcd.print(ecurrent,3);
 lcd.print(" mA"); //unit for the current to be measured


  
      int Virtual_C = ecurrent;
     String Data_c = "C";
     String stringThree =  Data_c + Virtual_C;
     stringThree = stringThree + 'N';
     s.print(stringThree);


  
if(ecurrent > 100){
          digitalWrite(18, LOW);
      digitalWrite(11, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Current ");
    lcd.print(ecurrent);
    lcd.print(" mA");
    lcd.setCursor(0, 1);
    lcd.print("Over Load Fault");
      while(1);
      }
     
 
//**********************************************************************************************
    delay(2000);
//**********************************************************************************************
    int readData = DHT.read11(outPin);
    int h = DHT.humidity;   
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Humidity");
    lcd.setCursor(6, 1);
    lcd.print(h);
    lcd.print(" %");

    int Virtual_D = h;
     String Data_d = "D";
     String stringFour =  Data_d + Virtual_D;
     stringFour = stringFour + 'N';
     s.print(stringFour);

    if(h > 80){
           digitalWrite(18, LOW);
      digitalWrite(11, HIGH);
       lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity = ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1);
    lcd.print("Over Humidity Fault");
      while(1);
      }

    
//**********************************************************************************************
    delay(2000);
//**********************************************************************************************
 
}
