
void remote()
{
  if (ir.decode(&irresult))
  {
    if (irresult.value == 0x61D6F00F)//1.86
    {

      rem = !rem;
      Serial.println(F("CODE_ZOOM"));
      if (rem) {
        Serial.println(F("REMOTE ON"));
      }
      if (!rem) {
        Serial.println(F("REMOTE OFF"));
      }
    }
    if (rem)
      switch (irresult.value)
      {

        case 0x61D6F00F:
          Serial.println(F("CODE_ZOOM"));
          break;

        case (0x61D628D7):
          Serial.println(F("CODE_SELECT"));
          break;

        case 0x61D69A65:
          right();
          Serial.println(F("CODE_RIGHT"));
          break;

        case 0x61D6A857:
          left();
          Serial.println(F("CODE_LEFT"));
          break;

        case 0x61D6AA55:
          up();
          Serial.println(F("CODE_UP"));
          break;

        case 0x61D618E7:
          down();
          Serial.println(F("CODE_DOWN"));
          break;

        case 0x61D632CD:
          Serial.println(F("CODE_MENU"));
          break;


        case 0x61D6728D:
          Serial.println(F("CODE_EXIT"));
          break;

        case 0x61D6D02F:
          Serial.println(F("CODE_SOURCE"));
          break;

        case 0x61D6708F:
          whspsw();
          Serial.println(F("CODE_VOLUP"));
          break;

        case 0x61D612ED:
          blspsw();
          Serial.println(F("CODE_VOLDW"));
          break;

        case 0x61D6629D:
          Serial.println(F("CODE_PIC"));
          break;

        case 0x61D6EA15:
          Serial.println(F("CODE_SOUND"));
          break;

        case 0x61D6DA25:
          Serial.println(F("CODE_FREEZE"));
          break;

        case 0x61D6906F:
          Serial.println(F("CODE_PLAY"));
          break;

        case (0x61D652AD):
          bluesw();
          Serial.println(F("CODE_MUTE"));
          break;

        case 0x61D648B7:
          bluepause();
          Serial.println(F("CODE_FF"));
          break;

        case 0x61D610EF:
          whitepause();
          Serial.println(F("CODE_RW"));
          break;

        case 0x61D6F20D:
          bluectrl();
          Serial.println(F("CODE_NEXT"));
          break;

        case 0x61D630CF:
          whitectrl();
          Serial.println(F("CODE_BACK"));
          break;

        case 0x61D69867:
        debug=!debug;
          Serial.println(F("CODE_VERT"));
          break;


        case 0x61D6A25D:
          Serial.println(F("CODE_HORI"));
          break;

        case (0x61D67887):
          Serial.println(F("CODE_LISTEN"));
          turnoff();
          resetFunc();
          break;

        case 0x61D650AF:
          Serial.println(F("CODE_POWER"));
          whitesw();
          break;


        default:
          Serial.println(irresult.value, HEX);


      }
    delay(200);
    ir.resume();
  }


}
