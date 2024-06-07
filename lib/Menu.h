#include <stdint.h>

#include <inttypes.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "../lib/EEPROMController.h"
#include "../lib/RTCController.h"

#define BUTTON_UP_PIN 13
#define BUTTON_DOWN_PIN 8
#define BUTTON_ENTER_PIN 7

class Menu{
   public:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
    EEPROMController epromController;
    RTCController rtcController;
    Menu();
    String menuOptions[6];
    uint8_t optionNumber;
    void timerDelay(uint16_t delayTime);
    void displayMenu(uint8_t optionNumber);
    void initialize();
    void handleMenu();
    void soundGame();
    void beginGameStart();
    void showResult(uint16_t result);
    void showFalseStartMessage();
    void handleEEPROMClear();
    int chooseNumber(int minValue, int maxValue, String message);


  private:    
  
    uint8_t menuSize = 4;
    String menuTitle;
    
};