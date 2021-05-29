
#define ENA_m1 11        // Enable/speed motor Front Right  
#define IN_11  9        // L298N #1 in 1 motor Front Right   
#define IN_12  8        // L298N #1 in 2 motor Front Right


#define ENB_m1 6         // Enable/speed motor Back Right   
#define IN_13  3       // L298N #1 in 3 motor Back Right
#define IN_14  2        // L298N #1 in 4 motor Back Right

#define ENA_m2 5       // Enable/speed motor Front Left    
#define IN_21  4         // L298N #2 in 1 motor Front Left
#define IN_22  7        // L298N #2 in 2 motor Front Left

#define ENB_m2 10      // Enable/speed motor Back Left      
#define IN_23  12      // L298N #2 in 3 motor Back Left
#define IN_24  13      // L298N #2 in 4 motor Back 

void setup()
{
  pinMode(ENA_m1, OUTPUT);
  pinMode(ENB_m1, OUTPUT);
  pinMode(ENA_m2, OUTPUT);
  pinMode(ENB_m2, OUTPUT);

  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);
  pinMode(IN_14, OUTPUT);

  pinMode(IN_21, OUTPUT);
  pinMode(IN_22, OUTPUT);
  pinMode(IN_23, OUTPUT);
  pinMode(IN_24, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
//  check();
}

void check()
{
  digitalWrite(ENB_m2, 1);
  digitalWrite(IN_23, HIGH);
  digitalWrite(IN_24, LOW);
  Serial.println("forw");

}
