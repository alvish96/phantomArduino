char data = 0;                //Variable for storing received data
void setup() 
{
  Serial1.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(2, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{

  digitalWrite(2,1);
  delay(1000);
digitalWrite(2,0);  
  if(Serial1.available() > 0)  // Send data only when you receive data:
  {
    data = Serial1.read();      //Read the incoming data and store it into variable data
    Serial1.print(data);        //Print Value inside data in Serial monitor
    Serial1.print("\n");        //New line 
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(2, HIGH);  //If value is 1 then LED turns ON
    else if(data == '0')       //Checks whether value of data is equal to 0
      digitalWrite(2, LOW);   //If value is 0 then LED turns OFF
  }                            
 
}
