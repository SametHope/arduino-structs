// Digital Output Component
// - `writeDigital(bool value)`: Sets the LED state to the specified value (no PWM).
// - `writeAnalog(uint8_t value)`: Sets the LED state to the specified value (PWM).
// - `toggleDigital()`: Toggles the LED state between ON and OFF (no PWM).
struct SH_SingleColoredLED {
  uint8_t pin;
  uint8_t value;

  SH_SingleColoredLED(uint8_t pin)
      : pin(pin) {
    pinMode(pin, OUTPUT);
  }

  void writeDigital(bool value) {
    this->value = value;
    digitalWrite(pin, value);
  }

  void writeAnalog(uint8_t value) {
    this->value = value;
    analogWrite(pin, value);
  }

  void toggleDigital() {
    writeDigital(!value);
  }
};