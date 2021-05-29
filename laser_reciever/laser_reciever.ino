// *** LaserCommunicator ***
// ***   Andrew Howden   ***
// ***     17/02/16      ***
// This program is designed to receive a laser signal through 5 photoresisters.

//-------------------------------------------initializing array-------------------------------------
  int ledArray [29][6] = {
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
    {'.',1,1,1,0,1},//new char
    {'/',1,1,1,1,1},//skip
    };

  /*****************ADJUSTABLE**********************/
  double cycleRate = 50;
  /*************************************************/
  int sensorInput[6]= {0,0,0,0,0,0};
  int sensorPins[6] = {0,1,2,3,4,5}; 

void setup(){
  //----------------------------------------------testing--------------------------------------------------
      
  Serial.begin(9600);
  Serial.print("---");Serial.print("Receiver is active");Serial.print("---");Serial.println();
  Serial.print("---");Serial.print("Establishing benchmark light sensitivity");Serial.print("---");Serial.println();
  //delay(1500);
  Serial.print("---");Serial.print("System test completed");Serial.print("---");Serial.println();Serial.println(); 
  //----------------------------Initializing complete, programm is now ready for transmissions-----------------------------  

}

  int threshold[6] = {70,70,70,70,70,70};
  int fire = 0;
  
void loop(){
  fire = 0;
  for(int i=1;i<6;i++){
   fire = fire + analogRead(sensorPins[i]);
  }
  
  if(fire > 150);{
  //set array "sensorInput" == to the active pins
  for(int i=1;i<6;i++){
     if (analogRead(sensorPins[i]) > threshold[i]){
      sensorInput[i] = 1;
     }else{
      sensorInput[i] = 0;
     }
  }
  
  
  //search for lettering based on active pins
  for(int i=0;i<29;i++){//vertical
    for(int j=1;j<6;j++){//horizontal
      if (ledArray[i][j] == sensorInput[j]){//testing each cell. failure breaks loop and moves to next row. success continues till looped 5 times and found a match.
        if(j == 5){
          if(ledArray[i][0]=='/'){//if handles the next line case
            Serial.println("");
          }else{
            Serial.print(char(ledArray[i][0]));//else for any letter
          }
          break;
        }
      }else{
        break;
      }
    }
  }
  delay(cycleRate);
  }

  delay(5);
}
