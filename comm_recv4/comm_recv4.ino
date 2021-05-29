
int recvchars[20];
boolean newdata = false;
void setup() {

  Serial.begin(9600);
  Serial1.begin(115200);
  
 

}


void loop() {
 recvdata();
  x();
}


void x()
{
  for (int i = 0; i < 20; i++)
  {
    Serial.print(i);
    Serial.println(" ");
    Serial.println(recvchars[i]);
    Serial.println();


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

    if (c == startmarker)
      recvinprogress = true;

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
