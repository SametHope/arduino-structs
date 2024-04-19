// This header file contains links to headers of data structures for some components with basic functionalities
// It is also viable to include headers individually
// All logic is on header files as they are easier to manage and pretty compact anyway
// Common properties of the structures:
// - Data structures are prefixed with SH_
// - Data structures and the files they are declared on have matching names
// - Data structures take required pins as input on declaration
// - Data structures store their own state
// - Data structures initialise their pins on declaration
// - State/variables of the data structures must not be modified directly but with functions
// Input components:
// - SH_X.value is used to read the cached value of the components
// - SH_X.update() must be called to update the state/value of the component
// Output components:
// - SH_X.value is used to read the cached value of the components
// - SH_X.update(newValue) must be called to update the state/vale of the component
// Exceptions:
// - SH_X.update(newValue) may have custom behaviours at certain values, those are likely commented
// - Some data structures may have extra parameters on declarations which are also likely commented
// - Some data structures such as joystick may store their value on different variables as they have multiple

#include "SH_Buzzer.h"
#include "SH_Joystick.h"
#include "SH_Potentiometer.h"
#include "SH_SingleColoredLed.h"
#include "SH_Switch.h"
#include "SH_UltrasonicSensor.h"
