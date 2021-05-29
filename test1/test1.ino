const int num=11;
bool b[num];
void setup() 
{
Serial.begin(9600);
for (int i =1;i<num+1;i++)
{
Serial.print(i);
b[i]=i;
Serial.print(" ");Serial.print(b[i]);
Serial.println();
}

}

void loop() {
  
}
