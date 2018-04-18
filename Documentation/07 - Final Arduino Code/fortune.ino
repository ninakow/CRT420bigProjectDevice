String fortune[] = {"Good things are coming your way!", "Watch out, you may lose it all to pride", "There's a special someone in your sight", "An old friend will betray you soon.", "Don't worry, it won't be that bad!"};
int fortuneTime = 5;


void showFortune() {
  if (!isFortune) {
    tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
    isFortune = true;
  }

  switch (fortuneMode) {
    case 0: fortuneInstructions(); break;
    case 1: fortuneCount(); break;
    case 2: fortuneResult(); break;
  }
}

void fortuneInstructions() {
    tft.setTextSize(2);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.setCursor(30, 30);
  tft.println("Fortune");
  tft.setCursor(40, 50);
  tft.println("Mode");
  tft.setTextSize(1);
  tft.setCursor(15, 70);
  tft.println("Place each thumb");
  tft.setCursor(15, 80);
  tft.println("on a sensor and ");
  tft.setCursor(15, 90);
  tft.println("let the fortune-");
  tft.setCursor(15, 100);
  tft.println("telling flamingo ");
  tft.setCursor(15, 110);
  tft.println("take it from here");
  delay(2000);
  fortuneMode = 1;
  tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
}

void fortuneCount() {
  tft.setCursor(40, 55);
  tft.setTextSize(8);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.print(fortuneTime);
  delay(1000);
  fortuneTime--;

  if (fortuneTime == 0) {
    fortuneMode = 2;
    fortuneTime = 5;
    tft.setTextSize(1);
    tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
  }
}

void fortuneResult() {
  if (!isResult) {
    tft.setCursor(15, 60);
    tft.setTextSize(1);
    tft.setTextColor(MAGENTA, WHITE);
    tft.setTextWrap(true);
    String feeling;
    int fortuneSense = getSensor();
    if (fortuneSense <= 625) {
      feeling = fortune[4];
       tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.println("Don't worry,");
  tft.setCursor(32, 80);
  tft.println("it won't be");
  tft.setCursor(37, 90);
  tft.println("that bad!");
    }
    else if (fortuneSense >= 626 && fortuneSense <= 650) {
      feeling = fortune[3];
       tft.setTextSize(1);
  tft.setCursor(15, 70);
  tft.println("An old friend");
  tft.setCursor(15, 80);
  tft.println("will betray you");
  tft.setCursor(15, 90);
  tft.println("soon.");
    }
    else if (fortuneSense >= 651 && fortuneSense <= 670) {
      feeling = fortune[2];
       tft.setTextSize(1);
  tft.setCursor(15, 70);
  tft.println("There's a special");
  tft.setCursor(15, 80);
  tft.println("someone in your");
  tft.setCursor(15, 90);
  tft.println("sight");
    }
    else if (fortuneSense >= 671 && fortuneSense <= 684) {
      feeling = fortune[1];
       tft.setTextSize(1);
  tft.setCursor(20, 70);
  tft.println("Watch out, you");
  tft.setCursor(15, 80);
  tft.println("may lose it all");
  tft.setCursor(38, 90);
  tft.println("to pride");
    }
    else if (fortuneSense >= 685) {
      feeling = fortune[0];
       tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.println("Good things");
  tft.setCursor(32, 80);
  tft.println("are coming");
  tft.setCursor(37, 90);
  tft.println("your way!");
    }

  //  tft.print(feeling);
    isResult = true;
    tft.setTextSize(1);
  }
}


