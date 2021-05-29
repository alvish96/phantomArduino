

#include <SoftwareSerial.h>
SoftwareSerial SWrecv(5, 6);

char mystr[10]; //Initialized variable to store recieved data
int x[10]; 
int i=0;
int incom;
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  Serial1.begin(9600);
  SWrecv.begin(9600);
 
 }
  //  SWrecv.readBytes(mystr, 5); //Read the serial data and store in
//    Serial1.readBytes(mystr, 5); //Read the serial data and store in
    //  Serial1.readBytes(mystr,5); //Read the serial data and store in var





void loop()
{
 if(Serial1.available()>0)
 {
// for(int i=0;i<10;i++)
incom=Serial1.read();
  
 }
//for(int i=0;i<10;i++)  
Serial.println(incom); 

//Print data on Serial Monitor
//    delay(1000);
  
  
}
