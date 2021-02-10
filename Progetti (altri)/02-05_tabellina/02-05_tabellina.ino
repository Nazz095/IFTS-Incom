const byte minimo = 1;
const byte massimo = 10;

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  if(
  unsigned short numero = random(minimo, massimo+1);
  Serial.print("\n\nNumero generato: ");
  Serial.println(numero);
  Serial.println("Tabellina: ");
  for (unsigned short i = 0; i < 11; i++)
  {
    Serial.print(numero);
    Serial.print("x");
    Serial.print(i);
    Serial.print("=");
    Serial.print(numero*i);
    Serial.print("\t");
    delay(200);
  }
  delay(20000);
}
