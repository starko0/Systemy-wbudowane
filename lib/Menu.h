#include <Arduino.h>
#include "../lib/LiquidCrystal_I2C.h"
#include <inttypes.h>

class Menu{
    public:
    Menu();
    void showMenu();

    LiquidCrystal_I2C *lcd = new LiquidCrystal_I2C((uint8_t)0x27, (uint8_t)16, (uint8_t)2);
    
    private:    
    byte optionNumber = 0;
    byte menuSize = 0;
    String menuTitle;
    String menuOptions[4];
    
};