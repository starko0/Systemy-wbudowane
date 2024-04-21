#pragma once
#include "Game.h"

class LedGame: public Game {
public:
    void turnOnLed();
    void showResult();
    uint16_t play() override;
    void turnOffLed();
};