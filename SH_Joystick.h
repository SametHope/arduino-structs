#include "SH_Utility.h"

// Analog and Digital Input Component
// Takes in min and max values for x and y on constructor to map their the input range of 0...1023 to.
// - `read()`: Updates x, y, and click values.
// - `readX()`: Reads and returns x-axis value.
// - `readY()`: Reads and returns y-axis value.
// - `readClick()`: Reads and returns click state.
struct SH_Joystick {
  uint8_t xPin;
  uint8_t yPin;
  uint8_t clickPin;

  int xValue;
  int yValue;
  bool clickValue;

  int xMinValue;
  int xMaxValue;

  int yMinValue;
  int yMaxValue;

  // Map both x and y axis 0...1023 values to provided mins and max inclusively
  SH_Joystick(uint8_t xPin, uint8_t yPin, uint8_t clickPin, int xMin, int xMax, int yMin, int yMax)
      : xPin(xPin), yPin(yPin), clickPin(clickPin), xValue(0), yValue(0), clickValue(false), xMinValue(xMin), xMaxValue(xMax), yMinValue(yMin), yMaxValue(yMax) {
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(clickPin, INPUT_PULLUP);
  }

  void read() {
    readX();
    readY();
    readClick();
  }

  int readX() {
    xValue = analogRead(xPin);
    xValue = mapInclusive(xValue, 0, 1024, xMinValue, xMaxValue);
    return xValue;
  }

  int readY() {
    yValue = analogRead(yPin);
    yValue = mapInclusive(yValue, 0, 1024, yMinValue, yMaxValue);
    return yValue;
  }

  bool readClick() {
    clickValue = !digitalRead(clickPin);
    return clickValue;
  }
};
