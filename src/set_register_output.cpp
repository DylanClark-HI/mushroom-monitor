#include <set_register_output.h>

void setShiftRegister(byte OUTPUTS)
{
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_OUT_PIN, CLOCK_PIN, MSBFIRST, OUTPUTS);
    digitalWrite(LATCH_PIN, HIGH);
}