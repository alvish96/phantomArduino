
void meas()
{
  digitalWrite (trig, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration / 58;
  Serial.print(duration);
  Serial.print("  <- time    and   distance ->  ");
  Serial.println(dist);
  delay(10);
}

int meas1()
{

  digitalWrite (trig, HIGH);
  delay(15);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  dist = duration / 58;
  delay(50);
  if (dist > 1000)
    return 0;
  else
    return dist;
}
