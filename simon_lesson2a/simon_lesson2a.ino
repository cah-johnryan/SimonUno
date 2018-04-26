/* Code as it looks at the end of lesson 2a. */

#include "Button.h"
#include "PiezoBuzzer.h"

/*
 * Define all buttons.
 */
constexpr Button redButton(18);

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);

bool lastPressed = false;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  // Initialize the buzzer so it can be used.
  buzzer.begin();
  redButton.begin();
}

void loop() {
  bool pressed = redButton.readState();
  if (pressed != lastPressed) {
    lastPressed = pressed;
    if (pressed) {
      Serial.println("Button Pressed");
      buzzer.turnOn();
    } else {
      Serial.println("Button Released");
      buzzer.turnOff();      
    }
  }
}
