const unsigned short MIN = 1;
const unsigned short MAX = 10;
const unsigned short QUANTITY = 10;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short numbers[QUANTITY] = {0}, random_num, count;
  //unsigned short trash[100] = {0}, t = 0;
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    random_num = random(MIN, MAX+1);
    //trash[t] = random_num;
    //t++;
    count = 0;
    for(unsigned short j = 0; j < i; j++)
    {
      if (random_num == numbers[j]) count++;
    }
    if (!count) numbers[i] = random_num;
    else i = i - 1;
  }
  Serial.print("Numeri casuali: ");
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    if(i == QUANTITY-1) Serial.println(numbers[i]);
    else{
      Serial.print(numbers[i]);
      Serial.print(", ");
    }
  }
  /*
  Serial.print("Numeri generati: ");
  for(unsigned short i = 0; i < 100; i++)
  {
    if(!trash[i]) 
    {
      Serial.println();
      break;
    }
    else{
      Serial.print(trash[i]);
      Serial.print(", ");
    }
  }*/
  while(1);
}
