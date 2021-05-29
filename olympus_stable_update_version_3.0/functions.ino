
void buzz(int n) //v
{
  if (mute == 0)
  {
    int del = 10;
    digitalWrite(buz, LOW);
    for (int i = 0; i < n; i++)
    {
      digitalWrite(buz, HIGH);
      delay(del);
      digitalWrite(buz, LOW);
      delay(del + 60);
    } digitalWrite(buz, LOW);
  }
}



void mutesw()//v
{
  mute = !mute;
}


void RESW() {}
//--

void deftype()  //v
{
  for (int i = 1; i < 5; i++)
  {
    
    mod[i].definetype(1);
  
  }
  for (int i = 5; i < 12; i++)
    mod[i].definetype(0);
}

void setinitial() //v
{
  for (int i = 1; i < 12; i++)
    mod[i].SWoff();
}

void initialise()  //v
{
  for (int i = 0; i < 12; i++)
    mod[i].initialise();
}

//--
