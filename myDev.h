#ifndef myDev_h
#define myDev_h

#include "Arduino.h"

class myDev
{
  private:
    uint8_t xAxis[2];
    uint8_t rAxis;
    uint8_t xAxisDir[2];
    uint8_t rAxisDir;
    uint8_t opticalSw[4];
    uint8_t xAxisStartPin;
    uint8_t xAxisEndPin;
    uint8_t rAxisStartPin;
    uint8_t rAxisEndPin;
    //uint8_t homePtPhase;
    uint16_t pts[2];
    //uint16_t stepPwm[2] = {900, 900};
    int i;
  public:
    myDev();
    ~myDev();
    uint8_t asciiGet(uint8_t inChar);
    void registerPinEna(uint8_t xAxisEna1, uint8_t xAxisEna2, uint8_t rAxisEna);
    void registerPinDir(uint8_t xAxisDir1, uint8_t xAxisDir2, uint8_t rAxisDir);
    void registerPinStep(uint8_t xAxis1, uint8_t xAxis2, uint8_t rAxis);
    void registerEndSw(uint8_t xAxisStart, uint8_t xAxisEnd, uint8_t rAxisStart, uint8_t rAxisEnd);
    int setOptical(int s1, int s2, int s3, int s4); //return present optical value
    uint16_t xAxisMovement();
    uint16_t rAxisMovement();
    void setDirection(uint8_t targetStep, uint8_t setDir);
    void xAxisHome();
    void rAxisHome();
    void homeAll();
};

#endif
