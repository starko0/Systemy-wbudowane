#include <Arduino.h>
#include <EEPROM.h>
#include "Deque.h"
#include "GameData.h"

#define QUEUE_MAX_ITEMS 5

class EEPROMController {
private:
    Deque<GameData> dataToSave = Deque<GameData>(QUEUE_MAX_ITEMS);

public:
    EEPROMController();

    String getGameDataAsString();

    void addGameData(GameData gameDataToSave);

    void saveGameData();

    void clearEEPROM();

    void clearGameData();

    void printEEPROM();

    void loadDataFromEEPROM();
};

