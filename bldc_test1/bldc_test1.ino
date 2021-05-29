#include <Servo.h>
Servo esc_signal;
Servo esc_signal1;
int i=0;
int spd=100;
int initi =40;
#define pin 9
#define pin1 10 
void setup()
{

  
Serial.begin(9600);
  esc_signal1.attach(pin1); 
  esc_signal.attach(pin);  //Specify here the pin number on which the signal pin of ESC is connected.
Serial.print("attached to pin 9");
Serial.println();
  esc_signal1.write(initi);
  esc_signal.write(initi);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  Serial.print("speed initiated 30"); 
Serial.println();
Serial.print("introducing delay 3secs"); 
Serial.println();
  delay(3000);            //ESC initialization delay.
Serial.print("exiting setup"); 
Serial.println();

}

void loop()

{
  /*
Serial.print(i); 
Serial.println();  
//delay(00);
i++;



esc_signal.write(spd);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
delay(100);
esc_signal.write(initi);
*/
test2(100);
//test2(15);
eop();
}
void eop(){
  
  
  Serial.print("ending program"); Serial.println();
  delay(2000);exit(0);
}
void test1(int x)
{Serial.print("motor 1"); Serial.println();//Serial.println(); Serial.println();  Serial.println(); Serial.println();    
delay(1000);  int is=x; int ma=250,mi=40,d=5;
for (int i=mi;i<=ma;i+=d)
{
esc_signal.write(i);
if(i%10==0)
{Serial.print(i); Serial.println();  
} delay(is);
}
  Serial.print("max speed"); Serial.println();  
delay(1000);
for (int j=ma;j>=mi;j-=d)
{
esc_signal.write(j);
if(j%10==0)
{Serial.print(j); Serial.println();  
}//Serial.print(j); Serial.println();  
  delay(is);
}
  Serial.print("termination"); Serial.println();  
delay(1000);
}



void test2(int x)
{Serial.print("motor 2"); Serial.println();//Serial.println(); Serial.println();  Serial.println(); Serial.println();    
 delay(1000); int is=x;
for (int i=50;i<=255;i++)
{
esc_signal1.write(i);
if(i%10==0)
{Serial.print(i); Serial.println();  
}
//Serial.print(i); Serial.println();  
  delay(is);
}
  Serial.print("max speed"); Serial.println();  delay(1000);
for (int j=255;j>=50;j--)
{
esc_signal1.write(j);
if(j%10==0)
{Serial.print(j); Serial.println();  
}//Serial.print(j); Serial.println();  
  delay(is);
}
  Serial.print("termination"); Serial.println();delay(1000);  
}

