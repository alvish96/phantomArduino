
//  t1 = millis();
void mainmenu()
{

  t1 = millis();
Serial.println();
  Serial.println("1.Relay Switch");
  Serial.println("2.Set Timer ");
  Serial.println("3.debug Switch");
  Serial.println("4.Reset");
  Serial.println("5.Flags");
  Serial.println("6.skip");


  if (o1 == 0) skip();
  else  readinp();

  switch (input)
  {
    case 1: setrel(); break;
    case 2: setime(); break;
    case 3: debugg(); break;
    case 4: reset(); break;
    case 5: flags();
    case 6: break;
    default: Serial.println("No Input");
  }
}

void skip()
{
  long c = 0;
  int per = 10;
  o = 0;
  bool g = 0;
  while (!g)
  {
    t2 = millis();
    int t3 = 0;

    c++;
    t3 = ((t2 - t1) / 1000);
    if (c == (20+4-2-1)*1000) 
    {
      Serial.print(" ");
      Serial.print(per - t3);
      c = 0;
    }
    int d = (t2 - t1) / 1000;
    if (per < d )
    {
      o = 1;
    }
    g = (Serial.available() || o);
  }
  input = Serial.parseInt();
  Serial.println(input);
m: int xy;
}


void readinp()
{
  Serial.println("Enter Option: ");
  while (!Serial.available())
  {
  }
  input = Serial.parseInt();
  Serial.println(input);

}


void setime()
{
  Serial.println("1.Relay 1 Timer 1");
  Serial.println("2.Relay 1 Timer 2");
  Serial.println("3.Relay 2 Timer 1");
  Serial.println("4.Relay 2 Timer 2");
  Serial.println("5.Back");
  readinp();
  switch (input)
  {
    case 1:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[1] = sethr();
          case 2:  tim[2] = setmin(); break;
          case 3: break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[3] = sethr();
          case 2:  tim[4] = setmin(); break;
          case 3: mainmenu();
          default: Serial.println("Invalid Input"); mainmenu();
        }
      }
    case 2:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[5] = sethr();
          case 2:  tim[6] = setmin(); break;
          case 3: break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[7] = sethr();
          case 2:  tim[8] = setmin(); break;
          case 3: break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
      }
    case 3:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[9] = sethr();
          case 2:  tim[10] = setmin(); break;
          case 3: break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[11] = sethr();
          case 2:  tim[12] = setmin(); break;
          case 3: break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
      }
    case 4:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[13] = sethr();
          case 2:  tim[14] = setmin(); break;
          default: Serial.println("Invalid Input"); mainmenu();
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  tim[15] = sethr();
          case 2:  tim[16] = setmin(); break;

          default: Serial.println("Invalid Input"); mainmenu();
        }
      }

    case 5: mainmenu();
    default: Serial.println("Invalid Input"); mainmenu();
  }

}

void sethrmin()
{
  Serial.println("1.Hour");
  Serial.println("2.Minute");
  Serial.println("3.Back");
  readinp();
  switch (input)
  {
    case 1:  tim[1] = sethr();
    case 2:  tim[2] = setmin();  break;
    case 3: break;
    default: Serial.println("Invalid Input"); mainmenu();
  }
}
int sethr()
{
  Serial.println("Set Hour = ");
  int n;
  readinp();
  n = input;
  Serial.println(n);
  return n;
}
int setmin()
{
  Serial.println("Set Min = ");
  int n;
  readinp();
  n = input;
  Serial.println(n);
  return n;
}





void setrel()
{
  Serial.println("1.Relay 1");
  Serial.println("2.Relay 2");
  Serial.println("3.Back");

  readinp();
  switch (input)
  {

    case 1:
      {
        Serial.println("1.Relay 1 ON");
        Serial.println("2.Relay 1 OFF");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  flag[1] = 1; break;
          case 2:  flag[1] = 0; break;
          case 3: break;


          default: Serial.println("Invalid Input"); mainmenu();
        }
      }
      break;
    case 2:
      {
        Serial.println("1.Relay 1 ON");
        Serial.println("2.Relay 1 OFF");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  flag[2] = 1; break;
          case 2:  flag[2] = 0; break;
          case 3: break;

          default: Serial.println("Invalid Input"); mainmenu();
        }

      }
      break;
    case 3: mainmenu(); break;

    default: Serial.println("Invalid Input"); mainmenu();
  }

}


void settimer()
{
  Serial.println("1.Relay 1 Timer 1");
  Serial.println("2.Relay 1 Timer 2");
  Serial.println("1.Relay 1 Timer 1");
  Serial.println("2.Relay 1 Timer 2");
  Serial.println("3.Back");

  readinp();
  switch (input)
  {

    case 1:
      {
        Serial.println("1.Relay 1 ON");
        Serial.println("2.Relay 1 OFF");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  flag[1] = 1; break;
          case 2:  flag[1] = 0; break;
          case 3: break;


          default: Serial.println("Invalid Input"); mainmenu();
        }
      }
      break;
    case 2:
      {
        Serial.println("1.Relay 1 ON");
        Serial.println("2.Relay 1 OFF");
        Serial.println("3.Back");
        readinp();
        switch (input)
        {
          case 1:  flag[2] = 1; break;
          case 2:  flag[2] = 0; break;
          case 3: break;

          default: Serial.println("Invalid Input"); mainmenu();
        }

      }
      break;
    case 3: mainmenu(); break;

    default: Serial.println("Invalid Input"); mainmenu();
  }

}


void debugg()
{
  Serial.println("1.Debug On");
  Serial.println("2.Debug Off");
  Serial.println("3.Back");

  readinp();
  switch (input)
  {
    case 1:  flag[0] = 1;  break;
    case 2:  flag[0] = 0;  break;
    case 3: mainmenu(); break;
    default: Serial.println("Invalid Input"); mainmenu();
  }
  debug =  flag[0];

}



void reset()
{
  Serial.println("1.Confirm");
  Serial.println("2.Back");

  readinp();
  switch (input)
  {
    case 1:
      {
        //r1t1
        a1 =  tim[1] = 8;
        a2 =  tim[2] = 30;
        b1 =  tim[3] = 15;
        b2 =  tim[4] = 30;

        //r1t2
        a3 =  tim[5] = 18;
        a4 =  tim[6] = 0;
        b3 =  tim[7] = 22;
        b4 =  tim[8] = 0;

        //r2t1
        a5 =  tim[9] = a1;
        a6 =  tim[10] = a2;
        b5 =  tim[11] = b1;
        b6 =  tim[12] = b2;

        //r2t2
        a7 =  tim[13] = a3;
        a8 =  tim[14] = a4;
        b7 =  tim[15] = b3;
        b8 =  tim[16] = b4;


        debug =  flag[0] = 1;                //debug switch
        RSwitch1 =  flag[1] = 1;             //relay 1 switch
        RSwitch2 =  flag[2] = 1;             //relay 2 switch

        R1T1 =  flag[3] = 1;                 //relay 1 timer 1 switch
        R1T2 =  flag[4] = 1;                 //relay 1 timer 2 switch
        R2T1 =  flag[5] = 1;                 //relay 2 timer 1 switch
        R2T2 =  flag[6] = 1;                 //relay 2 timer 2 switch
        flags();
      }
      break;
    case 2: mainmenu();
    default: Serial.println("Invalid Input"); mainmenu();
  }
}
