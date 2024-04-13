#include "Menu.h"
#include "defines.h"

Menu menu;

void setup() {
  pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
  pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
  pinMode(BUTTON_ENTER_PIN, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  menu.initialize();
}

void loop() {
  menu.handleMenu();
}