//---------------------------------------------------------------------------------------------------

bool motion()
{
  motn = 0;
  if (digitalRead(pirPin) == HIGH)
  {
    motn = 1;
    if (lockLow) 
    {
      //makes sure we wait for a transition to LOW before any further output is made:
      lockLow = false;
      Serial.println();
      count++;
      Serial.print("motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pirPin) == LOW)
  {
    //    digitalWrite(ledPin, LOW);  //the led visualizes the sensors output pin state
    if (takeLowTime)
    {
      lowIn = millis();          //save the time of the transition from high to LOW
      takeLowTime = false;       //make sure this is only done at the start of a LOW phase
    }

    if (!lockLow && millis() - lowIn > pause) {
      lockLow = true;
      Serial.println();
      Serial.print("motion ended at ");     //output
      lastmotion = (millis() - pause) / 1000;
      Serial.print(lastmotion);
      Serial.println(" sec");
      delay(50);
    }
  }
  return motn;
}
