
/* NUM = 11
 * ID   EXPECTED LENGTH(+3)
 * 
 * 233  2
 * 234  1 
 * 
 * 228
 * 229  30    //VOLTIMER0   VOLUNTARY TIMER LASTM,SECONDM, FIRSTM,PRESENT-LAST
 * 
 * 240  NUM
 * 241  NUM
 * 242  NUM
 * 
 * 243  10  
 * 244  10
 * 245  10
 * 
 * 246  20
 * 247
 * 
 * 248  30
 * 249  NUM                
 * 250  NUM
 * 251  NUM
 * 252  NUM
 * 
 * 
 * 
 * 
 * 
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







*/
