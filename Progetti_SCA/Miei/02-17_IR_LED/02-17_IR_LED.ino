#include <IRremote.h>

byte RECV_PIN = 11, LED_PIN = A0, led = 0, dimValue = 200;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 16753245) {
      if (!led) {
        digitalWrite(LED_PIN, HIGH);
        led = 1;
      }
      else {
        digitalWrite(LED_PIN, LOW);
        led = 0;
      }
    }
    if (results.value == 0xF629D){
      dimValue += 20;
      analogWrite(LED_PIN, dimValue);
    }
    if (results.value == 0xFFA857){
      dimValue -= 20;
      analogWrite(LED_PIN, dimValue);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
