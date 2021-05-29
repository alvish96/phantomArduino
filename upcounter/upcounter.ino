

int a=1285;

void setup() {
Serial.begin(9600);


int x= a%1000;
Serial.println(a%100-((a%10)*10));
}
void loop() {

  //fum();
  //while(1);
}



void fum()
{
  for(int i=0;i<=8;i++)
  {
    delay(1000);
    Serial.println(i);
  }
}

