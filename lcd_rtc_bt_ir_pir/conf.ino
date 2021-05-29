
//---------------------------------------------------------------------------------------------------
void lcdtimeout() {

  delay(700);
  lcd.clear();

}

void lt() {

  delay(100);
  lcd.clear();

}



//---------------------------------------------------------------------------------------------------
void tim() {
  i++;
  int n = 7;

  if (i < n * 10) {

    lcd.clear();

    lcd.setCursor(8, 0);
    lcd.print(rtc.getTimeStr());

    /* lcd.setCursor(6, 1);
      lcd.print(rtc.getDateStr());
      delay(100);
    */
    lcd.setCursor(4, 1);

    // lcd.print("_");
    lcd.print(t.date, DEC);
    lcd.print(" ");
    lcd.print(rtc.getMonthStr());
    lcd.print(" ");
    lcd.setCursor(12, 1);
    lcd.print(t.year, DEC);
    delay(100);
  }

  if (i >= n * 10)
  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(rtc.getTemp()); lcd.print("'C");
    lcd.setCursor(8, 0);
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(6, 1);
    lcd.print(rtc.getDOWStr());
    delay(100);

    if (i == 100) {
      i = 0;
    }
  }
}

//---------------------------------------------------------------------------------------------------
void nytlytsw1() {
  light0 = !light0;
  if (light0 == 1)  lightOn0();
  if (light0 == 0)  lightOff0();
  
  lcd.setCursor(1, 0);
  lcd.print(light0);
  
  delay(200);
}
void lightOn0() {
  digitalWrite(relay0, HIGH);
  digitalWrite(relay1, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("NIGHTLIGHT ON");
}

void lightOff0() {
  digitalWrite(relay0, LOW);
  digitalWrite(relay1, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("NIGHTLIGHT OFF");
}
//---------------------------------------------------------------------------------------------------

void nytlytsw()
{
  // light is lightstate
  light = !light;
  digitalWrite(lpos, light);
  digitalWrite(lneg, LOW);
  analogWrite(ENL, lytlevel);
  lcd.clear();
  lcd.setCursor(0, 0);
  if (light == 1)lcd.print("NIGHTLIGHT ON");
  if (light == 0)lcd.print("NIGHTLIGHT OFF");
  //z setl();
}


void nytlytmode()
{ bool out = 0;
  while (true)
  {
    if (light == 1)
    {

      // mode++;
      if (mode == 4)
        mode = 1;

      int spd, intl;
      if (mode == 1)
      {
        spd = 10; intl = 150;
      }
      if (mode == 2)
      {
        spd = 100; intl = 250;
      }
      if (mode == 3)
      {
        spd = 150; intl = 500;

      }
      for ( lytlevel = 255; lytlevel > 0; lytlevel--)
      {
        check(); if (exitloop == 1)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("EXITING");
          delay(400); digitalWrite(lpos, 1);
          break;
          goto x;
        }
        digitalWrite(lpos, light);
        digitalWrite(lneg, LOW);
        analogWrite(ENL, lytlevel);
        delay(spd);
      }
      delay(intl);
      check(); if (exitloop == 1)
      {
        //out=1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("EXITING");
        delay(400); digitalWrite(lpos, 1);
        break;
        goto x;
      }

      for (lytlevel = 0; lytlevel < 255; lytlevel++)
      {
        check(); if (exitloop == 1)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("EXITING");
          delay(400); digitalWrite(lpos, 1);
          break;
          goto x;
        }
        digitalWrite(lpos, light);
        digitalWrite(lneg, LOW);
        analogWrite(ENL, lytlevel);
        delay(spd);
      }

    }

    if (out == 1)
x: break;
  }
}
void btnessup()
{
  if (lytlevel > 225)
    lytlevel = 255;
  else
    lytlevel += 30;

  if (light == 1)
  {
    digitalWrite(lpos, light);
    digitalWrite(lneg, LOW);
    analogWrite(ENL, lytlevel);
  }
}

void btnessdn()
{
  if (lytlevel < 30)
    lytlevel = 0;
  else
    lytlevel -= 30;

  if (light == 1)
  {
    digitalWrite(lpos, light);
    digitalWrite(lneg, LOW);
    analogWrite(ENL, lytlevel);
  }
}

//---------------------------------------------------------------------------------------------------

void powersw() {
  power = !power;
  if (power == 1) powerup();
  if (power == 0)powerdown();
  delay(400);
}
void powerup()
{
  milli = millis();
  Serial.println("POWERING UP SYSTEM");
  digitalWrite(lcdlyt, 1);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("POWERING UP");
  buzz(2); setl();
  //resetflags();
}

void powerdown()
{
  Serial.println("POWERING DOWN SYSTEM");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("POWERING DOWN");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM");
  buzz(3); delay(300);
  lcd.clear();
  digitalWrite(lcdlyt, 0);
  digitalWrite(lpos, 0);
  resetflags();
}
//---------------------------------------------------------------------------------------------------
//f1=0;
void autobtness()
{
  if (millis() > (milli + delaytime * 1000))
  {
    ldrval = analogRead(A0);
    if (f1 == 1) goto x3;

    lcd.clear(); lcd.setCursor(0, 0);
    lcd.print("BRIGHTNESS LEVEL");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED ");
    Serial.println(ldrval);
    lcd.print(ldrval);
    delay(850);
x3:    if (ov == 0)
    {
      if (ldrval > ambv)
      {
        if (f1 == 1) goto x1;
        if (l == 0) goto x1;
        lcd.setCursor(0, 1);
        lcd.print("HIGH ");
        lcd.clear(); lcd.setCursor(0, 0);
        lcd.print("TURNING OFF LIGHTS");
        delay(800);
        lcd.clear(); delay(200);
        f1 = 1;
x1: digitalWrite(lcdlyt, 0);
      }

      if (ldrval < ambv)
      {
        if (f1 == 1) goto x2;
        if (l == 1) goto x2;
        lcd.setCursor(0, 1);
        lcd.print("LOW ");
        lcd.clear(); lcd.setCursor(0, 0);
        lcd.print("TURNING ON LIGHTS");
        delay(800);
        lcd.clear(); delay(200);
        f1 = 1;
x2:  digitalWrite(lcdlyt, HIGH);
      }
      f1++;
    }
    if (ov == 1)
      digitalWrite(lcdlyt, l); f1 = 1;
  }
}

//---------------------------------------------------------------------------------------------------
void resetflags()
{
  lightflag = 0;
  mode = 0;   //nightlight mode reset to 0
  light = 0;  //night light flag
  power = 0; //power off flag
  ov = 0;   //auto mode
  f1 = 0;   //btness  disp flag
  i = 0;
  setl();
}

//---------------------------------------------------------------------------------------------------

void setl()
{

  ldrval = analogRead(A0);
  if (ldrval > ambv )
    l = 0;
  if (ldrval < ambv )
    l = 1;
}
//---------------------------------------------------------------------------------------------------
void resetbuzz()
{
  buzz(3); del(); buzz(); del(); buzz(2); del();
}
void swbuzz()
{

}
//---------------------------------------------------------------------------------------------------
void term() {
  Serial.println("end prgm");
  b(5); buzz(3);
  exit(0);
}
//---------------------------------------------------------------------------------------------------
//void(* resetFunc) (void) = 0; //declare reset function @ address 0

//resetFunc();  //call reset
//---------------------------------------------------------------------------------------------------

void lcdlightSW()
{ // l is lightstate
  l = !l;
  digitalWrite(lcdlyt, l);
  lcd.setCursor(0, 1);
  if (l == 1)lcd.print("light on");
  if (l == 0)lcd.print("light off");
  //z setl();
}
//---------------------------------------------------------------------------------------------------
/*void mute()
  {
  m = !m;
  lcd.setCursor(0, 1);
  if (m == 1) {
    //#define buz A1
    //    buz = A1;
    lcd.print("unmute");
    buzz();
  }
  else if (m == 0) {
    noTone(A1);
    lcd.print("mute");
  }
  }

*/
//---------------------------------------------------------------------------------------------------
void del() {
  delay(50);
}
//---------------------------------------------------------------------------------------------------
void buzz(int n) {
  int del = 10;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
//---------------------------------------------------------------------------------------------------
void longbuzz(int n) {
  int del = 350;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}//---------------------------------------------------------------------------------------------------
void buzz() {
  int del = 10, n = 1;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
//---------------------------------------------------------------------------------------------------
void longbuzz() {
  int del = 350, n = 1;
  digitalWrite(buz, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(buz, HIGH);
    delay(del);
    digitalWrite(buz, LOW);
    delay(del + 60);
  } digitalWrite(buz, LOW);
}
//---------------------------------------------------------------------------------------------------
void b(int n) {
  int del = 50;
  digitalWrite(lyt, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(lyt, HIGH);
    delay(del);
    digitalWrite(lyt, LOW);
    delay(del);
  } digitalWrite(lyt, LOW);
}
//---------------------------------------------------------------------------------------------------
void b() {
  int del = 50, n = 1;
  digitalWrite(lyt, LOW);
  for (int i = 0; i < n; i++)
  {
    digitalWrite(lyt, HIGH);
    delay(del);
    digitalWrite(lyt, LOW);
    delay(del);
  } digitalWrite(lyt, LOW);
}

//---------------------------------------------------------------------------------------------------


void brightness() {
  ldrval = analogRead(A0);
  Serial.println(ldrval);
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print(ldrval);
  delay(1000);
}

//---------------------------------------------------------------------------------------------------
