/*
char s[]="add";
void fn4(unsigned int)
{
Serial.println(s);  
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
//  digitalWrite(led2,HIGH);
  delay(10000);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  delay(100);
  
}
/*

  byte fn6(int i)
  {
  unsigned int totalseconds = mod[i].timerdisp();
  seconds = totalseconds % 60;
  totalseconds = (totalseconds - seconds) / 60;
  minutes = totalseconds % 60;
  return minutes;
  }

  byte fn7(int i)
  {
  unsigned int totalseconds = mod[i].timerdisp();
  seconds = totalseconds % 60;
  totalseconds = (totalseconds - seconds) / 60;
  minutes = totalseconds % 60;
  return seconds;
  }

  void fn8()//1.8
  {
  if (look)
  {
    line();
    unsigned long x1 = millis();
    Serial.print(F(" "));
    for (int i = 1; i < num + 1; i++)                 //1-11
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data1 RELAY STATE "));
      Serial.print(data1[i]);
      line();
    }

    for (int i = 1; i < num + 1; i++) //11+1-11+11   12-22
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data2 PRIORITY TMP "));
      Serial.print(data2[i]);
      line();
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
      line();
    }
    for (int i = 1; i < num + 1; i++) //41-51
    {
      Serial.print(F(" index "));
      Serial.print(i);
      Serial.print(F(" data11 SECONDS "));
      Serial.print(data11[i]);
      line();
    }
    Serial.print(F(" data12 LOOK "));
    Serial.print(data12);        //52
    Serial.print(F(" data13 DEBUG "));
    Serial.print(data13);        //53
    Serial.print(F(" data14 TRANSMIT "));
    Serial.print(data14);        //54
    Serial.print(F(" data15 MOTION "));
    Serial.print(data15);        //55
    line();

    Serial.println((millis() - x1) );

  }
  }
*/
