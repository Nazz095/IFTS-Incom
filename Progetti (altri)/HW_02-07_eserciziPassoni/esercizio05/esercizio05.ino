const unsigned short MIN = 1;
const unsigned short MAX = 100;
unsigned short count = 1;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short random_num = random(MIN, MAX+1);
    Serial.print("Numero generato: ");
    Serial.println(random_num);
    count++;
  if (random_num == 47)
  {
    Serial.print("Sono stati generati ");
    Serial.print(count);
    Serial.println(" numeri.");
    while(true);
  }
}
