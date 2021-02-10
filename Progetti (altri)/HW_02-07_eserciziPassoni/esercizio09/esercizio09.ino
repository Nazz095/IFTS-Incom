const unsigned short MIN = 1;
const unsigned short MAX = 100;
const unsigned short QUANTITY = 10;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  unsigned short numbers[QUANTITY];

  Serial.print("Numeri casuali: ");
  for(unsigned short i = 0; i < QUANTITY; i++)
  {
    numbers[i] = random(MIN, MAX+1);
    if (i == QUANTITY-1)
    {
      Serial.println(numbers[i]);
    }
    else
    {
      Serial.print(numbers[i]);
      Serial.print(", ");
    }
  }

  Serial.print("In ordine inverso: ");
  for(unsigned short i = QUANTITY-1; i >= 0; i--)
  {
    if (!i)
    {
      Serial.println(numbers[i]);
      break;
    }
    else
    {
      Serial.print(numbers[i]);
      Serial.print(", ");
    }
  }
  while(1);
}
