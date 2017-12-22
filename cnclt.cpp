#include "Arduino.h"
#include "cnclt.h"

#define pinResult (d + _pinReader)

cnclt::cnclt(int a)
{
  _pinReader = 0;
  _switchStatus = 0;
}

int cnclt::initialize(){
  return 1;
}

int cnclt::endSwitchStatus(int d, int pinno) {
  _pinReader = digitalRead(pinno);
  return pinResult;
}
