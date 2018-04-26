/* Code as it looks at the end of lesson 1. */

#include "PiezoBuzzer.h"

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);

constexpr byte BEEP_COUNT = 5;
byte beeps_sounded = 0;

void setup() {
  // Initialize the buzzer so it can be used.
  buzzer.begin();
}

void loop() {
  // If we have not beeped enough yet beep again
  if (beeps_sounded < BEEP_COUNT) {
    // Turn on buzzer
    buzzer.turnOn();
    // Leave buzzer on for 250 milliseconds
    delay(250);
    buzzer.turnOff();
    // Wait for half a second before we go on
    delay(500);
    // Increment the number of beeps we have sounded.
    beeps_sounded++;
  }
}
