String a, b;

#define l1 12
#define l2 13
#define l3 52
#define l4 53


void setup() {
Serial.begin(9600);
  Serial1.begin(38400); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(115200);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  digitalWrite(l2, 0);
}

void loop()
{

  while (Serial1.available())

  {
    a = Serial1.readString(); // read the incoming data as string
    Serial1.print("            ");      
    Serial1.println(a);       Serial.print("a:");  Serial.println(a);
    Serial2.print("");
    Serial2.println(a);

  }
  while (Serial2.available())
  {
    b = Serial2.readString();
    Serial1.print("");       
    Serial1.println(b);      Serial.print("b:");  Serial.println(b);

    Serial2.print("           ");
    Serial2.println(b);
  }
}

    void light()
    {

  if (a == "1" || b == "1")
  {
    led(1);
  }
  else if (a == "2" || b == "2")
  {
    led(2);
  }
  else if (a == "3" || b == "3")
  {
    led(3);
  }
  else if (a == "4" || b == "4")
  {
    led(4);
  }

}

void led(int x)
{
  if (x == 1)
  {
    digitalWrite(l1, 1);
    delay(800);
    digitalWrite(l1, 0);
    delay(800);
    digitalWrite(l1, 1);
    delay(800);
    digitalWrite(l1, 0);
  }
  else if (x == 2)
  {
    digitalWrite(l2, 1);
    delay(800);
    digitalWrite(l2, 0);
    delay(800);
     digitalWrite(l2, 1);
    delay(800);
    digitalWrite(l2, 0);
    delay(800);
  }
  else if (x == 3)
  {
    digitalWrite(l3, 1); delay(800);    digitalWrite(l3, 0);delay(800); digitalWrite(l3, 1); delay(800);    digitalWrite(l3, 0);delay(800);
  }
  else if (x == 4)
  {
    digitalWrite(l4, 1); delay(800);    digitalWrite(l4, 0);delay(800);  digitalWrite(l4, 1); delay(800);    digitalWrite(l4, 0);delay(800); 
  }
}

