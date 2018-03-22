#include "Arduino.h"
#include "myAscii.h"


myAscii::myAscii() 
{
}

myAscii::~myAscii()
{
}

uint8_t myAscii::input(char inChar) {
  this->inChar = inChar;
  return (this->inChar);
}

void myAscii::nosignal() {
  Serial.println (asci);
}

uint16_t myAscii::asciiToPts(char inChar, uint16_t *ptA, uint16_t *ptB, uint16_t *ptC) {
  //65 to 90
  if (inChar <= 75) {
  } else if (inChar <= 85) {
  } else if (inChar <= 90) {
  }
}

uint16_t myAscii::asciiToPwm(char inChar, uint16_t *digitA, uint16_t *digitB, uint16_t *digitC) {
  if (inChar <= 106) {
    *digitA = ((inChar - 97) * 10);
  } else if (inChar <= 116) {
    *digitB = ((inChar - 107) * 100);
  } else if (inChar <= 122) {
    *digitC = ((inChar - 117) * 1000);
  }
  return (*digitA + *digitB + *digitC);
}

void myAscii::test() {
  Serial.println ("enter Ascii");
}
