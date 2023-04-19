#ifndef TIME_KEEPING_H
    #define TIME_KEEPING_H

    #include <RTClib.h>
    #include <settings.h>

RTC_DS1307 rtc;

void refreshTime(RTC_DS1307 rtc);

#endif