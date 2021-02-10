const unsigned short MIN = 1;
const unsigned short MAX = 100;
const unsigned short QUANTITY = 1000;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short count = 0;
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    if(random(MIN, MAX+1) % 2 == 0)
    {
      count++;
    }
  }
  Serial.print("In totale ");
  Serial.print(count);
  Serial.println(" numeri pari generati");
  while(1);
}
