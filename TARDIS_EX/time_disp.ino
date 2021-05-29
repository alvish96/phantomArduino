int x = 1;
void timex()
{
  display.clearDisplay();
  tmElements_t tm;
  if (RTC.read(tm))
  {
    display.clearDisplay();
    display.setTextSize(x + 2);
    display.setTextColor(WHITE);
    display.setCursor(1, 12);
    print2digits(tm.Hour);
    display.write(':');
    print2digits(tm.Minute);
    display.setTextSize(x + 1);
    display.setCursor(104, 16);
    print2digits(tm.Second);
    dis(tm.Second % 10);
    display.setCursor(0, 0);
    display.setTextSize(x);
    display.print(tm.Day);
    display.write('/');
    display.print(tm.Month);
    display.write('/');
    display.print(tmYearToCalendar(tm.Year));
    display.setTextSize(x + 1);
    display.setCursor(90, 0);
    //    display.print(meas1());
    display.display();

  }
  else
  {
    if (RTC.chipPresent())
    {
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.print("DS1307 stopped,run set time");
      display.display();
    }
    else
    {
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.print("DS1307 read error,check circuit");
      display.display();
    }
    delay(9000);
  }
  //  delay(1000);

}
void print2digits(int number)
{
  if (number >= 0 && number < 10) {
    display.write('0');
    // display.display();
  }
  display.print(number);
  //display.display();
  //display.println();
}

void timex1()
{
  if (oled)
  {
    i++;
    int n = 7;
    tmElements_t tm;
    if (RTC.read(tm))
    {
      i = tm.Second % 10;
      color(i);
      dis(i);
      if (i <= n )
      {
        display.clearDisplay();
        display.setTextSize(x + 2);
        display.setTextColor(WHITE);
        display.setCursor(1, 12);
        print2digits(tm.Hour);
        display.write(':');
        print2digits(tm.Minute);
        display.setTextSize(x + 1);
        display.setCursor(100, 16);
        print2digits(tm.Second);
        dis(tm.Second % 10);

        display.setCursor(10, 0);
        display.setTextSize(x );
        display.print(tm.Day);
        display.write('/');
        display.print(tm.Month);
        display.write('/');
        display.print(tmYearToCalendar(tm.Year));

        display.setTextSize(x);
        display.setCursor(80, 0);
        display.print(rtc.getDOWStr());

        display.display();
        //      delay(100);
      }
      if (i > n )
      {
        if (i > n + 1 )
        {

          display.clearDisplay();
          display.setCursor(10, 0);
          display.setTextSize(x );
          display.print(tm.Day);
          display.write('/');
          display.print(tm.Month);
          display.write('/');
          display.print(tmYearToCalendar(tm.Year));

          display.setTextSize(x);
          display.setTextColor(WHITE);
          display.setCursor(80, 0);
          print2digits(tm.Hour);
          display.write(':');
          print2digits(tm.Minute);
          display.write(':');
          print2digits(tm.Second);
          dis(tm.Second % 10);

          display.setTextSize(x + 1);
          display.setCursor(10, 13);
          display.print(rtc.getDOWStr());
          display.display();
          goto x;
        }
        display.clearDisplay();
        display.setTextSize(x);
        display.setCursor(80, 0);
        display.print(rtc.getDOWStr());
        display.setTextColor(WHITE);
        display.setCursor(10, 0);
        print2digits(tm.Hour);
        display.write(':');
        print2digits(tm.Minute);
        display.write(':');
        print2digits(tm.Second);
        dis(tm.Second % 10);
        display.setCursor(1, 12);
        display.setTextSize(x + 2);
        display.print(tm.Day);
        display.write('/');
        display.print(tm.Month);    //      display.write('/');
        display.setTextSize(x + 1);
        display.setCursor(80, 16);
        display.print(tmYearToCalendar(tm.Year));//      delay(100);



        display.display();
x: delay(0);
      }

    }
  }
  else if (!oled)
  {
    digitalWrite(segA, 1);
    digitalWrite(segB, 1);
    digitalWrite(segC, 1);
    digitalWrite(segD, 1);
    digitalWrite(segE, 1);
    digitalWrite(segF, 1);
    digitalWrite(segG, 1);
    colo(maxx, maxx, maxx);
    display.clearDisplay();
    display.display();
  }

}
