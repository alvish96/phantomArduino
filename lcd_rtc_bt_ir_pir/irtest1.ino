

int irtest1()
{ // tim();
  int j = 0;
  if (ir.decode(&irresult))
  { buzz();
    switch (irresult.value)
    {
      case 0x61D628D7:
        j = 1;

        Serial.println("select"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("OK");
        lcdtimeout();
        return j;
        break;

      case 0x61D69A65:
        j = 2;
        return j;
        Serial.println("CODE_RIGHT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RIGHT");
        lcdtimeout();

        break;

      case 0x61D6A857:
        j = 3;
        return j;
        Serial.println("CODE_LEFT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_LEFT");
        lcdtimeout();
        break;


      case 0x61D6AA55:
        j = 4;
        return j;
        Serial.println("CODE_UP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_UP");
        lcdtimeout();
        break;


      case 0x61D618E7:
        j = 5;
        return j;
        Serial.println("CODE_DOWN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_DOWN");
        lcdtimeout();
        break;


      case 0x61D632CD:
        j = 6;
        return j;
        Serial.println("CODE_MENU"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MENU");
        lcdtimeout();
        break;


      case 0x61D6728D:
        j = 7;
        return j;
        Serial.println("CODE_EXIT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_EXIT");
        lcdtimeout();
        break;


      case 0x61D6D02F:
        j = 8;
        return j;
        Serial.println("CODE_SOURCE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOURCE");
        lcdtimeout();
        break;


      case 0x61D6F00F:
        j = 9;
        return j;
        Serial.println("CODE_ZOOM"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_ZOOM");
        lcdtimeout();
        break;


      case 0x61D6708F:
        j = 10;
        return j;
        Serial.println("CODE_VOLUP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLUP");
        lcdtimeout();
        break;


      case 0x61D612ED:
        j = 11;
        return j;
        Serial.println("CODE_VOLDW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLDW");
        lcdtimeout();
        break;


      case 0x61D6629D:
        j = 12;
        return j;
        Serial.println("CODE_PIC"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PIC");
        lcdtimeout();
        break;


      case 0x61D6EA15:
        j = 13;
        return j;
        Serial.println("CODE_SOUND"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOUND");
        lcdtimeout();
        break;


      case 0x61D6DA25:
        j = 14;
        return j;
        Serial.println("CODE_FREEZE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_FREEZE");
        lcdtimeout();
        break;


      case 0x61D6906F:
        j = 15;
        return j;
        Serial.println("CODE_PLAY"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PLAY");
        ov = 1;
        lcdlightSW();
        lcdtimeout();
        break;


      case 0x61D652AD:
        j = 16;
        return j;
        Serial.println("CODE_MUTE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MUTE");
        // mute();

        lcdtimeout();
        break;


      case 0x61D648B7:
        j = 17;
        return j;
        Serial.println("CODE_FF"); lcd.clear(); lcd.setCursor(0, 0);   lcd.print("CODE_FF");
        lcdtimeout();
        break;


      case 0x61D610EF:
        j = 18;
        return j;
        Serial.println("CODE_RW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RW");
        lcdtimeout();
        break;

      case 0x61D6F20D:
        j = 19;
        return j;
        Serial.println("CODE_NEXT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_NEXT");
        lcdtimeout();
        break;

      case 0x61D630CF:
        j = 20;
        return j;
        Serial.println("CODE_BACK"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_BACK");
        lcdtimeout();
        break;

      case 0x61D69867:
        j = 21;
        return j;
        Serial.println("CODE_VERT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VERT");
        lcdtimeout();
        break;

      case 0x61D6A25D:
        j = 22;
        return j;
        Serial.println("CODE_HORI"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_HORI");
        lcdtimeout();
        break;

      case 0x61D650AF:
        j = 23;
        return j;
        lcd.clear(); lcd.setCursor(0, 0);
        Serial.println("CODE_POWER");
        lcd.clear(); lcd.setCursor(0, 0);
        lcd.print("CODE_POWER");
        lcd.setCursor(0, 1);
        lcd.print("CONFIRM ?");

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
        lcdtimeout();
        break;

      case 0x61D67887:
        j = 24;
        return j;
        Serial.println("CODE_LISTEN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RESET");
        lcd.setCursor(0, 1);
        lcd.print("reset initiated");
        delay(1000);
        lcd.clear();
        Serial.println("Resetting in 1 second"); buzz(5); del();
        resetFunc();  //call reset
        lcdtimeout();
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
    //   irresult.value = 0;
    ir.resume(); //delay(10);

  }
}
