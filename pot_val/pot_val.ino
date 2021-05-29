
//Analog Read with Serial Monitor

void setup() {
  //the setup routine runs once when you press reset

  Serial.begin(9600); //initialize serial communication at 9600 bits per second
}

void loop() {
  //the loop routine runs over and over again forever

  int sensorValue = analogRead(A5); //read the input on analog pin 0
 // int sensorValue1 = analogRead(A4); //read the input on analog pin 0

    //Serial.println();
    Serial.print("val 0 ");Serial.println(sensorValue);
    
   // Serial.println();
    //  Serial.print("------------val 1   ");Serial.println(sensorValue1); //print out the value you read

  delay(10); //delay in between reads for stability
}


