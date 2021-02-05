const int MIN = 20;
const int MAX = 50;
int value;


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

}

void loop() {
  Serial.print(F("\nInizio countdown a partire da "));
  value = random(MIN, MAX);
  Serial.println(value);
  int column = 0; 
  for(int i = value; i >= 0; i--)
  {
    if(column == 10)
    {
      Serial.println(i);
      column = 0;
    }
    else
    {
      Serial.print(i);
      Serial.print(F("\t"));
      column++;
    }
  }
  Serial.println(F("\nFine countdown"));
  delay(20000);
}
