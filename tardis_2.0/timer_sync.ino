
void sday()
{
  rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
}
void sdate()
{
  rtc.setDate(24, 7, 2020);  // Set the date to January 1st, 2014
}
void stime()
{
  rtc.setTime(00, 22, 00);     // Set the time to 12:00:00 (24hr format)
}
void setall()
{
  sdate();
  stime();
  sday();
}
void timeprint()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");

  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());

}
