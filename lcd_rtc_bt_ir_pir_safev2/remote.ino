int remote()

{
  //irresult.value = 0x11D648B7;
  ir.resume();
  int  j ;
  delay(1000); 
  while(ir.decode(&irresult))
  {j=0;
    buzz();
    if (irresult.value == 0x61D650AF)
    {
      Serial.println(irresult.value);       j = 23;
pre=j;     
        Serial.print("FROM REMOTE "); Serial.println(j);  buzz();    return j;
    }
    else if (irresult.value == 0x61D648B7)
    {
      Serial.println(irresult.value);       j = 17;pre=j;

           Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D610EF)
    {
      Serial.println(irresult.value);       j = 18;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6F20D)
    {
      Serial.println(irresult.value);       j = 19;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D630CF)
    {
      Serial.println(irresult.value);       j = 20;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D69867)
    {
      Serial.println(irresult.value);       j = 21;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6A25D)
    {
      Serial.println(irresult.value);       j = 22;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D67887)
    {
      Serial.println(irresult.value);       j = 24;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D628D7)
    {
      Serial.println(irresult.value);       j = 1;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D69A65)
    {
      Serial.println(irresult.value);       j = 2;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6A857)
    {
      Serial.println(irresult.value);       j = 3;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6AA55)
    {
      Serial.println(irresult.value);       j = 4;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D618E7)
    {
      Serial.println(irresult.value);       j = 5;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D632CD)
    {
      Serial.println(irresult.value);       j = 6;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6728D)
    {
      Serial.println(irresult.value);       j = 7;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6D02F)
    {
      Serial.println(irresult.value);       j = 8;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6F00F)
    {
      Serial.println(irresult.value);       j = 9;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6708F)
    {
      Serial.println(irresult.value);       j = 10;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D612ED)
    {
      Serial.println(irresult.value);       j = 11;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6629D)
    {
      Serial.println(irresult.value);       j = 12;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6EA15)
    {
      Serial.println(irresult.value);       j = 13;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6DA25)
    {
      Serial.println(irresult.value);       j = 14;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D6906F)
    {
      Serial.println(irresult.value);       j = 15;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else if (irresult.value == 0x61D652AD)
    {
      Serial.println(irresult.value);       j = 16;pre=j;

        Serial.println(j);   buzz();    return j;
    }
    else
    {
         Serial.println(irresult.value,HEX);
//     Serial.println(irresult.value);       
j = 0;pre=j;
        Serial.println(j);   buzz();    return j;
    }
}
//while( ir.decode(&irresult));
//ir.resume();
}
