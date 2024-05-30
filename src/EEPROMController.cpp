#include "../lib/EEPROMController.h"

EEPROMController::EEPROMController() {
    this->dataToSave = EEPROM.get(0, dataToSave);
}

void EEPROMController::addGameData(GameData dataToSave) {
    if(this->dataToSave.count() == maxitems) {
        this->dataToSave.pop_front();
    }
    this->dataToSave.push_back(dataToSave);
}

void EEPROMController::saveGameData() {
    EEPROM.put(0, this->dataToSave);
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