#include "../lib/LedGame.h"
#include "../lib/defines.h"
#include "../lib/EEPROMController.h"

uint16_t LedGame::play() {
    unsigned long previousMillis = millis();

    unsigned long interval = beginGame() + previousMillis;

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
        turnOnLed();
    }

    stopTime = millis();
    turnOffLed();
    return stopTime - startTime;

}


void LedGame::turnOnLed() {
    analogWrite(LED_GAME_LED_PIN, LED_ON_VALUE);
}

void LedGame::turnOffLed() {
    analogWrite(LED_GAME_LED_PIN, LED_OFF_VALUE);
}