/*FUNCTION DEFINITIONS\

   TURNOFF = TURNS OFF ALL THE APPLIANCES
   FUNCTION2 = SET DURATION AND CALL TURNOFF FN
   FUNCTION3 = DELAY TURNOFF
   FUNCTION4 = DATA ASSIGNMENT
   FUNCTION5 = DATA TRANSFER
   FUNCTION8 = PRINT TRANSFER VALUES
   line = new line if debugg==1



   //*******************************************************************************************************************************************
  //*******************************************************************************************************************************************
  //*************************************************  TRANSMIT SECTION  **********************************************************************
  //*******************************************************************************************************************************************
  //*******************************************************************************************************************************************

  /* NUM = 11
   ID   EXPECTED LENGTH(+3)

   202  3  // TIME RECV
   233  2  //SEND MOTIONSTATE AND MOTION COUNT
   234  1   DONT SEND MOTION STATE

   227  1     //TD1    SENDING CHECKMOTION DATAf
   228  3     //VOLTIMER1 SENDING INDIVIDUAL TIMER IF ON
   229  30    //VOLTIMER0   VOLUNTARY TIMER LASTM,SECONDM, FIRSTM,PRESENT-LAST

   240  NUM
   241  NUM
   242  NUM

   243  10
   244  10
   245  10

   246  20
   247

   248  30
   249  NUM
   250  NUM
   251  NUM
   252  NUM

  REQUEST CODE           reqcode  231
  CONTROL BYTE           cbyte    232
  switching              TMDon    233
                         TMDoff   234


  {{{    to swtich TMD TRANSMIT MOTION DATA
      1.send control byte
      2.send switch command   }}}


  //-----------------------------------------------------------------------------------------------
  const int num = 12;
  bool databool0[30];   //flags     248
  bool databool1[num];  //state     249
  bool databool2[num];  //timerflag 250
  bool databool3[num];  //relaytype 251
  bool databool4[num];  //prtemp    252

  byte databyte0[20]; //byte data   246
  byte databyte1[num];//hour        240
  byte databyte2[num];//minute      241
  byte databyte3[num];//second      242

  byte databyte4[10];//hr           243
  byte databyte5[10];//min          244
  byte databyte6[10];//sec          245

  //-----------------------------------------------------------------------------------------------
          case 248 : event(0); break;
        case 249 : event(1); break;
        case 250 : event(2); break;
        case 251 : event(3); break;
        case 252 : event(4); break;

        case 240 : event(5); break;//hr
        case 241 : event(6); break;//mi
        case 242 : event(7); break;//se

        case 243 : event(8); break;//hr
        case 244 : event(9); break;//mi
        case 245 : event(10); break;//se

        case 246 : event(11); break;

        case 247 : event(30); break;

  //-----------------------------------------------------------------------------------------------

        case 0: senddb0(); break;
        case 1: senddb1(); break;
        case 2: senddb2(); break;
        case 3: senddb3(); break;
        case 4: senddb4(); break;

        case 5: senddb5(); break;//hr
        case 6: senddb6(); break;//mi
        case 7: senddb7(); break;//se

        case 8: senddb8(); break;//hr
        case 9: senddb9(); break;//mi
        case 10: senddb10(); break; //se

        case 11: senddb11(); break;

        case 30: sendall(); break;



  //-----------------------------------------------------------------------------------------------

          case 233 : TMD = 1; break;
        case 234 : TMD = 0; break;
        case 210 : concode = 0; break;
        case 211 : concode = 1 ; break;
        case 212 : concode = 2 ; break;
        case 213 : concode = 3 ; break;
        case 214 : concode = 4 ; break;
        case 215 : concode = 5 ; break;
        case 216 : concode = 6 ; break;
        case 217 : concode = 7 ; break;
        case 218 : concode = 8 ; break;
        case 219 : concode = 9 ; break;
        case 220 : concode = 10 ; break;
        case 221 : concode = 11 ; break;
        case 222 : concode = 30 ; break;


    case 0: mod[1].SW(); break;
    case 1: mod[2].SW(); break;
    case 2: mod[3].SW(); break;
    case 3: mod[4].SW(); break;
    case 4: mod[5].SW(); break;
    case 5: mod[6].SW(); break;
    case 6: mod[7].SW(); break;
    case 7: mod[8].SW(); break;
    case 8: mod[9].SW(); break;
    case 9: mod[10].SW(); break;
    case 10: mod[11].SW(); break;
    case 11: break;
    case 12: break;
    case 13: break;
    case 14: break;

  //-----------------------------------------------------------------------------------------------

  //*******************************************************************************************************************************************
  //*******************************************************************************************************************************************
  //*************************************************  RECEIVER SECTION  **********************************************************************
  //*******************************************************************************************************************************************
  //*******************************************************************************************************************************************


  TID //transmit id


  recvcode purpose
  221 time transfer










  //REMOTE CONTROL DEFINITION
  #define CODE_REM_SELECT  0x61D628D7     //1
  #define CODE_REM_RIGHT  0x61D69A65      //2
  #define CODE_REM_LEFT  0x61D6A857       //3
  #define CODE_REM_UP  0x61D6AA55         //4
  #define CODE_REM_DOWN  0x61D618E7       //5
  #define CODE_REM_MENU  0x61D632CD       //6
  #define CODE_REM_EXIT  0x61D6728D       //7
  #define CODE_REM_SOURCE  0x61D6D02F     //8
  #define CODE_REM_ZOOM  0x61D6F00F       //9
  #define CODE_REM_VOLUP  0x61D6708F      //10
  #define CODE_REM_VOLDW  0x61D612ED      //11
  #define CODE_REM_PIC  0x61D6629D        //12
  #define CODE_REM_SOUND  0x61D6EA15      //13
  #define CODE_REM_FREEZE  0x61D6DA25     //14
  #define CODE_REM_PLAY  0x61D6906F       //15
  #define CODE_REM_MUTE  0x61D652AD       //16
  #define CODE_REM_FF  0x61D648B7         //17
  #define CODE_REM_RW  0x61D610EF         //18
  #define CODE_REM_NEXT  0x61D6F20D       //19
  #define CODE_REM_BACK  0x61D630CF       //20
  #define CODE_REM_VERT  0x61D69867       //21
  #define CODE_REM_HORI  0x61D6A25D       //22
  #define CODE_REM_POWER_ON  0x61D650AF   //23
  #define CODE_REM_LISTEN  0x61D67887     //24

  // MOBILE CONTROLS DEFINITION SET1
  #define CODE_MOB_POWER 0x5E7DB3DC
  #define CODE_MOB_HOME  0xF874E0F8
  #define CODE_MOB_OPTION  0xF574DC41
  #define CODE_MOB_OK 0x76A77416

  #define CODE_MOB_VOLDW  0x8453B5A5
  #define CODE_MOB_VOLUP  0x8753BA5C
  #define CODE_MOB_BACK  0xEB58E7B6
  #define CODE_MOB_BACK2 0xDE3AA631

  #define CODE_MOB_UP  0x52120F2
  #define CODE_MOB_UP2 0x6212287
  #define CODE_MOB_DOWN 0xDE3AA631
  #define CODE_MOB_LEFT  0x8753BA5C
  #define CODE_MOB_LEFT2 0xEA58E625
  #define CODE_MOB_RIGHT 0x69893291


  // MOBILE CONTROLS DEFINITION SET2

  FD6897 VOL UP
  FD58A7 VOL DN
  FD28D7 CH UP
  FD18E7 CH DN
  FDB847  UP
  FDA25D  DN
  FD42BD  RT
  FD02FD  LT
  FD629D  OK
  FDE01F MUTE
  FDC03F PW
  FD7887 EXT
  FD629D OPTION
  FD00FF  1
  FD807F 2
  FD40BF 3
  FD20DF 4
  FDA05F 5
  FD609F 6
  FD10EF 7
  FD906F 8
  FD50AF 9
  FDB04F 0

  FD22DD EXITTT
  FDB24D AR
  FD708F OREV
  FD7887 TV
  FD38C7  INF
  FD9867  GUIDE
























  11111111111

















*/
