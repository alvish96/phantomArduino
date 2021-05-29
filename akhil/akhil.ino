#include <dht.h>

#define DETECT 2 // pin 2 for  sensor
int sensorValue;
float temp;
int tempPin = 2;

int tch = 3;

int ldrval;
#define DHT11_PIN 4



void setup() {
  Serial.begin(9600);
  sensorValue = analogRead(0);       // read analog input pin 0
  pinMode(DETECT, INPUT);//define detect input pin
  //  pinMode(ACTION, OUTPUT);//define ACTION output pin

}


void loop()
{
  gas();                //A0 analog pin
  hall();               //d2 digital pin
  temper();             //A2 analog pin
  brightness();         //A3analog pin
  touch();              //d3 digital pin
  humid();              //d4 digital pin

}

void humid() {
  dht DHT;
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(100);

}

void hall()
{
  int detected = digitalRead(DETECT);// read Hall sensor

  if ( detected == LOW)
  {
    //    digitalWrite(ACTION,LOW);
    Serial.println(HIGH);
    Serial.println("\tMAGNETIC FIELD DETECTED!");


  }
  else
  {
    //    digitalWrite(ACTION,HIGH);
    Serial.println(LOW);
    Serial.println("\tMAGNETIC FIELD NOT DETECTED");

  }
  delay(10);
}

void touch() {
  if (digitalRead(tch) == HIGH)
    Serial.println("Sensor is touched");

}

void gas()
{
  Serial.print("\t\tAirQuality in PPM = ");
  Serial.println(sensorValue, DEC);               // prints the value read
  //  Serial.println(" PPM");
  //  Serial.println();


  delay(100);                                 // wait 100ms for next reading
}


void temper()
{
  temp = analogRead(tempPin);
  // read analog volt from sensor and save to variable temp
  temp = temp * 0.48828125;
  // convert the analog volt to its temperature equivalent
  Serial.print("TEMPERATURE = ");
  Serial.print(temp); // display temperature value
  Serial.print("*C");
  Serial.println();
  delay(1000); // update sensor reading each one second
}


void brightness() {
  ldrval = analogRead(A4);
  Serial.println(ldrval);
  delay(100);
}
