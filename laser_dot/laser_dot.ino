void setup ()
{
   pinMode (13, OUTPUT); 
    pinMode (8, OUTPUT);// define the digital output interface 13 feet
}
void loop () {
   digitalWrite (13, HIGH); // open the laser head
  
   digitalWrite (8, HIGH);
   delay (1000); // delay one second
   digitalWrite (13, LOW);
   digitalWrite (8, LOW);// turn off the laser head
   delay (1000); // delay one second
}
