
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
#include "DHT.h"
 
#define DHTPIN 12     // what pin we're connected to
 
//Uncomment whatever the type of sensor we are using. 
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
 
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is 
// pin3 of the sensor is not connected
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
// NOTE: For working with a faster chip, like an Arduino Due or Teensy, you
// might need to increase the threshold for cycle counts considered a 1 or 0.
// You can do this by passing a 3rd parameter for this threshold.  It's a bit
// of fiddling to find the right value, but in general the faster the CPU the
// higher the value.  The default for a 16mhz AVR is a value of 6.  For an
// Arduino Due that runs at 84mhz a value of 30 works.
// Example to initialize DHT sensor for Arduino Due:
//DHT dht(DHTPIN, DHTTYPE, 30);
 
boolean tflag = false; // temperature flag. 
// this flag will be used to stop unnecessary repetition of code. 
int relay = 13; 
 
void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!");
 
  dht.begin();
  pinMode(relay, OUTPUT); 
  digitalWrite(relay, LOW); 
}
 /*
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
 
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit
  int f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  // Compute heat index
  // Must send in temp in Fahrenheit!
  int hi = dht.computeHeatIndex(f, h);
 
if ( (t > 32 ) && ( tflag == false ) )
{
 digitalWrite(relay, HIGH); 
 Serial.println("Fan is On");
tflag = true;  
}
 
if ( (t <= 32 ) && ( tflag == true ) )
{
 digitalWrite(relay, LOW); 
  Serial.println("Fan is Off");
tflag = false;  
}
 
Serial.print("Temperature: "); 
Serial.println(t);
}*/
