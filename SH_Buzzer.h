// Digital Output Component
// - `write(uint16_t frequency)`: Sets the buzzer to the specified frequency. Pass `0` to silence the buzzer.
// - `silence()`: Stops the buzzer sound.
struct SH_Buzzer {
  uint8_t pin;
  uint16_t value;

  SH_Buzzer(uint8_t pin)
      : pin(pin), value(0) {
    pinMode(pin, OUTPUT);
  }

  void write(uint16_t frequency) {
    value = frequency;
    if (frequency != 0) {
      tone(pin, frequency);
    } else {
      silence();
    }
  }

  void silence() {
    noTone(pin);
  }
};