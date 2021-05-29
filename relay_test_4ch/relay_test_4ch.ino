#define s1 2
#define s2 3
#define s3 4
#define ron 255
#define roff 0


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(13,OUTPUT);
  analogWrite(s1, 255);
  analogWrite(s2, 255);
  analogWrite(s3, 255);
  analogWrite(13,0);
}

void loop() {
  analogWrite(s1, 0);
  analogWrite(s2, 0);
  analogWrite(s3,  0);
analogWrite(13,0);
delay(1000);
  analogWrite(s1,  255);
  analogWrite(s2,  255);
  analogWrite(s3,  255);
  analogWrite(13,255);
  delay(1000);

}
