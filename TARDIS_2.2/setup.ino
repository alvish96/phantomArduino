
void setup()
{
  //-----------------------
  Serial.begin(115200);
  Serial1.begin(115200);
  //-----------------------
  rtc.begin();
  ir.enableIRIn();
  //-----------------------
  pinMode(ledvcc, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  analogWrite(r, maxx);
  analogWrite(g, maxx);
  analogWrite(b, maxx);
  digitalWrite(ledvcc, 1);
  //-----------------------

  pinMode(pinCS, OUTPUT);
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    //    return;
  }
  //------------------
  
    Serial.println("SETUP COMPLETE ");
//  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
//  //display.display();
//  display.clearDisplay();
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.clearDisplay();
  //--------------------
  
    Serial.println("SETUP COMPLETE ");
  for (int i = 22; i < 29; i++)
  {
    pinMode(i, OUTPUT);// taking all pins from 2-8 as output
    digitalWrite(i, 1 ); // taking all pins from 2-8 as output
  }

  //initial conditions----------------
  
    Serial.println("SETUP COMPLETE ");
  segm = 0;
  //COMM-----------------------------------------
  b1 = 0;
  MSL = 0;
  MSEG = 0;
  reqTMD(1);  //TMD SET 1
  //  rx();

  RDP = 1; //rx debug print
  RP = 1; //RX PRINT

  oled = 0;
  databool0[22]=0;
  
    Serial.println("SETUP COMPLETE ");
}
