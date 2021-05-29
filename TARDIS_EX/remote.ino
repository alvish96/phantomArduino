
void remote()
{
  if (ir.decode(&irresult))
  {
    switch (irresult.value)
    {
      case (0x61D628D7):
        Serial.println("CODE_SELECT");

        ledf = !ledf;
        Serial.print(" RGB LED ledf ");
        Serial.print(ledf);
        line(); break;

      case 0x61D69A65:
        Serial.println("CODE_RIGHT");
        if ((inten -= 10) < 0)
          inten -= 10;
        line(); break;

      case 0x61D6A857:
        if ((inten += 10) > 255)
          inten += 10;
        Serial.println("CODE_LEFT");
        line(); break;

      case 0x61D6AA55:
        if ((inten -= 50) < 0)
          inten -= 50;
        Serial.println("CODE_UP");
        line(); break;

      case 0x61D618E7:
        if ((inten += 50) > 255)
          inten += 50;
        Serial.println("CODE_DOWN");
        line(); break;

      case 0x61D632CD:

        Serial.println("CODE_MENU");
        line(); break;

      case 0x61D6728D:
        swTMD();
        Serial.println("CODE_EXIT");
        Serial.print(" TRANSMIT MOTION DATA SWITCH ");
        Serial.print(b1);
        line(); break;

      case 0x61D6D02F:
        Serial.println("CODE_SOURCE");
        line(); break;

      case 0x61D6F00F:
        Serial.println("CODE_ZOOM");
        line(); break;

      case 0x61D6708F:

        Serial.println("CODE_VOLUP");
        line(); break;

      case 0x61D612ED:

        Serial.println("CODE_VOLDW");
        line(); break;

      case 0x61D6629D:
        MSL = !MSL;
        Serial.println("CODE_PIC");
        Serial.print(" MSL SWITCH ");
        Serial.print(MSL);
        line(); break;

      case 0x61D6EA15:
        RP = !RP;

        Serial.println("CODE_SOUND");
        Serial.print(" RP SWITCH ");
        Serial.print(RP);
        line(); break;

      case 0x61D6DA25:
        RDP = !RDP;
        Serial.println("CODE_FREEZE");
        Serial.print(" RDP SWITCH ");
        Serial.print(RDP);
        line(); break;

      case 0x61D6906F:
      volt=!volt;
              Serial.println("CODE_PLAY");
        Serial.print(" VOLT SWITCH ");
        Serial.print(volt);
        line(); break;

      case (0x61D652AD):
        segm = !segm;
        Serial.println("CODE_MUTE");
        Serial.print(" SEGM SWITCH ");
        Serial.print(segm);
        line(); break;

      case 0x61D648B7:
        Serial.println("CODE_FF");
        line(); break;

      case 0x61D610EF:
        Serial.println("CODE_RW");
        line(); break;

      case 0x61D6F20D:
        Serial.println("CODE_NEXT");
        line(); break;

      case 0x61D630CF:
        Serial.println("CODE_BACK");
        line(); break;

      case 0x61D69867:
        Serial.println("CODE_VERT");
        line(); break;


      case 0x61D6A25D:
        Serial.println("CODE_HORI");
        line(); break;

      case (0x61D67887):
        Serial.println("CODE_LISTEN");
        resetFunc();
        line(); break;


      case 0x61D650AF:  oled = !oled;
        Serial.println("CODE_POWER");
        Serial.print(" DISPLAY SWITCH ledf ");
        Serial.print(oled);

        line(); break;

      //--------------------------------------------------------------------------------
      case 0x5E7DB3DC ://power
        Serial.println("CODE_POWER MOB");
        line(); break;

      case 0xF874E0F8 ://home
        Serial.println("CODE_HOME MOB");
        line(); break;

      case 0xF574DC41 ://option
        Serial.println("CODE_OPTION MOB");
        line(); break;

      case 0x76A77416 ://ok
        Serial.println("CODE_OK MOB");
        line(); break;

      case 0x8453B5A5 ://vol  down
        Serial.println("CODE_VOLDOWN MOB");
        line(); break;

      case 0x8753BA5C :// vol up
        Serial.println("CODE_VOLUP MOB");
        line(); break;

      case 0xEB58E7B6 ://back
        Serial.println("CODE_BACK MOB");
        line(); break;

      case 0x52120F2 ://up
        Serial.println("CODE_UP MOB");
        line(); break;

      case 0x6212287 ://up
        Serial.println("CODE_UP MOB");
        line(); break;

      case 0xDE3AA631 ://down
        Serial.println("CODE_DOWN MOB");
        line(); break;

      case 0xEA58E625 ://left
        Serial.println("CODE_LEFT MOB");
        line(); break;

      case 0x69893291 ://right
        Serial.println("CODE_RIGHT MOB");
        line(); break;

      default : Serial.println("INVALID");

    }
    delay(100);
    ir.resume();
  }
}
