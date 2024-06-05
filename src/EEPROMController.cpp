#include "../lib/EEPROMController.h"

EEPROMController::EEPROMController() {
    uint8_t index = 0;
    for (int i = 0; i < maxitems; i++) {
        this->dataToSave.push_back(EEPROM.get(index, dataToSave[0]));
        index += sizeof(GameData)-1;
    }
}

void EEPROMController::addGameData(GameData dataToSave) {
    if(this->dataToSave.count() == maxitems) {
        this->dataToSave.pop_front();
    }
    this->dataToSave.push_back(dataToSave);
}

void EEPROMController::saveGameData() {
    uint8_t index = 0;
    for (int i = 0; i < this->dataToSave.count(); i++) {
        EEPROM.put(index, this->dataToSave[i]);
        index += sizeof(GameData)-1;
    }

}

Deque<GameData> EEPROMController::getGameData() {
    return this->dataToSave;
}

String EEPROMController::getGameDataAsString() {
    String data = "";
    for(int i = 0; i < this->dataToSave.count(); i++) {
        data += "Game Type: " + String(this->dataToSave[i].getGameType()) + " Reflex Time: " + String(this->dataToSave[i].getReflexTime()) + " Date: " + this->dataToSave[i].getDate() + "\n";
    }
    return data;
}

void EEPROMController::clearEEPROM() {
    for(int i=0; i<EEPROM.length(); i++ ) {
        EEPROM.write(i, 0);
    }
}

void EEPROMController::clearGameData() {
    this->dataToSave.clear();
}