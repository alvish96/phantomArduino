
void setup() {

  Serial.begin(9600);
  rtc.begin();
  lcd.begin(16, 2);

  lcd.print("*reset complete*"); delay(350); buzz();
  delay(1000); lcd.clear();

  power = 0; //power off
  ov = 0;   //auto mode
  f1 = 0;   //btness  disp flag

  pinMode(ENL, OUTPUT);
  pinMode(lpos, OUTPUT);
  pinMode(lneg, OUTPUT);
  digitalWrite(lneg,LOW);


  pinMode(lcdcon, OUTPUT);
  pinMode(lcdlyt, OUTPUT);

  pinMode(buz, OUTPUT);
  digitalWrite(lcdcon, 0);
  analogWrite(buz, 0);

pinMode (relay0, OUTPUT);
digitalWrite(relay0,LOW);
  setl();



  ir.enableIRIn();  // Start the receiver
  i = 0;
  t = rtc.getTime();
  //buzz(2);
  //resetFunc();



  //mario
  s = 1000 / f;        //fps to ms

}
