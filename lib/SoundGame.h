#pragma once
#include <stdint.h>
#include "Game.h"

class SoundGame: public Game {
public:
  void playSound();
  void showResult();
  uint16_t play() override;
  void stopSound();
};