#include "Arduino.h"
#include "../lib/SoundGame.h"

uint16_t SoundGame::play() {
  uint16_t previousMillis = millis();

  uint16_t interval = beginGame() + previousMillis;

  while(true) {
    if (millis() > interval) {
      break;
    }
    else{
      if(!digitalRead(BUTTON_ENTER_PIN) == HIGH){
        return 1;
      }
    }
  }

  startTime = millis();

  //play sound
  while (!digitalRead(BUTTON_ENTER_PIN) == LOW) {
    playSound();
  }
  stopTime = millis();
  stopSound();
  return stopTime - startTime;
}

void SoundGame::playSound() {
  digitalWrite(SPEAKER_PIN, HIGH);
}

void SoundGame::stopSound(){
  digitalWrite(SPEAKER_PIN, LOW);
}