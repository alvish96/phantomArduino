#include <SoftwareSerial.h>
SoftwareSerial s(D5,D6);
#include <ESP8266WiFi.h>
 
String apiKey = "6WDBQK5PWXBYUVMT";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "House LANnister";     // replace with your wifi ssid and wpa2 key
const char *pass =  "lannisterssendtheirregards";
const char* server = "api.thingspeak.com";

int a =0;
int b = 0;
int c=0;
int d =0;

WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");

    s.begin(115200);
 
}
 
void loop() 
{
  

  

                      if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(a);

                             postStr +="&field2=";
                             postStr += String(b);

                             postStr +="&field3=";
                             postStr += String(c);

                             postStr +="&field4=";
                             postStr += String(d);

                          
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                            
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
 for(int i = 0; i<1500; i++){
  delay(5);
  if (s.available()>0)
  {
    String s1 = s.readStringUntil('N');
    Serial.print("Received Data => ");
    Serial.println(s1);

    if (s1.charAt(0) == 'A') 
     {
        Serial.println("A fOUND");
        s1.remove(0,1); 
        Serial.println(s1);
        a = s1.toInt();
      
     }
        if (s1.charAt(0) == 'B') 
     {
        Serial.println("B fOUND");
        s1.remove(0,1); 
        Serial.println(s1);
        b = s1.toInt();
   
     }
      if (s1.charAt(0) == 'C') 
     {
        Serial.println("C fOUND");
        s1.remove(0,1); 
        Serial.println(s1);
        c = s1.toInt();
      
     }
      if (s1.charAt(0) == 'D') 
     {
        Serial.println("D fOUND");
        s1.remove(0,1); 
        Serial.println(s1);
        d = s1.toInt();
      
     }

  }
  }
}
