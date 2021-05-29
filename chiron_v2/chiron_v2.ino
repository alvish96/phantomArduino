#define l2 8
#define g1 22
#define g2 23
#define g3 24
#define g4 25
#define a1 4
#define a2 5
#define a3 6
#define a4 7



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
  deb();
  //  aq();
  //aq1();
t1();
  sh();
}


double b0 = 0;
double b1 = 5; //
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
double q4 = (b2 + ((b3 - b2) * 2) / 5);

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
  Serial.print("   level q1 = (b1 + ((b2 - b1) / 3))        = "); Serial.println(q1);
  Serial.print("   level q2 = (b1 + (((b2 - b1) * 2) / 3))  = "); Serial.println(q2);
  Serial.print("   level q3 = (b1 + ((b2 - b1) / 2))        = "); Serial.println(q3);
  Serial.print("   level q4 = (b2 + ((b3 - b2)* 2)/ 5)      = "); Serial.println(q4);
}


void t0()
{
  Serial.println();
  Serial.print("              *****----________t0 running_________----*****                   ");
 
  Serial.println(); Serial.print("                    -------------   0 -------------");
  analogWrite(a1, b0);
  analogWrite(a2, b0);         //0
  analogWrite(a3, b0);
  analogWrite(a4, b0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b0);
  Serial.print("                  led2  "); Serial.println(b0);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



  Serial.println(); Serial.print("                    -------------   1 -------------");
  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b0);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



  Serial.println(); Serial.print("                    -------------   2 -------------");
  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



  Serial.println(); Serial.print("                    -------------   3 -------------");
  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q2);
  Serial.print("                  led2  "); Serial.println(q1);
  Serial.print("                         led3  "); Serial.println(b1);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



  Serial.println(); Serial.print("                    -------------   4 -------------");
  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b2);
  Serial.print("                  led2  "); Serial.println(q2);
  Serial.print("                         led3  "); Serial.println(q1);
  Serial.print("                                led4  "); Serial.println(b1);
  delay(d);



  Serial.println(); Serial.print("                    -------------   5 -------------");
  analogWrite(a1, q3);      //5
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q3);
  Serial.print("                  led2  "); Serial.println(b2);
  Serial.print("                         led3  "); Serial.println(q2);
  Serial.print("                                led4  "); Serial.println(q1);
  delay(d);


  Serial.println(); Serial.print("                    -------------   6 -------------");

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  analogWrite(a3, b2);
  analogWrite(a4, q2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(q3);
  Serial.print("                         led3  "); Serial.println(b2);
  Serial.print("                                led4  "); Serial.println(q2);
  delay(d);


  Serial.println(); Serial.print("                    -------------   7 -------------");
  analogWrite(a1, b1);      //7
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  analogWrite(a4, b2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(q3);
  Serial.print("                                led4  "); Serial.println(b2);
  delay(d);


  Serial.println(); Serial.print("                    -------------   8 -------------");
  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  analogWrite(a3, b1);
  analogWrite(a4, b2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(b1);
  Serial.print("                                led4  "); Serial.println(b2);
  delay(d);


  Serial.println(); Serial.print("                    -------------   9 -------------");
  analogWrite(a1, b1);      //9
  analogWrite(a2, b1);
  analogWrite(a3, q4);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(q4);
  Serial.print("                                led4  "); Serial.println(b3);


  delay(d);


  Serial.println(); Serial.print("                    -------------   10 -------------");
  analogWrite(a1, b1);      //10
  analogWrite(a2, q4);
  analogWrite(a3, b3);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(q4);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);


  delay(d);


  Serial.println(); Serial.print("                    -------------   11 -------------");
  analogWrite(a1, q4);      //11
  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q4);
  Serial.print("                  led2  "); Serial.println(b3);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);
  delay(d);


  Serial.println(); Serial.print("                    -------------   12 -------------");

  analogWrite(a1, b3);      //12
  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);


  Serial.println();
  Serial.print("           led1  "); Serial.println(b3);
  Serial.print("                  led2  "); Serial.println(b3);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);

  delay(2000);
  off();
}




void t1()
{
  Serial.println();
  Serial.print("              *****----________t1 running_________----*****                   ");
 
  Serial.println();
  Serial.println();
  Serial.println();


  
  Serial.println(); Serial.print("                    -------------   0 -------------");
  analogWrite(a1, b0);
  analogWrite(a2, b0);         //0
  analogWrite(a3, b0);
  analogWrite(a4, b0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b0);
  Serial.print("                  led2  "); Serial.println(b0);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);


for (int i11=b0,i12=b0,i13=b0,i14=b0;i11<=b1,i12<=b0,i13<=b0,i14<=b0;i11++,i12++,i13++,i14++)
{
  analogWrite(a1, i11);  Serial.println();  Serial.print("           led1  "); Serial.println(i11);
  analogWrite(a2, i12);  Serial.println();  Serial.print("                led2  "); Serial.println(i12);
  analogWrite(a3, i13);  Serial.println();  Serial.print("                      led3  "); Serial.println(i13);
  analogWrite(a4, i14);  Serial.println();  Serial.print("                            led4  "); Serial.println(i14);

}


  Serial.println(); Serial.print("                    -------------   1 -------------");
  analogWrite(a1, b1);      //1
  analogWrite(a2, 0);
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b0);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);


for (int i21=b1,i22=b0,i23=b0,i24=b0;i21<=q1,i22<=b1,i23<=b0,i24<=b0;i21++,i22++,i23++,i24++)
{
  analogWrite(a1, i21);  Serial.println();  Serial.print("           led1  "); Serial.println(i21);
  analogWrite(a2, i22);  Serial.println();  Serial.print("                led2  "); Serial.println(i22);
  analogWrite(a3, i23);  Serial.println();  Serial.print("                      led3  "); Serial.println(i23);
  analogWrite(a4, i24);  Serial.println();  Serial.print("                            led4  "); Serial.println(i24);

}

  Serial.println(); Serial.print("                    -------------   2 -------------");
  analogWrite(a1, q1);      //2
  analogWrite(a2, b1);
  analogWrite(a3, 0);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(b0);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



for (int i31=q1,i32=b1,i33=0,i34=0;i31<=q2,i32<=q1,i33<=b1,i34<=0;i31++,i32++,i33++,i34++)
{
  analogWrite(a1, i31);  Serial.println();  Serial.print("           led1  "); Serial.println(i31);
  analogWrite(a2, i32);  Serial.println();  Serial.print("                led2  "); Serial.println(i32);
  analogWrite(a3, i33);  Serial.println();  Serial.print("                      led3  "); Serial.println(i33);
  analogWrite(a4, i34);  Serial.println();  Serial.print("                            led4  "); Serial.println(i34);

}

  Serial.println(); Serial.print("                    -------------   3 -------------");
  analogWrite(a1, q2);      //3
  analogWrite(a2, q1);
  analogWrite(a3, b1);
  analogWrite(a4, 0);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q2);
  Serial.print("                  led2  "); Serial.println(q1);
  Serial.print("                         led3  "); Serial.println(b1);
  Serial.print("                                led4  "); Serial.println(b0);
  delay(d);



for (int i41=q2,i42=q1,i43=b1,i44=0;i41<=b2,i42<=q2,i43<=q1,i44<=b1;i41++,i42++,i43++,i44++)
{
  analogWrite(a1, i41);  Serial.println();  Serial.print("           led1  "); Serial.println(i41);
  analogWrite(a2, i42);  Serial.println();  Serial.print("                led2  "); Serial.println(i42);
  analogWrite(a3, i43);  Serial.println();  Serial.print("                      led3  "); Serial.println(i43);
  analogWrite(a4, i44);  Serial.println();  Serial.print("                            led4  "); Serial.println(i44);
}

  Serial.println(); Serial.print("                    -------------   4 -------------");
  analogWrite(a1, b2);      //4
  analogWrite(a2, q2);
  analogWrite(a3, q1);
  analogWrite(a4, b1);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b2);
  Serial.print("                  led2  "); Serial.println(q2);
  Serial.print("                         led3  "); Serial.println(q1);
  Serial.print("                                led4  "); Serial.println(b1);
  delay(d);



for (int i51=b2,i52=q2,i53=q1,i54=b1;i51>=q3,i52<=b2,i53<=q2,i54<=q1;i51--,i52++,i53++,i54++)
{
  analogWrite(a1, i51);  Serial.println();  Serial.print("           led1  "); Serial.println(i51);
  analogWrite(a2, i52);  Serial.println();  Serial.print("                led2  "); Serial.println(i52);
  analogWrite(a3, i53);  Serial.println();  Serial.print("                      led3  "); Serial.println(i53);
  analogWrite(a4, i54);  Serial.println();  Serial.print("                            led4  "); Serial.println(i54);
}

  Serial.println(); Serial.print("                    -------------   5 -------------");
  analogWrite(a1, q3);      //5
  analogWrite(a2, b2);
  analogWrite(a3, q2);
  analogWrite(a4, q1);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q3);
  Serial.print("                  led2  "); Serial.println(b2);
  Serial.print("                         led3  "); Serial.println(q2);
  Serial.print("                                led4  "); Serial.println(q1);
  delay(d);


for (int i61=q3,i62=b2,i63=q2,i64=q1;i61>=b1,i62>=q3,i63<=b2,i64<=q2;i61--,i62--,i63++,i64++)
{
  analogWrite(a1, i61);  Serial.println();  Serial.print("           led1  "); Serial.println(i61);
  analogWrite(a2, i62);  Serial.println();  Serial.print("                led2  "); Serial.println(i62);
  analogWrite(a3, i63);  Serial.println();  Serial.print("                      led3  "); Serial.println(i63);
  analogWrite(a4, i64);  Serial.println();  Serial.print("                            led4  "); Serial.println(i64);

}

  Serial.println(); Serial.print("                    -------------   6 -------------");

  analogWrite(a1, b1);      //6
  analogWrite(a2, q3);
  analogWrite(a3, b2);
  analogWrite(a4, q2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(q3);
  Serial.print("                         led3  "); Serial.println(b2);
  Serial.print("                                led4  "); Serial.println(q2);
  delay(d);


for (int i71=b1,i72=q3,i73=b2,i74=q2;i71<=b1,i72<=b1,i73>=q3,i74<=b2;i71++,i72++,i73--,i74++)
{
  analogWrite(a1, i71);  Serial.println();  Serial.print("           led1  "); Serial.println(i71);
  analogWrite(a2, i72);  Serial.println();  Serial.print("                led2  "); Serial.println(i72);
  analogWrite(a3, i73);  Serial.println();  Serial.print("                      led3  "); Serial.println(i73);
  analogWrite(a4, i74);  Serial.println();  Serial.print("                            led4  "); Serial.println(i74);
}

  Serial.println(); Serial.print("                    -------------   7 -------------");
  analogWrite(a1, b1);      //7
  analogWrite(a2, b1);
  analogWrite(a3, q3);
  analogWrite(a4, b2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(q3);
  Serial.print("                                led4  "); Serial.println(b2);
  delay(d);


for (int i1,i2,i3,i4;i1,i2,i3,i4;i1,i2,i3,i4)
{
  analogWrite(a1, i1);     
  analogWrite(a2, i2);
  analogWrite(a3, i3);
  analogWrite(a4, i4);

}

  Serial.println(); Serial.print("                    -------------   8 -------------");
  analogWrite(a1, b1);      //8
  analogWrite(a2, b1);
  analogWrite(a3, b1);
  analogWrite(a4, b2);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(b1);
  Serial.print("                                led4  "); Serial.println(b2);
  delay(d);


for (int i1,i2,i3,i4;i1,i2,i3,i4;i1,i2,i3,i4)
{
  analogWrite(a1, i1);     
  analogWrite(a2, i2);
  analogWrite(a3, i3);
  analogWrite(a4, i4);

}

  Serial.println(); Serial.print("                    -------------   9 -------------");
  analogWrite(a1, b1);      //9
  analogWrite(a2, b1);
  analogWrite(a3, q4);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(b1);
  Serial.print("                         led3  "); Serial.println(q4);
  Serial.print("                                led4  "); Serial.println(b3);


  delay(d);


for (int i1,i2,i3,i4;i1,i2,i3,i4;i1,i2,i3,i4)
{
  analogWrite(a1, i1);     
  analogWrite(a2, i2);
  analogWrite(a3, i3);
  analogWrite(a4, i4);

}

  Serial.println(); Serial.print("                    -------------   10 -------------");
  analogWrite(a1, b1);      //10
  analogWrite(a2, q4);
  analogWrite(a3, b3);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(b1);
  Serial.print("                  led2  "); Serial.println(q4);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);


  delay(d);


for (int i1,i2,i3,i4;i1,i2,i3,i4;i1,i2,i3,i4)
{
  analogWrite(a1, i1);     
  analogWrite(a2, i2);
  analogWrite(a3, i3);
  analogWrite(a4, i4);

}

  Serial.println(); Serial.print("                    -------------   11 -------------");
  analogWrite(a1, q4);      //11
  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);

  Serial.println();
  Serial.print("           led1  "); Serial.println(q4);
  Serial.print("                  led2  "); Serial.println(b3);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);
  delay(d);


for (int i1,i2,i3,i4;i1,i2,i3,i4;i1,i2,i3,i4)
{
  analogWrite(a1, i1);     
  analogWrite(a2, i2);
  analogWrite(a3, i3);
  analogWrite(a4, i4);

}

  Serial.println(); Serial.print("                    -------------   12 -------------");

  analogWrite(a1, b3);      //12
  analogWrite(a2, b3);
  analogWrite(a3, b3);
  analogWrite(a4, b3);


  Serial.println();
  Serial.print("           led1  "); Serial.println(b3);
  Serial.print("                  led2  "); Serial.println(b3);
  Serial.print("                         led3  "); Serial.println(b3);
  Serial.print("                                led4  "); Serial.println(b3);

  delay(2000);
  off();
}












































void off()
{
  digitalWrite(l2, LOW);   Serial.print("light off"); Serial.println();
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);
  digitalWrite(g1, 0);
  digitalWrite(g2, 0);
  digitalWrite(g3, 0);
  digitalWrite(g4, 0);
}

void sh()
{
  while (1);
}
