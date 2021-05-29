#define p 2
#define l 13



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(p, OUTPUT);
 pinMode(l, OUTPUT);
digitalWrite(p,0);
digitalWrite(l,0);
}

void loop() {
  digitalWrite(p,0);
  digitalWrite(l,0);
  delay(2000);

  digitalWrite(p,1);
  digitalWrite(l,1);
  delay(2000);
}
