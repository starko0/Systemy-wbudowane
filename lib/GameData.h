#pragma once

#include "defines.h"
#include <Arduino.h>

class GameData {
private :
    uint8_t gameType;
    uint16_t reflexTime;
    char date[DATETIME_CHAR_ARRAY_SIZE];

public:
    GameData();

    GameData(uint8_t gameType, uint16_t reflexTime, String date);

    uint8_t getGameType();

    uint16_t getReflexTime();

    void setReflexTime(uint16_t reflexTime);

    void setGameType(uint8_t gameType);

    void setDate(char *date);

    char *getDate();
};
