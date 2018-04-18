int sensorPin = 2;
int getSensor(){
  int raw = analogRead(sensorPin);
  Serial.println(raw);
  return raw;
}

