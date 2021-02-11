/*
   Misura temperatura e umidità e visualizza su LCD e RGB LED, insieme a temperatura-soglia.
   Tramite due tasti si aumenta o diminuisce soglia.
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOGLIA_BASE 25
#define SOGLIA_MIN 10
#define SOGLIA_MAX 35
#define ISTERESI 1.0

const byte redPin = 3, greenPin = 5, bluePin = 6, buttonPlus = 4, buttonMinus = 13;
const float correzione = 2.5;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);
  Serial.println(F("Umidita'\tTemperatura\tIndiceCalore\tSoglia"));

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonMinus, INPUT_PULLUP);
  pinMode(buttonPlus, INPUT_PULLUP);
}

unsigned long tempo = millis(), lampeggio = millis(), indicatoreUmidita = millis();
byte i = 255, luminosita = 1, ledPinOn, minusPushed = 0, plusPushed = 0, secondi = 0, minuti = 0;
float soglia = SOGLIA_BASE;

void loop() {
  float h = dht.readHumidity();
  // Lettura di temperatura dal sensore in Celsius (the default) corretto di 2,5 gradi
  float t = dht.readTemperature() - correzione;
  // Lettura di temperatura dal sensore in Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  if ((millis() - tempo) > 2000) {
    tempo = millis();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    // stampa dati in seriale e temperatura sullo schermo LCD
    Serial.print(h);
    Serial.print(F("\t\t"));
    Serial.print(t);
    Serial.print(F("\t\t"));
    Serial.print(hic);
    Serial.print(F("\t\t"));
    Serial.println(soglia);
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.setCursor(2, 0);
    lcd.print(t, 1);

    if (t < soglia - ISTERESI / 2) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      ledPinOn = bluePin;
      lcd.setCursor(10, 0);
      lcd.print("Freddo");
    }
    else if (t > soglia + ISTERESI / 2) {
      ledPinOn = redPin;
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      lcd.setCursor(10, 0);
      lcd.print("Caldo ");
    }
    else {
      digitalWrite(redPin, LOW);
      ledPinOn = greenPin;
      digitalWrite(bluePin, LOW);
      lcd.setCursor(10, 0);
      lcd.print("Giusto");
    }
    lcd.setCursor(5, 1);
    lcd.print(" ");
    lcd.setCursor(6, 1);
    lcd.print(soglia, 1);
    lcd.setCursor(10, 1);
    lcd.print("  H:    ");
    lcd.setCursor(14, 1);
    lcd.print((int)h);
  }

  // lampeggio graduale del LED indicato da ledPinOn
  if ((millis() - lampeggio) > 30) {
    lampeggio = millis();
    if (i >= 255) {
      luminosita = 1;
    }
    else if (i <= 0) {
      luminosita = 0;
    }
    if (luminosita) {
      i -= 5;
    }
    else if (!luminosita) {
      i += 5;
    }
    analogWrite(ledPinOn, i);
  }

  // tasto di diminuzione della soglia schiacciato
  if (!digitalRead(buttonMinus) && !minusPushed) {
    indicatoreUmidita = millis();
    if (soglia == SOGLIA_MIN) {
      soglia = SOGLIA_MIN;
    }
    else {
      soglia -= 0.5;
    }
    minusPushed = 1;
  }
  // tasto di diminuzione della soglia rilasciato
  else if (digitalRead(buttonMinus)) {
    minusPushed = 0;
  }

  // tasto di aumento della soglia schiacciato
  if (!digitalRead(buttonPlus) && !plusPushed) {
    indicatoreUmidita = millis();
    if (soglia == SOGLIA_MAX) {
      soglia = SOGLIA_MAX;
    }
    else {
      soglia += 0.5;
    }
    plusPushed = 1;
  }
  // tasto di aumento della soglia rilasciato
  else if (digitalRead(buttonPlus)) {
    plusPushed = 0;
  }

  // mostra la soglia per 2s dopo la pressione dei tasti
  if ((millis() - indicatoreUmidita) < 2000) {
    lcd.setCursor(6, 1);
    lcd.print("  Sgl:");
    lcd.setCursor(12, 1);
    lcd.print(soglia);
  }

  // stampa l'orologio:
  lcd.setCursor(2, 1);
  lcd.print(":");
  if ((millis() / 1000) < 60) {
    secondi = millis() / 1000;
  }
  else {
    secondi = (millis() / 1000) % 60;
  }
  minuti = millis() / 60000;
  if (secondi < 10) {
    lcd.setCursor(3, 1);
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(secondi);
  }
  else {
    lcd.setCursor(3, 1);
    lcd.print(secondi);
  }
  if (minuti < 10) {
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(minuti);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print(minuti);
  }
}
