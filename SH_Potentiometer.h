// INPUT COMPONENT
struct SH_Potentiometer {
  uint8_t pin;
  int value;
  int minValue;
  int maxValue;

  // minVal and maxVal are used to map the 0...1023 input range of the potentiometer inclusively
  SH_Potentiometer(uint8_t pin, int minVal, int maxVal)
    : pin(pin), minValue(minVal), maxValue(maxVal) {
    pinMode(pin, INPUT);
  }

  void update() {
    value = analogRead(pin);
    value = map(value, 0, 1023, minValue, maxValue + 1);
  }
};