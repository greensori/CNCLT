#ifndef myAscii_h
#define myAscii_h

#include "Arduino.h"

class myAscii
{
  private:
    uint16_t asciiType;
    uint8_t inChar;
  public:
    myAscii();
    ~myAscii();
    uint16_t asciiToPwm(char inChar, uint16_t *digitA, uint16_t *digitB, uint16_t *digitC);
    void test();
};

#endif
