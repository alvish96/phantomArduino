
void irtest()
{
  int i=0;
//Serial.println("program started");Serial.println(++i);
  if (ir.decode(&irresult))
  {
    switch (irresult.value)
    {
      case 0x61D628D7:
        SW5(1);
        pre = 1;
        Serial.println("CODE_SELECT");
        break;

      case 0x61D69A65: pre = 2;
        Serial.println("CODE_RIGHT");

        break;

      case 0x61D6A857: pre = 3;
        Serial.println("CODE_LEFT");
        break;


      case 0x61D6AA55:
        SW4();
        pre = 4;
        Serial.println("CODE_UP");
        break;


      case 0x61D618E7:
        SW3();
        pre = 5;
        Serial.println("CODE_DOWN");
        break;


      case 0x61D632CD:
      SW6(1);
      pre = 6;
        Serial.println("CODE_MENU");
        break;


      case 0x61D6728D: pre = 7;
          SW4();Serial.println("CODE_EXIT");
        break;


      case 0x61D6D02F: pre = 8;
        Serial.println("CODE_SOURCE");
        break;


      case 0x61D6F00F: pre = 9;
        Serial.println("CODE_ZOOM");
        break;


      case 0x61D6708F: 
      timer(4,1);
      pre = 10;
        Serial.println("CODE_VOLUP");
        break;


      case 0x61D612ED: pre = 11;
        Serial.println("CODE_VOLDW");
        break;


      case 0x61D6629D:
        SW5(15);
        pre = 12;
        Serial.println("CODE_PIC");
        break;


      case 0x61D6EA15:
        SW5(30);
        pre = 13;
        Serial.println("CODE_SOUND");
        break;


      case 0x61D6DA25:
        SW5(45);
        pre = 14;
        Serial.println("CODE_FREEZE");
        break;


      case 0x61D6906F: pre = 15;
        Serial.println("CODE_PLAY");
        break;


      case 0x61D652AD:
        SW2();
        pre = 16;
        Serial.println("CODE_MUTE");
        break;


      case 0x61D648B7: pre = 17;
        Serial.println("CODE_FF");
        break;


      case 0x61D610EF: pre = 18;
        Serial.println("CODE_RW");
        break;

      case 0x61D6F20D: pre = 19;
        Serial.println("CODE_NEXT");
        break;

      case 0x61D630CF: pre = 20;
        Serial.println("CODE_BACK");
        break;

      case 0x61D69867: pre = 21;
        Serial.println("CODE_VERT");
        break;

      case 0x61D6A25D: pre = 22;
        Serial.println("CODE_HORI");
        break;

      case 0x61D67887:

        pre = 24;
        Serial.println("CODE_LISTEN");
        resetFunc();  //call reset
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
