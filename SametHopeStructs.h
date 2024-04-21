// This header file contains links to headers of data structures for some components with basic functionalities
// It is also viable to include headers individually
// All logic is on header files as they are easier to manage and pretty compact anyway
// Common properties of the structures:
// - Data structures are prefixed with SH_
// - Data structures and the files they are declared on have matching names
// - Data structures have documentation of their functions on the data structures definition
// - Data structures take required pins as parameters on declaration
// - Data structures store their own state
// - Data structures setup their pin modes on declaration
// - State/variables of the data structures should not be modified directly but with existing functions
// Input components:
// - SH_X.read() will update the values on the component and return the processed input if any
// Output components:
// - SH_X.write(newValue) must be called to update the state/value of the component
// Exceptions:
// - There are cases specific values may perform special actions which are commented/documented on structs definitions

#include "SH_Button.h"
#include "SH_Buzzer.h"
#include "SH_Joystick.h"
#include "SH_MultiColoredLED.h"
#include "SH_Potentiometer.h"
#include "SH_SingleColoredLed.h"
#include "SH_Switch.h"
#include "SH_UltrasonicSensor.h"
