class trans       //2.0
{
  private:
  public:


    bool databool0[n1];   //flags     248
    bool databool1[num];  //state     249
    bool databool2[num];  //timerflag 250
    bool databool3[num];  //relaytype 251
    bool databool4[num];  //prtemp    252

    byte databyte0[n2]; //byte data   246
    byte databyte1[num];//hour        240
    byte databyte2[num];//minute      241
    byte databyte3[num];//second      242

    byte databyte4[n3];//hr           243
    byte databyte5[n3];//min          244
    byte databyte6[n3];//sec          245



    void fn4()//2.0
    {
      assignt = 1;
      if (look) Serial.println(F("ASSIGNING"));

      databool0[0] =  0;
      databool0[1] =  checkmotion;
      databool0[2] =  minor;
      databool0[3] =  fromhere;
      databool0[4] =  CRF;
      databool0[5] =  wait;
      databool0[6] =  ato;
      databool0[7] =  priority;
      databool0[8] =  temp;
      databool0[9] =  mute;
      databool0[10] = look;
      databool0[11] = transmit;
      databool0[12] = flag2;
      databool0[13] = timeroff;
      databool0[14] = debugg;
      databool0[15] = deepc;
      databool0[16] = req;
      databool0[17] = rem;
      databool0[18] = all0;
      databool0[19] = motionstate;
      databool0[20] = testing;
      databool0[21] = TMD;
      for (int i = 1; i < num + 1; i++)
      {
        databool1[i] = mod[i].state;
        databool2[i] = mod[i].flag;
        databool3[i] = mod[i].relaytype;
        databool4[i] = mod[i].prtemp;
      }

      databyte0[1] = brt();
      databyte0[2] = motioncount;

      fn9();
      fn10((present - lastm), 1);
      fn10(present,           2);
      fn10(lastmotion,        3);
      fn10(lastm,             4);
      fn10(secondmotion,      5);
      fn10(firstmotion,       6);

      //  digitalRead(pirpin);

      if (look)Serial.println(F("ASSIGNMENT DONE"));
    }
};
