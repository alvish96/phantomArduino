
void seg()
{
  dis(COUNT);

  if (COUNT < 10)
  {
    COUNT++;
    delay(1000);///increment count integer for every second
  }
  if (COUNT == 10)
  {
    COUNT = 0; // if count integer value is equal to 10, reset it to zero.
    delay(1000);
  }
}



void dis(int num)
{
  if (segm)
    switch (num)
    {
      case 0://when count value is zero show”0” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 0);
        digitalWrite(segF, 0);
        digitalWrite(segG, 1);
        break;
      case 1:// when count value is 1 show”1” on disp
        digitalWrite(segA, 1);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 1);
        digitalWrite(segE, 1);
        digitalWrite(segF, 1);
        digitalWrite(segG, 1);
        break;
      case 2:// when count value is 2 show”2” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 1);
        digitalWrite(segD, 0);
        digitalWrite(segE, 0);
        digitalWrite(segF, 1);
        digitalWrite(segG, 0);
        break;
      case 3:// when count value is 3 show”3” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 1);
        digitalWrite(segF, 1);
        digitalWrite(segG, 0);
        break;
      case 4:// when count value is 4 show”4” on disp
        digitalWrite(segA, 1);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 1);
        digitalWrite(segE, 1);
        digitalWrite(segF, 0);
        digitalWrite(segG, 0);
        break;
      case 5:// when count value is 5 show”5” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 1);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 1);
        digitalWrite(segF, 0);
        digitalWrite(segG, 0);
        break;
      case 6:// when count value is 6 show”6” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 1);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 0);
        digitalWrite(segF, 0);
        digitalWrite(segG, 0);
        break;
      case 7:// when count value is 7 show”7” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 1);
        digitalWrite(segE, 1);
        digitalWrite(segF, 1);
        digitalWrite(segG, 1);
        break;
      case 8:// when count value is 8 show”8” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 0);
        digitalWrite(segF, 0);
        digitalWrite(segG, 0);
        break;
      case 9:// when count value is 9 show”9” on disp
        digitalWrite(segA, 0);
        digitalWrite(segB, 0);
        digitalWrite(segC, 0);
        digitalWrite(segD, 0);
        digitalWrite(segE, 1);
        digitalWrite(segF, 0);
        digitalWrite(segG, 0);
        break;
      default:
        digitalWrite(segA, 1);
        digitalWrite(segB, 1);
        digitalWrite(segC, 1);
        digitalWrite(segD, 1);
        digitalWrite(segE, 1);
        digitalWrite(segF, 1);
        digitalWrite(segG, 1);
        break;
    }
  else if (segm == 0)
  {
    digitalWrite(segA, 1);
    digitalWrite(segB, 1);
    digitalWrite(segC, 1);
    digitalWrite(segD, 1);
    digitalWrite(segE, 1);
    digitalWrite(segF, 1);
    digitalWrite(segG, 1);
  }

}
