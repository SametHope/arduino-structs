#include "SH_Utility.h"

// Analog Input Component
// Takes in min and max values on constructor to map the input range of 0...1023 to, inclusively.
// - `read()`: Updates and returns the mapped value of the potentiometer within the specified range.
struct SH_Potentiometer {
  uint8_t pin;
  int value;
  int minValue;
  int maxValue;

  SH_Potentiometer(uint8_t pin, int minVal, int maxVal)
      : pin(pin), minValue(minVal), maxValue(maxVal) {
    pinMode(pin, INPUT);
  }

  int read() {
    value = analogRead(pin);
    value = mapInclusive(value, 0, 1024, minValue, maxValue);
    return value;
  }
};