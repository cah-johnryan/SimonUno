/* Code as it looks at the end of lesson 4. */
#include "Animator.h"
#include "FlashAnimation.h"
#include "Keyboard.h"
#include "LedDisplay.h"
#include "PiezoBuzzer.h"

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
constexpr Led led0(13);   // Led1 is controlled by pin 13
constexpr Led led1(12);   // Led2 is controlled by pin 12
constexpr Led led2( 7);   // Led3 is controlled by pin 7
constexpr Led led3( 5);   // Led4 is controlled by pin 5

const int ledCount = 4;  // We have 4 leds in totoal
constexpr Led ledList[ledCount] = {led0, led1, led2, led3}; // Array of our led objects used to control the display

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);
RgbControl  rgbControl(11,10,9);
Keyboard    keyboard(buttonList, buttonCount);
LedDisplay  ledDisplay(ledList, ledCount, rgbControl, 4);
Animator    animator(ledDisplay);

const Button*  lastPressed = NULL;
FlashAnimation redBlink(COLORS::RED, 4, 250, 100);

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  // Initialize the buzzer so it can be used.
  buzzer.begin();
  rgbControl.begin();
  keyboard.begin();
  ledDisplay.begin();
}

void loop() {
  animator.update();
  ledDisplay.update();
  keyboard.scan();
  if (!animator.isActive()) {
    const Button* pressed = keyboard.buttonPressed();
    if (pressed != lastPressed) {
      lastPressed = pressed;
      if (pressed) {
        animator.playAnimation(redBlink);
      }
    }
  }
}
