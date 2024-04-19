#ifndef SH_Utility
#define SH_Utility

long mapInclusive(long x, long in_min, long in_max, long out_min, long out_max) {
  // Ensure x is within the input range
  x = constrain(x, in_min, in_max);

  // Calculate the mapped value inclusively
  return ((x - in_min) * (out_max - out_min + 1)) / (in_max - in_min + 1) + out_min;
}

#endif