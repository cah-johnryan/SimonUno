/* Code as it looks at the end of lesson 3b. */

#include "Button.h"
#include "Keyboard.h"
#include "Led.h"
#include "PiezoBuzzer.h"
#include "RgbControl.h"

/*
 * Define all buttons.
 */
constexpr Button redButton(18, 0, COLORS::RED);
constexpr Button greenButton(8, 1, COLORS::GREEN);
constexpr Button blueButton(6, 2, COLORS::BLUE);
constexpr Button yellowButton(4, 3, COLORS::YELLOW);

const int buttonCount = 4;
constexpr Button buttonList[buttonCount] = {redButton, greenButton, blueButton, yellowButton};

/*
 * Define all of our display leds.
 */
constexpr Led led0(13);   // Led0 is controlled by pin 13
constexpr Led led1(12);   // Led1 is controlled by pin 12
constexpr Led led2( 7);   // Led2 is controlled by pin 7
constexpr Led led3( 5);   // Led3 is controlled by pin 5

const int ledCount = 4;  // We have 4 leds in totoal
constexpr Led ledList[ledCount] = {led0, led1, led2, led3}; // Array of our led objects used to control the display

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);
RgbControl rgbControl(11,10,9);
Keyboard keyboard(buttonList, buttonCount);

const Button* lastPressed = NULL;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  // Initialize the buzzer so it can be used.
  buzzer.begin();
  rgbControl.begin();
  keyboard.begin();
  
  // Initialize LEDs
  led0.begin();
  led1.begin();
  led2.begin();
  led3.begin();
}

void loop() {
  keyboard.scan();
  const Button* pressed = keyboard.buttonPressed();
  if (pressed != lastPressed) {
    if (lastPressed != NULL) {
      Serial.println("Released");
      buzzer.turnOff();
      ledList[lastPressed->getId()].turnOff();
    }
    lastPressed = pressed;
    if (pressed) {
      Serial.print("Button ");
      Serial.print(pressed->getId(), DEC);
      Serial.print(" Pressed - ");
      rgbControl.setColor(pressed->getColor());
      ledList[pressed->getId()].turnOn();
      buzzer.turnOn();
    }
  }
}
