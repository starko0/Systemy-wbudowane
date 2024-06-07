#include <RTClib.h>

#include <Adafruit_BusIO_Register.h>

#define ARRAY_SIZE 20

class RTCController {
private:
    RTC_DS3231 rtc;

public:
    RTCController();

    bool setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute);

    bool autoSetDateTime();

    String getCurrentDateTimeAsString();

    String getCurrentTimeAsString();

    String getCurrentDateAsString();
};