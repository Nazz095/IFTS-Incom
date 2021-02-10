const unsigned short MIN = 1;
const unsigned short MAX = 100;
const unsigned short QUANTITY = 10;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short numbers[QUANTITY];
  unsigned short sum = 0;
  Serial.print(QUANTITY);
  Serial.print(" numeri casuali: ");
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    numbers[i] = random(MIN, MAX+1);
    sum += numbers[i];
    
    if(i == QUANTITY-1){
      Serial.println(numbers[i]);
    }
    else{
      Serial.print(numbers[i]);
      Serial.print(", ");
    }
  }
  Serial.print("Media aritmetica: ");
  Serial.println((float)sum / QUANTITY);
  while(1);
}
