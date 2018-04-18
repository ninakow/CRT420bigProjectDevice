
void showAbout(){
  if (!isAbout){
    tft.drawBitmap(0, 0, about, 128, 160, WHITE);
    isAbout = true;
  }
  tft.setTextSize(1);
  tft.setCursor(0, 40);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.print("The myth of the fortune-telling flamingo began in a land far far away by the name of San Fran. One tuesday afternoon in the 60s, a flamingo at the local zoo met a young psychic and the rest is history");
}

