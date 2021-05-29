
void remote()
{
  if (ir.decode(&irresult))
  {
    switch (irresult.value)
    {


      case (0x61D628D7):
        Serial.println("CODE_SELECT");
        ledf = !ledf;
        break;

      case 0x61D69A65:
        Serial.println("CODE_RIGHT");
     if((inten-=10) < 0)
        inten -= 10;
        break;

      case 0x61D6A857:
      if((inten += 10)>255)
        inten += 10;
        Serial.println("CODE_LEFT");
        break;

      case 0x61D6AA55:
      if((inten-=50) < 0)
        inten -= 50;
        Serial.println("CODE_UP");
        break;

      case 0x61D618E7:
        if((inten += 50)>255)
        inten += 50;
        Serial.println("CODE_DOWN");
        break;

      case 0x61D632CD:

        Serial.println("CODE_MENU");
        break;

      case 0x61D6728D:
        Serial.println("CODE_EXIT");
        break;

      case 0x61D6D02F:
        Serial.println("CODE_SOURCE");
        break;

      case 0x61D6F00F:
        Serial.println("CODE_ZOOM");
        break;

      case 0x61D6708F:

        Serial.println("CODE_VOLUP");
        break;

      case 0x61D612ED:

        Serial.println("CODE_VOLDW");
        break;

      case 0x61D6629D:
        Serial.println("CODE_PIC");
        break;

      case 0x61D6EA15:
        Serial.println("CODE_SOUND");
        break;

      case 0x61D6DA25:
        Serial.println("CODE_FREEZE");
        break;

      case 0x61D6906F:
        Serial.println("CODE_PLAY");
        break;

      case (0x61D652AD):
        segm = !segm;
        Serial.println("CODE_MUTE");
        break;

      case 0x61D648B7:
        Serial.println("CODE_FF");
        break;

      case 0x61D610EF:
        Serial.println("CODE_RW");
        break;

      case 0x61D6F20D:
        Serial.println("CODE_NEXT");
        break;

      case 0x61D630CF:
        Serial.println("CODE_BACK");
        break;

      case 0x61D69867:
        Serial.println("CODE_VERT");
        break;


      case 0x61D6A25D:
        Serial.println("CODE_HORI");
        break;

      case (0x61D67887):
        Serial.println("CODE_LISTEN");
        break;


      case 0x61D650AF:
        Serial.println("CODE_POWER");
        oled = !oled;
        break;

      //--------------------------------------------------------------------------------
      case 0x5E7DB3DC ://power
        Serial.println("CODE_POWER MOB");
        break;

      case 0xF874E0F8 ://home
        Serial.println("CODE_HOME MOB");
        break;

      case 0xF574DC41 ://option
        Serial.println("CODE_OPTION MOB");
        break;

      case 0x76A77416 ://ok
        Serial.println("CODE_OK MOB");
        break;

      case 0x8453B5A5 ://vol  down
        Serial.println("CODE_VOLDOWN MOB");
        break;

      case 0x8753BA5C :// vol up
        Serial.println("CODE_VOLUP MOB");
        break;

      case 0xEB58E7B6 ://back
        Serial.println("CODE_BACK MOB");
        break;

      case 0x52120F2 ://up
        Serial.println("CODE_UP MOB");
        break;

      case 0x6212287 ://up
        Serial.println("CODE_UP MOB");
        break;

      case 0xDE3AA631 ://down
        Serial.println("CODE_DOWN MOB");
        break;

      case 0xEA58E625 ://left
        Serial.println("CODE_LEFT MOB");
        break;

      case 0x69893291 ://right
        Serial.println("CODE_RIGHT MOB");
        break;

      default : Serial.println("INVALID");

    }
    delay(100);
    ir.resume();
  }
}
