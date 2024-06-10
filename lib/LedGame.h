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
    void turnOnLed();

    // void showResult();
    /*!
     *  @brief Implements play functionality of the game.
     *         Calculate interval as sum of beginGame() and previousMillis (time between now and start of the arduino program).
     *         While loop is running until the interval is reached. If user presses the game button in this time, the game is stopped.
     *         If the waiting time is completed it calcualtes the time between start and stop time (user reaction).
     *  @returns  Return 1 if user pressed button before interval time passed which means falsestart.
     *             Return stopTime - startTime if user waited for the interval time passed.
     *  @side effects:
     *            efekty uboczne
     */
    uint16_t play() override;
    /*!
     *  @brief  Uses analogWrite() and LED_GAME_LED_PIN to turn off led.
     *  @side effects:
     *            turn offs LED_GAME_LED_PIN conencted LED.
     */
    void turnOffLed();
};