int schiacciato = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  if(!digitalRead(9))
  {
    delay(500);
    digitalWrite(13,HIGH);
    delay(1000);
  }
  else if(!digitalRead(11) && !schiacciato)
  {
    Serial.println("Schiacciato tasto al pin 11");
    schiacciato = 1;
    delay(100);
  }
  else if(digitalRead(11))
  {
    schiacciato = 0;
    digitalWrite(13,LOW);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}
