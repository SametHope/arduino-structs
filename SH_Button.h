// INPUT COMPONENT
struct SH_Button {
  uint8_t pin;
  bool value;

  SH_Button(uint8_t pin)
      : pin(pin), value(false) {
    pinMode(pin, INPUT_PULLUP);
  }

  void update() {
    value = !digitalRead(pin);
  }
};
