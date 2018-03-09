#ifndef LM_h
#define LM_h

#include "Arduino.h"

class LM
{
  private:
    int _s1;
    int _s2;
    int _s3;
    int _pwm;
  public:
    LM();
    void setStep(int s1, int s2, int s3);
    int xAxis(int s1, int s2, int targetSW);
    int rotateAxis();
};

#endif
