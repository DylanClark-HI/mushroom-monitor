#ifndef SENSOR_READINGS_H
    #define SENSOR_READINGS_H

#include <settings.h>
#include <DHT.h>

DHT dht(DATA_INPUT_PIN, DHTTYPE);

void refreshReadings(DHT dht);

#endif