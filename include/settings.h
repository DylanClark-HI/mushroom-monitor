#ifndef SETTINGS_H
    #define SETTINGS_H

    // Defining Shift Register settings
    const int LATCH_PIN = 4;    // Latch pin of 74HC595 is connected to Digital pin 4
    const int CLOCK_PIN = 5;    // Clock pin of 74HC595 is connected to Digital pin 5
    const int DATA_OUT_PIN = 0; // Data Out pin of 74HC595 is connected to Digital pin 0

    // Defining sensor settings
    const int DATA_INPUT_PIN = 13; // Data returned from the digital sensors will be read with pin 13
    #define LDR_PIN A0;            // LDR sensor is connected to Analog pin A0
    #define DHTTYPE DHT11          // Using a DHT11 sensor

#endif