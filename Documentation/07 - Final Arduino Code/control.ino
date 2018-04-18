

int currentMode(){
  currentPos1 = digitalRead(pos1);
  currentPos2 = digitalRead(pos2);
  currentPos3 = digitalRead(pos3);
  currentPos4 = digitalRead(pos4);

  if (currentPos1 == 1){return 1;}
  else if (currentPos2 == 1){return 2;}
  else if (currentPos3 == 1) {return 3;}
  else if (currentPos4 == 1) {return 4;}
}

