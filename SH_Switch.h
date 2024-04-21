// Digital Input Component
// - `read()` Updates and returns click state.
// - Works identical to `SH_Button`.
struct SH_Switch {
  uint8_t pin;
  bool value;

  SH_Switch(uint8_t pin)
      : pin(pin), value(false) {
    pinMode(pin, INPUT_PULLUP);
  }

  bool read() {
    value = !digitalRead(pin);
    return value;
  }
};
