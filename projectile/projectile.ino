 double g=9.80000000525251;
 double v,y0,d;
 float a; 
/* g is acceleration due to gracity 
 *  v0 is intial velocity
 *  y0 is inital height or launch height  
 *  d  is the distance travelled 
 *  a is theta or launch angle 
 */



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

double distance()  //total horizontal distance travelled 
{
    double a1=sin(a);
    double a2=cos(a);
 double x2 = v*a1;
double x3=v*a2;
  double x1= ((x2*x2)+(2*g*y0));
  double root = sqrt(x1);
double brac1=(x2+root);
  double dist=((x3*brac1)/g);
  return dist;
}


double flatdistance() // distance of travel when initial launch height is 0
{
float x4=2*a;
double fdist=((v*v)*(sin(x4)))/g;
return fdist;
}

double maxdistance() //max range of the projectile 
{
double  maxdist=((v*v)/g);
return maxdist;
}


double flighttime() //total flight time of the projectile 
{
double dist1=distance();
  double x5=(v*cos(a));
   double t1= (dist1/x5);
   return t1;
}

double flattime() //total time if initial launch height is 0
{
  double t2= ((2*v*sin(a))/g);
return t2;
}

double maxtime()  //max time of flight of projectile when theta is 45
{
  double s=sqrt(2);
  double t3=((s*v)/g);
}


float angle() // calculates angle of launch depending on distance 
{
 // double brac2 = (g*)
}

