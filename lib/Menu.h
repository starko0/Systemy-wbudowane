#include <stdint.h>

#include <inttypes.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


#define BUTTON_UP_PIN 13
#define BUTTON_DOWN_PIN 8
#define BUTTON_ENTER_PIN 7

class Menu{
   public:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
    Menu();
    String menuOptions[4];
    uint8_t optionNumber;
    void displayMenu(uint8_t optionNumber);
    void initialize();
    void handleMenu();
    void soundGame();
    void beginGameStart();
    void showResult(uint16_t result);


  private:    
  
    uint8_t menuSize = 4;
    String menuTitle;
    
};