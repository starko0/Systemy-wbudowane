#include "../lib/EEPROMController.h"


EEPROMController::EEPROMController() {
    loadDataFromEEPROM();
}

void EEPROMController::addGameData(GameData dataToSave) {
    if(this->dataToSave.count() == maxitems) {
        this->dataToSave.pop_front();
    }
    this->dataToSave.push_back(dataToSave);
}

void EEPROMController::saveGameData() {
    uint8_t index = 0;
    for (int i = 0; i < this->dataToSave.count() ; i++) {
        EEPROM.put(index, this->dataToSave[i]);
        index += sizeof(GameData)-1;
    }
    this->printEEPROM();
    Serial.println(this->dataToSave.count());

}

Deque<GameData> EEPROMController::getGameData() {
    return this->dataToSave;
}

String EEPROMController::getGameDataAsString() {
    String data = "";
    for(int i = 0; i < this->dataToSave.count(); i++) {
        char* currDate = this->dataToSave[i].getDate();
        data += "Game Type: " + String(this->dataToSave[i].getGameType()) + " Reflex Time: " + String(this->dataToSave[i].getReflexTime()) + " Date: " + currDate + "\n";
        delete[] currDate;
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

void EEPROMController::printEEPROM() {
    for (size_t i = 0; i < sizeof(GameData) * 5; i++)
    {
        Serial.print("Index: ");
        Serial.print(i);
        Serial.print(" Value: ");
        Serial.println(EEPROM.read(i));
    }
}
void EEPROMController::loadDataFromEEPROM()
{
    uint8_t index = 0;
    for (int i = 0; i < maxitems; i++) {
        this->dataToSave.push_back(EEPROM.get(index, dataToSave[0]));
        index += sizeof(GameData)-1;
    }
}