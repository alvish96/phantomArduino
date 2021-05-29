int data[200];
byte datax;
const byte siz = 150;
byte bufer[151];
bool debugg = 1;
bool flag = 0;
//int i = 0;
bool recv = true;
bool e;
/*
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
*/

void receive()
{
  ab();
  rx();
  //  delay(1000);
}


void ab()
{
  e = 1;
  unsigned long x = millis() / 1000;
  if (e)
    if ((x % 10) == 0)
    {
      Serial.println(x);
      sndrq1();
      delay(1000);
      e = 0;
    }
}

void sndrq1()
{
  int  reqcode = 231;
  int req = 248;
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
}


void rx()
{
  while ((Serial1.available() > 0) && recv == true)
  {
    datax = Serial1.read();
    if (debugg)
    { Serial.print("  ");
      Serial.print(" i --> ");
      Serial.print(i);
      Serial.print("  ");
      Serial.print(" recvd data --> ");
      Serial.print(datax);
      Serial.print(" || ");
      Serial.print(" data pending --> ");
      Serial.println(Serial1.available());
      if (Serial1.available() == 0)
        Serial.println();
    }
    if (datax == 255)
      i = 0;
    else if (datax == 254)
    {
      recv = false;
      Serial.println(" jump ");
      goto jump;

    }
    data[i] = datax;
    i++;
  }
jump:
  recv = true;
  Serial1.flush();
  delay(5);
}

void dta()
{
  for  (int i = 0; i < 60; i++ )
  {
    Serial.print(" index ");
    Serial.print(i);
    Serial.print(" data ");
    Serial.print(bufer[i]);
    Serial.println();
  }
}
