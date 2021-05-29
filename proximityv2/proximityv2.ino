
#define in A0
int sen=0;
void setup() {
  Serial.begin(9600);
pinMode(A0,INPUT);

}

void loop() {
a();
}

void a()
{
  sen=analogRead(A0);
Serial.println(sen);
delay(50);
}
