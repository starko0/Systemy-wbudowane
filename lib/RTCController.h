#include <RTClib.h>

#include <Adafruit_BusIO_Register.h>

#define ARRAY_SIZE 20

class RTCController
{
private:
    RTC_DS3231 rtc;

public:
    RTCController();

    /*!
     *  @brief Sets date and time to the value of passed parameters.
     *  @param year  uint16_t - year (e.g. 2020)
     *  @param month  uint8_t - month (1-12)
     *  @param day  uint8_t - day (1-31)
     *  @param hour  uint8_t - hour (0-23)
     *  @param minute  uint8_t - minute (0-59)
     *  @returns true if RTC is initialized and date and time were set, false otherwise.
     *  @side effects:
     */
    bool setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute);

    /*!
     *  @brief Automatically sets date and time to the current time.
     *  @returns true if RTC is initialized and date and time were set, false otherwise.
     *  @side effects: sets date and time to the current time (start of arduino program)
     */
    bool autoSetDateTime();

    /*!
     *  @brief Returns date and time as a string.
     *  @returns String or "00-00-0000 00:00:00" if RTC is not initialized.
     *  @side effects: none
     */
    String getCurrentDateTimeAsString();

    /*!
     *  @brief Returns time as a string.
     *  @returns String, or "00:00:00" if RTC is not initialized.
     *  @side effects: none
     */
    String getCurrentTimeAsString();

    /*!
     *  @brief Returns date as a string.
     *  @returns String or "00-00-0000" if RTC is not initialized.
     *  @side effects: none
     */

    String getCurrentDateAsString();
};