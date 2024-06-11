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
  void turnOnDevice() override;
  /*!
   *  @brief  Uses analogWrite() and SPEAKER_PIN pin to turn off buzzer.
   *  @side effects:
   *            turns off SPEAKER_PIN conencted buzzer.
   */
  void turnOffDevice() override;
};