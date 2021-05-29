const int trig = 13, echo = 12,vcc=8;
long duration, Distanceincm;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT); pinMode (vcc, OUTPUT); 
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, HIGH);digitalWrite (vcc, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  Distanceincm = duration / 58;  // time to centimetres
 
  Serial.print("Distance in cm = ");
  Serial.println(Distanceincm);

  delay(500);
}
