#include "../lib/RTCController.h"
#include "../lib/defines.h"

#include <Adafruit_BusIO_Register.h>

RTCController::RTCController() = default;

bool RTCController::setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute) {
    DateTime dateTime(year, month, day, hour, minute, 0);

    if (this->rtc.begin()) {
        rtc.adjust(dateTime);
        return true;
    };

    return false;
}

bool RTCController::autoSetDateTime() {
    if (this->rtc.begin()) {
        if (this->rtc.begin()) {
            this->rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
            return true;
        }
    }
    return false;
}


String RTCController::getCurrentDateTimeAsString() {
    if (this->rtc.begin()) {
        DateTime currentDate = this->rtc.now();
        String testStr = currentDate.timestamp(DateTime::TIMESTAMP_FULL);
        testStr.replace("T", " ");
        return testStr;
    }
    return "00-00-0000 00:00:00";
}

String RTCController::getCurrentTimeAsString() {
    if (this->rtc.begin()) {
        String timeString = this->rtc.now().timestamp(this->rtc.now().TIMESTAMP_TIME);
        return timeString;
    }
    return "00:00:00";

}

String RTCController::getCurrentDateAsString() {
    if (this->rtc.begin()) {
        String dateString = this->rtc.now().timestamp(this->rtc.now().TIMESTAMP_DATE);
        return dateString;
    }
    return "00-00-0000";
}