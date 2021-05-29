void test()
{
/*f1:( accel();     check();)
f2: movf();   check();
f3: movm();   check();
f4: movs();   check();
f5: kill(); check();

turn: deci();
 
}
void deci()
{
int n[2] = {0, 0};

one.write(180);
n[0] = meas();
one.write(20);
n[1] = meas();

if (n[0] > n[1] && n[0] > 20)
{
  go_left();
}
else if (n[0] < n[1] && n[1] > 20)
{
  go_right();
}
else 
{
  turn_around();
}
}
void go_left(){
  
}
void go_right(){
  
}
void turn_around(){
  
}

*/
void accel() {
  digitalWrite(forw, HIGH);
}
void movf() {
  analogWrite(forw, 200);
}
void movm() {
  analogWrite(forw, 100);
}
void movs() {
  analogWrite(forw, 20);
}
void decel() {
  int vel = 100;
  analogWrite(back, vel);
}
void kill() {
  digitalWrite(forw, LOW);
  digitalWrite(back, LOW);
}


/*
void check()
{
  float dis = meas();
  if (dist > 50) {
    goto x;
  }
  if (dis <= 50 && dis >= 40)  {
    goto f1;
  }
  if (dis <= 39 && dis >= 30) {
    goto f2;
  }
  if (dis <= 29 && dis >= 20) {
    goto f3;
  }
  if (dis <= 20 && dis >= 15) {
    goto f4;
  }
  if (dis <= 14 && dis >= 10) {
    goto f5;
  }
  if (dis <= 9 && dis >= 5) {
    goto turn;
  }
}
*/





