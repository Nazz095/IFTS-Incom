const unsigned short MIN = 1;
const unsigned short MAX = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short number = random(MIN, MAX+1);
  if (number % 3 == 0) 
  {
    Serial.print("\nNumero generato, divisibile per 3 è: ");
    Serial.println(number);
  }
  else 
  {
    Serial.print(number);
    Serial.print(", ");
  }
  delay(500);
}
