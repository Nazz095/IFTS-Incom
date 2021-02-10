#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Inserisci codifica RGB: ");

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}


void loop() {
  int red_read, red, green_read, green, blue_read, blue;
  if (Serial.available()) {
    red_read = Serial.parseInt();
    Serial.print("Red: ");
    Serial.println(red_read);
    // do it again:
    green_read = Serial.parseInt();
    Serial.print("Green: ");
    Serial.println(green_read);
    // do it again:
    blue_read = Serial.parseInt();
    Serial.print("Blue: ");
    Serial.println(blue_read);
    //String stringa = Serial.readString();
    lcd.setCursor(0, 0);
    lcd.print("                ");/*
    lcd.setCursor(0, 0);
    lcd.print(red_read);
    lcd.setCursor(4, 0);
    lcd.print(green_read);
    lcd.setCursor(8, 0);
    lcd.print(blue_read);*/
      // look for the next valid integer in the incoming serial stream:
      // look for the newline. That's the end of your sentence:
      if (Serial.read() == '\n') {
        // constrain the values to 0 - 255 and invert
        // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
        red = constrain(red_read, 0, 255);
        green = constrain(green_read, 0, 255);
        blue = constrain(blue_read, 0, 255);

        // fade the red, green, and blue legs of the LED:
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);

        // print the three numbers in one string as hexadecimal:
        Serial.print("RGB: ");
        Serial.print(red, HEX);
        Serial.print(green, HEX);
        Serial.println(blue, HEX);
        lcd.setCursor(0, 0);
        lcd.print("RGB code: ");
        lcd.setCursor(10, 0);
        lcd.print(red, HEX);
        lcd.setCursor(12, 0);
        lcd.print(green, HEX);
        lcd.setCursor(14, 0);
        lcd.print(blue, HEX);
        if(!red && !green && blue)
    {
      lcd.setCursor(5, 1);
      lcd.print("          ");
      lcd.setCursor(9, 1);
      lcd.print("Blu");
    }
    else if(red && !green && !blue)
    {
      lcd.setCursor(5, 1);
      lcd.print("          ");
      lcd.setCursor(9, 1);
      lcd.print("Rosso");
    }
    else if(!red && green && !blue)
    {
      lcd.setCursor(5, 1);
      lcd.print("          ");
      lcd.setCursor(9, 1);
      lcd.print("Verde");
    }
      }
  }
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis() / 1000);
    
}
