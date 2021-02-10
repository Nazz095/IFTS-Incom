#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("inserisci una stringa di massimo 16 caratteri");
}


void loop() {
   if (Serial.available()) {
    String stringa = Serial.readString();
    Serial.println(stringa);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(stringa);
    Serial.println("inserisci una stringa di massimo 16 caratteri");
  }
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
