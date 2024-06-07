#include <stdint.h>

#include <inttypes.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "../lib/EEPROMController.h"
#include "../lib/RTCController.h"
#include "../lib/defines.h"

#define MENU_SIZE 6

class Menu{
private:
    String menuTitle;

public:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
    EEPROMController epromController;
    RTCController rtcController;
    Menu();
    String menuOptions[MENU_SIZE];
    uint8_t optionNumber;
    int chooseNumber(int minValue, int maxValue, String message);
    void timerDelay(uint16_t delayTime);
    void displayMenu(uint8_t optionNumber);
    void initialize();
    void handleMenu();
    void soundGame();
    void beginGameStart();
    void showResult(uint16_t result);
    void showFalseStartMessage();
    void handleEEPROMClear();





};