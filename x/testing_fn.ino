
char s[]="add";
void fn4(unsigned int)
{
Serial.println(s);  
}


void remote2()
{
  if (ir.decode(&irresult))
  {
    switch (irresult.value)
    {
      case (0x61D628D7):
        Serial.println(F("CODE_SELECT"));
        break;

      case 0x61D69A65:
        Serial.println(F("CODE_RIGHT"));
        break;

      case 0x61D6A857:
        Serial.println(F("CODE_LEFT"));
        break;

      case 0x61D6AA55:
        Serial.println(F("CODE_UP"));
        break;

      case 0x61D618E7:
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

      case 0x61D6F00F:
        Serial.println(F("CODE_ZOOM"));
        break;

      case 0x61D6708F:

        Serial.println(F("CODE_VOLUP"));
        break;

      case 0x61D612ED:

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
        Serial.println(F("CODE_MUTE"));
        break;

      case 0x61D648B7:
        Serial.println(F("CODE_FF"));
        break;

      case 0x61D610EF:
        Serial.println(F("CODE_RW"));
        break;

      case 0x61D6F20D:
        Serial.println(F("CODE_NEXT"));
        break;

      case 0x61D630CF:
        Serial.println(F("CODE_BACK"));
        break;

      case 0x61D69867:
        Serial.println(F("CODE_VERT"));
        break;


      case 0x61D6A25D:
        Serial.println(F("CODE_HORI"));
        break;

      case (0x61D67887):
        Serial.println(F("CODE_LISTEN"));
        break;


      //--------------------------------------------------------------------------------
      case 0x61D650AF:
        Serial.println(F("CODE_POWER"));
        break;

      case 0x5E7DB3DC ://power
        Serial.println(F("CODE_POWER MOB"));
        break;

      case 0xF874E0F8 ://home
        Serial.println(F("CODE_HOME MOB"));
        break;

      case 0xF574DC41 ://option
        Serial.println(F("CODE_OPTION MOB"));
        break;

      case 0x76A77416 ://ok
        Serial.println(F("CODE_OK MOB"));
        break;

      case 0x8453B5A5 ://vol  down
        Serial.println(F("CODE_VOLDOWN MOB"));
        break;

      case 0x8753BA5C :// vol up
        Serial.println(F("CODE_VOLUP MOB"));
        break;

      case 0xEB58E7B6 ://back
        Serial.println(F("CODE_BACK MOB"));
        break;

      case 0x52120F2 ://up
        Serial.println(F("CODE_UP MOB"));
        break;

      case 0x6212287 ://up
        Serial.println(F("CODE_UP MOB"));
        break;

      case 0xDE3AA631 ://down
        Serial.println(F("CODE_DOWN MOB"));
        break;

      case 0xEA58E625 ://left
        Serial.println(F("CODE_LEFT MOB"));
        break;

      case 0x69893291 ://right
        Serial.println(F("CODE_RIGHT MOB"));
        break;

      default : Serial.println(F("INVALID"));

    }
    delay(100);
    ir.resume();
  }
}


char incomingByte = 0; // for incoming serial data

void in() 
{
  // send data only when you receive data:
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    if ((incomingByte == 10 )||(incomingByte == 13 ))
      goto a;
   
    Serial.print(F("I received: "));
    Serial.println(incomingByte,DEC);
a:
Serial.print(F(""));
  }
}


void test()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(100);
  
}
