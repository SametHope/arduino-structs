#include "SH_Utility.h"

// Analog and Digital Input Component
// Takes in min and max values for x and y on constructor to map the input with.
// - `read()`: Updates x, y, and click values.
// - `readX()`: Updates and returns x-axis value.
// - `readY()`: Updates and returns y-axis value.
// - `readClick()`: Updates and returns click state.
struct SH_Joystick {
  uint8_t xPin;
  uint8_t yPin;
  uint8_t clickPin;

  int xValue;
  int xValueRaw;
  int yValue;
  int yValueRaw;
  bool clickValue;

  int xMinValue;
  int xMaxValue;

  int yMinValue;
  int yMaxValue;

  SH_Joystick(uint8_t xPin, uint8_t yPin, uint8_t clickPin, int xMin, int xMax, int yMin, int yMax)
      : xPin(xPin), yPin(yPin), clickPin(clickPin), xMinValue(xMin), xMaxValue(xMax), yMinValue(yMin), yMaxValue(yMax) {
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
    xValueRaw = analogRead(xPin);
    xValue = map(xValueRaw, 0, 1023, xMinValue, xMaxValue);
    return xValue;
  }

  int readY() {
    yValueRaw = analogRead(yPin);
    yValue = map(yValueRaw, 0, 1023, yMinValue, yMaxValue);
    return yValue;
  }

  bool readClick() {
    clickValue = !digitalRead(clickPin);
    return clickValue;
  }
};
