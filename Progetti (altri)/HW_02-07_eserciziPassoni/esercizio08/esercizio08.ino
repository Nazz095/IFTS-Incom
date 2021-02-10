const unsigned short MIN = 1;
const unsigned short MAX = 100;
const unsigned short QUANTITY = 10;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short max_num = 0;
  unsigned short random_num;
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    random_num = random(MIN, MAX+1);
    Serial.print("Il ");
    Serial.print(i+1);
    Serial.print("° numero: ");
    Serial.println(random_num);
    if (random_num > max_num) max_num = random_num;
  }
  Serial.print("Il numero maggiore è: ");
  Serial.println(max_num);
  while(1);
}
