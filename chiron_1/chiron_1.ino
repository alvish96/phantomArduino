

   #define l2 8
#define g1 22
#define g2 23
#define g3 24
#define g4 25
#define a1 4
#define a2 5
#define a3 6
#define a4 7


char c = '0';

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(38400); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(115200);
  analogWrite(l2, 0);
  analogWrite(g1, 0);
  analogWrite(g2, 0);
  analogWrite(g3, 0);
  analogWrite(g4, 0);

}

void loop() {
  

    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial1.available() )   
    {  
         c = Serial1.read();
         Serial1.print(c);
         Serial.write( c ); 
    }
         Serial.println(); 
          Serial1.println();
    // listen for user input and send it to the HC-05
   if ( Serial.available() )   
   { 
         c = Serial.read();
         Serial.print(c);
         Serial1.write( c ); 

   }


  deb();
  aq();

  t2();


  sh();

}

void f()
{ int x = 50; int q = 10;
  int z1 = 200;
  int z2 = z1 - x;
  int z3 = z2 - x;
  int z4 = z3 - x;
  for (z1, z2, z3, z4; z1 <= 255, z2 <= 255, z3 <= 255, z4 <= 255; z1 += q, z2 += q, z3 += q, z4 += q)
  {
    analogWrite(a1, z1);  Serial.print("led1  ---->>>"); Serial.println(z1); delay(50);
    analogWrite(a2, z2);  Serial.print("        led2  ---->>>"); Serial.println(z2); delay(50);
    analogWrite(a3, z3);  Serial.print("                 led3  ---->>>"); Serial.println(z3); delay(50);
    analogWrite(a4, z4);  Serial.print("                        led4  ---->>>"); Serial.println(z4); delay(50);
  }
}



void g()
{ int x = 40; int q = 50;
  int z1 = 180;
  int z2 = z1 + x;
  int z3 = z2 + x;
  int z4 = z3 + x;
  for (z1, z2, z3, z4; z1 >= 0, z2 >= 0, z3 >= 0, z4 >= 0; z1 -= q, z2 -= q, z3 -= q, z4 -= q)
  {
    analogWrite(a1, z1);  Serial.print("led1  ---->>>"); Serial.println(z1); //delay(50);
    analogWrite(a2, z2);  Serial.print("        led2  ---->>>"); Serial.println(z2); //delay(50);
    analogWrite(a3, z3);  Serial.print("                 led3  ---->>>"); Serial.println(z3); //delay(50);
    analogWrite(a4, z4);  Serial.print("                        led4  ---->>>"); Serial.println(z4); //delay(50);
  }
}


double b1 = 30; //
double b2 = 100; //
double b3 = 255; //

double x = 1;
double d = (x * 1000);
double z1 = (1 * 1000);

double x1 = ((3 * d) / (b2 - b1));
double x2 = ((2 * d) / (b2 - b1));
double x3 = ((3 * d) / (b3 - b1));
double x4 = ((2 * d) / (b3 - b1));
double x5 = (d / (b3 - b2));

double q1 = (b1 + ((b2 - b1) / 3));
double q2 = (b1 + (((b2 - b1) * 2) / 3));
double q3 = (b1 + ((b2 - b1) / 2));
double q4 = (b2 + ((b3 - b2) / 3));
void deb()
{

  Serial.print("   level1 b1 = "); Serial.println(b1);
  Serial.print("   level2 b2 = "); Serial.println(b2);
  Serial.print("   level1 b3 = ");  Serial.println(b3);
  Serial.println();
  Serial.print("   3d/b2-b1   delay1 x1 = "); Serial.println(x1);  //        3d/b2-b1
  Serial.print("   2d/b2-b1   delay2 x2 = "); Serial.println(x2);   //        2d/b2-b1
  Serial.print("   3d/b3-b1   delay3 x3 = "); Serial.println(x3);  //        3d/ b3-b1
  Serial.print("   2d/b3-b1   delay4 x4 = "); Serial.println(x4);  //        2d/ b3-b1
  Serial.print("   d/b3-b2    delay5 x5 = "); Serial.println(x5);  //           d/b3-b2
  Serial.println();
  Serial.print("   level q1 = "); Serial.println(q1);
  Serial.print("   level q2 = "); Serial.println(q2);
  Serial.print("   level q3 = "); Serial.println(q3);
  Serial.print("   level q4 = "); Serial.println(q4);
}

void t0()
{
  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  //delay();

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(x1); //42

  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(x1);  //42

  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);
  delay(x1);  //42

  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);
  delay(x2);   //28

  analogWrite(a1, q3);      //5
  delay(x1 - x2); //14
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);
  delay(x2);  //28

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  delay(x1 - x2); //14
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  //delay();

  analogWrite(a1, b1);      //7
  delay(x2);  //28
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  delay(x1 - x2);
  analogWrite(a4, b2);
  // delay();

  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  delay(x5);  //6
  analogWrite(a4, b3);
  delay(x2 - x5); //28-6 = 22
  analogWrite(a3, b1);

  delay(z1);

  analogWrite(a1, b1);      //9
  analogWrite(a4, b3);
  delay(x4);  //8
  analogWrite(a3, b2);
  delay(x3 - x4); // 13-8 = 5
  analogWrite(a2, q2);


  // delay(z1/2);

  analogWrite(a4, b3);
  delay(x4);  //8
  analogWrite(a3, b3);
  delay(x3 - x4);
  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);


  //delay(z1/2);

  analogWrite(a3, b3);
  analogWrite(a4, b3);
  delay(x3);  //13
  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11


  //delay(z1/2);


  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  delay(x3);  //13
  analogWrite(a1, b3);      //12


  delay(2000);
  off();


}


void t1()
{

  Serial.println();
  Serial.print("          t1 running       ");

  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0); Serial.println(); Serial.print("-------------   0 -------------");
  analogWrite(a4, 0);
  //delay();

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0); Serial.println(); Serial.print("-------------   1 -------------");
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  for (int i11 = b1; i11 <= q1; i11++)
  {
    analogWrite(a1, i11);
    delay(x1); //42
  }

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, q1);      //2
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   2 -------------");
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  for (int i21 = q1, i22 = b1; i21 <= q2, i22 <= q1; i21++, i22++)
  {
    analogWrite(a1, i21);
    analogWrite(a2, i22);
    delay(x1);  //42
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, q2);      //3
  analogWrite(a2, q1); Serial.println(); Serial.print("-------------   3 -------------");
  analogWrite(a3, b1);
  analogWrite(a4, 0);

  for (int i31 = q2, i32 = q1, i33 = b1; i31 <= b2, i32 <= q2, i33 <= q1; i31++, i32++, i33++)
  {
    analogWrite(a1, i31);
    analogWrite(a2, i32);
    analogWrite(a3, i33);
    delay(x1);  //42
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b2);      //4
  analogWrite(a2, q2); Serial.println(); Serial.print("-------------   4  -------------");
  analogWrite(a3, q1);
  analogWrite(a4, b1);

  for (int i41 = b2, i42 = q2, i43 = q1, i44 = b1; i41 >= q3, i42 <= b2, i43 <= q2, i44 <= q1; i41--, i42++, i43++, i44++)
  {
    delay(x2);   //28
    analogWrite(a1, i41);
    delay(x1 - x2);  //14
    analogWrite(a2, i42);
    analogWrite(a3, i43);
    analogWrite(a4, i44);
  }



  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, q3);      //5
  analogWrite(a2, b2); Serial.println(); Serial.print("-------------   5  -------------");
  analogWrite(a3, q2);
  analogWrite(a4, q1);

  for (int i51 = q3, i52 = b2, i53 = q2, i54 = q1; i51 >= b1, i52 >= q3, i53 <= b2, i54 <= q2 ; i51--, i52--, i53++, i54++  )
  {
    delay(x2);  //28
    analogWrite(a1, i51);
    analogWrite(a2, i52);
    delay(x1 - x2);  //14
    analogWrite(a3, i53);
    analogWrite(a4, i54);
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3); Serial.println(); Serial.print("-------------   6 -------------");
  delay(x1 - x2); //14
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  //delay();

  for (int i62 = q3, i63 = b2, i64 = q2; i62 >= b1, i63 >= q3, i64 <= b2; i62--, i63--, i64++)
  {
    delay(x2);  //28
    analogWrite(a2, i62);
    analogWrite(a3, i63);
    delay(x1 - x2); //14
    analogWrite(a4, i64);

  }

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      //7
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   7 -------------");
  analogWrite(a3, q3);
  analogWrite(a4, b2);
  // delay();

  for (int i73 = q3, i74 = b2; i73 >= b1, i74 <= b3; i73--, i74++)

  {
    delay(x5);  //6
    analogWrite(a4, i74);
    delay(x2 - x5); //28-6 = 22
    analogWrite(a3, i73);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      //8
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   8 -------------");
  analogWrite(a4, b3);
  analogWrite(a3, b1);

  //  delay(z1);

  for (int i82 = b1, i83 = b1; i82 <= q2, i83 <= b2; i82++, i83++)
  {
    delay(x4);  //8
    analogWrite(a3, i83);
    delay(x3 - x4); // 13-8 = 5
    analogWrite(a2, i82);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      Serial.println(); Serial.print("-------------   9 -------------"); //9
  analogWrite(a4, b3);

  analogWrite(a3, b2);

  analogWrite(a2, q2);

  for (int i91 = b1, i92 = q2, i93 = b2; i91 <= q2, i92 <= q4, i93 <= b3; i91++, i92++, i93++)
  {
    delay(x4);  //8
    analogWrite(a3, i93);
    delay(x3 - x4);
    analogWrite(a1, i91);
    analogWrite(a2, i92);
  }



  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a4, b3); Serial.println(); Serial.print("-------------   10 -------------");

  analogWrite(a3, b3);

  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);

  for (int i101 = q2, i102 = q4; i101 <= q4, i102 <= b3; i101++, i102++)
  {
    delay(x3);
    analogWrite(a1, i101);
    analogWrite(a2, i102);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a3, b3); Serial.println(); Serial.print("-------------   11 -------------");
  analogWrite(a4, b3);
  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11

  for (int i111 = q4; i111 <= b3; i111++)
  {
    analogWrite(a1, i111);
    delay(x3);  //13
  }

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a2, b3); Serial.println(); Serial.print("-------------   12 -------------");
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  analogWrite(a1, b3);      //12
  //delay();

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  delay(2000); off();
}






void t11()
{
  Serial.println();
  Serial.print("          t11 running       ");

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0); Serial.println(); Serial.print("-------------   0 -------------");
  analogWrite(a4, 0);
  //delay();

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0); Serial.println(); Serial.print("-------------   1 -------------");
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  for (int i11 = b1; i11 <= q1; i11++)
  {
    analogWrite(a1, i11);
    delay(x1); //42

    Serial.println();
    Serial.print("           led1  "); Serial.println(i11);
    Serial.print("                  led2  "); Serial.println(a2);
    Serial.print("                         led3  "); Serial.println(a3);
    Serial.print("                                led4  "); Serial.println(a4);
  }
  analogWrite(a1, q1);      //2
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   2 -------------");
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  for (int i21 = q1, i22 = b1; i21 <= q2, i22 <= q1; i21++, i22++)
  {
    analogWrite(a1, i21);
    analogWrite(a2, i22);
    delay(x1);  //42
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, q2);      //3
  analogWrite(a2, q1); Serial.println(); Serial.print("-------------   3 -------------");
  analogWrite(a3, b1);
  analogWrite(a4, 0);

  for (int i31 = q2, i32 = q1, i33 = b1; i31 <= b2, i32 <= q2, i33 <= q1; i31++, i32++, i33++)
  {
    analogWrite(a1, i31);
    analogWrite(a2, i32);
    analogWrite(a3, i33);
    delay(x1);  //42
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, b2);      //4
  analogWrite(a2, q2); Serial.println(); Serial.print("-------------   4  -------------");
  analogWrite(a3, q1);
  analogWrite(a4, b1);

  for (int i41 = b2, i42 = q2, i43 = q1, i44 = b1; i41 >= q3, i42 <= b2, i43 <= q2, i44 <= q1; i41--, i42++, i43++, i44++)
  {
    delay(x2);   //28
    analogWrite(a1, i41);
    delay(x1 - x2);  //14
    analogWrite(a2, i42);
    analogWrite(a3, i43);
    analogWrite(a4, i44);
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a1, q3);      //5
  analogWrite(a2, b2); Serial.println(); Serial.print("-------------   5  -------------");
  analogWrite(a3, q2);
  analogWrite(a4, q1);

  for (int i51 = q3, i52 = b2, i53 = q2, i54 = q1; i51 >= b1, i52 >= q3, i53 <= b2, i54 <= q2 ; i51--, i52--, i53++, i54++  )
  {
    delay(x2);  //28
    analogWrite(a1, i51);
    analogWrite(a2, i52);
    delay(x1 - x2);  //14
    analogWrite(a3, i53);
    analogWrite(a4, i54);
  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  //  analogWrite(a1, b1);      //6
  analogWrite(a2, q3); Serial.println(); Serial.print("-------------   6 -------------");
  delay(x1 - x2); //14
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  //delay();

  for (int i62 = q3, i63 = b2, i64 = q2; i62 >= b1, i63 >= q3, i64 <= b2; i62--, i63--, i64++)
  {
    delay(x2);  //28
    analogWrite(a2, i62);
    analogWrite(a3, i63);
    delay(x1 - x2); //14
    analogWrite(a4, i64);

  }

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  // analogWrite(a1, b1);      //7
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   7 -------------");
  analogWrite(a3, q3);
  analogWrite(a4, b2);
  // delay();

  for (int i73 = q3, i74 = b2; i73 >= b1, i74 <= b3; i73--, i74++)

  {
    delay(x5);  //6
    analogWrite(a4, i74);
    delay(x2 - x5); //28-6 = 22
    analogWrite(a3, i73);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  //  analogWrite(a1, b1);      //8
  analogWrite(a2, b1); Serial.println(); Serial.print("-------------   8 -------------");
  //analogWrite(a4, b3);
  analogWrite(a3, b1);

  //  delay(z1);

  for (int i82 = b1, i83 = b1; i82 <= q2, i83 <= b2; i82++, i83++)
  {
    delay(x4);  //8
    analogWrite(a3, i83);
    delay(x3 - x4); // 13-8 = 5
    analogWrite(a2, i82);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  //analogWrite(a1, b1);
  Serial.println(); Serial.print("-------------   9 -------------"); //9
  // analogWrite(a4, b3);

  analogWrite(a3, b2);

  analogWrite(a2, q2);

  for (int i91 = b1, i92 = q2, i93 = b2; i91 <= q2, i92 <= q4, i93 <= b3; i91++, i92++, i93++)
  {
    delay(x4);  //8
    analogWrite(a3, i93);
    delay(x3 - x4);
    analogWrite(a1, i91);
    analogWrite(a2, i92);
  }



  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  //analogWrite(a4, b3);
  Serial.println(); Serial.print("-------------   10 -------------");

  //  analogWrite(a3, b3);

  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);

  for (int i101 = q2, i102 = q4; i101 <= q4, i102 <= b3; i101++, i102++)
  {
    delay(x3);
    analogWrite(a1, i101);
    analogWrite(a2, i102);

  }


  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  //analogWrite(a3, b3);
  Serial.println(); Serial.print("-------------   11 -------------");
  // analogWrite(a4, b3);
  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11

  for (int i111 = q4; i111 <= b3; i111++)
  {
    analogWrite(a1, i111);
    delay(x3);  //13
  }

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  analogWrite(a2, b3); Serial.println(); Serial.print("-------------   12 -------------");
  //analogWrite(a3, b3);
  // analogWrite(a4, b3);
  analogWrite(a1, b3);      //12
  //delay();

  Serial.println();
  Serial.print("           led1  "); Serial.println(a1);
  Serial.print("                  led2  "); Serial.println(a2);
  Serial.print("                         led3  "); Serial.println(a3);
  Serial.print("                                led4  "); Serial.println(a4);

  delay(2000); off();
}





void t2()
{ int m = 500;
  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m);

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m); //42

  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m);  //42

  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);
  delay(m);

  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);
  delay(m);

  analogWrite(a1, q3);      //5
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);
  delay(m);

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  delay(m);

  analogWrite(a1, b1);      //7
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  analogWrite(a4, b2);
  delay(m);

  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  analogWrite(a4, b3);
  analogWrite(a3, b1);
  delay(m);


  analogWrite(a1, b1);      //9
  analogWrite(a4, b3);
  analogWrite(a3, b2);
  analogWrite(a2, q2);
  delay(m);

  // delay(z1/2);

  analogWrite(a4, b3);
  analogWrite(a3, b3);
  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);
  delay(m);

  //delay(z1/2);

  analogWrite(a3, b3);
  analogWrite(a4, b3);

  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11
  delay(m);

  //delay(z1/2);


  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  analogWrite(a1, b3);      //12
  delay(m);

  delay(2000); off();
}

//----------------------------------------------------------------------------------
void t21()
{ int m = 1;

  analogWrite(a1, 0);
  analogWrite(a2, 0);         //0
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m);

  for (int i1a = 0, i2a = 0, i3a = 0, i4a = 0; i1a <= b1, i2a <= 0, i3a <= 0, i4a <= 0; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }

  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m); //42

  for (int i1a = b1, i2a = 0, i3a = 0, i4a = 0; i1a <= q1, i2a <= b1, i3a <= 0, i4a <= 0; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(m);  //42

  for (int i1a = q1, i2a = b1, i3a = 0, i4a = 0; i1a <= q2, i2a <= q1, i3a <= b1, i4a <= 0; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);
  delay(m);

  for (int i1a = q2, i2a = q1, i3a = b1, i4a = 0; i1a <= b2, i2a <= q2, i3a <= q1, i4a <= b1; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);
  delay(m);

  for (int i1a = b2, i2a = q2, i3a = q1, i4a = b1; i1a >= q3, i2a <= b2, i3a <= q2, i4a <= q1; i1a--, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, q3);      //5
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);
  delay(m);

  for (int i1a = q3, i2a = b2, i3a = q2, i4a = q1; i1a >= b1, i2a >= q3, i3a <= b2, i4a <= q2; i1a--, i2a--, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  analogWrite(a3, b2);
  analogWrite(a4, q2);
  delay(m);

  for (int i1a = b1, i2a = q3, i3a = b2, i4a = q2; i1a >= b1, i2a >= b1, i3a >= q3, i4a <= b2; i1a--, i2a--, i3a--, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, b1);      //7
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  analogWrite(a4, b2);
  delay(m);

  for (int i1a = b1, i2a = b1, i3a = q3, i4a = b2; i1a <= b1, i2a <= b1, i3a >= b1, i4a <= b3; i1a++, i2a++, i3a--, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  analogWrite(a4, b3);
  analogWrite(a3, b1);
  delay(m);

  for (int i1a = b1, i2a = b1, i3a = b1, i4a = b3; i1a <= b1, i2a <= q2, i3a <= b2, i4a <= b3; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }

  analogWrite(a1, b1);      //9
  analogWrite(a4, b3);
  analogWrite(a3, b2);
  analogWrite(a2, q2);
  delay(m);

  for (int i1a = b1, i2a = q2 , i3a = b2, i4a = b3; i1a <= q2, i2a <= q4, i3a <= b3, i4a <= b3; i1a, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  // delay(z1/2);

  analogWrite(a4, b3);
  analogWrite(a3, b3);
  analogWrite(a1, q2);      //10
  analogWrite(a2, q4);
  delay(m);

  for (int i1a = q2, i2a = q4, i3a = b3, i4a = b3; i1a <= q4, i2a <= b3, i3a <= b3, i4a <= b3; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }
  //delay(z1/2);

  analogWrite(a3, b3);
  analogWrite(a4, b3);

  analogWrite(a2, b3);
  analogWrite(a1, q4);      //11
  delay(m);

  //delay(z1/2);

  for (int i1a = q4, i2a = b3, i3a = b3, i4a = b3; i1a <= b3, i2a <= b3, i3a <= b3, i4a <= b3; i1a++, i2a++, i3a++, i4a++)
  {
    Serial.println();
    analogWrite(a1, i1a); Serial.print("___led1--->"); Serial.println(i1a);
    analogWrite(a2, i2a); Serial.print("______________led2--->"); Serial.println(i2a);
    analogWrite(a3, i3a); Serial.print("_________________________led3--->"); Serial.println(i3a);
    analogWrite(a4, i4a); Serial.print("___________________________________led1--->"); Serial.println(i4a);
    delay(m);
  }

  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  analogWrite(a1, b3);      //12
  delay(m);

  delay(2000); off();
}
/*
  void t1()
  {
  for(int i=b1;i<=q1;i++)
  {
  analogWrite(a1,);
  analogWrite(a2,0);
  analogWrite(a3,0);
  analogWrite(a4,0);
  }
  }
  void t2()
  {
  analogWrite(a1,q1);    for(int i=q1;i<=;i)     {  analogWrite(a1,i);   delay();    }
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }


  void t3()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t4()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t5()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t6()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t7()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t8()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t9()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t10()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t11()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

  void t12()
  {
  analogWrite(a1,);
  analogWrite(a2,);
  analogWrite(a3,);
  analogWrite(a4,);
  }

*/












void aq()
{ int i = 65;
  analogWrite(a1, 70);
  analogWrite(a2, 70);
  analogWrite(a3, 70);
  analogWrite(a4, 70);
  delay(i);
  analogWrite(a1, 255);
  analogWrite(a2, 255);
  analogWrite(a3, 255);
  analogWrite(a4, 255);
  delay(i);
  analogWrite(a1, 70);
  analogWrite(a2, 70);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(i);
  off();
  delay(250);

  analogWrite(a1, 70);
  analogWrite(a2, 70);
  analogWrite(a3, 70);
  analogWrite(a4, 70);
  delay(i);
  analogWrite(a1, 255);
  analogWrite(a2, 255);
  analogWrite(a3, 255);
  analogWrite(a4, 255);
  delay(i);
  analogWrite(a1, 70);
  analogWrite(a2, 70);
  analogWrite(a3, 0);
  analogWrite(a4, 0);
  delay(i);
  off();
  delay(2500);

}


void man()
{

  analogWrite(a1, b1);
  analogWrite(a2, b1);
  analogWrite(a3, b1);
  analogWrite(a4, b1);
  delay(500);
  analogWrite(a1, b2);
  analogWrite(a2, b2);
  analogWrite(a3, b2);
  analogWrite(a4, b2);
  delay(500);
  analogWrite(a1, b3);
  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);
  delay(500);
  off();
}


void man1()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a1, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 1 sec dalay"); Serial.println();
  delay(d);                  Serial.print("delay 1 sec complete"); Serial.println();
  analogWrite(a1, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i += ((3 * d) / 70))
  {
    analogWrite(a1, i);                  Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  for (int j = b2; j >= b1; j -= ((2 * d) / 70))
  {
    analogWrite(a1, j);                  Serial.print(j); Serial.println();
  }
  Serial.print("level 1 attained"); Serial.println();
  Serial.print("initialising 3 sec dalay"); Serial.println();
  delay(3 * d);                  Serial.print("delay 3 sec complete"); Serial.println();

  for (int k = b1; k <= b3; k += ((3 * d) / 225))
  {
    analogWrite(a1, k);                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}


void man2()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a1, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 1 sec dalay"); Serial.println();
  delay(d);                  Serial.print("delay 1 sec complete"); Serial.println();
  analogWrite(a1, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i++)
  {
    analogWrite(a1, i);                  Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  for (int j = b2; j >= b1; j--)
  {
    analogWrite(a1, j);                  Serial.print(j); Serial.println();
  }
  Serial.print("level 1 attained"); Serial.println();
  Serial.print("initialising 3 sec dalay"); Serial.println();
  delay(3 * d);                  Serial.print("delay 3 sec complete"); Serial.println();

  for (int k = b1; k <= b3; k++)
  {
    analogWrite(a1, k);                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}



void man3()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a1, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 1 sec dalay"); Serial.println();
  delay(d);                  Serial.print("delay 1 sec complete"); Serial.println();
  analogWrite(a1, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i++)
  {
    analogWrite(a1, i); delay(((3 * d) / 70));                 Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  for (int j = b2; j >= b1; j--)
  {
    analogWrite(a1, j);  delay(((2 * d) / 70));                Serial.print(j); Serial.println();
  }
  Serial.print("level 1 attained"); Serial.println();
  Serial.print("initialising 3 sec dalay"); Serial.println();
  delay(3 * d);                  Serial.print("delay 3 sec complete"); Serial.println();

  for (int k = b1; k <= b3; k++)
  {
    analogWrite(a1, k); delay(((3 * d) / 225));                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}


void mbn1()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a1, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 2 sec dalay"); Serial.println();
  delay(2 * d);                  Serial.print("delay 2 sec complete"); Serial.println();
  analogWrite(a2, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i++)
  {
    analogWrite(a2, i); delay(((3 * d) / 70));                 Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  for (int j = b2; j >= b1; j--)
  {
    analogWrite(a2, j);  delay(((2 * d) / 70));                Serial.print(j); Serial.println();
  }
  Serial.print("level 1 attained"); Serial.println();
  Serial.print("initialising 1 sec dalay"); Serial.println();
  delay(1 * d);                  Serial.print("delay 1 sec complete"); Serial.println();

  for (int k = b1; k <= b3; k++)
  {
    analogWrite(a2, k); delay(((3 * d) / 225));                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}

void mcn1()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a3, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 3 sec dalay"); Serial.println();
  delay(3 * d);                  Serial.print("delay 3 sec complete"); Serial.println();
  analogWrite(a3, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i++)
  {
    analogWrite(a3, i); delay(((3 * d) / 70));                 Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  for (int j = b2; j >= b1; j--)
  {
    analogWrite(a3, j);  delay(((2 * d) / 70));                Serial.print(j); Serial.println();
  }
  Serial.print("level 1 attained"); Serial.println();
  Serial.print("initialising 0 sec dalay"); Serial.println();
  //delay(3*d);
  Serial.print("delay 0 sec complete"); Serial.println();

  for (int k = b1; k <= b3; k++)
  {
    analogWrite(a3, k); delay(((2 * d) / 225));                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}


void mdn1()
{ int x = 1;
  int d = (x * 1000);
  analogWrite(a1, 0);              Serial.println();    Serial.print("initial off");
  Serial.println();
  Serial.print("initialising 4 sec dalay"); Serial.println();
  delay(4 * d);                  Serial.print("delay 4 sec complete"); Serial.println();
  analogWrite(a4, b1);                  Serial.print("level 1 attained"); Serial.println();
  for (int i = b1; i <= b2; i++)
  {
    analogWrite(a4, i); delay(((3 * d) / 70));                 Serial.print(i); Serial.println();
  }
  Serial.print("level 2 attained"); Serial.println();

  /*for(int j=b2;j>=b1;j--)
    {
    analogWrite(a1,j);  delay(((2*d)/70));                Serial.print(j);Serial.println();
    }
                    Serial.print("level 1 attained");Serial.println();
                    Serial.print("initialising 3 sec dalay");Serial.println();
                    delay(3*d);                  Serial.print("delay 3 sec complete");Serial.println();
  */

  for (int k = b2; k <= b3; k++)
  {
    analogWrite(a4, k); delay(((1 * d) / 155));                  Serial.print(k); Serial.println();
  }
  Serial.print("level 3 attained"); Serial.println();
  delay(3000);                  Serial.print("delay 3 sec complete"); Serial.println();

  off();
  Serial.print("end "); Serial.println();

}

































void a()
{
  up1(0, 255);
  delay(100);
  down1(255, 0);
  delay(2000);
}
void s()
{

  analogWrite(a1, 255);
  delay(200);
  analogWrite(a2, 255);
  delay(200);
  analogWrite(a1, 0);
  analogWrite(a3, 255);
  delay(200);
  analogWrite(a2, 0);
  analogWrite(a4, 255);
  delay(200);
  analogWrite(a3, 0);
  delay(200);
  analogWrite(a4, 0);
}

void on() {
  analogWrite(l2, 255); Serial.print("light on"); Serial.println();
  analogWrite(a1, 255); analogWrite(a2, 255); analogWrite(a3, 255); analogWrite(a4, 255); digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(g3, 0);
  digitalWrite(g4, 0);
}


void up1(int i, int k)
{
  for (int j = i; j <= k; j++)
  {
    analogWrite(a1, j); delay(5);
  }
}

void up2(int i, int k)
{
  for (int j = i; j <= k; j++)
  {
    analogWrite(a2, j);
  }
}
void up3(int i, int k)
{
  for (int j = i; j <= k; j++)
  {
    analogWrite(a3, j);
  }
}
void up4(int i, int k)
{
  for (int j = i; j <= k; j++)
  {
    analogWrite(a4, j);
  }
}



void down1(int i, int k)
{
  for (int j = i; j >= k; j--)
  {
    analogWrite(a1, j); delay(5);
  }
}


void down2(int i, int k)
{
  for (int j = i; j >= k; j--)
  {
    analogWrite(a2, j);
  }
}

void down3(int i, int k)
{
  for (int j = i; j >= k; j--)
  {
    analogWrite(a3, j);
  }
}

void down4(int i, int k)
{
  for (int j = i; j >= k; j--)
  {
    analogWrite(a4, j);
  }
}

void off()
{
  digitalWrite(l2, LOW);   Serial.print("light off"); Serial.println();
  digitalWrite(a1, LOW);   digitalWrite(a2, LOW);   digitalWrite(a3, LOW);   digitalWrite(a4, LOW);    digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(g3, 0);
  digitalWrite(g4, 0);
}

void chiron()
{
  for (int i = 0; i < 256; i += 5)
  {
    analogWrite(l2, i); delay(1000); Serial.print("light level   "); Serial.println(i); digitalWrite(l2, 0);
  }
  delay(800);

  for (int j = 255; j > 0; j -= 5)
  {
    analogWrite(l2, j); delay(1000); Serial.print("light level   "); Serial.println(j); digitalWrite(l2, 0);
  }
  digitalWrite(l2, 1);
}

void bl()
{

  off();
  delay(400);
  on();
  delay(1000);
  off();
}

void sh()
{
  while (1);
}


