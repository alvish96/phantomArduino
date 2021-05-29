
#define A 46
void setup() {
  // initialize digital pin A as an output.
  pinMode(A, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(A, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
