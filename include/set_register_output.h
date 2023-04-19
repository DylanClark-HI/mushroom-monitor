#ifndef SET_REGISTER_H
#define SET_REGISTER_H

#include <settings.h>
#include <Arduino.h>

byte OUTPUTS = 0; // A variable to store the sequence of what outputs we want active on the shift registers

void setShiftRegister(byte OUTPUTS);

#endif