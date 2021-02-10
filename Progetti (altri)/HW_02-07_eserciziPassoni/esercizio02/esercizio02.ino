const unsigned short MIN = 1;
const unsigned short MAX = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short first_num = random(MIN, MAX+1);
  Serial.print("\nIl primo numero è: ");
  Serial.println(first_num);
  
  unsigned short second_num = random(MIN, MAX+1);
  Serial.print("Il secondo numero è: ");
  Serial.println(second_num);
  
  Serial.print("Il più grande dei due è: ");
  if(first_num > second_num) Serial.println(first_num);
  else Serial.println(second_num);
  
  delay(5000);
}
