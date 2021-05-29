double dist=0;      //distance from the platform to the launch pad 
double v0=0;      // initial velocity of the projectile 
double g=9.81;     //acceleration due to gravity
double h0=0;      //initial height of launch
void setup() {
}

void loop() {
}
double al=xlen();  //actual distacne to the target 
double xl=0;     //coordinate distance x calculated by the previous 
double pd=dist+xl;     //perpendicular distance bwn platform and launchpad 
double y=0;     // coordinate distance y calculated 
double m=0;   // desired distance 
float t1=angle1();     //launch angle
float t2=angle2();     //alternate calculation for launch angle 
//float t3=angle3();


double xlen()     //calculates actual distance to the target
{
  double brac=((pd*pd)+(y*y));
double x=sqrt(brac);
return x;
return brac;
}

double maxdist()   //calc maximum range of the projectile 
{
  double l=((v0*v0)/g);
return l;
}

double range(double h0)    //range of projectile from launch height h0
{
  if(h0==0)   //if height is 0
  {
    double l=(((v0*v0)*sin(2*t1))/g);
    return l;
  }
  else {
  double u=sin(t1);
  double a=((2*g*h0)/((v0*v0)*(u*u)));
  double x=(1+a);
  double brac=(1+sqrt(x));
  double l=(((v0*v0)*brac*sin(2*t1))/(2*g));
  return l;
}
}



double tau()    //time of flight of the projectile
{
  double l=xlen();
  double t=(l/(v0*cos(t1)));
  return t;

  /*  if y0=0;   t=(2*v0*sin(t1))/g; 
   *   if t1=45;  t=(v0*sqrt(2)/g);
   * 
   * actual formula t=(((v0*sin(t1)+sqrt(((v0*sin(t1))*(v0*sin(t1)))+(2*g*h0))))/g);
*/
}

float angle1()    //launch angle calc
{
  double l=xlen();
  double x=((g*l)/(v0*v0));
float t=(asin(x)/2);
 return t;
}

double height(double m)   //height of projectile at distance m
{
  double q=(v0*cos(t1));
  double p=((g*(m*m))/(2*(q*q)));
  double h=(h0+(m*tan(t1))-p);
return h;
}
double vel(double m)   //velocity of projectile at distance m
{
  double u=((g*(m*m))/(v0*cos(t1)));
  double x=(u*u);
  double a= ((v0*v0)-(2*g*m*tan(t1))+(x*x));
  double v=sqrt(a);
  return v;
}

double angle2() //angle theta req to hit (lenght,height)coordinates 
{
  double l=xlen();
  double m=(v0*v0);
  double x=((m*m)-(g*((g*l*l)+(2*h0*m))));
  double brac=(m+sqrt(x));
float t=atan(brac/(g*l));
return t;  
}













