

#define en 11
#define ip 8
#define lp 9
  int a = 0;
void setup() {
  pinMode(en, OUTPUT);
  pinMode(ip, OUTPUT);
  pinMode(lp, OUTPUT);
  
Serial.begin(9600);
digitalWrite(lp,LOW);


  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
fn();
delay(1000);
}


void fn()
{
  digitalWrite(ip, HIGH);
  for (a = 50; a < 255; a++)
  {
    analogWrite(en, a);Serial.println(a);delay(5);
  }
  delay(500);
  for (a = 255; a > 50; a--)
  {
    analogWrite(en, a);Serial.println(a);delay(5);
  }
  digitalWrite(ip,LOW);
}
