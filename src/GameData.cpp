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

void GameData::setDate(String date) {
    this->date = date;
}

String GameData::getDate() {
    return date;
}

GameData::GameData() {
    this->gameType = 0;
    this->reflexTime = 0;
    this->date = "";
}

GameData::GameData(uint8_t gameType, uint16_t reflexTime, String date) {
    this->gameType = gameType;
    this->reflexTime = reflexTime;
    this->date = date;
}
