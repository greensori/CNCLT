#include "Arduino.h"
#include "myAscii.h"


myAscii::myAscii() 
{
}

myAscii::~myAscii()
{
}

uint16_t myAscii::asciiToPwm(char inChar, uint16_t *digitA, uint16_t *digitB, uint16_t *digitC) {
  if (inChar <= 106) {
    Serial.println ("enter inchar A");
    *digitA = ((inChar - 97) * 10);
  } else if (inChar <= 116) {
    Serial.println ("enter inchar B");
    *digitB = ((inChar - 107) * 100);
  } else if (inChar <= 122) {
    *digitC = ((inChar - 117) * 1000);
  }
  return (*digitA + *digitB + *digitC);
}

void myAscii::test() {
  Serial.println ("enter Ascii");
}
