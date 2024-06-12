#include <stdint.h>

#include <inttypes.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "../lib/EEPROMController.h"
#include "../lib/RTCController.h"
#include "../lib/defines.h"

#define MENU_SIZE 6

class Menu
{
private:
    String menuTitle;

public:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
    EEPROMController epromController;
    RTCController rtcController;
    Menu();
    String menuOptions[MENU_SIZE];
    uint8_t optionNumber;
    /*!
     *  @brief Choose number from the range. Handles user decision
     *  @param int minValue - minimum value of the range
     *  @param int maxValue - maximum value of the range
     *  @param String message - message to be displayed
     *  @returns int - number chosen by user
     *  @side effects:
     */
    int chooseNumber(int minValue, int maxValue, String message);

    /*!
     *  @brief Using millis to wait certain given time.
     *  @param uint16_t delayTime - time to wait in milliseconds
     *  @returns void
     *  @side effects: waits given time in millieseconds
     */
    void timerDelay(uint16_t delayTime);
    /*!
     *  @brief Displays menu on the LCD.
     *  @param uint8_t optionNumber - number of option to be displayed
     *  @returns void
     *  @side effects: displays menu option on the LCD which number is given as parameter
     */
    void displayMenu(uint8_t optionNumber);

    /*!
     *  @brief Handles all menu options and their actions.
     *  @returns void
     *  @side effects: It handles all menu options and their actions (games and data access/saving).
     */
    void handleMenu();

    /*!
     * @brief Displays starting menu action when starting the game.
     * @returns void
     * @side effects: displays menu title on the LCD
     *  */
    void beginGameStart();

    /*!
     * @brief Displays menu action when game is finished (displays reaction time in millieseconds).
     * @returns void
     * @side effects: Displays menu action when game is finished (displays reaction time in millieseconds)
     */
    void showResult(uint16_t result);
    /*!
     * @brief Displays falsestart action when user fails waiting for signal.
     * @returns void
     * @side effects: Displays falsestart action when user fails waiting for signal.
     *
     */

    void showFalseStartMessage();

    /*!
     * @brief Handles display when user choosed to clear EEPROM data.
     * @returns void
     * @side effects: Handles display when user choosed to clear EEPROM data (displays Clearing... message)
     *                while there is clearing of EEPROM data.
     */
    void handleEEPROMClear();
};