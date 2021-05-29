/*int p1 = random(0, 100);
int p2 = random(0, 100);
int p3 = random(0, 100);
void loop() {
  // Clear the buffer.
  display.clearDisplay();
  drawPercentbar( 0, 0, 50, 10, p1);
  drawPercentbar( 0, 20, 100, 15, p2);
  drawPercentbar( 0, 40, 128, 20, p3);
  display.display();
  p1++; p2++; p3++;
  if ( p1 > 100) p1 = 0;
  if ( p2 > 100) p2 = 0;
  if ( p3 > 100) p3 = 0;
  delay(100);
}
void drawPercentbar(int x, int y, int width, int height, int progress)
{
  progress = progress > 100 ? 100 : progress;
  progress = progress < 0 ? 0 : progress;
  float bar = ((float)(width - 4) / 100) * progress;
  display.drawRect(x, y, width, height, WHITE);
  display.fillRect(x + 2, y + 2, bar , height - 4, WHITE);
  // Display progress text
  if ( height >= 15) {
    display.setCursor((width / 2) - 3, y + 5 );
    display.setTextSize(1);
    display.setTextColor(WHITE);
    if ( progress >= 50)
      display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.print(progress);
    display.print("%");
  }
}
*/
