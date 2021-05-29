

//void test4Fun(int t, int t2=2);


void setup()
{

  Serial.begin(9600);
 
  test4Fun(10,11);
 
  test4Fun(12);
}

void loop()
{
 
}


void test4Fun(int t, int t2=2)
{
  Serial.print(t);
  Serial.print(" ");
  Serial.println(t2);
}
