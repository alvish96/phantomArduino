int ifl = 22;          //indicator front left
int iflr = 28;        //indcator front left red
int iflg = 25;           
int iflb = 24;         //indicator front left blue


int head = 26;         //headlamps
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

  pinMode(head, OUTPUT);
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
test();
shutdown1();
}

void test()
{
  headonly_on();
  delay(800);
headon();

tailonly_on();

tailon_f();
delay(3000);
headon();
delay(3000);

for(int i=0;i<5;i++)
{
  left_on();
  delay(600);
  left_off();
  delay(500);
}

headon();
delay(3000);

for(int j=0;j<5;j++)
{
  right_on();
  delay(600);
right_off();
delay(500);
}

headon();
delay(3000);
brake();
delay(3000);
rev();
delay(3000);

for(int l=0;l<5;l++)
{
  rev_left_on();
  delay(600);
rev_left_off();
delay(500);
}

rev();
delay(3000);

for(int k=0;k<5;k++)
{
  rev_right_on();
  delay(600);
rev_right_off();
delay(500);
}
 rev();
delay(3000);
brake();
lights_out();
}

void lights_out()
{
  headoff();
  tailoff();
}




void headon()
{
  digitalWrite(head, HIGH); //          headlight on
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
  digitalWrite(headr, LOW); //
  digitalWrite(headb, LOW); //
  digitalWrite(headg, LOW); //

}

void headonly_off()
{
  digitalWrite(head, LOW); //
  digitalWrite(headr, HIGH); //                headlight off
  digitalWrite(headg, HIGH); //                headlight off
  digitalWrite(headb, HIGH); //                headlight off

}









void tailon_h() {

  analogWrite(tail, 150);               //   vcc half
  digitalWrite(tailr, LOW);            //       red on                    tail red on
  digitalWrite(tailg, HIGH);            //       blue green off
  digitalWrite(tailb, HIGH);            //       blue green off


  analogWrite(ibl, 150);               //  left back half
  digitalWrite(iblr, LOW);            //   red on                           red on
  digitalWrite(iblg, HIGH);            //   green off
  digitalWrite(iblb, HIGH);            //   blue off

  analogWrite(ibr, 150);                //  left right half
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

/*
  digitalWrite(ibl, LOW);     //  vcc active                       left back
  digitalWrite(iblr, HIGH);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, LOW);          //         vcc active              right back
  digitalWrite(ibrr, HIGH);         //right indi red on                  red on
  digitalWrite(ibrb, HIGH);         //right indi blue off
  digitalWrite(ibrg, HIGH);         //right indi green off
*/
}

void tailoff() {

  digitalWrite(tail, LOW);       //   vcc active
  digitalWrite(tailr, HIGH);       //    red on                           tail red on
  digitalWrite(tailg, HIGH);            //  blue green off
  digitalWrite(tailb, HIGH);            //  blue green off


  digitalWrite(ibl, LOW);     //  vcc active                       left back
  digitalWrite(iblr, HIGH);     //left indi  red on                    red on
  digitalWrite(iblb, HIGH);     //left indi blue off
  digitalWrite(iblg, HIGH);     //left indi green off


  digitalWrite(ibr, LOW);          //         vcc active              right back
  digitalWrite(ibrr, HIGH);         //right indi red on                  red on
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

  digitalWrite(tail, HIGH);                    //   vcc active
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
  tailon_f();
  /*
    digitalWrite(tail,HIGH);              //   vcc active
    digitalWrite(tailr,LOW);                //    red on                     tailon
    digitalWrite(tailgb,HIGH);             //  blue green off

    digitalWrite(ifr,HIGH);//    front right    vcc active
    digitalWrite(ifrrg,LOW);//                 yellow on                    white on
    digitalWrite(ifrb,LOW);//                   blue on

    digitalWrite(ifl,HIGH);//   front left        vcc active
    digitalWrite(iflrg,LOW);//                   yellow on                      white on
    digitalWrite(iflb,LOW);//                   blue on

    digitalWrite(ibr,HIGH);//       back right    vcc active
    digitalWrite(ibrr,LOW);//                    red on                      red on
    digitalWrite(ibrb,HIGH);//                   blue off
    digitalWrite(ibrg,HIGH);//                   green off

    digitalWrite(ibl,HIGH);//      back left      vcc active
    digitalWrite(iblr,LOW);//                 red on                        red on
    digitalWrite(iblb,HIGH);//                   blue off
    digitalWrite(iblg,HIGH);//                   green off
  */
}

void right_on() {
  headon();

  digitalWrite(tail, HIGH);            //    vcc active
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
  digitalWrite(iblr, LOW); //                     red on                red on
  digitalWrite(iblb, HIGH); //                   blue off
  digitalWrite(iblg, HIGH); //                   green off

}

void right_off() {

  headon();
  tailon_f();
}




void rev()
{
  headon();

  digitalWrite(tail, HIGH);       //   vcc active
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


  digitalWrite(tail, HIGH);                    //   vcc active
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


  digitalWrite(tail, HIGH);             //   vcc active
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

  digitalWrite(tail, HIGH);            //    vcc active
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

  digitalWrite(ibl, HIGH); //      front left     vcc active
  digitalWrite(iblr, LOW); //                     red on                white on
  digitalWrite(iblb, LOW); //                   blue on
  digitalWrite(iblg, LOW); //                   green on

}

void rev_right_off() {
  headon();
  digitalWrite(tail, HIGH);  //                  vcc active
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


