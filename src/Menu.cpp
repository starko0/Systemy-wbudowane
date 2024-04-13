#include "../lib/Menu.h"
#include <inttypes.h>

Menu::Menu(){

    menuTitle = "!! REFLEX !!";
    menuOptions[0] = "1. Dźwięk";
    menuOptions[1] = "2. Diody";
    menuOptions[2] = "3. Zabranie reki";
    menuOptions[3] = "4. Klimat";
    menuSize = 4;
    optionNumber = 0;
    // Add this line to initialize the 'LiquidCrystal_I2C' object
}


void Menu::showMenu(){

}
