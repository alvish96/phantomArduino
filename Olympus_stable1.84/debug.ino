
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
    Serial.print(F(" "));
    Serial.println();

  }
  }
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
    Serial.print(F(" firstmotion "));
    Serial.print(firstmotion);
    Serial.print(F(" secondmotion "));
    Serial.print(secondmotion );
    Serial.print(F(" lasm "));
    Serial.print(lastm);
    Serial.print(F(" lastmotion "));
    Serial.print(lastmotion);

    Serial.print(F(" "));
    Serial.println();

  }
}



void fn9()
{
  int x;
  for (int i = 1; i < 12; i++)
  {
    Serial.print(F(" i "));
    Serial.print(i);
    x = (mod[i].total / 1000) - (millis() / 1000);
    if (mod[i].flag == HIGH)
    {
      if (x < 5000)
      {
        mod[i].se = x % 60;
        x = (x - mod[i].se) / 60;
        mod[i].mi = x % 60;
        x = (x - mod[i].mi) / 60;
        mod[i].hr = x % 60;
      }
    }

    else
    {
      mod[i].hr = mod[i].se = mod[i].mi = 0;
    }

    Serial.print(F(" hr "));
    Serial.print(mod[i].hr);
    Serial.print(F(" mi "));
    Serial.print(mod[i].mi);
    Serial.print(F(" se "));
    Serial.print(mod[i].se);
    Serial.println();
  }
}
/*for (int i = 1; i < 12; i++)
    {
    Serial.print(F(" i "));
    Serial.print(i);
    Serial.print(F(" i "));
    if (mod[i].state == mod[i].relayon)
      if (((mod[i].total / 1000) - (millis() / 1000)) < 5000)
        Serial.print((mod[i].total / 1000) - (millis() / 1000));
    Serial.println();
    }*/
