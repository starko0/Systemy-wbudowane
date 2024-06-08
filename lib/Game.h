#pragma once
#include <stdint.h>
#include <inttypes.h>
#include <Arduino.h>
#include "defines.h"

class Game
{
protected:
  unsigned long interval;
  unsigned long previousMillis;
  unsigned long startTime;
  unsigned long stopTime;
  uint16_t finalResult;

public:
  /*!
   *  @brief Virtual method represents play functionality of games.
   */
  virtual uint16_t play();
  /*!
   *  @brief Pick a random number (intepreted for us as seconds) between 2 and 7.
   *  @returns random number between 2 and 7 times times 10 to represent seconds
   *
   *  @side effects:
   *            none
   */
  uint16_t beginGame();
};