/*start turn on for 30 sec
   start count
   if count increases more than 5 within 30
   keep on
   else
   turn off after 30

   if no motion for 4 mins
    turn off




bool motion()
{
  if (checkmotion == 1)
  {
    pirval = digitalRead(pirpin);
    if (pirval == HIGH)
    {
      //motion detected
      if (motionstate == LOW)
      {
        motionstate = HIGH;
        Serial.println("MOTION DETECTED AT ");
        Serial.print(millis() / 1000);
        Serial.println(" sec");
        motioncount++;
        delay(50);
      }
    }
    else
    {
      if (motionstate == HIGH)
      {
        motionstate = LOW;
        lastmotion=millis()/1000;
        Serial.println("MOTION ENDED AT ");
        Serial.print(millis() / 1000);
        Serial.println(" sec");
        delay(50);
      }
    }
  }
  return motionstate;
}


void algo()
{
  if (motioncount == 1)
    mod[1].SWtimer(30, 's');

  if (motioncount > 5)
  {
    mod[1].SWon();
    motioncount = 0;
  }
}/
*/
