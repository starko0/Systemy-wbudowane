#include "../lib/Menu.h"
#include "../lib/defines.h"

Menu menu;

void setup()
{
    pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
    pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
    pinMode(BUTTON_ENTER_PIN, INPUT_PULLUP);
    pinMode(SPEAKER_PIN, OUTPUT);
    pinMode(VIBRATION_PIN, OUTPUT);
    pinMode(FALSE_START_LED_PIN, OUTPUT);
    pinMode(LED_GAME_LED_PIN, OUTPUT);
    pinMode(LED_MENU, OUTPUT);
    menu.initialize();
}

void loop()
{
    menu.handleMenu();
}
