
void irtest()
{

  if (ir.decode(&irresult))
  {
    switch (irresult.value)
    {
      case 0x61D628D7:
        SW3t(1);
        pre = 1;
        Serial.println("CODE_SELECT");
        break;

      case 0x61D69A65:
        //        incsw3(1);
        SW6();
        pre = 2;
        Serial.println("CODE_RIGHT");

        break;

      case 0x61D6A857:
        //        decsw3(1);
        SW8();      pre = 3;
        Serial.println("CODE_LEFT");
        break;


      case 0x61D6AA55:
        pre = 4;
        //        incsw3(10);
        SW5();
        Serial.println("CODE_UP");
        break;


      case 0x61D618E7:
        //   decsw3(10);
        SW7();   pre = 5;
        Serial.println("CODE_DOWN");
        break;


      case 0x61D632CD:
        SW3t(5);
        pre = 6;
        Serial.println("CODE_MENU");
        break;


      case 0x61D6728D: pre = 7;
        SW3t(10);
        Serial.println("CODE_EXIT");
        break;


      case 0x61D6D02F:
        SW4();
        pre = 8;
        Serial.println("CODE_SOURCE");
        break;


      case 0x61D6F00F: pre = 9;

        Serial.println("CODE_ZOOM");
        reset(20);
        //        wait(20);
        break;


      case 0x61D6708F:
        SW1t(10);
        pre = 10;
        Serial.println("CODE_VOLUP");
        break;


      case 0x61D612ED:
        SW4t(10);
        pre = 11;
        Serial.println("CODE_VOLDW");
        break;


      case 0x61D6629D:
        SW3t(15);
        pre = 12;
        Serial.println("CODE_PIC");
        break;


      case 0x61D6EA15:
        SW3t(30);
        pre = 13;
        Serial.println("CODE_SOUND");
        break;


      case 0x61D6DA25:
        SW3t(45);
        pre = 14;
        Serial.println("CODE_FREEZE");
        break;


      case 0x61D6906F: pre = 15;
        SW3();
        Serial.println("CODE_PLAY");
        break;


      case 0x61D652AD:
        SW2();
        pre = 16;
        Serial.println("CODE_MUTE");
        break;


      case 0x61D648B7:
        //        SW1t(60);//
        buzz(5);
        reset(20);
        pre = 17;
        Serial.println("CODE_FF");
        break;


      case 0x61D610EF: pre = 18;
        SW1t(30);
        Serial.println("CODE_RW");
        break;

      case 0x61D6F20D:
        SW4t(45);
        pre = 19;
        Serial.println("CODE_NEXT");
        break;

      case 0x61D630CF:
        SW4t(30);
        pre = 20;
        Serial.println("CODE_BACK");
        break;

      case 0x61D69867:
        RESW();
        pre = 21;
        Serial.println("CODE_VERT");
        break;

      case 0x61D6A25D:
        SW2t(5);
        //        decsw1(30);
        pre = 22;
        Serial.println("CODE_HORI");
        break;

      case 0x61D67887:

        pre = 24;
        Serial.println("CODE_LISTEN");
        reset(0);
        // resetFunc();  //call reset
        break;

      case 0x61D650AF:
        SW1();
        pre = 23;
        Serial.println("CODE_POWER");
        break;
    }

    ir.resume(); //delay(10);
  }


}
