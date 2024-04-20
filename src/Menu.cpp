#include "Arduino.h"
#include "../lib//Menu.h"
#include "../lib/SoundGame.h"

Menu::Menu(){
  menuTitle = "!! REFLEX !!";
  menuOptions[0]="1. Dzwiek";
  menuOptions[1]="2. Dioda";
  menuOptions[2]= "3. Zabierz reke";
  menuOptions[3]= "4. Klimat";
  optionNumber = 0;
}

void Menu::displayMenu(uint8_t optionNumber) {
  lcd.clear();         
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print(menuTitle);
  
  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print(menuOptions[optionNumber]);
}

void Menu::initialize() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print(menuTitle);
  lcd.setCursor(0,1);   //Move cursor to character 2 on line 1
  lcd.print(menuOptions[0]);
}

void Menu::beginGameStart(){
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  for(int i=3; i>0; i--){
    lcd.setCursor(7,0);   
    lcd.print(i);
    delay(900);
    lcd.clear();
  }
  lcd.setCursor(2,1);
  lcd.print("!!! START !!!");
  delay(800);
  lcd.clear();
}

void Menu::showResult(uint16_t result){
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(5,0);   //Set cursor to character 2 on line 0
  lcd.print(result);
  lcd.print(" ms");
}

void Menu::handleMenu(){
  int isUpButtonPressed = digitalRead(BUTTON_UP_PIN);
  int isDownButtonPressed = digitalRead(BUTTON_DOWN_PIN);
  int isEnterButtonPressed = digitalRead(BUTTON_ENTER_PIN);
  if(!isUpButtonPressed == HIGH){
    digitalWrite(12, HIGH);
    if(optionNumber>0){
      optionNumber--;
      displayMenu(optionNumber);
      delay(200);
    }
  }

  if(!isDownButtonPressed == HIGH){

    digitalWrite(12, HIGH);
    if(optionNumber < 3){
      optionNumber++;
      displayMenu(optionNumber);
      delay(200);
    }
  }

  if(!isEnterButtonPressed == HIGH) {
    switch(optionNumber){
      case 0: {
        SoundGame soundGame;
        beginGameStart();
        uint16_t finalResult = soundGame.play();
        showResult(finalResult);
        // delay(1500);
        bool flaga = false;

        while(!flaga){
          if(!digitalRead(BUTTON_ENTER_PIN) == HIGH){
            flaga = true;
          }
        }
        
        
        displayMenu(0);
        delay(500);
          
      }
    }
  }

  digitalWrite(12, LOW);
}




    