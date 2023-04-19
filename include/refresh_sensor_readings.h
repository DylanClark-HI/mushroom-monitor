#ifndef SENSOR_READINGS_H
    #define SENSOR_READINGS_H

#include <DHT.h>

// Defining sensor settings
const int DATA_INPUT_PIN = 13; // Data returned from the digital sensors will be read with pin 13
const int LDR_PIN = A0;            // LDR sensor is connected to Analog pin A0
#define DHTTYPE DHT11          // Using a DHT11 sensor

extern DHT dht;

void refreshReadings();

#endif