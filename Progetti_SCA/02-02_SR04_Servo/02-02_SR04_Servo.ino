#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
  #include <Servo.h>
  Servo myservo;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
   
   Serial.println(F("Distance (cm)\tServoVal (0-180)"));
   myservo.attach(9);
}

void loop() {
   a=sr04.Distance();
   //Serial.print(a);
   //Serial.println("cm");
   while(a < 50)
   {
      Serial.print(a);
     int xval = map(a, 0, 50, 0, 180);
     myservo.write(xval);
     Serial.print(F("\t\t"));
     Serial.println(xval);
     //Serial.println("cm");
     delay(100);
     a=sr04.Distance();
     
   }
}
