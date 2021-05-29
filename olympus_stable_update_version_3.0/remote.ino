
void remote()
{
  if (ir.decode(&irresult))
  {
    buzz(1);
    switch (irresult.value)
    {
      case (0x61D628D7):
        mod[3].SWtimer(1);
        Serial.println("CODE_SELECT");
        break;

      case 0x61D69A65:
        mod[6].SW();
        Serial.println("CODE_RIGHT");
        break;

      case 0x61D6A857:
        mod[8].SW();
        Serial.println("CODE_LEFT");
        break;

      case 0x61D6AA55:
        mod[5].SW();
        Serial.println("CODE_UP");
        break;

      case 0x61D618E7:
        mod[7].SW();
        Serial.println("CODE_DOWN");
        break;

      case 0x61D632CD:
        if (mod[9].state == 0)
          mod[9].SW();
        else if (mod[9].state == 1)
          mod[9].SWtimer(1);
        Serial.println("CODE_MENU");
        break;

      case 0x61D6728D:
        mod[10].SW();
        Serial.println("CODE_EXIT");
        break;

      case 0x61D6D02F:
        mod[4].SW();
        Serial.println("CODE_SOURCE");
        break;

      case 0x61D6F00F:
        Serial.println("CODE_ZOOM");
        mod[0].SWtimer(20, 's');
        break;

      case 0x61D6708F:
        mod[1].SWtimer(10);

        Serial.println("CODE_VOLUP");
        break;

      case 0x61D612ED:
        mod[4].SWtimer(10);

        Serial.println("CODE_VOLDW");
        break;

      case 0x61D6629D:
        mod[3].SWtimer(15);

        Serial.println("CODE_PIC");
        break;

      case 0x61D6EA15:
        mod[3].SWtimer(30);

        Serial.println("CODE_SOUND");
        break;

      case 0x61D6DA25:
        mod[3].SWtimer(45);
        Serial.println("CODE_FREEZE");
        break;

      case 0x61D6906F:
        mod[3].SW();
        Serial.println("CODE_PLAY");
        break;

      case (0x61D652AD):
        mod[2].SW();
        Serial.println("CODE_MUTE");
        break;

      case 0x61D648B7:
        buzz(5);
        mod[0].SWtimer(20, 's');
        Serial.println("CODE_FF");
        break;

      case 0x61D610EF:
        mod[1].SWtimer(30);
        Serial.println("CODE_RW");
        break;

      case 0x61D6F20D:
        mutesw();
        Serial.println("CODE_NEXT");
        break;

      case 0x61D630CF:
        mod[4].SWtimer(30);
        Serial.println("CODE_BACK");
        break;

      case 0x61D69867:
        RESW();
        Serial.println("CODE_VERT");
        break;


      case 0x61D6A25D:
        mod[2].SWtimer(5);
        Serial.println("CODE_HORI");
        break;

      case (0x61D67887):
        Serial.println("CODE_LISTEN");
        mod[0].SWtimer(0, 's');
        break;


      //--------------------------------------------------------------------------------
      case 0x61D650AF:
        mod[1].SW();
        Serial.println("CODE_POWER");
        break;

      case 0x5E7DB3DC ://power
        mod[1].SW();
        Serial.println("CODE_POWER MOB");
        break;

      case 0xF874E0F8 ://home
        Serial.println("CODE_HOME MOB");
        mod[0].SWtimer(0, 's');
        break;

      case 0xF574DC41 ://option
        Serial.println("CODE_OPTION MOB");
        RESW();
        break;

      case 0x76A77416 ://ok
        Serial.println("CODE_OK MOB");
        mutesw();
        break;

      case 0x8453B5A5 ://vol  down
        Serial.println("CODE_VOLDOWN MOB");
        mod[10].SW();
        break;

      case 0x8753BA5C :// vol up
        Serial.println("CODE_VOLUP MOB");
        mod[9].SW();
        break;

      case 0xEB58E7B6 ://back
        buzz(5);
        mod[0].SWtimer(20, 's');
        Serial.println("CODE_BACK MOB");
        break;

      case 0x52120F2 ://up
        Serial.println("CODE_UP MOB");
        mod[1].SW();
        break;

      case 0x6212287 ://up
        Serial.println("CODE_UP MOB");
        mod[1].SW();
        break;

      case 0xDE3AA631 ://down
        Serial.println("CODE_DOWN MOB");
        mod[2].SW();
        break;

      case 0xEA58E625 ://left
        Serial.println("CODE_LEFT MOB");
        mod[4].SW();
        break;

      case 0x69893291 ://right
        Serial.println("CODE_RIGHT MOB");
        mod[3].SW();
        break;
    }
    delay(100);
    ir.resume();
  }


}
