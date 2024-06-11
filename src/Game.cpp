#include "../lib/Game.h"

uint16_t Game::beginGame() {
    interval = random(200, 700);
    return interval * 10;
}

uint16_t Game::play() {
    previousMillis = millis();

    interval = beginGame() + previousMillis;

    while (true) {
        if (millis() > interval) {
            break;
        } else {
            if (!digitalRead(BUTTON_ENTER_PIN) == HIGH) {
                return 1;
            }
        }
    }

    startTime = millis();

    while (!digitalRead(BUTTON_ENTER_PIN) == LOW) {
        turnOnDevice();
    }

    stopTime = millis();
    turnOffDevice();
    return stopTime - startTime;
}
