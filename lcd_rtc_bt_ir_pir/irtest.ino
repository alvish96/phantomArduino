

void irtest()
{
  if (power == 0)
  {
    digitalWrite(lcdlyt, 0);
    // mario();

    /*  int a2 = remote();
      if (a2 == 23)
      {
        powersw();
      }
    */

    if (ir.decode(&irresult))
    {
      if (irresult.value == 0x61D650AF)
        powersw();
      ir.resume();
    }


  }



  if (power == 1)
  {
    tim(); autobtness();
    if (ir.decode(&irresult))
    {
      buzz();
      switch (irresult.value)
      {
        case 0x61D628D7: pre = 1;
          Serial.println("CODE_SELECT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SELECT");
          lcdtimeout();
          break;

        case 0x61D69A65: pre = 2;
          Serial.println("CODE_RIGHT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RIGHT");
          nytlytmode();
          lcdtimeout();

          break;

        case 0x61D6A857: pre = 3;
          Serial.println("CODE_LEFT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_LEFT");
          lcdtimeout();
          break;


        case 0x61D6AA55: pre = 4;
          Serial.println("CODE_UP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_UP");
          btnessup();
          lt();
          break;


        case 0x61D618E7: pre = 5;
          Serial.println("CODE_DOWN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_DOWN");
          btnessdn();
          lt();
          break;


        case 0x61D632CD: pre = 6;
          Serial.println("CODE_MENU"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MENU");
          lcdtimeout();
          break;


        case 0x61D6728D: pre = 7;
          Serial.println("CODE_EXIT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_EXIT");
          lcdtimeout();
          break;


        case 0x61D6D02F: pre = 8;
          Serial.println("CODE_SOURCE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOURCE");
          //  test1();
          nytlytsw1();
          lcdtimeout();
          break;


        case 0x61D6F00F: pre = 9;
          Serial.println("CODE_ZOOM"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_ZOOM");
          lcdtimeout();
          break;


        case 0x61D6708F: pre = 10;
          Serial.println("CODE_VOLUP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLUP");
          lcdtimeout();
          break;


        case 0x61D612ED: pre = 11;
          Serial.println("CODE_VOLDW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLDW");
          lcdtimeout();
          break;


        case 0x61D6629D: pre = 12;
          Serial.println("CODE_PIC"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PIC");
          lcdtimeout();
          break;


        case 0x61D6EA15: pre = 13;
          Serial.println("CODE_SOUND"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOUND");
          lcdtimeout();
          break;


        case 0x61D6DA25: pre = 14;
          Serial.println("CODE_FREEZE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_FREEZE");
          lcdtimeout();
          break;


        case 0x61D6906F: pre = 15;
          Serial.println("CODE_PLAY"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PLAY");
          lcdlightSW();
          ov = 1;    //overwrite bool  automode off mode
          lcdtimeout();
          break;


        case 0x61D652AD: pre = 16;
          Serial.println("CODE_MUTE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MUTE");
          // mute();

          lcdtimeout();
          break;


        case 0x61D648B7: pre = 17;
          Serial.println("CODE_FF"); lcd.clear(); lcd.setCursor(0, 0);   lcd.print("CODE_FF");
          lcdtimeout();
          break;


        case 0x61D610EF: pre = 18;
          Serial.println("CODE_RW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RW");
          lcdtimeout();
          break;

        case 0x61D6F20D: pre = 19;
          Serial.println("CODE_NEXT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_NEXT");
          lcdtimeout();
          break;

        case 0x61D630CF: pre = 20;
          Serial.println("CODE_BACK"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_BACK");
          lcdtimeout();
          break;

        case 0x61D69867: pre = 21;
          Serial.println("CODE_VERT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VERT");

          lcdtimeout();
          mario();
          break;

        case 0x61D6A25D: pre = 22;
          Serial.println("CODE_HORI"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_HORI");
          lcdtimeout();
          break;

        case 0x61D67887: pre = 24;
          Serial.println("CODE_LISTEN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RESET");
          lcd.setCursor(0, 1);
          lcd.print("reset initiated");
          delay(1000);
          lcd.clear();
          Serial.println("Resetting in 1 second");
          resetbuzz();
          resetflags();
          digitalWrite(lpos, 0);
          resetFunc();  //call reset
          lcdtimeout();
          break;

        case 0x61D650AF: pre = 23;
          Serial.println("CODE_POWER");
          lcd.clear(); lcd.setCursor(0, 0);
          lcd.print("CODE_POWER");
          powersw();
          delay(1000);



          /*
                  Serial.println("CODE_POWER");
                  lcd.clear(); lcd.setCursor(0, 0);
                  lcd.print("CODE_POWER");
                  lcd.setCursor(0, 1);
                  lcd.print("CONFIRM ?");

            x: int k = remote();
                  Serial.print("from main ");   Serial.println(k);
                  // while(k==pre)
                  //goto x;
                  if (k == 1)
                  {
                    lcd.clear(); lcd.setCursor(0, 0);
                    lcd.print("CONFIRMED!"); delay(500); buzz(); del(); longbuzz();
                    lcd.setCursor(0, 0);    lcd.print("PRESS RESET ");
                    lcd.setCursor(0, 1);    lcd.print("TO START AGAIN "); del();
                    term();
                  } else if (k == 7) {
                    lcd.clear(); lcd.setCursor(0, 0);
                    lcd.print("ABORT!");     lcdtimeout();
                    break;
                  }
                  else {
                    lcd.clear(); lcd.setCursor(0, 0);
                    lcd.print("INVALID INPUT!");
                    lcd.setCursor(0, 1);
                    lcd.print("FROM ELSE");
                    lcdtimeout();
                    break;
                  }

                  /*


                    void buttonWait(int buttonPin){
                    int buttonState = 0;
                    while(1)
                    {
                      buttonState = digitalRead(buttonPin);
                      if (buttonState == HIGH)
                      {
                      return;

                      void keeps checking all the values for the next thing

                    }

                             }


                                  while (ir.decode(&irresult))
                                  {
                                    if ( irresult.value == 0x61D628D7)
                                    { lcd.clear(); lcd.setCursor(0, 0);
                                      lcd.print("CONFIRMED!"); delay(500); buzz(); del(); longbuzz();
                                      lcd.setCursor(0, 0);    lcd.print("PRESS RESET ");
                                      lcd.setCursor(0, 1);    lcd.print("TO START AGAIN "); del();
                                      term();
                                    } else {
                                      lcd.clear(); lcd.setCursor(0, 0);
                                      lcd.print("ABORT!");
                                      return;
                                    }
                                  }
          */


          break;




          /* delay(1000);
            lcd.clear();



            Serial.println("Resetting in 1 second"); buzz(5); del();
            void(* resetFunc) (void) = 0; //declare reset function @ address 0
            resetFunc();  //call reset
          */


          //  default:
          //   Serial.println("nothing");//      Serial.println("delay"); delay(1000);
          //       continue;

      }

      ir.resume(); //delay(10);

    }
  }
}
