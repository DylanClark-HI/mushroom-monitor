#ifndef TIME_KEEPING_H
    #define TIME_KEEPING_H

    #include <RTClib.h>

extern RTC_DS1307 rtc;

void refreshTime();

#endif