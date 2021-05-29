

void receive()
{
//  ab();
  rx();
}



void ab()
{
  unsigned long x = millis() / 1000;
  if ((x % 10) == 0)
  {
    Serial.println(x);
    sndrq1();
    delay(1000);
  }
}

void sndrq11()
{
  Serial.print(" REQUEST CODE 1- ");
  int  reqcode = 231;
  int req = 249;
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial.print(" REQUEST CODE 2- ");
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
}

void sndrq1()
{TID=202;
int d=10;
  Serial.print(" REQUEST CODE 1- ");
  int  reqcode = 231;
  int req = 249;
  
  Serial1.write(TID);delay(d);
  Serial1.write(1);delay(d);Serial1.flush();
  Serial1.write(2);delay(d);Serial1.flush();
  Serial1.write(3);delay(d);Serial1.flush();
  
  Serial1.write(reqcode);delay(d);Serial1.flush();
  Serial.println(reqcode);
  Serial.print(" REQUEST CODE 2- ");
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
}




void sndrq()
{ int del = 500;
  int req = 248;
  int  reqcode = 231;
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
  rx();
  req = 249; delay(del);
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
  rx();
  req = 250; delay(del);
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
  rx();
  req = 251; delay(del);
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
  rx();
  req = 252; delay(del);
  Serial1.write(reqcode);
  Serial.println(reqcode);
  Serial1.write(req);
  Serial.println(req);
  Serial1.flush();
  rx();
}
void rxt()
{
  byte datalen = Serial1.available();

  if ( datalen > 0)
  { i = 0;
    line();
    Serial.print(" INCOMING LENGTH ");
    Serial.print(datalen);
    line();
    while (Serial1.available() > 0)
    {
      Serial.print(" i ");
      Serial.print(i);

      datax = Serial1.read();
      Serial.print(" CURRENT BYTE ");
      Serial.print(datax);
      i++;
      line();
    }
  }
}
byte check(byte a)
{
  byte byt;
  switch (a)
  {
    //    case 233:  byt = 1; break;

    case 229: byt = 32;
    case 248:  byt = (sizeof(databool0) / sizeof(databool0[0])); break;
    case 249:  byt = (sizeof(databool1) / sizeof(databool1[0])); break;
    case 250:  byt = (sizeof(databool2) / sizeof(databool2[0])); break;
    case 251:  byt = (sizeof(databool3) / sizeof(databool3[0])); break;
    case 252:  byt = (sizeof(databool4) / sizeof(databool4[0])); break;

    case 246:  byt = (sizeof(databyte0) / sizeof(databyte0[0])); break;
    case 240:  byt = (sizeof(databyte1) / sizeof(databyte1[0])); break;
    case 241:  byt = (sizeof(databyte2) / sizeof(databyte2[0])); break;
    case 242:  byt = (sizeof(databyte3) / sizeof(databyte3[0])); break;

    case 243:  byt = (sizeof(databyte4) / sizeof(databyte4[0])); break;
    case 244:  byt = (sizeof(databyte5) / sizeof(databyte5[0])); break;
    case 245:  byt = (sizeof(databyte6) / sizeof(databyte6[0])); break;

    case 0: byt = 0; break;
    default:  break;
  }
  return byt;
}
void assign(byte x1, byte x2, byte x3)
{
  if (RDP)
  {
    Serial.print(" CRNTDATA ");
    Serial.print(x1);
    Serial.print(" I ");
    Serial.print(x2);
    Serial.print(" ARRAY ");
    Serial.print(x3);
  }
  switch (x3)
  {
    case 248: databool0[x2] = x1; break;
    case 249: databool1[x2] = x1; break;
    case 250: databool2[x2] = x1; break;
    case 251: databool3[x2] = x1; break;
    case 252: databool4[x2] = x1; break;

    case 246: databyte0[x2] = x1; break;
    case 240: databyte1[x2] = x1; break;
    case 241: databyte2[x2] = x1; break;
    case 242: databyte3[x2] = x1; break;

    case 243: databyte4[x2] = x1; break;
    case 244: databyte5[x2] = x1; break;
    case 245: databyte6[x2] = x1; break;

    case 0: shred[x2] = x1; if (RDP) {
        line();
        Serial.print(" SHRED ");
        line();
        break;
      }
    default: shred[x2] = x1; if (RDP) Serial.print(" DEF SHRED "); break;
  }
}



void flushdata()
{
  bool x = 0;
  if (x)
    for (int i = 0; i < 50; i++)
    {
      databool0[i] = {0};
      databool1[i] = {0};
      databool2[i] = {0};
      databool3[i] = {0};
      databool4[i] = {0};
      databyte0[i] = {0}; //byte data   246
      databyte1[i] = {0};//hour        240
      databyte2[i] = {0};//minute      241
      databyte3[i] = {0};//second      242

      databyte4[i] = {0};//hr           243
      databyte5[i] = {0};//min          244
      databyte6[i] = {0};//sec          245
      shred[i] = {0};
    }
}
