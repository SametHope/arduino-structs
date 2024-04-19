// OUTPUT COMPONENT
struct SH_Buzzer {
  uint8_t pin;
  unsigned int value;

  SH_Buzzer(uint8_t pin)
      : pin(pin), value(0) {
    pinMode(pin, OUTPUT);
  }

  // Calls tone(pin, freq), set freq 0 for noTone()
  void update(unsigned int freq) {
    if (freq == 0)
      noTone(pin);
    else
      tone(pin, freq);
  }
};