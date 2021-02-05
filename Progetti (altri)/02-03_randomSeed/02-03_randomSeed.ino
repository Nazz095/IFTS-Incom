const int VOTO_SUF = 18;
const int VOTO_MAX = 32;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int voto = random(VOTO_SUF, VOTO_MAX);
  if(voto == 31) Serial.println(F("LODE!!!"));
  else Serial.println(voto);
  delay(1000);
}
