/* Code as it looks at the end of lesson 2b. */

#include "Button.h"
#include "Keyboard.h"
#include "PiezoBuzzer.h"

/*
 * Define all buttons.
 */
constexpr Button redButton(18, 0);
constexpr Button greenButton(8, 1);
constexpr Button blueButton(6, 2);
constexpr Button yellowButton(4, 3);

const int buttonCount = 4;
constexpr Button buttonList[buttonCount] = {redButton, greenButton, blueButton, yellowButton};

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);
Keyboard keyboard(buttonList, buttonCount);

const Button* lastPressed = NULL;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  // Initialize the buzzer so it can be used.
  buzzer.begin();
  keyboard.begin();
}

void loop() {
  keyboard.scan();
  const Button* pressed = keyboard.buttonPressed();
  if (pressed != lastPressed) {
    if (lastPressed != NULL) {
      Serial.println("Released");
      buzzer.turnOff();
    }
    lastPressed = pressed;
    if (pressed) {
      Serial.print("Button ");
      Serial.print(pressed->getId(), DEC);
      Serial.print(" Pressed - ");
      buzzer.turnOn();
    }
  }
}
