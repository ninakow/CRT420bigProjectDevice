String moods[] = {"Happy", "Jealous", "In Love", "Angry", "Nervous"};
int moodTime = 5;


void showMood() {
  if (!isMood) {
    tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
    isMood = true;
  }

  switch (moodMode) {
    case 0: moodInstructions(); break;
    case 1: moodCount(); break;
    case 2: moodResult(); break;
  }
}

void moodInstructions() {
  tft.setTextSize(2);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.setCursor(15, 40);
  tft.println("Mood Mode");
  tft.setTextSize(1);
  tft.setCursor(15, 60);
  tft.println("Place each thumb");
  tft.setCursor(15, 70);
  tft.println("on a sensor and ");
  tft.setCursor(15, 80);
  tft.println("let the fortune-");
  tft.setCursor(15, 90);
  tft.println("telling flamingo ");
  tft.setCursor(15, 100);
  tft.println("take it from here");
  delay(2000);
  moodMode = 1;
  tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
}

void moodCount() {
  tft.setCursor(40, 55);
  tft.setTextSize(8);
  tft.setTextColor(MAGENTA, WHITE);
  tft.setTextWrap(true);
  tft.print(moodTime);
  delay(1000);
  moodTime--;

  if (moodTime == 0) {
    moodMode = 2;
    moodTime = 5;
    tft.setTextSize(1);
    tft.drawBitmap(0, 0, mood, 128, 160, WHITE);
  }
}

void moodResult() {
  if (!isResult) {
    tft.setCursor(25, 65);
    tft.setTextSize(2);
    tft.setTextColor(MAGENTA, WHITE);
    tft.setTextWrap(true);
    String feeling;
    int moodSense = getSensor();
    if (moodSense <= 625) {
      feeling = moods[4];
    }
    else if (moodSense >= 626 && moodSense <= 650) {
      feeling = moods[3];
    }
    else if (moodSense >= 651 && moodSense <= 670) {
      feeling = moods[2];
    }
    else if (moodSense >= 671 && moodSense <= 684) {
      feeling = moods[1];
    }
    else if (moodSense >= 685) {
      feeling = moods[0];
    }

    tft.print(feeling);
    isResult = true;
    tft.setTextSize(1);
  }
}


