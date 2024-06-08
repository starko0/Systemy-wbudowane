#pragma once
#include <stdint.h>
#include "Game.h"

class SoundGame : public Game
{
public:
  /*!
   *  @brief  Uses analogWrite() and SPEAKER_PIN pin to turn on the buzzer;
   *  @side effects:
   *            turns on SPEAKER_PIN conencted buzzer.
   */
  void playSound();
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
  uint16_t play() override;
  /*!
   *  @brief  Uses analogWrite() and SPEAKER_PIN pin to turn off buzzer.
   *  @side effects:
   *            turns off SPEAKER_PIN conencted buzzer.
   */
  void stopSound();
};