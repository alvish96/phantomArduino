
//---------------------------------------------------------------------------------------------------
void lcdtimeout() {
  delay(1000);
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

    lcd.setCursor(6, 1);
    lcd.print(rtc.getDateStr());
    delay(100);
  }

  if (i >= n * 10)
  {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(rtc.getTemp()); lcd.print("'C");
    lcd.setCursor(8, 0);
    lcd.print(rtc.getTimeStr());

    lcd.setCursor(0, 1);
    lcd.print(rtc.getMonthStr());
    lcd.print("_");
    lcd.print(t.date, DEC);

    lcd.print("th ");
    lcd.print(rtc.getDOWStr());

    delay(100);

    if (i == 100) 
    {
      i = 0;
    }
  }
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
{
  l = !l;
  digitalWrite(lcdlyt, l);
  lcd.setCursor(0, 1);
  if (l == 1)lcd.print("light on");
  if (l == 0)lcd.print("light off");
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
