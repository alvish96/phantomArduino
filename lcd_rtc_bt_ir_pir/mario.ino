
void check()
{lightflag=0;
  exitloop = 0;
  if (ir.decode(&irresult))
  {
    if (irresult.value == 0x61D6728D)
      exitloop = 1;
    ir.resume();
  }
}

void mario() {

  lcd.setCursor(0, 0);           //intro
  lcd.print("  8-Bit Mario");
  lcd.setCursor(0, 1);
  lcd.print(" Run Animation");
  delay(800);
  lcd.clear();

  for (int a = 0; a < 16; a++)              //for loop to repeat marios animation until the end of the display
  {
    int b = a + 1;
    int c = a + 2;
    int d = a + 3;
    int e = a + 4;

    lcd.createChar(1, mario11);
    lcd.createChar(2, mario12);
    lcd.createChar(3, mario13);
    lcd.createChar(4, mario14);
    lcd.createChar(5, mario15);
    lcd.createChar(6, mario16);
    lcd.createChar(7, clean);

    lcd.setCursor(a, 0);
    lcd.write(1);
    lcd.setCursor(a, 1);
    lcd.write(2);
    lcd.setCursor(b, 0);
    lcd.write(3);
    lcd.setCursor(b, 1);
    lcd.write(4);
    lcd.setCursor(c, 0);
    lcd.write(5);
    lcd.setCursor(c, 1);
    lcd.write(6);
    delay(s); check(); if (exitloop == 1)
    {
      lcd.print("EXITING");
      delay(400);
      break;
    }

    lcd.createChar(1, mario21);
    lcd.createChar(2, mario22);
    lcd.createChar(3, mario23);
    lcd.createChar(4, mario24);
    lcd.createChar(5, mario25);
    lcd.createChar(6, mario26);

    lcd.setCursor(a, 0);
    lcd.write(1);
    lcd.setCursor(a, 1);
    lcd.write(2);
    lcd.setCursor(b, 0);
    lcd.write(3);
    lcd.setCursor(b, 1);
    lcd.write(4);
    lcd.setCursor(c, 0);
    lcd.write(5);
    lcd.setCursor(c, 1);
    lcd.write(6);

    delay(s); check(); if (exitloop == 1)     {
      lcd.print("EXITING");
      delay(400);
      break;
    }

    lcd.createChar(1, mario31);
    lcd.createChar(2, mario32);
    lcd.createChar(3, mario33);
    lcd.createChar(4, mario34);
    lcd.createChar(5, mario35);
    lcd.createChar(6, mario36);

    lcd.setCursor(a, 0);
    lcd.write(1);
    lcd.setCursor(a, 1);
    lcd.write(2);
    lcd.setCursor(b, 0);
    lcd.write(3);
    lcd.setCursor(b, 1);
    lcd.write(4);
    lcd.setCursor(c, 0);
    lcd.write(5);
    lcd.setCursor(c, 1);
    lcd.write(6);

    delay(s); check(); if (exitloop == 1)     {
      lcd.print("EXITING");
      delay(400);
      break;
    }

    lcd.createChar(1, mario41);
    lcd.createChar(2, mario42);
    lcd.createChar(3, mario43);
    lcd.createChar(4, mario44);
    lcd.createChar(7, clean);
    lcd.setCursor(a, 0);
    lcd.write(7);
    lcd.setCursor(a, 1);
    lcd.write(7);
    lcd.setCursor(b, 0);
    lcd.write(1);
    lcd.setCursor(b, 1);
    lcd.write(2);
    lcd.setCursor(c, 0);
    lcd.write(3);
    lcd.setCursor(c, 1);
    lcd.write(4);


    delay(s); check(); if (exitloop == 1)     {
      lcd.print("EXITING");
      delay(400);
      break;
    }


    lcd.createChar(1, mario51);
    lcd.createChar(2, mario52);
    lcd.createChar(3, mario53);
    lcd.createChar(4, mario54);
    lcd.createChar(5, mario55);
    lcd.createChar(6, mario56);
    lcd.createChar(7, clean);
    lcd.setCursor(a, 0);
    lcd.write(7);
    lcd.setCursor(a, 1);
    lcd.write(7);
    lcd.setCursor(b, 0);
    lcd.write(1);
    lcd.setCursor(b, 1);
    lcd.write(2);
    lcd.setCursor(c, 0);
    lcd.write(3);
    lcd.setCursor(c, 1);
    lcd.write(4);
    lcd.setCursor(d, 0);
    lcd.write(5);
    lcd.setCursor(d, 1);
    lcd.write(6);

    delay(s); check(); if (exitloop == 1)     {
      lcd.print("EXITING");
      delay(400);
      break;
    }

    lcd.createChar(1, mario61);
    lcd.createChar(2, mario62);
    lcd.createChar(3, mario63);
    lcd.createChar(4, mario64);
    lcd.createChar(5, mario65);
    lcd.createChar(6, mario66);
    lcd.setCursor(b, 0);
    lcd.write(1);
    lcd.setCursor(b, 1);
    lcd.write(2);
    lcd.setCursor(c, 0);
    lcd.write(3);
    lcd.setCursor(c, 1);
    lcd.write(4);
    lcd.setCursor(d, 0);
    lcd.write(5);
    lcd.setCursor(d, 1);
    lcd.write(6);

    delay(s); check(); if (exitloop == 1)     {
      lcd.print("EXITING");
      delay(400);
      break;
    }
  }

}
