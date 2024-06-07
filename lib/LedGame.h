#pragma once

#include "Game.h"

#define LED_ON_VALUE 255
#define LED_OFF_VALUE 0

class LedGame : public Game {
public:
    uint16_t play() override;

    void turnOnLed();

    void showResult();

    void turnOffLed();
};