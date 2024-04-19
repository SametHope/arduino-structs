// OUTPUT COMPONENT
struct SH_SingleColoredLED {
  uint8_t pin;
  bool value;

  SH_SingleColoredLED(uint8_t pin)
      : pin(pin), value(false) {
    pinMode(pin, OUTPUT);
  }

  void update(bool value) {
    this->value = value;
    if (value) {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
  }

  void toggle() {
    update(!value);
  }
};