int a=52,b=12,c=53;


void setup() {
Serial.begin(115200);
Serial1.begin(38400);
pinMode(a,OUTPUT);  // put your setup code here, to run once:
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
}

void loop() {
  test();


sh();
}
void test()
{

  digitalWrite(a,1);delay(100);digitalWrite(a,0);
  delay(200);
  digitalWrite(a,1);delay(100);digitalWrite(a,0);
  delay(500);
 digitalWrite(a,1);delay(200);digitalWrite(a,0);
  delay(300);
  digitalWrite(a,1);delay(200);digitalWrite(a,0);
  delay(500);

   digitalWrite(b,1);delay(100);digitalWrite(b,0);
  delay(200);
  digitalWrite(b,1);delay(100);digitalWrite(b,0);
  delay(500);
 digitalWrite(b,1);delay(200);digitalWrite(b,0);
  delay(300);
  digitalWrite(b,1);delay(200);digitalWrite(b,0);
  delay(500);
  
  digitalWrite(c,1);delay(100);digitalWrite(c,0);
  delay(200);
  digitalWrite(c,1);delay(100);digitalWrite(c,0);
  delay(500);
 digitalWrite(c,1);delay(200);digitalWrite(c,0);
  delay(300);
  digitalWrite(c,1);delay(200);digitalWrite(c,0);
  delay(500);

}

void sh(){
 Serial.print("  **           end         **  "); 
Serial.println();
 Serial1.print("  **           end         **  "); 
Serial1.println();
  while(1);
}

