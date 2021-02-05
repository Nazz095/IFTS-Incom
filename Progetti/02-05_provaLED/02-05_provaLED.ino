void setup() {
  pinMode(9,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println (digitalRead(9));
  delay(1000);
  digitalWrite(9,HIGH);
  Serial.println (digitalRead(9));
}
