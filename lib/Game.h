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
   *  @brief Implements play functionality of the game.
   *         Calculate interval as sum of beginGame() and previousMillis (time between now and start of the arduino program).
   *         While loop is running until the interval is reached. If user presses the game button in this time, the game is stopped.
   *         If the waiting time is completed it calcualtes the time between start and stop time (user reaction).
   *  @returns  Return 1 if user pressed button before interval time passed what means falsestart.
   *             Return stopTime - startTime if user waited for the interval time passed.
   *  @side effects:
   *           none
   */
  uint16_t play();
  /*!
   *  @brief Pick a random number (intepreted for us as seconds) between 2 and 7.
   *  @returns random number between 2 and 7 times times 10 to represent seconds
   *
   *  @side effects:
   *            none
   */
  uint16_t beginGame();
  virtual void turnOnDevice();
  virtual void turnOffDevice();
};