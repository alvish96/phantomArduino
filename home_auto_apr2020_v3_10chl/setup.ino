void setup()
{

  Serial.begin(9600);
  ir.enableIRIn();          // Start the receiver
  //  pinMode(G, OUTPUT);

  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5 , OUTPUT);
  pinMode(s6 , OUTPUT);
  pinMode(s7 , OUTPUT);
  pinMode(s8 , OUTPUT);
  pinMode(s9 , OUTPUT);
  pinMode(s10, OUTPUT);
  pinMode(s11, OUTPUT);
  digitalWrite(s1, roff);
  digitalWrite(s2, roff);
  digitalWrite(s3, roff);
  digitalWrite(s4, roff);
  digitalWrite(s5 , r1off);
  digitalWrite(s6 , r1off);
  digitalWrite(s7 , r1off);
  digitalWrite(s8 , r1off);
  digitalWrite(s9 , r1off);
  digitalWrite(s10, r1off);
  digitalWrite(s11, r1off);
  digitalWrite(buz, 0);
  pinMode(buz, OUTPUT);//  digitalWrite(G, LOW);


  pinMode(ldr, INPUT);
  pinMode(pirPin, INPUT);

  //  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  Serial.print("calibrating sensor ");
  for (int i = 0; i < calibrationTime; i++)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
  checkmotion = 1; prflag = 0;
  debug = 1;

  f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, fres, ft1, ft2, ft3, ft4, ft5, ft6, ft7, ft8, ft9, ft10, ft11, ftres = 0;
  a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ares, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, xres = 0;

}
