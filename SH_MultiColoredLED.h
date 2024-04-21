// Analog Output Component
// - `write(uint8_t red, uint8_t green, uint8_t blue)`: Sets the RGB values for the LED.
// - `writeRed(uint8_t value)`: Sets the red component of the LED.
// - `writeGreen(uint8_t value)`: Sets the green component of the LED.
// - `writeBlue(uint8_t value)`: Sets the blue component of the LED.
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

  void write(uint8_t red, uint8_t green, uint8_t blue) {
    writeRed(red);
    writeGreen(green);
    writeBlue(blue);
  }

  void writeRed(uint8_t value) {
    redValue = value;
    analogWrite(redPin, value);
  }

  void writeGreen(uint8_t value) {
    greenValue = value;
    analogWrite(greenPin, value);
  }

  void writeBlue(uint8_t value) {
    blueValue = value;
    analogWrite(bluePin, value);
  }
};