int ifl = 22;          //indicator front left
int iflr = 23;        //indcator front left red
int iflg = 25;
int iflb = 24;         //indicator front left blue


int head = 26;         //headlamps
int head1 = 46;
int head2 = 47;
int head3 = 49;
int headr = 27;       //headlamp red
int headg = 29;
int headb = 28;


int ifr = 30;          //indicator front right
int ifrr = 31;        //indicator front right red green
int ifrg = 33;
int ifrb = 32;         //indicator front right blue

int ibl = 10;          //indicator back left
int iblr = 43;         //indicator back left red
int iblg = 45;         //indicator back left green
int iblb = 44;         //indicator back left blue


int ibr = 8;          //indicator back right
int ibrr = 35;         //indicator back right red
int ibrg = 37;         //indicator back right green
int ibrb = 36;         //indicator back right blue


int tail = 9;         //taillamps
int tailr = 39;        //taillamp red
int tailg = 41;        //taillamp green blue
int tailb = 40;







void setup() {
  Serial.begin(9600);
Serial1.begin(115200);
  pinMode(head, OUTPUT);
  pinMode(head1, OUTPUT);
  pinMode(head2, OUTPUT);
  pinMode(head3, OUTPUT);
  pinMode(headr, OUTPUT);
  pinMode(headg, OUTPUT);
  pinMode(headb, OUTPUT);


  pinMode(ifl, OUTPUT);
  pinMode(iflr, OUTPUT);
  pinMode(iflg, OUTPUT);
  pinMode(iflb, OUTPUT);

  pinMode(ifr, OUTPUT);
  pinMode(ifrr, OUTPUT);
  pinMode(ifrg, OUTPUT);
  pinMode(ifrb, OUTPUT);

  pinMode(ibl, OUTPUT);
  pinMode(iblr, OUTPUT);
  pinMode(iblg, OUTPUT);
  pinMode(iblb, OUTPUT);


  pinMode(ibr, OUTPUT);
  pinMode(ibrr, OUTPUT);
  pinMode(ibrg, OUTPUT);
  pinMode(ibrb, OUTPUT);

  pinMode(tail, OUTPUT);
  pinMode(tailr, OUTPUT);
  pinMode(tailg, OUTPUT);
  pinMode(tailb, OUTPUT);









}

void loop() {
  // put your main code here, to run repeatedly:
testall();
test();
  testrev  ();
  shutdown1();
}

void test()
{
  headonly_on();
  delay(800);
  headon();

  tailonly_on();

  tailon_f();
  delay(1100);
  headon();
  delay(1100);

  for (int i = 0; i < 5; i++)
  {
    left_on();
    delay(600);
    left_off();
    delay(500);
  }

  headon();
  delay(1100);

  for (int j = 0; j < 5; j++)
  {
    right_on();
    delay(600);
    right_off();
    delay(500);
  }

  headon();
  delay(1100);
  brake();
  delay(1100);
  rev();
  delay(1100);

  for (int l = 0; l < 5; l++)
  {
    rev_left_on();
    delay(600);
    rev_left_off();
    delay(500);
  }

  rev();
  delay(1100);

  for (int k = 0; k < 5; k++)
  {
    rev_right_on();
    delay(600);
    rev_right_off();
    delay(500);
  }
  rev();
  delay(1100);
  brake();
lights_out();
  delay(5000);


}
void testrev()
{
  headon();tailon_f();delay(1000);headoff();tailoff();delay(1000);
  for (int a = 0; a < 5; a++)
  {
    xleft_on();
    delay(600);
    xleft_off();
    delay(500);
  }

  headoff();
  delay(1100);

  for (int b = 0; b < 5; b++)
  {
    xright_on();
    delay(600);
    xright_off();
    delay(500);
  }

  headoff();
  delay(1100);
  brake();
  delay(1100);
  xrev();
  delay(1100);

  for (int c = 0; c < 5; c++)
  {
    xrev_left_on();
    delay(600);
    xrev_left_off();
    delay(500);
  }

  xrev();
  delay(1100);

  for (int d = 0; d < 5; d++)
  {
   xrev_right_on();
    delay(600);
    xrev_right_off();
    delay(500);
  }
  xrev();
  delay(1100);
  brake();
  
  lights_out();
}

void testall()
{
  //front left indicator
  digitalWrite(ifl, HIGH);
  digitalWrite(iflr, LOW); 
  digitalWrite(iflg, LOW); 
  digitalWrite(iflb, LOW);
  delay(150); 
  digitalWrite(iflr, HIGH); 
  digitalWrite(iflg, HIGH); 
  digitalWrite(iflb, HIGH); 
  delay(150);
  
  digitalWrite(iflr, LOW); delay(150);
  digitalWrite(iflr, HIGH); delay(150);
  digitalWrite(iflg, LOW);delay(150);
  digitalWrite(iflg, HIGH);delay(150);
  digitalWrite(iflb, LOW); delay(150);
  digitalWrite(iflb, HIGH); delay(150);
  digitalWrite(ifl, LOW); delay(150);

//front right indicator
 digitalWrite(ifr, HIGH);
  digitalWrite(ifrr, LOW); 
  digitalWrite(ifrg, LOW); 
  digitalWrite(ifrb, LOW);
  delay(150); 
  digitalWrite(ifrr, HIGH); 
  digitalWrite(ifrg, HIGH); 
  digitalWrite(ifrb, HIGH); 
  delay(150);
  
  digitalWrite(ifrr, LOW); delay(150);
  digitalWrite(ifrr, HIGH); delay(150);
  digitalWrite(ifrg, LOW);delay(150);
  digitalWrite(ifrg, HIGH);delay(150);
  digitalWrite(ifrb, LOW); delay(150);
  digitalWrite(ifrb, HIGH); delay(150);
  digitalWrite(ifr, LOW); delay(150);

//headlamps
 digitalWrite(head, HIGH);
 digitalWrite(head1, HIGH);
  digitalWrite(head2, HIGH);
   digitalWrite(head3, HIGH);
   digitalWrite(headr, LOW); 
  digitalWrite(headg, LOW); 
  digitalWrite(headb, LOW);
  delay(150); 
  digitalWrite(headr, HIGH); 
  digitalWrite(headg, HIGH); 
  digitalWrite(headb, HIGH); 
  delay(150);
  
  digitalWrite(headr, LOW); delay(150);
  digitalWrite(headr, HIGH); delay(150);
  digitalWrite(headg, LOW);delay(150);
  digitalWrite(headg, HIGH);delay(150);
  digitalWrite(headb, LOW); delay(150);
  digitalWrite(headb, HIGH); delay(150);
  digitalWrite(head, LOW); delay(150);

//back right indicator
 digitalWrite(ibr, HIGH);
  digitalWrite(ibrr, LOW); 
  digitalWrite(ibrg, LOW); 
  digitalWrite(ibrb, LOW);
  delay(150); 
  digitalWrite(ibrr, HIGH); 
  digitalWrite(ibrg, HIGH); 
  digitalWrite(ibrb, HIGH); 
  delay(150);
  
  digitalWrite(ibrr, LOW); delay(150);
  digitalWrite(ibrr, HIGH); delay(150);
  digitalWrite(ibrg, LOW);delay(150);
  digitalWrite(ibrg, HIGH);delay(150);
  digitalWrite(ibrb, LOW); delay(150);
  digitalWrite(ibrb, HIGH); delay(150);
  digitalWrite(ibr, LOW); delay(150);

//back left indicator
 digitalWrite(ibl, HIGH);
  digitalWrite(iblr, LOW); 
  digitalWrite(iblg, LOW); 
  digitalWrite(iblb, LOW);
  delay(150); 
  digitalWrite(iblr, HIGH); 
  digitalWrite(iblg, HIGH); 
  digitalWrite(iblb, HIGH); 
  delay(150);
  
  digitalWrite(iblr, LOW); delay(150);
  digitalWrite(iblr, HIGH); delay(150);
  digitalWrite(iblg, LOW);delay(150);
  digitalWrite(iblg, HIGH);delay(150);
  digitalWrite(iblb, LOW); delay(150);
  digitalWrite(iblb, HIGH); delay(150);
  digitalWrite(ibl, LOW); delay(150);

//tail 
 digitalWrite(tail, HIGH);
  digitalWrite(tailr, LOW); 
  digitalWrite(tailg, LOW); 
  digitalWrite(tailb, LOW);
  delay(150); 
  digitalWrite(tailr, HIGH); 
  digitalWrite(tailg, HIGH); 
  digitalWrite(tailb, HIGH); 
  delay(150);
  
  digitalWrite(tailr, LOW); delay(150);
  digitalWrite(tailr, HIGH); delay(150);
  digitalWrite(tailg, LOW);delay(150);
  digitalWrite(tailg, HIGH);delay(150);
  digitalWrite(tailb, LOW); delay(150);
  digitalWrite(tailb, HIGH); delay(150);
  digitalWrite(tail, LOW); delay(150);

}


void lights_out()
{
  headoff();
  tailoff();
}

void headon()
{
  digitalWrite(head, HIGH); //          headlight on
  digitalWrite(head1, HIGH); //          headlight on
  digitalWrite(head2, HIGH); //          headlight on
  digitalWrite(head3, HIGH); //          headlight on
  digitalWrite(headr, LOW); //
  digitalWrite(headg, LOW); //
  digitalWrite(headb, LOW); //


  digitalWrite(ifl, HIGH); //
  digitalWrite(iflr, LOW); //                left white on
  digitalWrite(iflb, LOW); //
  digitalWrite(iflg, LOW); //                left white on



  digitalWrite(ifr, HIGH); //
  digitalWrite(ifrr, LOW); //                 right white on
  digitalWrite(ifrb, LOW); //
  digitalWrite(ifrg, LOW); //

}


void headoff()
{
  digitalWrite(head, LOW); //
  digitalWrite(head1, LOW); //
  digitalWrite(head2, LOW); //
  digitalWrite(head3, LOW); //
  digitalWrite(headr, HIGH); //            headlight off
  digitalWrite(headg, HIGH); //            headlight off
  digitalWrite(headb, HIGH); //            headlight off


  digitalWrite(ifl, LOW); //
  digitalWrite(iflr, HIGH); //             left indi off
  digitalWrite(iflb, HIGH); //
  digitalWrite(iflg, HIGH); //             left indi off

  digitalWrite(ifr, LOW); //
  digitalWrite(ifrr, HIGH); //                 right indi off
  digitalWrite(ifrb, HIGH); //
  digitalWrite(ifrg, HIGH); //

}


void headonly_on()
{
  digitalWrite(head, HIGH); //                headlight on
  digitalWrite(head1, HIGH); //                headlight on
  digitalWrite(head2, HIGH); //                headlight on
  digitalWrite(head3, HIGH); //                headlight on
  digitalWrite(headr, LOW); //
  digitalWrite(headb, LOW); //
  digitalWrite(headg, LOW); //

}

void headonly_off()
{
  digitalWrite(head, LOW); //
  digitalWrite(head1, LOW); //
  digitalWrite(head2, LOW); //
  digitalWrite(head3, LOW); //
  digitalWrite(headr, HIGH); //                headlight off
  digitalWrite(headg, HIGH); //                headlight off
  digitalWrite(headb, HIGH); //                headlight off

}



void tailon_h() {

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //       red on                    tail red on
  digitalWrite(tailg, HIGH);            //       blue green off
  digitalWrite(tailb, HIGH);            //       blue green off


  analogWrite(ibl, 80);               //  left back half
  digitalWrite(iblr, LOW);            //   red on                           red on
  digitalWrite(iblg, HIGH);            //   green off
  digitalWrite(iblb, HIGH);            //   blue off

  analogWrite(ibr, 80);                //  left right half
  digitalWrite(ibrr, LOW);            //   red on                          red on
  digitalWrite(ibrg, HIGH);            //   green off
  digitalWrite(ibrb, HIGH);            //   blue off

}



void tailon_f() {

  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                  red on
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}

void tailonly_on()
{
  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

}
void tailonly_off() {

  digitalWrite(tail, LOW);       //   vcc active
  digitalWrite(tailr, HIGH);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


}

void tailoff() {

  digitalWrite(tail, LOW);       //   vcc active
  digitalWrite(tailr, HIGH);       //    red off                           tail red off
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, LOW);     //  vcc active                       left back
  digitalWrite(iblr, HIGH);     //left indi  red off               red off
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, LOW);          //         vcc active              right back
  digitalWrite(ibrr, HIGH);         //right indi red off                  red off
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}


void brake() {

  digitalWrite(tail, HIGH);       //   vcc active
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                  red on
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off

}



void left_on() {
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off

  digitalWrite(ifr, HIGH); //     front right      vcc active
  digitalWrite(ifrr, LOW); //                      yellow on                white on
  digitalWrite(ifrg, LOW); //                      yellow on                white on
  digitalWrite(ifrb, LOW); //                       blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off


  analogWrite(ibr, 80); //    back right        vcc active
  digitalWrite(ibrr, LOW); //                      red on                red on
  digitalWrite(ibrb, HIGH); //                     blue off
  digitalWrite(ibrg, HIGH); //                     green off

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}

void left_off() {
  headon();
  tailon_h();
 
}

void right_on() {
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ifl, HIGH); //       front left     vcc active
  digitalWrite(iflr, LOW); //                     yellow on                 white on
  digitalWrite(iflg, LOW); //                     yellow on                 white on
  digitalWrite(iflb, LOW); //                       blue on

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  analogWrite(ibl, 80); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                red on
  digitalWrite(iblb, HIGH); //                   blue off
  digitalWrite(iblg, HIGH); //                   green off

}

void right_off() {

  headon();
  tailon_h();
}




void rev()
{
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    white on
  digitalWrite(iblb, LOW);     //left indi blue on
  digitalWrite(iblg, LOW);     //left indi green on


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}


void rev_left_on()
{
  headon();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off

  digitalWrite(ifr, HIGH); //     front right      vcc active
  digitalWrite(ifrr, LOW); //                      yellow on                white on
  digitalWrite(ifrg, LOW); //                      yellow on                white on
  digitalWrite(ifrb, LOW); //                       blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off


  digitalWrite(ibr, HIGH); //    back right        vcc active
  digitalWrite(ibrr, LOW); //                      red on                white on
  digitalWrite(ibrb, LOW); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}


void rev_left_off() {

  headon();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);               //    red on                     tailon
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

  digitalWrite(ifr, HIGH); //                   vcc active
  digitalWrite(ifrr, LOW); //                 yellow on                    white on
  digitalWrite(ifrg, LOW); //                 yellow on                    white on
  digitalWrite(ifrb, LOW); //                   blue on

  digitalWrite(ifl, HIGH); //                 vcc active
  digitalWrite(iflr, LOW); //                yellow on                      white on
  digitalWrite(iflg, LOW); //                yellow on                      white on
  digitalWrite(iflb, LOW); //                   blue on

  digitalWrite(ibr, HIGH); //                     vcc active
  digitalWrite(ibrr, LOW); //                 red on                      white on
  digitalWrite(ibrb, LOW); //                   blue on
  digitalWrite(ibrg, LOW); //                   green on

  digitalWrite(ibl, HIGH); //                     vcc active
  digitalWrite(iblr, LOW); //                 red on                        white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}



void rev_right_on()
{
  headon();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ifl, HIGH); //       front left     vcc active
  digitalWrite(iflr, LOW); //                     yellow on                 white on
  digitalWrite(iflg, LOW); //                     yellow on                 white on
  digitalWrite(iflb, LOW); //                       blue on

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}

void rev_right_off() {
  headon();
  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW); //                  red on                     tailon
  digitalWrite(tailg, HIGH); //                 blue green off
  digitalWrite(tailb, HIGH); //                 blue green off


  digitalWrite(ifr, HIGH); //     front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                    white on
  digitalWrite(ifrg, LOW); //                    yellow on                    white on
  digitalWrite(ifrb, LOW); //                      blue on

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                     yellow on                   white on
  digitalWrite(iflg, LOW); //                     yellow on                   white on
  digitalWrite(iflb, LOW); //                    blue on

  digitalWrite(ibr, HIGH); //   back right        vcc active
  digitalWrite(ibrr, LOW); //                     red on                      white on
  digitalWrite(ibrb, LOW); //                      blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //   back left         vcc active
  digitalWrite(iblr, LOW); //                      red on                      white on
  digitalWrite(iblb, LOW); //                      blue on
  digitalWrite(iblg, LOW); //                     green on

}
// ****************************************************************************************

void xleft_on() {
  headoff();

  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off

  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}

void xleft_off() {
  headoff();
  tailoff();
 
}

void xright_on() {
  headoff();

  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off

  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

}

void xright_off() {

  headoff();
  tailoff();
}

void xrev()
{
  headoff();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, HIGH);     //  vcc active                       left back
  digitalWrite(iblr, LOW);     //left indi  red on                    white on
  digitalWrite(iblb, LOW);     //left indi blue on
  digitalWrite(iblg, LOW);     //left indi green on


  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}


void xrev_left_on()
{
  headoff();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);                   //    red on                     tailon
  digitalWrite(tailg, HIGH);                //  blue green off
  digitalWrite(tailb, HIGH);                //  blue green off


  digitalWrite(ifl, HIGH); //     front left        vcc active
  digitalWrite(iflr, LOW); //                       yellow on               yellow on
  digitalWrite(iflg, LOW); //                       yellow on               yellow on
  digitalWrite(iflb, HIGH); //                     blue off



  digitalWrite(ibl, HIGH); //     back left        vcc active
  digitalWrite(iblr, LOW); //                     red on                yellow on
  digitalWrite(iblb, HIGH); //                    blue on
  digitalWrite(iblg, LOW); //                       green on

}


void xrev_left_off() {

  headoff();


  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);               //    red on                     tailon
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off

digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}



void xrev_right_on()
{
  headoff();

  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW);            //     red on                     tailon
  digitalWrite(tailg, HIGH);            //    blue green off
  digitalWrite(tailb, HIGH);            //    blue green off


  digitalWrite(ifr, HIGH); //      front right     vcc active
  digitalWrite(ifrr, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrg, LOW); //                    yellow on                  yellow on
  digitalWrite(ifrb, HIGH); //                       blue off


  digitalWrite(ibr, HIGH); //       back right    vcc active
  digitalWrite(ibrr, LOW); //                     red on                yellow on
  digitalWrite(ibrb, HIGH); //                     blue on
  digitalWrite(ibrg, LOW); //                     green on

  digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}

void xrev_right_off() {
  headoff();
  analogWrite(tail, 80);               //   vcc half
  digitalWrite(tailr, LOW); //                  red on                     tailon
  digitalWrite(tailg, HIGH); //                 blue green off
  digitalWrite(tailb, HIGH); //                 blue green off

 digitalWrite(ibl, HIGH); //      back left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

  digitalWrite(ibr, HIGH);          //         vcc active              right back
  digitalWrite(ibrr, LOW);         //right indi red on                 white on
  digitalWrite(ibrb, LOW);         //right indi blue on
  digitalWrite(ibrg, LOW);         //right indi green on

}
// *********************************************************************************************

void shutdown1()
{
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println ("                   *************************");
  Serial.println ("                         end of program ");
  Serial.println ("                   *************************");
  while (1);
}


