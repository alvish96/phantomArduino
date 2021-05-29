
void remote()
{
  if (ir.decode(&irresult))
  {
    if (irresult.value == 0x61D6F00F)//1.86
    {

      rem = !rem;
      Serial.println(F("CODE_ZOOM"));
      if (rem) {
        clip(90);
        Serial.println(F("REMOTE ON"));
      }
      if (!rem) {
        clip(90);
        clip(30);
        Serial.println(F("REMOTE OFF"));
      }
    }
    if (rem)
      switch (irresult.value)
      {

        case 0x61D6F00F:
          Serial.println(F("CODE_ZOOM"));
          //          mod[0].SWtimer(20, 's');
          break;

        case (0x61D628D7):
          mod[11].SW();
          Serial.println(F("CODE_SELECT"));
          break;

        case 0x61D69A65:
          mod[6].SW();
          Serial.println(F("CODE_RIGHT"));
          break;

        case 0x61D6A857:
          mod[8].SW();
          Serial.println(F("CODE_LEFT"));
          break;

        case 0x61D6AA55:
          mod[10].SW();
          Serial.println(F("CODE_UP"));
          break;

        case 0x61D618E7:
          mod[7].SW();
          Serial.println(F("CODE_DOWN"));
          break;

        case 0x61D632CD:
          fn3(9, 1);
          Serial.println(F("CODE_MENU"));
          break;


        case 0x61D6728D:
          mod[5].SW();
          Serial.println(F("CODE_EXIT"));
          break;

        case 0x61D6D02F:
          mod[4].SW();
          Serial.println(F("CODE_SOURCE"));
          break;


        case 0x61D6708F:
          mod[1].SWtimer(10);
          Serial.println(F("CODE_VOLUP"));
          break;

        case 0x61D612ED:
          mod[4].SWtimer(10);

          Serial.println(F("CODE_VOLDW"));
          break;

        case 0x61D6629D:
          mod[3].SWtimer(15);

          Serial.println(F("CODE_PIC"));
          break;

        case 0x61D6EA15:
          mod[3].SWtimer(30);

          Serial.println(F("CODE_SOUND"));
          break;

        case 0x61D6DA25:
          mod[3].SWtimer(45);
          Serial.println(F("CODE_FREEZE"));
          break;

        case 0x61D6906F:
          mod[3].SW();
          Serial.println(F("CODE_PLAY"));
          break;

        case (0x61D652AD):
          mod[2].SW();
          Serial.println(F("CODE_MUTE"));
          break;

        case 0x61D648B7:
          buzz(5);
          //        function2();
          mod[0].SWtimer(20, 's');
          Serial.println(F("CODE_FF"));
          break;

        case 0x61D610EF:
          mod[1].SWtimer(30);
          Serial.println(F("CODE_RW"));
          break;

        case 0x61D6F20D:
          mutesw();
          Serial.println(F("CODE_NEXT"));
          break;

        case 0x61D630CF:
        
          mod[10].SWtimer(1, 'h');   //3.0.1
//          mod[4].SWtimer(30);
          Serial.println(F("CODE_BACK"));
          break;

        case 0x61D69867:
          tune(11);
          AUTO();
          Serial.println(F("CODE_VERT"));
          break;


        case 0x61D6A25D:
          mod[2].SWtimer(5);
          Serial.println(F("CODE_HORI"));
          break;

        case (0x61D67887):
          Serial.println(F("CODE_LISTEN"));
          mod[0].SWtimer(0, 's');
          break;


        //--------------------------------------------------------------------------------
        case 0x61D650AF:
          mod[1].SW();
          Serial.println(F("CODE_POWER"));
          break;

        case 0x5E7DB3DC ://power
          mod[1].SW();
          Serial.println(F("CODE_POWER MOB"));
          break;

        case 0xF874E0F8 ://home
          Serial.println(F("CODE_HOME MOB"));
          mod[0].SWtimer(0, 's');
          break;

        case 0xF574DC41 ://option
          Serial.println(F("CODE_OPTION MOB"));
          AUTO();
          break;

        case 0x76A77416 ://ok
          Serial.println(F("CODE_OK MOB"));
          mutesw();
          break;

        case 0x8453B5A5 ://vol  down
          Serial.println(F("CODE_VOLDOWN MOB"));
          mod[5].SW();
          break;

        case 0x8753BA5C :// vol up
          Serial.println(F("CODE_VOLUP MOB"));
          mod[9].SW();
          break;

        case 0xEB58E7B6 ://back
          buzz(5);
          mod[0].SWtimer(20, 's');
          Serial.println(F("CODE_BACK MOB"));
          break;

        case 0x52120F2 ://up
          Serial.println(F("CODE_UP MOB"));
          mod[1].SW();
          break;

        case 0x6212287 ://up
          Serial.println(F("CODE_UP MOB"));
          mod[1].SW();
          break;

        case 0xDE3AA631 ://down
          Serial.println(F("CODE_DOWN MOB"));
          mod[2].SW();
          break;

        case 0xEA58E625 ://left
          Serial.println(F("CODE_LEFT MOB"));
          mod[4].SW();
          break;

        case 0x69893291 ://right
          Serial.println(F("CODE_RIGHT MOB"));
          mod[3].SW();
          break;

        //--------------------------------------------------------------------------------




        case 0xFD6897 :// VOL UP
          Serial.println(F("CODE_ VOL UP MOB"));
          //        fn3_projector();
          fn3(9, 1);
          break;

        case 0xFD58A7 ://VOL DN
          Serial.println(F("CODE_VOL DN MOB"));
          mod[5].SW();
          break;

        case 0xFD28D7 ://CH UP
          Serial.println(F("CODE_CH UP MOB"));
          mod[10].SW();
          break;

        case 0xFDB847 ://UP
          Serial.println(F("CODE_UP MOB"));
          mod[1].SW();
          break;

        case 0xFD18E7 ://CH DN
          Serial.println(F("CODE_CH DN MOB"));
          mod[7].SW();
          break;

        case 0xFDA25D ://DN
          Serial.println(F("CODE_DN MOB"));
          mod[2].SW();
          break;

        case 0xFD42BD ://RT
          Serial.println(F("CODE_RT MOB"));
          mod[3].SW();
          break;

        case 0xFD02FD ://LT
          Serial.println(F("CODE_LT MOB"));
          mod[4].SW();
          break;

        case 0xFD629D ://OK
          Serial.println(F("CODE_OK MOB"));

          break;

        case 0xFDE01F ://MUTE
          Serial.println(F("CODE_MUTE MOB"));
          mod[2].SW();
          break;

        case 0xFDC03F ://PW
          Serial.println(F("CODE_PW MOB"));
          AUTO();
          mod[1].SW();
          break;

        case 0xFD7887 ://EXT
          Serial.println(F("CODE_EXT MOB"));
          buzz(5);
          mod[0].SWtimer(20, 's');
          break;

        /*  case 0xFD629D ://OPTION
            Serial.println(F("CODE_OPTION MOB"));

            break;
        */

        case 0xFD00FF ://1
          Serial.println(F("CODE_1 MOB"));
          mod[1].SW();
          break;

        case 0xFD807F ://
          Serial.println(F("CODE_2 MOB"));
          mod[2].SW();
          break;

        case 0xFD40BF ://
          Serial.println(F("CODE_3 MOB"));
          mod[3].SW();
          break;

        case 0xFD20DF ://
          Serial.println(F("CODE_4 MOB"));
          mod[4].SW();
          break;

        case 0xFDA05F ://
          Serial.println(F("CODE_5 MOB"));
          mod[5].SW();
          break;

        case 0xFD609F ://
          Serial.println(F("CODE_6 MOB"));
          mod[6].SW();
          break;

        case 0xFD10EF ://
          Serial.println(F("CODE_7 MOB"));
          mod[7].SW();
          break;

        case 0xFD906F ://
          Serial.println(F("CODE_8 MOB"));
          mod[8].SW();
          break;

        case 0xFD50AF ://
          Serial.println(F("CODE_9 MOB"));
          mod[9].SW();
          break;


        case 0xFDB04F ://
          Serial.println(F("CODE_0 MOB"));
          mod[10].SW();
          break;


        case 0xFD22DD ://EXITTT
          Serial.println(F("CODE_EXITTT MOB"));

          break;


        case 0xFDB24D ://AR
          Serial.println(F("CODE_AR MOB"));

          break;


        case 0xFD708F ://OREV
          Serial.println(F("CODE_OREV MOB"));

          break;


        /*    case 0xFD7887://TV
              Serial.println(F("CODE_TV MOB"));

              break;
        */

        case 0xFD38C7 ://INF
          Serial.println(F("CODE_INF MOB"));

          break;


        case 0xFD9867 ://GUIDE
          Serial.println(F("CODE_GUIDE MOB"));

          break;

        //--------------------------------------------------------------------------------

        default:
          Serial.println(irresult.value, HEX);
          tune(10);

      }
    delay(200);
    ir.resume();
  }


}
