
int ledAnalogOne[] = {8, 10, 11};

const byte RED[] = {255, 0, 0};
const byte ORANGE[] = {83, 4, 0};
const byte YELLOW[] = {255, 255, 0};
const byte GREEN[] = {0, 255, 0};
const byte BLUE[] = {0, 0, 255};
const byte INDIGO[] = {4, 0, 19};
const byte VIOLET[] = {23, 0, 22};
const byte CYAN[] = {0, 255, 255};
const byte MAGENTA[] = {255, 0, 255};
const byte WHITE[] = {255, 255, 255};
const byte BLACK[] = {0, 0, 0};
//const byte PINK[] = {158, 4, 79};


int r1=255;
 int g1=255;
 int b1=0;

 int r=255-r1;
 int g=255-g1;
 int b=255-b1;
 
void setup() {
  
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(ledAnalogOne[0], OUTPUT);
  pinMode(ledAnalogOne[1], OUTPUT);
  pinMode(ledAnalogOne[2], OUTPUT);
  digitalWrite(9,HIGH);
}

void loop() {

white();delay(5000);black();
  /*
white();
delay(3000);
turn();
white();
delay(2000);
red();
delay(2000);
black();
delay(1000);
haz();
delay(1000);
analogWrite(ledAnalogOne[0], 255);
  analogWrite(ledAnalogOne[1], 255);
  analogWrite(ledAnalogOne[2], 255);
*/


  /*
  // set the brightness of pin 9:
  analogWrite(9,255);
  analogWrite(ledAnalogOne[0], r);
  analogWrite(ledAnalogOne[1], g);
  analogWrite(ledAnalogOne[2], b);
  
delay(3000);
  
*/



shutdown1();
}

void haz()
{analogWrite(9, 150);
  for (int i=0;i<5;i++)
  {
    orange();
    delay(700);
    black();
    delay(550);
  }
analogWrite(9, 255);}
  void turn()                  
{analogWrite(9, 150);
  for (int i=0;i<5;i++)
  {
    white();
    delay(600);
    orange();
    delay(600);
  }analogWrite(9, 255);
}


void black(){
analogWrite(ledAnalogOne[0], 255);
  analogWrite(ledAnalogOne[1], 255);
  analogWrite(ledAnalogOne[2], 255);
}
void white()
{
 analogWrite(ledAnalogOne[0], 0);
  analogWrite(ledAnalogOne[1], 0);
  analogWrite(ledAnalogOne[2], 0);
  
//digitalWrite(ledAnalogOne[0],LOW);
//digitalWrite(ledAnalogOne[1],LOW);
//digitalWrite(ledAnalogOne[2],LOW);
}
void red()
{
   analogWrite(ledAnalogOne[0], 0);
  analogWrite(ledAnalogOne[1], 255);
  analogWrite(ledAnalogOne[2], 255);
  
//digitalWrite(ledAnalogOne[0],LOW);
//digitalWrite(ledAnalogOne[1],HIGH);
//digitalWrite(ledAnalogOne[2],HIGH);
}
void orange()
{
 analogWrite(ledAnalogOne[0], 0);
  analogWrite(ledAnalogOne[1], 0);
  analogWrite(ledAnalogOne[2], 255);
  
//digitalWrite(ledAnalogOne[0],LOW);
//digitalWrite(ledAnalogOne[1],LOW);
//digitalWrite(ledAnalogOne[2],HIGH);
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

