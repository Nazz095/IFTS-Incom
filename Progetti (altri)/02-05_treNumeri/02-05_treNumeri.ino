void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  short primo_num = random(0, 101);
  short secondo_num = random(0, 101);
  short terzo_num = random(0, 5);

  //controllo numeri
  Serial.print("\nPrimo numero: ");
  Serial.println(primo_num);
  Serial.print("Secondo numero: ");
  Serial.println(secondo_num);
  Serial.print("Terzo numero: ");
  Serial.println(terzo_num);
  
  switch(terzo_num)
  {
    case 0:
      Serial.println("Errore!");
      break;
    case 1:
      Serial.print("Somma dei primi due numeri è pari a ");
      Serial.println(primo_num + secondo_num);
      break;
    case 2:
      Serial.print("Differenza tra i primi due numeri è pari a ");
      Serial.println(primo_num - secondo_num);
      break;
    case 3:
      Serial.print("Prodotto dei primi due numeri è pari a ");
      Serial.println(primo_num * secondo_num);
      break;
    case 4:
      if(!secondo_num) 
      {
        Serial.println("Il secondo numero è pari a 0. Vietata la divisione");
        break;
      }
      Serial.print("Divisione tra i primi due numeri è pari a ");
      Serial.print((float)primo_num / secondo_num);
      //Serial.print(" con il resto di ");
      //Serial.println(primo_num % secondo_num);
      break;
  }
  while(true);
}
