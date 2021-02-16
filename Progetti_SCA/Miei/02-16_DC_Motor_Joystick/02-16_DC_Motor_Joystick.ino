/***************************
Exercise the motor using
the L293D chip and joystick
***************************/

//considero soltanto l'asse X del joystick collegato ad A0 e la tolleranza in mezzo
const byte X_pin = 0, TOLLERANZA = 5;
//imposto i pin del motore e la sua velocita'
const byte ENABLE = 5, DIRA = 3, DIRB = 4, SPEED_MIN = 65, SPEED_MAX = 255;
const unsigned short VAL_MEDIO = 508, VAL_MAX = 1023;

byte i, fanSpeed, dir;
unsigned short x_value;
unsigned long tempo = millis();

void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("X-value\t\tSpeed\t\tDirection");
}

void loop() {
  x_value = analogRead(X_pin);

  //muovo joystick verso i propri pin (per me verso destra)
  if(x_value > VAL_MEDIO + TOLLERANZA){
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    fanSpeed = map (x_value, VAL_MEDIO + TOLLERANZA, VAL_MAX, SPEED_MIN, SPEED_MAX);
    dir = 1;
  }
  //muovo joystick lontano dai propri pin (per me verso sinistra)
  else if (x_value < VAL_MEDIO - TOLLERANZA){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    fanSpeed = map (x_value, VAL_MEDIO - TOLLERANZA, 0, SPEED_MIN, SPEED_MAX);
    dir = 2;
  }
  //joystick sta fermo in centro, nella sua posizione neutrale
  else{
    dir = 0;
    fanSpeed = 0;
  }
  //muovo il motore con la velocita' calcolata  dalla posizione di joystick
  analogWrite(ENABLE, fanSpeed);

  //scrivo nella seriale i valori soltanto ogni 500ms
  if((millis() - tempo) > 500){
    tempo = millis();
    Serial.print(x_value);
    Serial.print("\t\t");
    Serial.print(fanSpeed);
    Serial.print("\t\t");
    
    if (dir == 1){
      Serial.println("SX");
    }
    else if (dir == 2){
      Serial.println("DX");
    }
    else{
      Serial.println(" -");
    }
  }
}
   
