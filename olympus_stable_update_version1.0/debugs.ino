//---------------------------------------------------------------------------------------------------

void pf()
{
  /*Serial.println();
    Serial.print(" f1 ");
    Serial.print(f1);
    Serial.print(" || ");
    Serial.print(" f2 ");
    Serial.print(f2);
    Serial.print(" || ");
    Serial.print(" f3 ");
    Serial.print(f3);
    Serial.print(" || ");
    Serial.print(" f4 ");
    Serial.print(f4);
    Serial.print(" || ");
    Serial.print(" f11 ");
    Serial.print(f11);
    Serial.print(" || ");
    Serial.print(" f21 ");
    Serial.print(f21);
    Serial.print(" || ");
    Serial.print(" f31 ");
    Serial.print(f31);
    Serial.print(" || ");
    Serial.print(" f41 ");
    Serial.print(f41);
    Serial.print(" || ");

    Serial.print(" Gap ");
    Serial.print(present - lastmotion);
    Serial.print(" || ");
    Serial.print(" CNT ");
    Serial.print(count);
    Serial.print(" || ");
    Serial.print(" brt ");
    // Serial.print(brt());
    Serial.print(" || ");
    Serial.print(" PT ");
    Serial.print(prflag);
    Serial.print(" || ");
  */

}
int printtimer(unsigned long a, unsigned long b)
{
  int  x = (((a + b) - millis()) / 1000);

  if (x < 0)
    x = 0;
  return x;
}


void printvals()
{
  if(debug==1){
  Serial.println();
  Serial.print(" f1 ");
  Serial.print(f1);
  Serial.print(" || ");
  Serial.print(" f2 ");
  Serial.print(f2);
  Serial.print(" || ");
  Serial.print(" f3 ");
  Serial.print(f3);
  Serial.print(" || ");
  Serial.print(" f4 ");
  Serial.print(f4);
  Serial.print(" || ");
  Serial.print(" f5  ");
  Serial.print(f5 );
  Serial.print(" || ");
  Serial.print(" f6  ");
  Serial.print(f6 );
  Serial.print(" || ");
  Serial.print(" f7  ");
  Serial.print(f7 );
  Serial.print(" || ");
  Serial.print(" f8  ");
  Serial.print(f8 );
  Serial.print(" || ");
  Serial.print(" f9  ");
  Serial.print(f9 );
  Serial.print(" || ");
  Serial.print(" f10 ");
  Serial.print(f10);
  Serial.print(" || ");
  Serial.print(" f11 ");
  Serial.print(f11);
  Serial.print(" || ");
  Serial.print(" Gap ");
  Serial.print(present - lastmotion);
  Serial.print(" || ");
  Serial.print(" count ");
  Serial.print(count);
  Serial.print(" || ");
  Serial.print(" brt ");
  Serial.print(brt());
  Serial.print(" || ");
  Serial.print(" priority ");
  Serial.print(prflag);
  Serial.print(" || ");
  Serial.print(" motion ");
  Serial.print(checkmotion);
  Serial.print(" || ");

  Serial.print(" TIMER ");

  Serial.print(" T1 ");
  Serial.print(printtimer(a1, x1));
  Serial.print(" || ");

  Serial.print(" T2 ");
  Serial.print(printtimer(a2, x2));
  Serial.print(" || ");

  Serial.print(" T3 ");
  Serial.print(printtimer(a3, x3));
  Serial.print(" || ");

  Serial.print(" T4 ");
  Serial.print(printtimer(a4, x4));
  Serial.print(" || ");

  Serial.print(" T5 ");
  Serial.print(printtimer(a5 , x5 ));
  Serial.print(" || ");

  Serial.print(" T6 ");
  Serial.print(printtimer(a6 , x6 ));
  Serial.print(" || ");

  Serial.print(" T7 ");
  Serial.print(printtimer(a7 , x7 ));
  Serial.print(" || ");

  Serial.print(" T8 ");
  Serial.print(printtimer(a8 , x8 ));
  Serial.print(" || ");

  Serial.print(" T9 ");
  Serial.print(printtimer(a9 , x9 ));
  Serial.print(" || ");

  Serial.print(" T10 ");
  Serial.print(printtimer(a10, x10));
  Serial.print(" || ");

  Serial.print(" T11 ");
  Serial.print(printtimer(a11, x11));
  Serial.print(" || ");

  }

}
