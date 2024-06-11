#pragma once

#include "Game.h"

#define LED_ON_VALUE 255
#define LED_OFF_VALUE 0

class LedGame : public Game
{
public:
    /*!
     *  @brief Uses analogWrite() and LED_GAME_LED_PIN pin to turn on the LED.
     *   @returns none
     *  @side effects:
     *            turn on LED_GAME_LED_PIN conencted LED.
     */
    void turnOnDevice();
    /*!
     *  @brief  Uses analogWrite() and LED_GAME_LED_PIN to turn off led.
     *  @side effects:
     *            turn offs LED_GAME_LED_PIN conencted LED.
     */
    void turnOffDevice();
};