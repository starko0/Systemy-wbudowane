#pragma once

#include "defines.h"
#include <Arduino.h>

class GameData {
    private :
    uint8_t gameType;
    uint16_t reflexTime;
    char date [MAX_CHAR_ARRAY_SIZE];
    
    public:
    GameData();
    GameData(uint8_t gameType, uint16_t reflexTime,String date);
    void setGameType(uint8_t gameType);
    uint8_t getGameType();
    void setReflexTime(uint16_t reflexTime);
    uint16_t getReflexTime();
    void setDate(char* date);
    char* getDate();
};
