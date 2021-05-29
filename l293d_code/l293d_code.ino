/*int en1 = 6, en2 = 5, en3 = 10, en4 = 11;
int f11 = 2, f12 = 3, f21 = 4, f22 = 7, f31 = 12, f32 = 13, f41 = 8, f42 = 9;

/*
 * en4 is front right
 * en3 is back left
 * en2 is front left
 * en1 is back right
 

#define ENA_m1 11        // Enable/speed motor Front Right  
#define IN_11  8        // L298N #1 in 1 motor Front Right   
#define IN_12  9        // L298N #1 in 2 motor Front Right


#define ENB_m1 6         // Enable/speed motor Back Right   
#define IN_13  2       // L298N #1 in 3 motor Back Right
#define IN_14  3        // L298N #1 in 4 motor Back Right

#define ENA_m2 5       // Enable/speed motor Front Left    
#define IN_21  4         // L298N #2 in 1 motor Front Left
#define IN_22  7        // L298N #2 in 2 motor Front Left

#define ENB_m2 10      // Enable/speed motor Back Left      
#define IN_23  12      // L298N #2 in 3 motor Back Left
#define IN_24  13      // L298N #2 in 4 motor Back 


void setup() {

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(en3, OUTPUT);
  pinMode(en4, OUTPUT);
  digitalWrite(en1, 1);
  digitalWrite(en2, 1);
  digitalWrite(en3, 1);
  digitalWrite(en4, 1);

  pinMode(f11, OUTPUT);
  pinMode(f12, OUTPUT);
  pinMode(f21, OUTPUT);
  pinMode(f22, OUTPUT);
  pinMode(f31, OUTPUT);
  pinMode(f32, OUTPUT);
  pinMode(f41, OUTPUT);
  pinMode(f42, OUTPUT);
  digitalWrite(f11, 0);
  digitalWrite(f12, 0);
  digitalWrite(f21, 0);
  digitalWrite(f22, 0);
  digitalWrite(f31, 0);
  digitalWrite(f32, 0);
  digitalWrite(f41, 0);
  digitalWrite(f42, 0);
}

void loop() {
//fn1();
}
void fn1()
{
  digitalWrite(en1, 1);
  digitalWrite(f12, 0);
  digitalWrite(f11, 1);
  delay(1000);
  digitalWrite(f11, 0);
  delay(1000);
}
//        int en1 = 6, en2 = 5, en3 = 10, en4 = 11;
//        int f11 = 2, f12 = 3, f21 = 4, f22 = 7, f31 = 12, f32 = 13, f41 = 8, f42 = 9;





void fn()
{
  digitalWrite(f11, 1);
  digitalWrite(f12, 0);
  delay(500);

  digitalWrite(f11, 0);
  digitalWrite(f12, 0);
  delay(500);

  digitalWrite(f11, 0);
  digitalWrite(f12, 1);
  delay(500);

  digitalWrite(f11, 0);
  digitalWrite(f12, 0);
  delay(500);


  digitalWrite(f21, 1);
  digitalWrite(f22, 0);
  delay(500);

  digitalWrite(f21, 0);
  digitalWrite(f22, 0);
  delay(500);

  digitalWrite(f21, 0);
  digitalWrite(f22, 1);
  delay(500);

  digitalWrite(f21, 0);
  digitalWrite(f22, 0);
  delay(500);



  digitalWrite(f31, 1);
  digitalWrite(f32, 0);
  delay(500);

  digitalWrite(f31, 0);
  digitalWrite(f32, 0);
  delay(500);

  digitalWrite(f31, 0);
  digitalWrite(f32, 1);
  delay(500);

  digitalWrite(f31, 0);
  digitalWrite(f32, 0);
  delay(500);




  digitalWrite(f41, 1);
  digitalWrite(f42, 0);
  delay(500);

  digitalWrite(f41, 0);
  digitalWrite(f42, 0);
  delay(500);

  digitalWrite(f41, 0);
  digitalWrite(f42, 1);
  delay(500);

  digitalWrite(f41, 0);
  digitalWrite(f42, 0);
  delay(500);


}
*/
