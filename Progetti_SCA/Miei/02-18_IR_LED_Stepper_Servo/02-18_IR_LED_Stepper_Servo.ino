//www.elegoo.com
//2016.12.12

#include "Stepper.h"
#include "IRremote.h"
#include <Servo.h>

/*----- Variables, Pins -----*/
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 12
byte led = 0, val = 90;

/*-----( Declare objects )-----*/
// Setup of proper sequencing for Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4

Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'
Servo myservo; // create servo object to control a servo

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  myservo.attach(5); // attaches the servo on pin 5 to the servo object
  pinMode (LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    switch (results.value)
    {
      case 0xFFA857: // VOL+ button pressed
        small_stepper.setSpeed(500); //Max seems to be 500
        Steps2Take  =  2048;  // Rotate CW
        small_stepper.step(Steps2Take);
        //delay(2000);
        break;

      case 0xFF629D: // VOL- button pressed
        small_stepper.setSpeed(500);
        Steps2Take  =  -2048;  // Rotate CCW
        small_stepper.step(Steps2Take);
        //delay(2000);
        break;
        
      case 0xFFA25D:      //tasto POWER
        if (!led) {
          digitalWrite(LED_BUILTIN, HIGH);
          led = 1;
        }
        else {
          digitalWrite(LED_BUILTIN, LOW);
          led = 0;
        }
        break;
        
      case 0xFF906F:  //tasto SU
        if (val < 180) {
          val += 10;
          myservo.write(val);
        }
        break;
        
      case 0xFFE01F:  //tasto GIU'
        if (val > 0) {
          val -= 10;
          myservo.write(val);
        }
        break;
      default:
        break;
    }

    irrecv.resume(); // receive the next value
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

}
