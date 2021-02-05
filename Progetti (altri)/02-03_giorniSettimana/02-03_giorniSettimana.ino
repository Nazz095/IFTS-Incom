const int GIORNO_INIZ = 1;
const int GIORNO_FIN = 8;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int giorno = random(GIORNO_INIZ, GIORNO_FIN);
  Serial.print(giorno);
  Serial.print(F(" - "));
  switch(giorno)
  {
    case 1:
      Serial.println(F("Lunedì"));
      break;
    case 2:
      Serial.println(F("Martedì"));
      break;
    case 3:
      Serial.println(F("Mercoledì"));
      break;
    case 4:
      Serial.println(F("Giovedì"));
      break;
    case 5:
      Serial.println(F("Venerdì"));
      break;
    case 6:
      Serial.println(F("Sabato"));
      break;
    case 7:
      Serial.println(F("Domenica"));
      break;
    default:
      break;    
  }
  delay(1000);
}
