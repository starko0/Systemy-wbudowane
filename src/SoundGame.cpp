#include "Arduino.h"
#include "../lib/SoundGame.h"

uint16_t SoundGame::play() {
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

    //play sound
    while (!digitalRead(BUTTON_ENTER_PIN) == LOW) {
        turnOnDevice();
    }
    stopTime = millis();
    turnOffDevice();
    return stopTime - startTime;
}

void SoundGame::turnOnDevice() {
    digitalWrite(SPEAKER_PIN, HIGH);
}

void SoundGame::turnOffDevice() {
    digitalWrite(SPEAKER_PIN, LOW);
}