



void test4()
{
  tim();
  //int i = remote();
  switch (remote())
  {
    case 1:

      Serial.println("CODE_OK"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_OK");
      lcdtimeout();
      break;

    case 2:

      Serial.println("CODE_RIGHT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RIGHT");
      lcdtimeout();

      break;

    case 3:

      Serial.println("CODE_LEFT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_LEFT");
      lcdtimeout();
      break;


    case 4:

      Serial.println("CODE_UP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_UP");
      lcdtimeout();
      break;


    case 5:

      Serial.println("CODE_DOWN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_DOWN");
      lcdtimeout();
      break;


    case 6:

      Serial.println("CODE_MENU"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MENU");
      lcdtimeout();
      break;


    case 7:
      Serial.println("CODE_EXIT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_EXIT");
      lcdtimeout();
      break;


    case 8:

      Serial.println("CODE_SOURCE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOURCE");
      lcdtimeout();
      break;


    case 9:

      Serial.println("CODE_ZOOM"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_ZOOM");
      lcdtimeout();
      break;


    case 10:

      Serial.println("CODE_VOLUP"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLUP");
      lcdtimeout();
      break;


    case 11:

      Serial.println("CODE_VOLDW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VOLDW");
      lcdtimeout();
      break;


    case 12:

      Serial.println("CODE_PIC"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PIC");
      lcdtimeout();
      break;


    case 13:

      Serial.println("CODE_SOUND"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_SOUND");
      lcdtimeout();
      break;


    case 14:

      Serial.println("CODE_FREEZE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_FREEZE");
      lcdtimeout();
      break;


    case 15:

      Serial.println("CODE_PLAY"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_PLAY");

      lcdlightSW();
      lcdtimeout();
      break;


    case 16:

      Serial.println("CODE_MUTE"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_MUTE");
      // mute();

      lcdtimeout();
      break;


    case 17:

      Serial.println("CODE_FF"); lcd.clear(); lcd.setCursor(0, 0);   lcd.print("CODE_FF");
      lcdtimeout();
      break;


    case 18:

      Serial.println("CODE_RW"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RW");
      lcdtimeout();
      break;

    case 19:

      Serial.println("CODE_NEXT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_NEXT");
      lcdtimeout();
      break;

    case 20:

      Serial.println("CODE_BACK"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_BACK");
      lcdtimeout();
      break;

    case 21:

      Serial.println("CODE_VERT"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_VERT");
      lcdtimeout();
      break;

    case 22:

      Serial.println("CODE_HORI"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_HORI");
      lcdtimeout();
      break;

    case 23:

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

    case 24:

      Serial.println("CODE_LISTEN"); lcd.clear(); lcd.setCursor(0, 0); lcd.print("CODE_RESET");
      lcd.setCursor(0, 1);
      lcd.print("reset initiated");
      delay(1000);
      lcd.clear();



      Serial.println("Resetting in 1 second"); buzz(5); del();

      resetFunc();  //call reset
      lcdtimeout();
      break;

      /*
          default:
            Serial.println("INVALID"); buzz(2); del();
            break;*/
  }
}
