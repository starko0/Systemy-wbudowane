#include <Arduino.h>
#include <EEPROM.h>
#include "Deque.h"
#include "GameData.h"

class EEPROMController {
    private:
    const uint8_t maxitems = 5;
    Deque<GameData> dataToSave = Deque<GameData>(5);

    public:
    EEPROMController();
    void addGameData(GameData dataToSave);
    void saveGameData();
    Deque<GameData> getGameData();
    String getGameDataAsString();
    void clearEEPROM();
    void clearGameData();
    void printEEPROM();
    void loadDataFromEEPROM();
};

