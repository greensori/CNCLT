#include "Arduino.h"
#include "myDev.h"


myDev::myDev() 
{
}

myDev::~myDev()
{
}

uint8_t myDev::asciiGet(char inChar) {
  Serial.println (inChar);
}

void myDev::registerPinEna(uint8_t xAxisEna1, uint8_t xAxisEna2, uint8_t rAxisEna) {
  pinMode(xAxisEna1, OUTPUT);
  pinMode(xAxisEna2, OUTPUT);
  pinMode(rAxisEna, OUTPUT);
  digitalWrite(xAxisEna1, LOW);
  digitalWrite(xAxisEna2, LOW);
  digitalWrite(rAxisEna, LOW);
}

void myDev::registerPinDir(uint8_t xAxisDir1, uint8_t xAxisDir2, uint8_t rAxisDir) {
  xAxisDir[0] = xAxisDir1;
  xAxisDir[1] = xAxisDir2;
  this->rAxisDir = rAxisDir;
  pinMode(xAxisDir[0], OUTPUT);
  pinMode(xAxisDir[1], OUTPUT);
  pinMode(rAxisDir, OUTPUT);
}

void myDev::registerPinStep(uint8_t xAxis1, uint8_t xAxis2, uint8_t rAxis) {
  xAxis[0] = xAxis1;
  xAxis[1] = xAxis2;
  this->rAxis = rAxis;
  pinMode(xAxis[0], OUTPUT);
  pinMode(xAxis[0], OUTPUT);
  pinMode(rAxis, OUTPUT);
}

void myDev::registerEndSw(uint8_t xAxisStartPin, uint8_t xAxisEndPin, uint8_t rAxisStartPin, uint8_t rAxisEndPin) {
    this->xAxisStartPin = xAxisStartPin;
    this->xAxisEndPin = xAxisEndPin;
    this->rAxisStartPin = rAxisStartPin;
    this->rAxisEndPin = rAxisEndPin;
}


//return potitionValue
uint16_t myDev::xAxisMovement() {
  if (digitalRead(xAxisStartPin) == 0) {
    digitalWrite(xAxis[0], HIGH);
    digitalWrite(xAxis[1], HIGH);
    delayMicroseconds(stepPwm[0]);
    digitalWrite(xAxis[0], LOW);
    digitalWrite(xAxis[1], LOW);
    pts[0]++;
    return pts[0];   
  } else {
    pts[0] = 0;
    return pts[0];
  }
}

uint16_t myDev::rAxisMovement() {
  if (digitalRead(rAxisStartPin) == 0) {
    digitalWrite(rAxis, HIGH);
    delayMicroseconds(stepPwm[1]);
    digitalWrite(rAxis, LOW);
  } else {
    pts[1] = 0;
    return pts[1];
  }
}

void myDev::setDirection(uint8_t targetStep, uint8_t setDir) {
  if (targetStep == 1) {
    if (setDir == 0) {
      digitalWrite(xAxisDir[0], HIGH);
      digitalWrite(xAxisDir[1], HIGH);
    } else if (setDir == 1) {
      digitalWrite(xAxisDir[0], LOW);
      digitalWrite(xAxisDir[1], LOW);      
    }
  } else if (targetStep == 2) {
    if (setDir == 0) {
      digitalWrite(xAxisDir[1], HIGH);
    } else if (setDir == 1) {
      digitalWrite(xAxisDir[1], LOW);
    }
  }
}

void myDev::homeAll() {
  setDirection(1, 0);
  do {
    xAxisMovement();
  } while(pts[0] != 0);
  setDirection(1, 1);
  stepPwm[0] = (stepPwm[0] * 2);
  for (i = 0; i < 10; i++) {
    xAxisMovement();
    //this phase pwm must half values
  }
  stepPwm[0] = (stepPwm[0] / 2);
  setDirection(1, 0);
  do {
    xAxisMovement();
  } while(pts[0] != 0); //end xAixs home position
  setDirection(2, 0);
}


