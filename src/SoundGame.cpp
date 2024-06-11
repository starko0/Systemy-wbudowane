#include "Arduino.h"
#include "../lib/SoundGame.h"


void SoundGame::turnOnDevice() {
    digitalWrite(SPEAKER_PIN, HIGH);
}

void SoundGame::turnOffDevice() {
    digitalWrite(SPEAKER_PIN, LOW);
}