#define BUTTON 2
#define RED_LED 7
#define GREEN_LED 10

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop() {
  int interrupted = 0;
  if(!digitalRead(BUTTON))  //se tasto è premuto
  {
    for(int push_count = 0; push_count < 10; push_count++)
    {
      if(push_count < 5)
      {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
      }
      else
      {
        digitalWrite(GREEN_LED, HIGH);
      }
      delay(500);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      delay(500);
      if(digitalRead(BUTTON)) 
      {
        interrupted = 1;
        break;
      }
    }
  }
  else
  {
    for(int pull_count = 0; pull_count < 10; pull_count++)
    {
      if(pull_count < 5)
      {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
      }
      else
      {
        digitalWrite(RED_LED, HIGH);
      }
      delay(500);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      delay(500);
      if(!digitalRead(BUTTON)) 
      {
        interrupted = 1;
        break;
      }
    }
  }
  if(!interrupted) delay(3000);

}
