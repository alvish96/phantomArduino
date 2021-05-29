
//receiving
const byte siz = 150;
byte bufer[151];

int recvchars[30];
int data[200];
byte datax;
boolean newdata = false;

bool debugg = 1;
bool flag = 0;
int i = 0;

bool endd = false;
bool recv = true;
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  ab();
  rx();
  delay(1000);
}
void ab()
{
  unsigned long x = millis() / 1000;

  if ((x % 10) == 0)
  {
    Serial.println(x);
    sndrq1();

  }
}

void sndrq()
{ int del = 1000;
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

void sndrq1()
{

  int  reqcode = 231;
  int req = 245;
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
  //    dta();
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

























void rx1()
{
  if (Serial1.available() > 0)
  {
    while (Serial1.available() > 0)
    {
      Serial1.readBytes(bufer, 100);
    }
    //  Serial.println();
    dta();
    Serial.println("DONE READING DATA ");

    //    if (Serial1.peek() != -1)
    //    {
    //      Serial.print("90 byte Buffer Overflowed. ");
    //    }
    // Clear out "your" buffer's contents.
    memset(bufer, 1, sizeof(bufer));
    dta();
    Serial.println("CLEARED BUFFER COMPLETE");
  }
}

void x()
{
  for (int i = 0; i < 200; i++)
  {
    Serial.print(" i ");
    Serial.print(i);
    Serial.print(" int ");
    Serial.print(recvchars[i]);
    Serial.println();
  }
}

/*
    working code here
*/
//while(c!=endmarker)
void r()
{
  char startmarker = '<';
  char c;
  char endmarker = '>';
  while (Serial1.available() > 0 )
  {
    datax = Serial1.read();
    Serial.println(datax);
    if (flag == 1)
      goto x;
    c = Serial1.read();

    if (c == startmarker)
    {
      i = 0;
      flag = 1;
    }
x:
    data[i] = Serial1.read();
    i++;
    c = Serial1.read();

    if (c == endmarker)
    {
      flag = 0;
    }
  }
}

void recvdata()
{
  static boolean recvinprogress = false;
  static byte ndx = 0;
  char startmarker = '<';
  char comma = ',';
  char endmarker = '>';
  char c;

  while (Serial1.available() > 0 && newdata == false)
  {
    c = Serial1.read();
    Serial.print(" char ");
    Serial.print(c);
    Serial.print(" indx ");
    Serial.print(ndx);
    Serial.println();

    if (c == startmarker)
    {

      recvinprogress = true;
    }
    else if (c == endmarker)
    {
      recvinprogress = false;
      ndx = 0;
      newdata = true;
    }
    if (recvinprogress == true && c != comma)
    {
      recvchars[ndx] = c;
      ndx++;
    }

  }

}

/*
   dont mess till here
*/

void recvdata11()
{
  static boolean recvinprogress = false;
  static byte ndx = 0;
  char startmarker = '<';
  char comma = ',';
  char endmarker = '>';
  char c;

  while (Serial1.available() > 0 && newdata == false)
  {
    c = Serial1.read();

    if (c == startmarker)
    {

      recvinprogress = true;
    }
    else if (c == endmarker)
    {
      recvinprogress = false;
      ndx = 0;
      newdata = true;
    }
    if (recvinprogress == true && c != comma)
    {
      recvchars[ndx] = c;
      ndx++;
    }

  }



}

void mine()
{
  while (Serial1.available() > 0)

  {

  }

}
