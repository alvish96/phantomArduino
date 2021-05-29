
/*
  #ifdef DEBUG
  Serial.print("Some debug stuff follows");
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
#if DEBUG
  
    Serial.print(" brt ");
    Serial.print(brt());
    Serial.print(" motioncount ");
    Serial.print(motioncount);
    Serial.print(" checkmotion ");
    Serial.print(checkmotion);
    Serial.print(" priority ");
    Serial.print(priority);
    Serial.print(" wait ");
    Serial.print(wait);
    Serial.print(" ato ");
    Serial.print(ato);
    Serial.print(" ");
    Serial.println();
  #endif
}
