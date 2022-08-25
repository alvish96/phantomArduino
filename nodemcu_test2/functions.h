
//-----------------------------------
//functions executing client requests
//-----------------------------------
void handleRoot()
{
  server.send(200, "text/html", "<h1>ESP8266 Controller<br>Potentiometer: /pot<br>Button: /button<br>LED: /led</h1>");
}
//------------------------------------------------------------------------
void pot()
{
  String pot_val = String("Pot Value: ") + String(analogRead(0)) + "\n";
  pot_val = "<html><head><meta http-equiv=\"refresh\" content=\"2\"> <body bgcolor=\"#ffff00\">"
         + pot_val + "</body></html>";
  server.send(200, "text/html", pot_val);
}
//------------------------------------------------------------------------
void button()
{
  String button_val;
  if(digitalRead(D1)==LOW)
  {
    button_val = String("Button: ") + String("OFF") + "\n";
  }
  if(digitalRead(D1)==HIGH)
  {
    button_val = String("Button: ") + String("ON") + "\n";
  }
  button_val = "<html><head><meta http-equiv=\"refresh\" content=\"2\"> <body bgcolor=\"#add8e6\">"
                + button_val + "</body></html>";
  server.send(200, "text/html", button_val);
}
//------------------------------------------------------------------------
void led()
{
server.send(200, "text/html", "<p><a href=/led><button>Toggle LED</button></a></p><body bgcolor=\"#ffa500\">");
}