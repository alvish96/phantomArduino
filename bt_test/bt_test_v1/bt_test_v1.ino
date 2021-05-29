//#include String
char command;
String string;
char ch, n;
String u = "", v = "";

char p[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


void setup()
{

  Serial.begin(9600);
  Serial1.begin(115200);
  Serial2.begin(38400);
}
void loop()
{

  test1();
  test2();
  shutdown1();
}










void cha()
{
  Serial.print("Enter string ");
x: if (Serial.available())
  {
    v = Serial.readString();
    goto y;
  }
  else
    goto x;

y : {

    Serial.println();

    Serial.print("the entered string is ");
    Serial.print(v);

    char o = v[1];
    Serial.println();
    Serial.print("the extracted character is ");
    Serial.print(o);

  }

}
void test1()
{
  Serial.print("this is a test code ");
  String str = "something";
  String amo = "something";
  if (str == amo)
  { Serial.println();
    Serial.println("test 1 is working");
    Serial.println(); Serial.println();
  }
  else
  { Serial.println();
    Serial.println("test 1  is not working ");
  }
}
void test2()
{
  int l1, l2, l3;
  Serial.println("this is the second test code ");
  Serial.println("test code is ");
  String s = "cod\n";
  Serial.println(s);

  l1 = s.length();
  Serial.print("length 1 is ");
  Serial.println(l1);



  String g = readtil();
  Serial.print("The entered string is ");
  Serial.println(g);
  l2 = g.length();
  Serial.print("length 2 is ");
  Serial.println(l2);

  String k = g;
  l3 = k.length();
  Serial.print("length 3 is ");
  Serial.println(l3);

  bool a = s.equals(k);
  Serial.println(a);
  if (a == true)
  {
    Serial.println("working ");
  } else   Serial.println("not working ");



}

void test3()
{
  if (Serial.available() > 0)
  {
    string = "";
  }
x:if (Serial.available() > 0)
  {
    command = ((byte)Serial.read());
   {
      string += command;
    }
    delay(1);
  }
else goto x;
}




String readtil()
{
x: if (Serial.available())
  {
    u = Serial.readString();
    goto y;
  }
  else
    goto x;

y :
  return u;

}



void sum()
{ int i = 0;
z:  i++;
  if (i == 2)return;
  if (Serial.available() == 1)
  {
    goto a;
  } else if (Serial1.available() == 1)
  {
    goto b;
  } else if (Serial2.available() == 1)
  {
    goto c;
  }
a: Serial.print("Enter name");
x: if (Serial.available())
  {
    u = Serial.readString();
    goto y;
  }
  else
    goto x;

y : {
    Serial.println();
    Serial.print  (" name entered is ");
    Serial.print(u);
    goto z;
  }




c: Serial2.print("Enter name");
l: if (Serial2.available())
  {
    u = Serial2.readString();
    goto m;
  }
  else
    goto l;

m : {
    Serial2.println();
    Serial2.print (" name entered is ");
    Serial2.print(u);
    goto z;
  }


b: Serial1.print("Enter name");
s: if (Serial1.available())
  {
    u = Serial1.readString();
    goto t;
  }
  else
    goto s;

t : {
    Serial1.println();
    Serial1.print(" name entered is ");
    Serial1.print(u);
    goto z;
  }


}

void clrscr()
{
  for (int i = 0; i < 10; i++)
  {
    Serial.println();

  }
}

void check()
{
r:  Serial.println(); Serial.println();
  Serial.println("what would you like to do");
  Serial.println("  1  -->   rerun program ");
  Serial.println("  2  -->    end  program ");
x: if (Serial.available())
  {
    u = Serial.readString();
    goto y;
  }
  else
    goto x;

y : {
    char n = u[0];
    Serial.println();
    Serial.print("option selected is ");
    Serial.println(n);
    if (strcmp(n, '1') == 0)
    {
      Serial.println();
      Serial.println("resetting board ");
      delay(100);
      Serial.println("***************");
      delay(100);
      Serial.println("***************");
      delay(100);
      Serial.println("***************");
      Serial.println("reset initiating ....");

      reset();
    }
    else if (strcmp(n, '2') == 0)
    { Serial.println();
      Serial.println("terminating program");
      Serial.println("termination initated ......");
      shutdown1();
    }
    else {
      Serial.println();
      Serial.println("          error!!!! ");
      Serial.println("         invalid input");
      Serial.println("    please enter a valid option");
      clrscr();
      goto r;

    }

  }
}














void reset()
{
  void(* resetFunc) (void) = 0;
  resetFunc();
}
void shutdown1()
{

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println ("                   *************************");
  Serial.println ("                       program terminated  ");
  Serial.println ("                   *************************");

  Serial1.println();
  Serial1.println();
  Serial1.println();
  Serial1.println (" *************************");
  Serial1.println ("        end of program ");
  Serial1.println (" *************************");

  Serial2.println();
  Serial2.println();
  Serial2.println();
  Serial2.println (" *************************");
  Serial2.println ("       end of program ");
  Serial2.println (" *************************");

  while (1);
}

