// OUTPUT COMPONENT
struct SH_MultiColoredLED {
  uint8_t redPin;
  uint8_t greenPin;
  uint8_t bluePin;

  uint8_t redValue;
  uint8_t greenValue;
  uint8_t blueValue;

  SH_MultiColoredLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
      : redPin(redPin), greenPin(greenPin), bluePin(bluePin) {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
  }

  void update(uint8_t red, uint8_t green, uint8_t blue) {
    updateRed(red);
    updateGreen(green);
    updateBlue(blue);
  }

  void updateRed(uint8_t value) {
    redValue = value;
    analogWrite(redPin, value);
  }

  void updateGreen(uint8_t value) {
    greenValue = value;
    analogWrite(greenPin, value);
  }

  void updateBlue(uint8_t value) {
    blueValue = value;
    analogWrite(bluePin, value);
  }
};