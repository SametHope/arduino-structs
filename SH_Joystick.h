#include "SH_Utility.h"

// INPUT COMPONENT
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
      : xPin(xPin), yPin(yPin), clickPin(clickPin), xMinValue(xMin), xMaxValue(xMax), yMinValue(yMin), yMaxValue(yMax) {
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);
    pinMode(clickPin, INPUT_PULLUP);
  }

  void update() {
    updateX();
    updateY();
    updateClick();
  }

  void updateX() {
    xValue = analogRead(xPin);
    xValue = mapInclusive(xValue, 0, 1023, xMinValue, xMaxValue);
  }

  void updateY() {
    yValue = analogRead(yPin);
    yValue = mapInclusive(yValue, 0, 1023, yMinValue, yMaxValue);
  }

  void updateClick() {
    clickValue = !digitalRead(clickPin);
  }
};
