// Analog Input Component
// - `read()`: Updates and returns the distance value (in cm) based on the sensor readings.
// - `readAccurate(unsigned int accuracy = 3)`: Reads multiple times, filters values, and returns the average distance (in cm). Returns 1200 on invalid values or divide by zero.
struct SH_UltrasonicSensor {
  uint8_t trigPin;
  uint8_t echoPin;
  unsigned long duration;
  // Distance in cm
  int value;

  SH_UltrasonicSensor(uint8_t trigPin, uint8_t echoPin)
      : trigPin(trigPin), echoPin(echoPin), duration(0), value(0) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  int read() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    // formula for distance in cm
    value = (duration / 2) / 29.1;

    return value;
  }

  // Performs multiple update(), filters values > 1198 and returns the average, returns 1200 on invalid values or on divide by zero
  int readAccurate(unsigned int accuracy = 3) {
    int sum = 0;
    int fails = 0;
    for (int i = 0; i < accuracy; i++) {
      read();
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

    return value;
  }
};