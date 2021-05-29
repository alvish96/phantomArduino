#define DETECT 2 // pin 2 for  sensor
#define ACTION 13 // pin 8 for action to do someting


void setup() {
  Serial.begin(9600);

  pinMode(DETECT, INPUT);//define detect input pin
  pinMode(ACTION, OUTPUT);//define ACTION output pin
 
}

void loop() {
 

  int detected = digitalRead(DETECT);// read Hall sensor
  
  if( detected == LOW)
  {
    digitalWrite(ACTION,LOW);
    Serial.println("Detected!");
    Serial.println(LOW);
    
  }
  else
  {
    digitalWrite(ACTION,HIGH); 
    Serial.println("Nothing");
    Serial.println(HIGH);
    
    }
  delay(10);
}

