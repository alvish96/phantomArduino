/*
    NAME: ScreenSaver Mouse Jiggler
    DATE: 2016-10-20
    DESC: Arduino based mouse emulator, preventing computer screen-saver from
        kicking in and locking desktop (eg. during forensic investigation).
    AUTHOR: nshadov
    VERSION: 1.0
*/


#include <Mouse.h>

// This is runned once, during device initialization

void setup()
{
  Mouse.begin();
}



/// Main loop - move mouse back and forth every 5 seconds

void loop()
{
  delay(2000);

  while (true)
  {
    fn();
    delay(5000);
  }
}

void fn()
{ int dl = 500;
  Mouse.move(100, 0 , 0);
  delay(dl);
  Mouse.move(0, 100 , 0);
  delay(dl);
  Mouse.move(-100, 0 , 0);
  delay(dl);
  Mouse.move(0, -100 , 0);
  delay(dl);

}


/*    Mouse.move(4, 0, 0);
    delay(100);
    Mouse.move(-8, 0, 0);
    delay(100);
    Mouse.move(4, 0, 0);

    delay(1000);
    
    */
