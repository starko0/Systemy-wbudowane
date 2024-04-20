#include <stdint.h>
#include <inttypes.h>
#include <Arduino.h>
#include "defines.h"

class Game {
  protected:
    uint16_t interval;
    uint16_t previousMillis;
    uint16_t startTime;
    uint16_t stopTime;
    uint16_t finalResult;
    
  public:
    virtual uint16_t play();

    uint16_t beginGame();
};