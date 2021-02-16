/************************
Exercise the motor using
the L293D chip
************************/

#define ENABLE 5
#define DIRA 3
#define DIRB 4

void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
  Serial.println("Controllo velocita' di partenza:");
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,HIGH);
  for (byte i = 140; i < 255; i++)
  {
    analogWrite(ENABLE, i);
    Serial.print("Velocita': ");
    Serial.println(i);
    delay(500);
  }*/
  Serial.println("Velocita' massima!");
  digitalWrite(DIRA,LOW);
  digitalWrite(DIRB,HIGH);
  digitalWrite(ENABLE, HIGH);
  delay(500);
  for (byte i = 235; i > 55; i-=10)
  {
    analogWrite(ENABLE, i);
    Serial.print("Velocita': ");
    Serial.println(i);
    delay(100);
  }
  for (byte j = 55; j < 255; j+=10)
  {
    analogWrite(ENABLE, j);
    Serial.print("Velocita': ");
    Serial.println(j);
    delay(100);
  }
}
