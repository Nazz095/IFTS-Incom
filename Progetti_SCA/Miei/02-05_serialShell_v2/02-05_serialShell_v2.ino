#define LED_START 2
#define LED_END 9
#define LED LED_BUILTIN

void setup() {
  Serial.begin(9600);

  for (unsigned char i = LED_START; i <= LED_END; i++)
  {
    pinMode(i, OUTPUT);
    //Serial.println(i);
  }
  Serial.println("Accende e spegne i LED da 2 a 9 con la seriale");
  Serial.println("Accendere o spegnere il LED (a oppure s)?");
  
  bool stato = false;
}

void loop() {
  
  if (Serial.available()) {
  unsigned char comando = Serial.read();
  Serial.print("Il numero di LED (tra ");
  Serial.print(LED_START);
  Serial.print(", e ");
  Serial.print(LED_END);
  Serial.println(" )");
  unsigned char num_led = Serial.read();
  switch(comando)
    {
      case 'a':
      case 'A':
        if(digitalRead(num_led)) Serial.println("LED già acceso");
        else
        {
          digitalWrite(num_led, HIGH);
          Serial.println("Acceso");
        }
        break;
      case 's':
      case 'S':
        if(!digitalRead(num_led)) Serial.println("LED già spento");
        else 
        {
          digitalWrite(LED, LOW);
          Serial.println("Spento");
        }
        break;
      default:
        Serial.println("Comando non riconosciuto!");
        break;
    }
  
  /*
  unsigned char num_led = Serial.read();
  if (stato) 
  {
    Serial.print("Il LED numero ");
    Serial.print(led);
    Serial.println(" è acceso. Cosa devo farci?");
  }
  else 
  {
    Serial.print("Il LED numero ");
    Serial.print(led);
    Serial.println(" è acceso. Cosa devo farci?");
  }*/
    
    
  }
}
