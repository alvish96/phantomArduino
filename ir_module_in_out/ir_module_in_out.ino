#define ir1 A3
#define ir2 A4
#define led A2

unsigned long tim1;
unsigned long tim2;
unsigned long timdif;

void setup()
{
  Serial.begin(9600);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(led, OUTPUT);



}

void loop()
{
  fn();
  printdif();
}
void printdif()
{
  
  if (tim1 > tim2)
  {

    timdif = tim1 - tim2;
    Serial.print("***********");
    Serial.print(timdif);
    Serial.print("***********");
  }
  else if (tim2 > tim1)
  {
    timdif = tim2 - tim1;
    Serial.print("***********");
    Serial.print(timdif);
    Serial.print("***********");
  }

//  tim1=tim2=0;
  
}
void fn()
{
//  tim = millis();
  bool s1 = !digitalRead(ir1);
  bool s2 = !digitalRead(ir2);

  if (s1)
  {
    Serial.print(" HIGH s1--->");
    digitalWrite(led, 1);
    tim1 = millis();
//    Serial.print(" ");
    Serial.print(tim1);
//    Serial.print(" ");
    Serial.println();
  }
  else if (s2)
  {
    Serial.print(" HIGH s2--->");
    digitalWrite(led, 1);
    tim2 = millis();
//    Serial.print(" ");
    Serial.print(tim2);
//    Serial.print(" ");
    Serial.println();
  }


  else
  {
    //    Serial.print(" LOW");
    digitalWrite(led, 0);
  }

  delay(20);



}
