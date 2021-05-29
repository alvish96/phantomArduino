char command;
char data = 0;
String string;

int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor

bool b ;
#define S 22
#define L 12
#define Y 48
#define G 49
#define trig 25
#define echo 27
#define vcc 23
#define gnd 29

float duration, dist;


void setup()
{

  Serial.begin(9600);
  Serial2.begin(38400);

  pinMode (S, OUTPUT);
  pinMode (Y, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (L, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(gnd, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(gnd, LOW);
  digitalWrite(S, 1 );

  pinMode(trig, OUTPUT);
  pinMode(vcc, OUTPUT);
  pinMode(echo, INPUT);
}



void loop() {
 // btcheck();
//ldr();
t2();
}


void ldr()
{
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
delay(500);
if (sensorValue<400)
{
  switchon();
}
else switchoff();

}


void btcheck()
{
 
}





void t2()
{ if (Serial2.available() > 0) // Send data only when you receive data:
  {
    data = Serial2.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line
    if (data == '1')           //Checks whether value of data is equal to 1
     {
      b=1;
     switchon();
     } 
     else if (data == '0') 
     {
      b=0;
      switchoff();
     }else if (data == '2')
     {goto n;}

  }
  
  
  dist = meas();
  if (dist < 100 && dist > 30)
  {
    Serial.println(dist);
    b = !b;
    Serial.println(b);

    if (b == 1)
    {
      switchon();
      Serial.println("lights on"); delay(3000);
    }
    else if (b == 0) {
      switchoff();
      Serial.println("lights off"); delay(3000);
    }
    Serial.println();
    Serial.println();
    delay(500);
    goto m;
  }
  n:Serial.println ("skipped distance ");
m:Serial.println ("didnt skip distance ");
}


float meas()
{
  float av = 0;
  for (int k = 0; k <= 3; k++)
  {
    dist = nut();//  Serial.println(dist);
    if (k == 2)
    {
      av = dist;
    }
  }
  Serial.println(av);
  return av;
}

float nut()
{
  digitalWrite(trig, HIGH);
  digitalWrite(vcc, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration / 58;
  return dist;
}



void t1()
{
  switchon();
  delay(500);
  switchoff();
  delay(500);
}

void switchon()
{
  digitalWrite(S, 0);
  Serial.println("Light ON");
}


void switchoff()
{

  digitalWrite(S, 1);
  Serial.println("Light OFF");
}

void b1()
{
  digitalWrite(Y, 1);
  delay(100);
  digitalWrite(Y, 0);
  delay(100);
  digitalWrite(Y, 1);
  delay(100);
  digitalWrite(Y, 0);
  delay(700);
  Serial.println("yellow on");
}

void b2()
{
  digitalWrite(G, 1);
  delay(100);
  digitalWrite(G, 0);
  delay(100);
  digitalWrite(G, 1);
  delay(100);
  digitalWrite(G, 0);
  delay(700);
  Serial.println("green on");
}


void shutdown1()
{

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println ("                   *************************");
  Serial.println ("                       program terminated  ");
  Serial.println ("                   *************************");

  Serial1.println();
  Serial1.println();
  Serial1.println();
  Serial1.println (" *************************");
  Serial1.println ("        end of program ");
  Serial1.println (" *************************");

  Serial2.println();
  Serial2.println();
  Serial2.println();
  Serial2.println (" *************************");
  Serial2.println ("       end of program ");
  Serial2.println (" *************************");

  while (1);
}

void repeat(int x , int c1)
{ int i;
  for ( i = 0; i < c1; i++)
  {


    if (x == 1)
    {
      goto a;
z1: Serial.print("");
    }


    if (x == 2)
    {
      goto b;
z2: Serial.print("");
    }

    if (x == 3)
    {
      goto c;
z3: Serial.print("");
    }

    else {
      Serial.println("Invalid input");
      goto l1;
    }
  }

  goto l;

a: {
    b1();
    goto z1;
  }
b: {
    b2();
    goto z2;
  }
c: {
    t1();
    goto z3;
  }
l1: Serial.println("incomplete execution");
l: Serial.println("execution complete");
  c1 = 0;
}

void bt() {

  Serial.print("Choose your option");
  Serial.print("      --->  LO  light on");
  Serial.print("      --->  LF  light off");

  if (Serial.available() > 0)
  {
    string = "";
  }
  while (Serial.available() > 0)
  {
    command = ((byte)Serial.read());
    if (command == ':')
    {
      break;
    }
    else
    {
      string += command;
    }
    delay(1);
  }
  if (string == "LO")
  {
    LEDOn();
  }
  if (string == "LF")
  {
    LEDOff();
  }

}
void LEDOn() {
  digitalWrite(L, 1);
}
void LEDOff() {
  digitalWrite(L, 0);



































  
{
  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  //delay();

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  
  delay(x1); //42

  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(x1);  //42

  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);
  delay(x1);  //42

  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);
  delay(x2);   //28

  analogWrite(a1, q3);      //5
  delay(x1 - x2); //14
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);
  delay(x2);  //28

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  delay(x1 - x2); //14
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  //delay();

  analogWrite(a1, b1);      //7
  delay(x2);  //28
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  delay(x1 - x2);
  analogWrite(a4, b2);
  // delay();

  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  delay(x5);  //6
  analogWrite(a4, b3);
  delay(x2 - x5); //28-6 = 22
  analogWrite(a3, b1);

  delay(z1);

  analogWrite(a1, b1);      //9
  analogWrite(a4, b3);
  delay(x4);  //8
  analogWrite(a3, b2);
  delay(x3 - x4); // 13-8 = 5
  analogWrite(a2, q2);


  // delay(z1/2);

  analogWrite(a4, b3);
  delay(x4);  //8
  analogWrite(a3, b3);
  delay(x3 - x4);
  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);


  //delay(z1/2);

  analogWrite(a3, b3);
  analogWrite(a4, b3);
  delay(x3);  //13
  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11


  //delay(z1/2);


  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  delay(x3);  //13
  analogWrite(a1, b3);      //12


  delay(2000);
  off();
}
