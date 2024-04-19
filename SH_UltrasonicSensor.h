// INPUT COMPONENT
struct SH_UltrasonicSensor {
  uint8_t trigPin;
  uint8_t echoPin;
  unsigned long duration;
  int value; // Distance in cm

  SH_UltrasonicSensor(uint8_t trig, uint8_t echo)
      : trigPin(trig), echoPin(echo), duration(0), value(0) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  void update() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    // formula for distance in cm
    value = (duration / 2) / 29.1;
  }

  // Performs multiple update(), filters values > 1198 and returns the average, returns 1200 on invalid values or on divide by zero
  void updateAccurate(unsigned int accuracy = 3) {
    int sum = 0;
    int fails = 0;
    for (int i = 0; i < accuracy; i++) {
      update();
      if (value > 1198)
        fails++;
      else
        sum += value;
    }

    if (accuracy - fails <= 0) {
      value = 1200;
    } else {
      value = int(float(sum) / float(accuracy - fails));
    }
  }
};