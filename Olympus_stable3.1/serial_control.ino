
void serialcontrol()
{
  switch (concode)
  {
    case 1: mod[1].SW(); break;
    case 2: mod[2].SW(); break;
    case 3: mod[3].SW(); break;
    case 4: mod[4].SW(); break;
    case 5: mod[5].SW(); break;
    case 6: mod[6].SW(); break;
    case 7: mod[7].SW(); break;
    case 8: mod[8].SW(); break;
    case 9: mod[9].SW(); break;
    case 10: mod[10].SW(); break;
    case 11: mod[11].SW(); break;
    case 12: break;
    case 13: break;
    case 14: break;
    case 15: break;
    default: tune(10);
  }
  delay(200);
}
