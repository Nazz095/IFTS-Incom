#define LED LED_BUILTIN

void setup() {
  pinMode(LED, OUTPUT);
   //Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  Serial.println("Accende e spegne il LED con la seriale");
  Serial.println("0 spegne il LED");
  Serial.println("1 accende il LED");
  Serial.println("2 lampeggia il LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    switch(comando)
    {
      case '1':
        digitalWrite(LED, HIGH);
        Serial.println("Acceso");
        break;
      case '0':
        digitalWrite(LED, LOW);
        Serial.println("Spento");
        break;
      case '2':
        Serial.print("Lampeggia: ");
        digitalWrite(LED, HIGH);
        Serial.print("acceso, ");
        delay(500);
        digitalWrite(LED, LOW);
        Serial.print("spento, ");
        delay(500);
        digitalWrite(LED, HIGH);
        Serial.println("acceso");
        delay(500);
        
        break;
      default:
        Serial.println("Comando non riconosciuto. Inserire 0 o 1!");
        break;
    }
  }
}
