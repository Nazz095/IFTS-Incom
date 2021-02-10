/*
   Misura temperatura e umidità e visualizza su LCD e RGB LED
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
#define TEMPERATURA 25
#define ISTERESI 1

DHT dht(DHTPIN, DHTTYPE);

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);
  Serial.println(F("Humidity\tTemperature\tHeatIndex"));

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

unsigned long tempo = millis(), lampeggio = millis();
int i = 255, luminosita = 1, ledPinOn;

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).

  if ((millis() - tempo) > 2000) {
    tempo = millis();
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(h);
    Serial.print(F("\t\t"));
    Serial.print(t);
    Serial.print(F("\t\t"));
    Serial.print(hic);
    Serial.println(F("\t\t"));
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.setCursor(2, 0);
    lcd.print(t, 1);
    lcd.setCursor(9, 0);
    lcd.print("H:");
    lcd.setCursor(11, 0);
    lcd.print((int)h);

    if (t < TEMPERATURA - ISTERESI) {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      ledPinOn = bluePin;
      lcd.setCursor(7, 1);
      lcd.print("             ");
      lcd.setCursor(7, 1);
      lcd.print("FaFreddo");
    }
    else if (t > TEMPERATURA + ISTERESI) {
      ledPinOn = redPin;
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      lcd.setCursor(7, 1);
      lcd.print("             ");
      lcd.setCursor(7, 1);
      lcd.print("FaCaldo");
    }
    else {
      digitalWrite(redPin, LOW);
      ledPinOn = greenPin;
      digitalWrite(bluePin, LOW);
      lcd.setCursor(7, 1);
      lcd.print("             ");
      lcd.setCursor(7, 1);
      lcd.print("SiStaBene");
    }
  }
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

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
