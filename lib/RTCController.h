#include <RTClib.h>

#define ARRAY_SIZE 20

class RTCController {
    private: 
    RTC_DS3231 rtc;

    public:
    RTCController();
    String getCurrentDateAsString();
} ;