#include <IRremote.h>

int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);

decode_results results;

int i = 0;
const int iter = 100;

unsigned long irset[iter];
unsigned long Set[iter];
int setcount[iter];
int count[iter] = {0};
int ax[iter];
//unsigned long irset[iter];
unsigned long element[iter];

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the receiver
  Serial.println("Enabled IRin");
}

void loop()
{
  //  for
  /*
    record1();
    delay(1000);
    verify2();
    delay(1000);
    pri();
    delay(3000);
  */

  record1();
  delay(1000);
  sort();
  delay(1000);
  printsort();
  resetvals();
  delay(3000);
}

void record()
{
  for (int i = 0; i < iter; i++)
  {
    while (irrecv.decode(&results))
    {
      if (i < iter)
      {
        irset[i] = results.value;
        Serial.println(results.value, HEX);
        irrecv.resume();
        delay(100);
      }
    }
  }
}

void record1()
{
  Serial.println(" starting record function  ");
  int t = 0;
  while (t < iter)
  {
    if (irrecv.decode(&results))
    {
      irset[t] = results.value;
      Serial.println(results.value, HEX);
      irrecv.resume(); // Receive the next value
      //      count[t]++;
      t++;
    }
    delay(250);
  }
  Serial.println(" ending record function  ");
}


void verify()
{
  Serial.println(" starting verification function  ");
  int c = 0;
  for (int j = 0; j < iter; j++)
  {
    unsigned long testval = irset[j];

    for (int i = 0; i < iter; i++)
    {
      if (irset[i] == testval)
        c++;
    }
    count[j] = c;
    c = 0;
  }
  Serial.println(" ending verification function  ");
}
//------------------------------------------------------------------
void verify1()
{
  Serial.println(" starting verification function  ");
  int c = 0, a = 0;
  for (int j = 0; j < iter; j++)
  {
    unsigned long testval = irset[j];

    for (int i = 0; i < iter; i++)
    {
      if (irset[i] == testval)
      {
        ax[c] = i;
        c++;
      }
    }
    count[j] = c;
    a = 0;
w:   if (Set[a] == testval)
      goto x;
    else
    {
      Set[a] = testval;
      Serial.print(" ");
      Serial.print(Set[a]);
      Serial.print(" ");


      setcount[a] = c;
      Serial.print(" ");
      Serial.print(setcount[a]);
      Serial.print("-----");

      for (int x = 0; x < c ; x++)
      {
        Serial.print(ax[x]);
        Serial.print(" ");
      }
      Serial.println();
      goto y;
    }
x:
    a++;
    goto w;
y:
    c = 0;
  }
  Serial.println(" ending verification function  ");
}



// ------------------------------------------------------------------ -

//------------------------------------------------------------------
void verify2()
{
  Serial.println(" starting verification function  ");
  int c = 0, a = 0;
  for (int j = 0; j < iter; j++)
  {
    unsigned long testval = irset[j];

    for (int i = 0; i < iter; i++)
    {
      if (irset[i] == testval)
      {
        ax[c] = i;
        c++;
      }
    }
    count[j] = c;

w:   if (Set[a] == testval)
      goto x;
    else
    {
      Set[a] = testval;
      Serial.print(" ");
      Serial.print(Set[a], HEX);
      Serial.print(" ");

      setcount[a] = c;
      Serial.print(" ");
      Serial.print(setcount[a]);
      Serial.print("-----");

      //      for (int x = 0; x < c ; x++)
      //      {
      //        Serial.print(ax[x]);
      //        Serial.print(" ");
      //      }
      Serial.println();
      goto y;
      //
    }
x:
    a++;
    goto w;
y:
    c = 0;
  }
  Serial.println(" ending verification function  ");
}



// ------------------------------------------------------------------ -

void sort()
{

  for (int j = 0; j < iter; j++)
  {
    unsigned long testval = irset[j];

    for (int i = 0; i < iter; i++)
    {
      if (testval == element[i])
      {
        count[i]++;
        break;
      }
      else if (testval != element[i])
      {
        if (element[i] == 0)
        { element[i] = testval;
          count[i]++;
          break;
        }
      }
    }
  }
}
void printsort()
{
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.println(" PRINTING RECORDED VALUES");
  for (int i = 0; i < iter; i++)
  {
    Serial.print(" ");
    Serial.print(i);
    Serial.print(" ");
    Serial.print(irset[i]);
    Serial.print(" ");
    Serial.print(count[i]);
    Serial.println();
  }
  Serial.println();
  Serial.println();
  Serial.println(" PRINTING STATISTIC VALUES");
  Serial.println();
  Serial.println();
  for (int i = 0; i < iter; i++)
  { if (element[i] != 0)
    {
      Serial.print(" ");
      Serial.print(element[i]);
      Serial.print(" ");
      Serial.print(count[i]);
      Serial.println();
    }
  }
  //  resetvals();
  Serial.println();
  Serial.println();
  Serial.println();
}
void resetvals()
{ Serial.println();
  Serial.println();
  Serial.println(" CLEARING ALL VALUES");
  Serial.println();
  Serial.println();
  for (int i = 0; i < iter; i++)
  {
    irset[i] = 0;
    Set[i] = 0;
    setcount[i] = 0;
    count[i] = 0;
    ax[i] = 0;
    element[i] = 0;
  }
}
void pri()
{ Serial.println();
  Serial.println();
  Serial.println();

  for (int i = 0; i < iter; i++)
  {
    Serial.print(" ");
    Serial.print(i);
    Serial.print(" ");
    Serial.print(irset[i], HEX);
    Serial.print(" ");
    Serial.print(count[i]);
    Serial.println();
  }

  //    for (int z = 0; z < iter ; z++)
  //    {
  //      Serial.print(Set[z],HEX);
  //      Serial.print(" ");
  //      Serial.print(setcount[z]);
  //      Serial.print(" ");
  //
  //    Serial.println();
  //    }
}
