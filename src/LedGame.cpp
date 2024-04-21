#include "../lib/LedGame.h"
#include "../lib/defines.h"

uint16_t LedGame::play()
{
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

  while (!digitalRead(BUTTON_ENTER_PIN) == LOW) {
    turnOnLed();
  }

  stopTime = millis();
  turnOffLed();
  return stopTime - startTime;

}


void LedGame::turnOnLed()
{
  analogWrite(LED_GAME_LED_PIN, 255);
}

void LedGame::turnOffLed()
{
  analogWrite(LED_GAME_LED_PIN, 0);
}