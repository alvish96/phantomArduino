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
   Serial.println("CODE_MENU");
   break;

*
//=============


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
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
      Serial.print("transfer  ");
      Serial.print(i);
      Serial.print("  value  ");
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
      Serial.print("number  ");
      Serial.print(j);
      Serial.print("  value  ");
      Serial.print(last[j]);
      Serial.print("  total  ");
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
    Serial.println("average");
    Serial.println("end of one cycle");
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


//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
