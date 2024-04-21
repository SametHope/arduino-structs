#include "SH_Utility.h"

// Analog Input Component
// Takes in min and max values on constructor to map the input with.
// - `read(unsigned int readAmount = 1)`: Reads input `readAmount` times and returns the mapped value of the median.
struct SH_Potentiometer {
  uint8_t pin;
  int value;
  int valueRaw;
  int minValue;
  int maxValue;

  SH_Potentiometer(uint8_t pin, int minVal, int maxVal)
      : pin(pin), minValue(minVal), maxValue(maxVal) {
    pinMode(pin, INPUT);
  }

  int read(unsigned int readAmount = 1) {
    // Take readAmount samples
    int samples[readAmount];
    for (int i = 0; i < readAmount; i++) {
      samples[i] = analogRead(pin);
    }

    // Selection Sort
    for (int i = 0; i < readAmount - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < readAmount; j++) {
        if (samples[j] < samples[minIndex]) {
          minIndex = j;
        }
      }
      if (minIndex != i) {
        int temp = samples[i];
        samples[i] = samples[minIndex];
        samples[minIndex] = temp;
      }
    }

    valueRaw = samples[readAmount / 2];
    value = map(valueRaw, 0, 1023, minValue, maxValue);

    return value;
  }
};