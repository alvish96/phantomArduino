
/*
  #ifdef DEBUG
  Serial.print(F("Some debug stuff follows"));
  // More debug code...
  #endif

  #if expression

  //compile this code

  #elif different_expression

  //compile this different code

  #else

  //compile this entirely different code

  #endif

*/

void debug()
{
  if (debugg)
  {
    Serial.print(F(" brt "));
    Serial.print(brt());
    Serial.print(F(" motioncount "));
    Serial.print(motioncount);
    Serial.print(F(" checkmotion "));
    Serial.print(checkmotion);
    Serial.print(F(" priority "));
    Serial.print(priority);
    Serial.print(F(" wait "));
    Serial.print(wait);
    Serial.print(F(" ato "));
    Serial.print(ato);
    Serial.print(F(" look "));
    Serial.print(look);
    Serial.print(F(" "));

    Serial.println();
  }
}
