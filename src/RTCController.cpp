#include "../lib/RTCController.h"
#include "../lib/defines.h"

#include <Adafruit_BusIO_Register.h>

RTCController::RTCController() {
    //this->rtc.begin();
} 

String RTCController::getCurrentDateAsString() {
    this->rtc.begin();
    DateTime currentDate = this->rtc.now();
    String testStr = currentDate.timestamp(currentDate.TIMESTAMP_FULL);
    testStr.replace("T", " ");
    return testStr;
}
