#pragma once

#include "Arduino.h"
#include "../lib//Menu.h"
#include "../lib/SoundGame.h"
#include <string.h>
#include "../lib/GameData.h"

#include "../lib/LedGame.h"

Menu::Menu() {
    menuTitle = "!! REFLEX !!";
    menuOptions[0] = "1. Dzwiek";
    menuOptions[1] = "2. Dioda";
    menuOptions[2] = "3. Czysc EEPROM";
    menuOptions[3] = "4. Klimat";
    optionNumber = 0;
}

void Menu::displayMenu(uint8_t optionNumber) {
    lcd.clear();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);   //Set cursor to character 2 on line 0
    lcd.print(menuTitle);

    lcd.setCursor(0, 1);   //Move cursor to character 2 on line 1
    lcd.print(menuOptions[optionNumber]);
}

void Menu::initialize() {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);   //Set cursor to character 2 on line 0
    lcd.print(menuTitle);
    lcd.setCursor(0, 1);   //Move cursor to character 2 on line 1
    lcd.print(menuOptions[0]);
    Serial.begin(9600);
}

void Menu::beginGameStart() {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(2, 0);   //Set cursor to character 2 on line 0
    for (int i = 3; i > 0; i--) {
        lcd.setCursor(7, 0);
        lcd.print(i);
        delay(900);
        lcd.clear();
    }
    lcd.setCursor(2, 1);
    lcd.print("!!! START !!!");
    delay(800);
    lcd.clear();
}

void Menu::showResult(uint16_t result) {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(5, 0);   //Set cursor to character 2 on line 0
    lcd.print(result);
    lcd.print(" ms");
}

void Menu::handleEEPROMClear() {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(5, 0);   //Set cursor to character 2 on line 0
    lcd.print("Clearing...");
    epromController.clearEEPROM();
    epromController.clearGameData();
}

void Menu::showFalseStartMessage() {
    lcd.clear();
    lcd.setCursor(0, 0);   //Set cursor to character 2 on line 0
    lcd.print("! FALSE START !");
}

void Menu::handleMenu() {
    int isUpButtonPressed = digitalRead(BUTTON_UP_PIN);
    int isDownButtonPressed = digitalRead(BUTTON_DOWN_PIN);
    int isEnterButtonPressed = digitalRead(BUTTON_ENTER_PIN);
    if (!isUpButtonPressed == HIGH) {
        digitalWrite(LED_MENU, HIGH);
        if (optionNumber > 0) {
            optionNumber--;
            displayMenu(optionNumber);
            delay(200);
        }
    }

    if (!isDownButtonPressed == HIGH) {

        digitalWrite(LED_MENU, HIGH);
        if (optionNumber < 3) {
            optionNumber++;
            displayMenu(optionNumber);
            delay(200);
        }
    }

    if (!isEnterButtonPressed == HIGH) {
        switch (optionNumber) {
            case 0: {
                SoundGame soundGame;
                beginGameStart();
                uint16_t finalResult = soundGame.play();
                if (finalResult == 1) {
                    analogWrite(FALSE_START_LED_PIN, 255);
                    analogWrite(VIBRATION_PIN, 255);
                    showFalseStartMessage();
                    delay(1000);
                    digitalWrite(FALSE_START_LED_PIN, LOW);
                    analogWrite(VIBRATION_PIN, 0);
                    this->optionNumber = 0;
                    displayMenu(optionNumber);
                    delay(500);
                } else {
                    showResult(finalResult);
                    //epromController.clearEEPROM();
                    GameData soundGameData;
                    soundGameData.setReflexTime(finalResult);
                    soundGameData.setGameType(0);
                    soundGameData.setDate("19:00:00 10.10.2000");
                    epromController.addGameData(soundGameData);
                    epromController.saveGameData();
                    Serial.println("Dane z eepromController: ");
                    Serial.println(epromController.getGameDataAsString());
                    // Serial.println("");
                    // Serial.println("");

                    // Serial.println("Dane z eeprom: ");      
                    // Deque<GameData> dataRead = Deque<GameData>(5);
                    // GameData testGameData;
                    // String testString;
                    // // for(int i=0;i<23;i++){
                    // //     if (i > 2) {
                    // //         testString += char(EEPROM.read(i));
                    // //     } else {
                    // //         testString += EEPROM.read(i);
                    // //     }
                        
                    // // }
                    
                    // // Serial.println(testString);
                    
                    // testGameData = EEPROM.get(0, testGameData);

                    bool flaga = false;
                    


                    while (!flaga) {
                        if (!digitalRead(BUTTON_ENTER_PIN) == HIGH) {
                            flaga = true;
                        }
                    }

                    this->optionNumber = 0;
                    displayMenu(optionNumber);
                    delay(500);
                }
                break;
            }
            case 1: {
                LedGame ledGame;
                beginGameStart();
                uint16_t finalResult = ledGame.play();
                if (finalResult == 1) {
                    analogWrite(FALSE_START_LED_PIN, 255);
                    analogWrite(VIBRATION_PIN, 255);
                    showFalseStartMessage();
                    delay(1000);
                    digitalWrite(FALSE_START_LED_PIN, LOW);
                    analogWrite(VIBRATION_PIN, 0);
                    this->optionNumber = 1;
                    displayMenu(optionNumber);
                    delay(500);
                } else {
                    GameData ledGameData;
                    ledGameData.setReflexTime(finalResult);
                    ledGameData.setGameType(1);
                    ledGameData.setDate("10.10.2000");
                    epromController.addGameData(ledGameData);
                    epromController.saveGameData();
                    Serial.println("data saved");
                    Serial.println(epromController.getGameDataAsString());
                    showResult(finalResult);
                    bool flaga = false;

                    while (!flaga) {
                        if (!digitalRead(BUTTON_ENTER_PIN) == HIGH) {
                            flaga = true;
                        }
                    }

                    this->optionNumber = 1;
                    displayMenu(optionNumber);
                    delay(500);
            
                }
                break;
            }
            case 2:{
                handleEEPROMClear();
                this->optionNumber = 2;
                displayMenu(optionNumber);
                delay(500);
                break;
            }
            
        }
    }

    digitalWrite(LED_MENU, LOW);
}




    