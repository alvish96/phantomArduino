// *** LaserCommunicator ***
// ***   Andrew Howden   ***
// ***     17/02/16      ***
// This program is designed to activate an array of 5 induvidual lasers in order to communicate to a receiver arduino

//-------------------------------------------initializing array-------------------------------------
  int ledArray [28][6] = {
    {'a',0,0,0,0,1},//a
    {'b',0,0,0,1,0},//b
    {'c',0,0,0,1,1},//c
    {'d',0,0,1,0,0},//d
    {'e',0,0,1,0,1},//e
    {'f',0,0,1,1,0},//f
    {'g',0,0,1,1,1},//g
    {'h',0,1,0,0,0},//h
    {'i',0,1,0,0,1},//i
    {'j',0,1,0,1,0},//j
    {'k',0,1,1,0,0},//k
    {'l',0,1,1,0,1},//l
    {'m',0,1,1,1,0},//m
    {'n',0,1,1,1,1},//n
    {'o',1,0,0,0,0},//o
    {'p',1,0,0,0,1},//p
    {'q',1,0,0,1,0},//q
    {'r',1,0,0,1,1},//r
    {'s',1,0,1,0,0},//s
    {'t',1,0,1,0,1},//t
    {'u',1,0,1,1,0},//u
    {'v',1,0,1,1,1},//v
    {'w',1,1,0,0,0},//w
    {'x',1,1,0,0,1},//x
    {'y',1,1,0,1,0},//y
    {'z',1,1,0,1,1},//z
    {' ',1,1,1,0,0},//space
    };
  double ledRate = 50;
  int lightUp[6]= {0,0,0,0,0,0};


void setup(){
  //----------------------------------------------testing--------------------------------------------------
      
  Serial.begin(9600);
  Serial.print("---");Serial.print("Transmitter is active");Serial.print("---");Serial.println();

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
/*
  for(int i=0;i <= 26; i++){
    for(int j=1;j < 6; j++){
      lightUp[j]= ledArray[i][j];
        if (j == 5){
          if( lightUp[1] == 1){digitalWrite(8, HIGH);}else{digitalWrite(8, LOW);}
          if(lightUp[2] == 1){digitalWrite(9, HIGH);}else{digitalWrite(9, LOW);}
          if(lightUp[3] == 1){digitalWrite(10, HIGH);}else{digitalWrite(10, LOW);}
          if(lightUp[4] == 1){digitalWrite(11, HIGH);}else{digitalWrite(11, LOW);}
          if(lightUp[5] == 1){digitalWrite(12, HIGH);}else{digitalWrite(12, LOW);}
          delay(ledRate);
         }
    }    
  }
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  ledRate = 150;*/
  Serial.print("---");Serial.print("System test completed");Serial.print("---");Serial.println();Serial.println();
  
  //----------------------------Initializing complete, programm is now ready for transmissions-----------------------------  
}


void loop() 
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
  Serial.print("Waiting for message now:");Serial.println();
  while(Serial.available()==0){}
  String message = Serial.readString();
  Serial.print("Transmitting now:");Serial.println();Serial.println();
  //Message Breakdown
  int messageSize=message.length()-1;
  char messageBreakdown[100];
  for (int i=0;i<=messageSize;i++)
    {
      messageBreakdown[i]=message[i];
      Serial.print(messageBreakdown[i]);Serial.print(" ");      
      for(int j=0;j <= 26; j++){  
        if (messageBreakdown[i] == ledArray[j][0]){
          for(int k = 1;k<6;k++){
            lightUp[k]= ledArray[j][k];
            if (k == 5){
              if(lightUp[1] == 1){digitalWrite(8, HIGH);}else{digitalWrite(8, LOW);}
              if(lightUp[2] == 1){digitalWrite(9, HIGH);}else{digitalWrite(9, LOW);}
              if(lightUp[3] == 1){digitalWrite(10, HIGH);}else{digitalWrite(10, LOW);}
              if(lightUp[4] == 1){digitalWrite(11, HIGH);}else{digitalWrite(11, LOW);}
              if(lightUp[5] == 1){digitalWrite(12, HIGH);}else{digitalWrite(12, LOW);}
              delay(50);
            }  
          }
          break; 
        } 
      }  
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          digitalWrite(10, LOW);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          delay(50);    
    }
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(ledRate);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    
    Serial.println();Serial.println();
   //Compare message to database of characters*/
}
