#include "Arduino.h"
#include "myDev.h"

#include "myAscii.h"

#include <Servo.h>


Servo shouldeServo, elbowServo, wristServo, elbowRoll, handServo;

myAscii myAscii;


myDev::myDev() 
{
}

myDev::~myDev()
{
}

uint8_t myDev::asciiGet(uint8_t inChar) {
  Serial.println (inChar);
  myAscii.test();
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
  pinMode(xAxis[1], OUTPUT);
  pinMode(rAxis, OUTPUT);
  digitalWrite(xAxis[0], HIGH);
  digitalWrite(xAxis[1], HIGH);
  digitalWrite(rAxis, HIGH);
}

void myDev::registerServo(uint8_t sv1, uint8_t sv2, uint8_t sv3, uint8_t sv4, uint8_t sv5) {
  shouldeServo.attach(sv1);
  elbowServo.attach(sv2);
  wristServo.attach(sv3);
  elbowRoll.attach(sv4);
  handServo.attach(sv5);
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
    digitalWrite(xAxis[0], LOW);
    digitalWrite(xAxis[1], LOW);
    //delayMicroseconds(stepPwm[0]);
    digitalWrite(xAxis[0], HIGH);
    digitalWrite(xAxis[1], HIGH);
    pts[0]++;
    return pts[0];   
  } else {
    pts[0] = 0;
    return pts[0];
  }
}

uint16_t myDev::rAxisMovement() {
  if (digitalRead(rAxisStartPin) == 0) {
    digitalWrite(rAxis, LOW);
    //delayMicroseconds(stepPwm[1]);
    digitalWrite(rAxis, HIGH);
  } else {
    pts[1] = 0;
    return pts[1];
  }
}

void myDev::servoMovement(uint8_t servoNum, uint16_t pt) {
  if (servoNum == 2) {
    shouldeServo.writeMicroseconds(pt); 
  } else if (servoNum == 3) {
    elbowServo.writeMicroseconds(pt);
  } else if (servoNum == 4) {
    wristServo.writeMicroseconds(pt);
  } else if (servoNum == 5) {
    elbowRoll.writeMicroseconds(pt);
  } else if (servoNum == 6) {
    handServo.writeMicroseconds(pt); 
  }
}

void myDev::setDirection(uint8_t targetStep, uint8_t setDir) {
  if (targetStep == 0) {
    if (setDir == 0) {
      digitalWrite(xAxisDir[0], HIGH);
      digitalWrite(xAxisDir[1], HIGH);
    } else if (setDir == 1) {
      digitalWrite(xAxisDir[0], LOW);
      digitalWrite(xAxisDir[1], LOW);      
    }
  } else if (targetStep == 1) {
    if (setDir == 0) {
      digitalWrite(xAxisDir[1], HIGH);
    } else if (setDir == 1) {
      digitalWrite(xAxisDir[1], LOW);
    }
  }
}

void myDev::xAxisHome() {
  setDirection(1, 0);
  do {
    delayMicroseconds(900);
    xAxisMovement();
  } while(pts[0] != 0);
  setDirection(1, 1);
  //stepPwm[0] = (stepPwm[0] * 2);
  for (i = 0; i < 10; i++) {
    delayMicroseconds(1800);
    xAxisMovement();
    //this phase pwm must half values
  }
  setDirection(1, 0);
  do {
    delayMicroseconds(900);
    xAxisMovement();
  } while(pts[0] != 0); //end xAixs home position
  //stepPwm[0] = (stepPwm[0] / 2); //xAxis speed normalize
}


void myDev::rAxisHome() {
  setDirection(2, 0);
  do {
    delayMicroseconds(900);
    rAxisMovement();
  } while(pts[1] != 0);
  setDirection(2, 1);
  //stepPwm[1] = (stepPwm[1] * 2);
  for (i = 0; i < 10; i++) {
    delayMicroseconds(1800);
    rAxisMovement();
    //this phase pwm must half values
  }
  setDirection(2, 0);
  do {
    delayMicroseconds(900);
    rAxisMovement();
  } while(pts[1] != 0); //end xAixs home position
  //stepPwm[1] = (stepPwm[1] / 2); //xAxis speed normalize  
}

void myDev::homeAll() {
  xAxisHome();
  rAxisHome();
}
