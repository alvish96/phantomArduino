/*


*///=============

//   from remote
/* case 0x61D632CD:
   if (mod[9].state == mod[9].relayoff)
   {
     mod[9].SW();
     mark1 = millis()/1000;
   }
   else if (mod[9].state == mod[9].relayon)
   {
     mark2 = millis()/1000;
     if ((mark2/1000) - (mark1/1000) > 60)
       mod[9].SWtimer(1);
     else
       mod[9].SW();
   }
   Serial.println(F("CODE_MENU"));
   break;

*
//=============

/*void fn3_projector()
{
  if (mod[9].state == mod[9].relayoff)
  {
    mod[9].SW();
    mod[9].mark1 = millis() / 1000;
  }
  else if (mod[9].state == mod[9].relayon)
  {
    mod[9].mark2 = millis() / 1000;
    if ((mod[9].mark2) - (mod[9].mark1) > 60)
      mod[9].SWtimer(1);
    else
      mod[9].SW();
  }
}
*/



/*
  int brt()
  {
  ldrval = analogRead(A7);
  delay(100);
  // Serial.println(ldrval);
  return ldrval;
  }


  int brt3()
  {
  if (deepc)
  { Serial.println();
    Serial.println();
    Serial.println();
  }
  int n = smooth;
  for (int i = n; i > 0; i--)
  {
    last[i] = last[i - 1];
    if (deepc)  {
      Serial.println();
      Serial.print(F("transfer  "));
      Serial.print(i);
      Serial.print(F("  value  "));
      Serial.print(last[i]);
      Serial.println();
    }
  }
  if (deepc) {
    Serial.println();
    Serial.println();
    Serial.println();
  }
  last[0] = analogRead(ldr) / 10;
  total = 0;
  for (int j = 0; j < n; j++)
  {
    total += last[j];
    if (deepc) {
      Serial.println();
      Serial.print(F("number  "));
      Serial.print(j);
      Serial.print(F("  value  "));
      Serial.print(last[j]);
      Serial.print(F("  total  "));
      Serial.print(total);
      Serial.println();
    }
  }
  if (deepc) {
    Serial.println();
    Serial.println();
    Serial.println();
  }
  average = total / n;
  if (deepc) {
    Serial.println(F("average"));
    Serial.println(F("end of one cycle"));
  }
  return average;
  }
*/



/*
  void deftype(int x)
  {
  mod[x].definetype(0);
  }
  void setinitial(int x)
  {
  mod[x].SWoff();
  mod[x].state = mod[x].relayoff;
  }
  void initialise(int x)
  {
  mod[x].initialise();
  }

*/







//*/
