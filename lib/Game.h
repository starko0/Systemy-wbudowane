#pragma once
#include <stdint.h>
#include <inttypes.h>
#include <Arduino.h>
#include "defines.h"

class Game {
  protected:
    unsigned long interval;
    unsigned long previousMillis;
    unsigned long startTime;
    unsigned long stopTime;
    uint16_t finalResult;

  public:
    virtual uint16_t play();

    uint16_t beginGame();
};