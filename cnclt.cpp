#include "Arduino.h"
#include "cnclt.h"

#define pinResult (d + _pinReader)

cnclt::cnclt(int a)
{
  _pinReader = 0;
}

int cnclt::initialize(){
  return 1;
}

int cnclt::endSwitchStatus(int d, int pinno) {
  _pinReader = digitalRead(pinno);
  return pinResult;
}

void cnclt::endSwitchChecker(int DIR, int STEP, int endswitch) {
  digitalWrite(DIR, HIGH);
  while (digitalRead(endswitch) == 0) {
    digitalWrite(STEP, LOW);
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
  }
}

