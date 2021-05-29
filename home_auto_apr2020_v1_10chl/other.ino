
int brt()
{
  ldrval = analogRead(A7);
  delay(100);
  // Serial.println(ldrval);
  return ldrval;
}

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


void gapstt(int gap)
{
  if ((present - lastmotion) > (gap * 60))
  {
    resetFunc();
  }
}
