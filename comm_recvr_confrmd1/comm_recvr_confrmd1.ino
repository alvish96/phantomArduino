void setup() {

  Serial.begin(9600);
  Serial1.begin(115200);
}
void loop() {
  rx1(); 
//  fn8();
}
bool recv = true;
bool look= 1;
int i = 0;
int datax;
const int num = 11;
bool data1[num];             // state
bool data2[num];              //temp
unsigned int data3;         //present-lastmotion
int data4;  //brt
byte data5, data10[num], data11[num]; //mtncnt  // minutes // seconds
bool data6, data7, data8, data9; //chkmtn // pr // wait // ato
bool data12, data13, data14, data15; //deepc // debugg // transmit //motioin()
void rx1()
{
  while ((Serial1.available() > 0) && recv == true)
  {
    datax = Serial1.read();
    Serial.println(datax);
  }
}
void rx()
{
  while ((Serial1.available() > 0) && recv == true)
  {
    datax = Serial1.read();
    Serial.println(datax);
    Serial.println(Serial1.available());
    if (datax == 255)
      i = 0 ;
    else if (datax == 254)
    {
      recv = false;
      goto jump;
    }
    if (i > 0 && i  < 12) //1-11
      data1[i] = datax;
    if (i > 11 && i < 23 )  //12-22
      data2[i] = datax;
    if (i == 23) data3  = datax;  //23
    if (i == 24) data4  = datax;  //24
    if (i == 25) data5  = datax;  //25
    if (i == 26) data6  = datax;  //26
    if (i == 27) data7  = datax;  //27
    if (i == 28) data8  = datax;  //28
    if (i == 29) data9  = datax;  //29
    if (i > 29 && i < 41) //30-40
      data10[i] = datax;
    if (i > 40 && i  < 52) //41-51
      data11[i] = datax;

    if (i == 52) data12 = datax;  //52
    if (i == 53) data13 = datax;  //53
    if (i == 54) data14 = datax;  //54
    if (i == 55) data15 = datax;  //55

    i++;

  }
jump:
  //  if (Serial1.available() > 0)
  //    fn8();
  recv = true;
  Serial1.flush();
  delay(5);
}


void fn8()
{
  if (look)
  {
    Serial.println();
    unsigned long x1 = millis();
    Serial.print(F(" "));
    for (int i = 1; i < num + 1; i++)                 //1-11
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data1 RELAY STATE "));
      Serial.print(data1[i]);
      Serial.println();
    }

    for (int i = 1; i < num + 1; i++) //11+1-11+11   12-22
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data2 PRIORITY TMP "));
      Serial.print(data2[i]);
      Serial.println();
    }

    Serial.print(F(" data3 COUNTDOWN "));
    Serial.print(data3);       //23
    Serial.print(F(" data4 BRIGTNESS "));
    Serial.print(data4);       //24
    Serial.print(F(" data5 MOTIONCOUNT "));
    Serial.print(data5);       //25
    Serial.print(F(" data6 CHECKMOTION "));
    Serial.print(data6);       //26
    Serial.print(F(" data7 PRIORITY "));
    Serial.print(data7);        //27
    Serial.print(F(" data8 WAIT "));
    Serial.print(data8);        //28
    Serial.print(F(" data9 AUTO "));
    Serial.print(data9);        //29

    for (int i = 1; i < num + 1; i++) //30-40
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data10 MINUTES "));
      Serial.print(data10[i]);
      Serial.println();
    }
    for (int i = 1; i < num + 1; i++) //41-51
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data11 SECONDS "));
      Serial.print(data11[i]);
      Serial.println();
    }
    Serial.print(F(" data12 LOOK "));
    Serial.print(data12);        //52
    Serial.print(F(" data13 DEBUG "));
    Serial.print(data13);        //53
    Serial.print(F(" data14 TRANSMIT "));
    Serial.print(data14);        //54
    Serial.print(F(" data15 MOTION "));
    Serial.print(data15);        //55
    Serial.println();
    
    Serial.println((millis() - x1) );

  }
}
