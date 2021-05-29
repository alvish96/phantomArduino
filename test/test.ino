char data=0;


int buz = 12;



void setup() {
  Serial.begin(115200);
Serial1.begin(9600);

  
 pinMode(2,OUTPUT);
 pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
}

void loop() {
a();
shutdown1();
 
  // put your main code here, to run repeatedly:

}

void a(){
   beep();
   for(int i=0;i<=5;i++)
   {
   digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(2,LOW);
  delay(100);
}
}

void beep()
{
  analogWrite(buz, 255 );
  delay(400);
  soundoff();
}
void soundoff()
{
  digitalWrite(buz,LOW);
}

void shutdown1()
{
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println ("                   *************************");
  Serial.println ("                         end of program ");
  Serial.println ("                   *************************");
  while (1);
}

