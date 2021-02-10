const unsigned short MIN = 1;
const unsigned short MAX = 100;

void setup() { 
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short random_num = random(MIN, MAX+1);
  Serial.print("Numero generato: ");
  Serial.println(random_num);
  for(unsigned short i = MIN; i < random_num; i++)
  {
    if(i % 2 == 0){
      Serial.print("Numero pari < numero generato: ");
      Serial.println(i);
    }
  }
  while(1);
}
