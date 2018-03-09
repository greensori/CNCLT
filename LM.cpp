#include "Arduino.h"
#include "LM.h"

#define coupleStep

LM::LM()
{
}

void LM::setStep(int s1, int s2, int s3) {
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  _pwm = 800;
}

int LM::xAxis(int s1, int s2, int targetSW) {
  digitalWrite(s1, HIGH);
  digitalWrite(s2, HIGH);
  delayMicroseconds(_pwm);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  return _pwm;
}
