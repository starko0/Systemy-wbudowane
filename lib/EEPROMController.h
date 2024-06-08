#include <Arduino.h>
#include <EEPROM.h>
#include "Deque.h"
#include "GameData.h"

#define QUEUE_MAX_ITEMS 5



class EEPROMController
{
private:
    Deque<GameData> dataToSave = Deque<GameData>(5);

public:
    EEPROMController();
    /*!
     *  @brief Add game data to the queue. If the queue is full (above maxItems), the oldest data is removed.
     *  @param dataToSave GameData object to be added to the queue.
     *  @returns void
     *  @side effects: none
     */
    void addGameData(GameData dataToSave);
    /*!
     *  @brief Save game data to EEPROM from the queue.
     *  @param none
     *  @returns void
     *  @side effects: none
     */
    void saveGameData();
    /*!
     *  @brief Get all game data from the queue.
     *  @param none
     *  @returns Deque<GameData> Game data queue which stores all game data.
     *  @side effects: none
     */
    Deque<GameData> getGameData();
    /*!
     *  @brief Get all game data from the queue and return it as string.
     *  @param none
     *  @returns String which includes all game data.
     *  @side effects: none
     */
    String getGameDataAsString();
    /*!
     *  @brief Clear all EEPROM data.
     *  @param none
     *  @returns void
     *  @side effects: clear EEPROM data (write 0 to all eeprom bytes).
     */
    void clearEEPROM();
    /*!
     *  @brief Clear all game data from the queue (pop all data from the queue).
     *  @param none
     *  @returns void
     *  @side effects: clear game data queue.
     */
    void clearGameData();
    /*!
     *  @brief Print all EEPROM game data (reads eeprom to the size of game data).
     *  @param none
     *  @returns void
     *  @side effects: Prints all EEPROM game data through UART (Serial).
     */
    void printEEPROM();
    /*!
     *  @brief Load game data from EEPROM to the queue.
     *  @param none
     *  @returns void
     *  @side effects: Load game data from EEPROM to the queue.
     */
    void loadDataFromEEPROM();
};
