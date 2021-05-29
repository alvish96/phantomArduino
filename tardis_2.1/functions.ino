
void line()//1.83
{
  if (debugg)Serial.println();
}

void swTMD()
{
  b1 = !b1;
  reqTMD(b1);
}

void reqTMD(bool x)
{
  MSL = x;
  ledf = x;
  int codeB;
  int codeA = 232;
  if (x == 1)  codeB = 233;
  if (x == 0)   codeB = 234;

  Serial1.write(codeA);
  Serial.println(codeA);
  Serial1.write(codeB);
  Serial.println(codeB);
  Serial1.flush();
}
