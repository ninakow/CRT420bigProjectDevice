void showHelp(){
  if (!isHelp){
    tft.drawBitmap(0, 0, about, 128, 160, WHITE);
    isHelp = true;
  }
  tft.setTextSize(1);
  tft.setCursor(0, 40);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.print("Need help? It's easy! Just place each thumb on one of the sensors found above each handle. Then, depending on if you are in fortune mode or mood mode the fortune-telling flamingo will reveal the relevant information to you.");
}

