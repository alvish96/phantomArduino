
//sending
#include <SoftwareSerial.h>

int datax;
bool recv = true;
SoftwareSerial mySerial(5, 6); //rx pin,tx pin
int otp = 1;
int a[] = {1, 5, 125, 127, 128, 225, 256, 500, 1024};
int b[50];
int val;



bool req;

void setup() {

  mySerial.begin(115200);
  Serial.begin(9600);
  req = 1;
  for (int i = 0; i < 50; i++)
  {
    b[i] = i + 1;
  }


}

void loop()
{
  recrq();
}
void ab()
{ unsigned long x = millis() / 1000;
  Serial.println(x);
  if ((x % 10) == 0)
    event();
}
void recrq()
{
  while ((mySerial.available() > 0) && recv == true)
  {
    datax = mySerial.read();
    if (datax == 248)
      req = 1;
    else req = 0;
  }
  event();
  recv = true;
  mySerial.flush();
  delay(5);
}

void event()
{
  if (req == 1)
  {
//    s();
    senddatax();
    mySerial.flush();
    req = 0;
  }
}
void senddatax()
{
  int data[150];
  for (int i = 0; i < 150; i++)
  { data[i] = i + 1;
  mySerial.write(data[i]);
    Serial.println(data[i]);

  }
}

  void s()
  {
    unsigned long x1 = millis();
    delay(500);
    for (int i = 0; i < 12; i++) {
      mySerial.write(a[i]);
      Serial.println(a[i]);
    }
    Serial.println("done 1");
    delay(100);

    mySerial.write(255);
    for (int i = 0; i < 21; i++) {
      mySerial.write(b[i]);
      Serial.println(b[i]);
    }
    mySerial.write(254);
    Serial.println("done 2");


    Serial.println((millis() - x1));
    delay(500);

  }
  void sr()
  {
    unsigned long x1 = millis();
    delay(500);
    mySerial.write(255);
    for (int i = 21; i < 42; i++) {
      mySerial.write(b[i]);
      Serial.println(b[i]);
    }
    mySerial.write(254);
    Serial.println("done 3");


    Serial.println((millis() - x1));
    delay(500);

  }




  void x()
  {
    for (int i = 1; i < 6; i++)
    {
      senddata2(i);
    }

  }
  void x1()
  {
    senddata2(1);
    senddata2(2);
    senddata2(3);
    senddata2(4);
    senddata2(5);
  }


  void senddata() 
  {
    int i;
    mySerial.print("<");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
      mySerial.write(a[i]);
      mySerial.print(",");

    }
    mySerial.print(">");
  }



  void senddata2(int val)
  {
    mySerial.print("<");
    switch (val)
    {
      case 1: y(1, 10); break;
      case 2: y(10, 20); break;
      case 3: y(20, 30); break;
      case 4: y(30, 40); break;
      case 5: y(40, 50); break;

    }
    mySerial.print(">");
  }

  void y(int m, int n)
  {

    for (int i = m; i <= n; i++)
    {
      mySerial.write(b[i]);
      mySerial.print(",");
    }


  }

  void senddata3()
  {
    mySerial.print("<");
    for (int i = 0; i < 50; i++)
    {
      mySerial.write(b[i]);
      mySerial.print(",");
    }
    mySerial.print(">");
  }
