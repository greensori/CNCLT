#include "Arduino.h"
#include "cnclt.h"

#define pinResult (d + _pinReader)

#define returnPosition (stepcount - 1)

cnclt::cnclt(int a)
{
  _pinReader = 0;
}

 
int cnclt::initialize(){
  return 1;
}


/*
 * this module to checking end switch status
 */
int cnclt::endSwitchStatus(int d, int pinno) {
  _pinReader = digitalRead(pinno);
  return pinResult;
}

// input pts.stepCount[n],
int cnclt::stepWorkPosition(int pinno, int stepcount){
  if (digitalRead(pinno) == 1) {
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, HIGH);
    return (stepcount - 1);
  } else if (digitalRead(pinno) == 0) {
    return 0;
  }
}

/*
 * this is using for initiating machine
 */
int cnclt::endSwitchChecker(int DIR, int STEP, int endswitch) {
  digitalWrite(DIR, HIGH);
  while (digitalRead(endswitch) == 0) {
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
  }
  while (digitalRead(endswitch) == 1) {
    digitalWrite(DIR, LOW);
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1500);
  }
  while (digitalRead(endswitch) == 0) {
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1500);
  }
  return 0;
}

