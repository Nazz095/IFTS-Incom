/* Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The circuit:
   LCD RS pin to digital pin 7
   LCD Enable pin to digital pin 8
   LCD D4 pin to digital pin 9
   LCD D5 pin to digital pin 10
   LCD D6 pin to digital pin 11
   LCD D7 pin to digital pin 12
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  Library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  Example added 9 Jul 2009
  by Tom Igoe
  Modified 22 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#include "SR04.h"
#define TRIG_PIN 5
#define ECHO_PIN 6
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

unsigned long tempo = millis(), lampChar = millis();
byte posizione = 0, j = 0, blCh = 0;
unsigned char blinkChar = '.';

void setup() {
  Serial.begin(9600);
  delay(1000);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
}

void loop() {

  if ((millis() - tempo) > 500) {
    tempo = millis();
    if (j == 3) posizione = 1;
    else if (j == 0) posizione = 0;
    if (posizione == 0)j++;
    else if (posizione == 1) j--;
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(j, 0);
    lcd.print("Hello, World!");

    a = sr04.Distance();
    Serial.print(a);
    Serial.println("cm");
  //}
/*
 * stampa il punto lampeggiante
  if ((millis() - lampChar) > 500)
  {*/
    //lampChar = millis();
    lcd.setCursor(0, 1);
    if (!blCh) {
      lcd.write(blinkChar);
      blCh = 1;
    }
    else {
      lcd.print(" ");
      blCh = 0;
    }

    //stampa distanza
    lcd.setCursor(2, 1);
    if(a < 10) {
      lcd.print("Distanza: ");
      lcd.setCursor(12, 1);
    }
    else {
      lcd.print("Distanza:");
      lcd.setCursor(11, 1);
    }
    lcd.print(a);
    lcd.setCursor(13, 1);
    lcd.print("cm");
    
  }
}
