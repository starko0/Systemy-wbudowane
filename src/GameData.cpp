#include "Arduino.h"
#include "../lib/GameData.h"

void GameData::setGameType(uint8_t gameType) {
    this->gameType = gameType;
}

uint8_t GameData::getGameType() {
    return gameType;
}

void GameData::setReflexTime(uint16_t reflexTime) {
    this->reflexTime = reflexTime;
}

uint16_t GameData::getReflexTime() {
    return reflexTime;
}

void GameData::setDate(char *date) {
    for (int i = 0; i < 20; i++) {
        this->date[i] = date[i];
    }
}

char *GameData::getDate() {
    char *currDate = new char[DATETIME_CHAR_ARRAY_SIZE];
    for (size_t i = 0; i < DATETIME_CHAR_ARRAY_SIZE; i++) {
        currDate[i] = date[i];
    }

    return currDate;
}

GameData::GameData() {
    this->gameType = 0;
    this->reflexTime = 0;
    strcpy(this->date, "19:00:00 10.10.2000");
}

GameData::GameData(uint8_t gameType, uint16_t reflexTime, String date) {
    this->gameType = gameType;
    this->reflexTime = reflexTime;
    strcpy(this->date, date.c_str());
}
