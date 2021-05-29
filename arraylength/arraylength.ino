


int ones[] = {3, 4, 5, 7};
int zeros[] = {1, 2, 6, 8, 9, 10, 11};

int x1 = sizeof(ones)/sizeof(ones[0]);
int x2 = sizeof(zeros)/sizeof(zeros[0]);


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
Serial.println(x1);
Serial.println(x2);
}
