#pragma once

#include "defines.h"
#include <Arduino.h>

class GameData
{
private:
    uint8_t gameType;
    uint16_t reflexTime;
    char date[DATETIME_CHAR_ARRAY_SIZE];

public:
    GameData();
    GameData(uint8_t gameType, uint16_t reflexTime, String date);
    /*!
     *  @brief  Sets gameType field value to value of passed parameter.
     *  @param gameType  uint8_t - typ gry
     *                 0 - Sound Game
     *                 1 - LED Game
     *  @returns void
     *  @side effects:
     *          sets gameType field accordingly to game and parameter described above
     * */
    void setGameType(uint8_t gameType);
    /*!
     *  @brief  Returns gameType field value.
     *  @returns uint8_t - gameType field value
     *  @side effects:
     *          none
     * */
    uint8_t getGameType();
    /*!
     *  @brief  Sets reflexTime field to the value of passed parameter.
     *  @param reflexTime  uint16_t - reflex time
     *  @returns void
     *  @side effects:
     *          sets reflexTime field value
     * */
    void setReflexTime(uint16_t reflexTime);
    /*!
     *  @brief  Returns reflexTime field value.
     *  @returns uint16_t - reflexTime field value
     *  @side effects:
     *          none
     * */
    uint16_t getReflexTime();
    /*!
     *  @brief  Sets date field to the value of passed parameter.
     *  @param date  char* - date
     *  @returns void
     *  @side effects:
     *          sets date field value
     * */
    void setDate(char *date);
    /*!
     *  @brief  Returns date field value.
     *  @returns char* - date field value
     *  @side effects:
     *          none
     * */
    char *getDate();
};
