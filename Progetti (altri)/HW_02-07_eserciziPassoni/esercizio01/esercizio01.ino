const unsigned short MIN = 1;
const unsigned short MAX = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short first_num = random(MIN, MAX+1);
  Serial.print("\nPrimo numero generato: ");
  Serial.println(first_num);
  unsigned short second_num = random(MIN, MAX+1);
  Serial.print("Secondo numero generato: ");
  Serial.println(second_num);
  unsigned short sum = first_num + second_num;
  Serial.print("La loro somma è: ");
  Serial.println(sum);
  delay(5000);
}
