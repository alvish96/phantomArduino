void mainmenu()
{
  Serial.println("1.Relay Switch");
  Serial.println("2.Timer Switch");
  Serial.println("3.debug Switch");
  Serial.println("4.Reset");
  Serial.println("5.skip");
  readinp();
  switch (input)
  {
    case 1: setrel(); break;
    case 2: setime(); break;
    case 3: debugg(); break;
    case 4: reset(); break;
    case 5: break;

  }
}


void readinp()
{
  Serial.println("Enter input Number: ");
  while (!Serial.available()) {
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
        readinp();
        switch (input)
        {
          case 1: obj.tim[1] = sethr(); 
          case 2: obj.tim[2] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[3] = sethr(); 
          case 2: obj.tim[4] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
      }
    case 2:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[5] = sethr(); 
          case 2: obj.tim[6] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[7] = sethr();
          case 2: obj.tim[8] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
      }
    case 3:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[9] = sethr();
          case 2: obj.tim[10] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[11] = sethr(); 
          case 2: obj.tim[12] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
      }
    case 4:
      {
        Serial.println("From");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[13] = sethr(); 
          case 2: obj.tim[14] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
        Serial.println("To");
        Serial.println("1.Hour");
        Serial.println("2.Minute");
        readinp();
        switch (input)
        {
          case 1: obj.tim[15] = sethr();
          case 2: obj.tim[16] = setmin(); break;
          default: Serial.println("Invalid Input");
        }
      }

    case 5: mainmenu();
    default: Serial.println("Invalid Input");
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
    case 1: obj.tim[1] = sethr();  
    case 2: obj.tim[2] = setmin();  break;
    case 3:break;
default: Serial.println("Invalid Input");
  }
}
int sethr()
{
  Serial.println("Set Hour = ");
  int n;
  readinp();
  n=input;
  Serial.println(n);
  return n;
}
int setmin()
{
  Serial.println("Set Min = ");
  int n;
  readinp();
  n=input;
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
          case 1: obj.flag[1] = 1; break;
          case 2: obj.flag[1] = 0; break;
          case 3: break;


          default: Serial.println("Invalid Input");
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
          case 1: obj.flag[2] = 1; break;
          case 2: obj.flag[2] = 0; break;
          case 3: break;

          default: Serial.println("Invalid Input");
        }

      }
      break;
    case 3: mainmenu(); break;

    default: Serial.println("Invalid Input");
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
    case 1: obj.flag[0] = 1;  break;
    case 2: obj.flag[0] = 0;  break;
    case 3: mainmenu(); break;
    default: Serial.println("Invalid Input");
  }
  debug = obj.flag[0];

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
        a1 = obj.tim[1] = 8;
        a2 = obj.tim[2] = 30;
        b1 = obj.tim[3] = 15;
        b2 = obj.tim[4] = 30;

        //r1t2
        a3 = obj.tim[5] = 18;
        a4 = obj.tim[6] = 0;
        b3 = obj.tim[7] = 22;
        b4 = obj.tim[8] = 0;

        //r2t1
        a5 = obj.tim[9] = a1;
        a6 = obj.tim[10] = a2;
        b5 = obj.tim[11] = b1;
        b6 = obj.tim[12] = b2;

        //r2t2
        a7 = obj.tim[13] = a3;
        a8 = obj.tim[14] = a4;
        b7 = obj.tim[15] = b3;
        b8 = obj.tim[16] = b4;


        debug = obj.flag[0] = 1;                //debug switch
        RSwitch1 = obj.flag[1] = 1;             //relay 1 switch
        RSwitch2 = obj.flag[2] = 1;             //relay 2 switch

        R1T1 = obj.flag[3] = 1;                 //relay 1 timer 1 switch
        R1T2 = obj.flag[4] = 1;                 //relay 1 timer 2 switch
        R2T1 = obj.flag[5] = 1;                 //relay 2 timer 1 switch
        R2T2 = obj.flag[6] = 1;                 //relay 2 timer 2 switch
      }
      break;
    case 2: mainmenu();
    default: Serial.println("Invalid Input");
  }
}
