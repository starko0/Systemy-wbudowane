#include "../lib/LedGame.h"
#include "../lib/defines.h"
#include "../lib/EEPROMController.h"



void LedGame::turnOnDevice() {
    analogWrite(LED_GAME_LED_PIN, LED_ON_VALUE);
}

void LedGame::turnOffDevice() {
    analogWrite(LED_GAME_LED_PIN, LED_OFF_VALUE);
}