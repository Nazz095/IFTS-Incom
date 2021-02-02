void setup() {
  pinMode(12,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  if(!digitalRead(12))
  {
    digitalWrite(13,HIGH);
    delay(5000);
  }
  else
    digitalWrite(13,LOW);
}
