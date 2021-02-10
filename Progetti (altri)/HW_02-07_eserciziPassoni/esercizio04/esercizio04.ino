const unsigned short MIN = 1;
const unsigned short MAX = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short number = random(MIN, MAX+1);
  Serial.print("Numero generato: ");
  Serial.println(number);
  Serial.print("Numeri primi: ");
  unsigned short sum = 0;
  for(unsigned short i = 1; i < number; i++)
  {
    unsigned short count = 0;
    for(unsigned short j = 1; j <= i; j++)
    {
      if(i % j == 0) count++;
    }
    if(count == 2) 
    {
      sum += i;
      Serial.print(i);
      Serial.print(", ");
    }
  }
  Serial.print("\nSomma dei numeri primi < numero generato: ");
  Serial.println(sum);
  delay(5000);
}
