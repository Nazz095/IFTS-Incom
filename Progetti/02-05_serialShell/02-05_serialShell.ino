#define LED LED_BUILTIN

void setup() {
  pinMode(LED, OUTPUT);
   //Initialize serial and wait for port to open:
  Serial.begin(9600);
  
  Serial.println("\nAccende e spegne il LED con la seriale");
  Serial.println("S: spegne il LED");
  Serial.println("A: accende il LED");
  Serial.println("L: fa lampeggiare il LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    unsigned char comando = Serial.read();
    switch(comando)
    {
      case 'a':
      case 'A':
        digitalWrite(LED, HIGH);
        Serial.println("Acceso");
        break;
      case 's':
      case 'S':
        digitalWrite(LED, LOW);
        Serial.println("Spento");
        break;
      case 'l':
      case 'L':
        Serial.println("Lampeggio. Inserire il numero di lampeggi (da 1 a 9)");
        unsigned char lamp = Serial.read();
        while (lamp < '0' || lamp > '9')
        {
          lamp = Serial.read();
        }
        Serial.print("Lampeggia ");
        Serial.print(lamp - 48);
        Serial.print(" volte: ");
        for (int i = 0; i < lamp - '0'; i++)
        {
          digitalWrite(LED, HIGH);
          Serial.print("acceso, ");
          delay(500);
          digitalWrite(LED, LOW);
          if(i == lamp - '0' - 1) Serial.println("spento");
          else Serial.print("spento, ");
          delay(500);
        }
        break;
      default:
        Serial.println("Comando non riconosciuto!");
        break;
    }
  }
}
