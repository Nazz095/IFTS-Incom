const unsigned short MIN = 1;
const unsigned short MAX = 10;
const unsigned QUANTITY = 1000;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short random_num, count[10] = {0}, sum = 0;
  Serial.println();
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    random_num = random(MIN, MAX+1);
    count[random_num-1]++;
  }
  for(unsigned short i = 0; i < 10; i++)
  {
    Serial.print("Numero ");
    Serial.print(i+1);
    Serial.print(" è stato ripetuto ");
    Serial.print(count[i]);
    Serial.println(" volte");
    sum += count[i];
  }
  Serial.print("Su un totale di ");
  Serial.print(sum);
  Serial.println(" numeri");
  while(1);
}
