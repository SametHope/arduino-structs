// Digital Output Component
// - `write(bool value)`: Sets the LED state to the specified value.
// - `toggle()`: Toggles the LED state between ON and OFF.
struct SH_SingleColoredLED {
  uint8_t pin;
  bool value;

  SH_SingleColoredLED(uint8_t pin)
      : pin(pin), value(false) {
    pinMode(pin, OUTPUT);
  }

  void write(bool value) {
    this->value = value;
    if (value) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }

  void toggle() {
    write(!value);
  }
};