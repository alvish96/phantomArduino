
void test()
{
  readspd();
  wrtspd(minspd);
  line();
}
void test2()
{ int o = 32;
  for (int i = o; i < maxspd; i++)
  {
    readspd();
    wrtspd(i);
    line();
    delay(100);
  }
  delay(1000);
  for (int j = maxspd; j > o; j--)
  {
    readspd();
    wrtspd(j);
    line();
    delay(100);
  }

  delay(3000);
}
