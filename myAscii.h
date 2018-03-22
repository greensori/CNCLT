#ifndef myAscii_h
#define myAscii_h

#include "Arduino.h"

#define asci 877

class myAscii
{
  private:
    uint16_t asciiType;
    uint8_t inChar;
  public:
    myAscii();
    ~myAscii();
    uint8_t input(char inChar);
    void nosignal();
    uint16_t asciiToPwm(char inChar, uint16_t *digitA, uint16_t *digitB, uint16_t *digitC);
    uint16_t asciiToPts(char inChar, uint16_t *ptA, uint16_t *ptB, uint16_t *ptC);
    void test();
};

#endif
