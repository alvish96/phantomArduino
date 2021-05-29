const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
int val=0;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
Serial.begin(9600);
}

void loop() {
digitalWrite(ledPin, state);
Serial.println(val/2);
test();
}

void test() {
state = !state;
val++;
}
