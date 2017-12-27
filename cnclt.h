#ifndef cnclt_h
#define cnclt_h

#include "Arduino.h"

class cnclt
{
  private:
    int _test;
    int _switchStatus;
    int _pinReader;
    int _count;
  public:
    cnclt(int a);
    int initialize();
    int endSwitchStatus(int d, int pinno);
    int stepWorkPosition(int pinno, int stepCount);
    int endSwitchChecker(int DIR, int STEP, int endswitch);
};

#endif
