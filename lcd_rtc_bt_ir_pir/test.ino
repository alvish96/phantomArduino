void test()
{
x: int a = remote();Serial.println(a);
  if (a == 7)
  { goto y;
    Serial.println("entered if");
  }
  else
  {
    goto x; Serial.println("goto x");
  }
y: lcd.clear(); lcd.setCursor(0, 0); lcd.print("EXITING SOURCE");
Serial.println("exit");
}

void test1()
{ bool fl;
x: unsigned long a = remote();Serial.println(a);

  if (a == 0x61D6728D)
  {Serial.println("entered if");
    fl = 1; 
    Serial.println("goto y");
    goto y;
  }
  while (fl == 0)   
  //if this is false >exit\\if true loop
  {
    Serial.println("inside while");a=0;
    goto x;
    Serial.println("goto x");
  }
  
  /*{
    a=remote();
    }*/

y: lcd.clear(); lcd.setCursor(0, 0); lcd.print("EXITING SOURCE");
Serial.println("exit");
}
