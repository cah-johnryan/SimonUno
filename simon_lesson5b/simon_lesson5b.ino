/* Code as it looks at the end of lesson 5. */
#include "Animator.h"
#include "FlashAnimation.h"
#include "Keyboard.h"
#include "LedDisplay.h"
#include "PatternAnimation.h"
#include "PiezoBuzzer.h"
#include "SimonGame.h"

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

const int colorCount = 4;
constexpr Color colorList[colorCount] = {COLORS::RED, COLORS::GREEN, COLORS::BLUE, COLORS::YELLOW};

/*
 * Setup game sub-systems
 */
PiezoBuzzer buzzer(19);
RgbControl  rgbControl(11,10,9);
Keyboard    keyboard(buttonList, buttonCount);
LedDisplay  ledDisplay(ledList, ledCount, rgbControl, 4);
Animator    animator(ledDisplay);
SimonGame   game(colorList, colorCount);

PatternAnimation  patternAnimation(game.getPattern(), buttonList, buttonCount);
FlashAnimation    successGameAnimation(COLORS::GREEN, 2, 100, 100);
FlashAnimation    failGameAnimation(COLORS::RED, 4, 300, 150);
FlashAnimation    gameCompleteAnimation(COLORS::GREEN, 6, 300, 50); 

const Button*    lastButton = NULL;

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
  ledDisplay.update();
  keyboard.scan();
  
  const Button* const button = keyboard.buttonPressed();
  if (lastButton != button) {
    lastButton = button;
    if (button != NULL) {
      game.buttonPressed(button->getColor());      
    }
  }

  switch(game.getState()) {
    case SimonGame::DISPLAY_PATTERN:
      animator.playAnimation(patternAnimation);
      break;
    
    case SimonGame::GAME_FAILED:
      animator.playAnimation(failGameAnimation);
      break;

    case SimonGame::ROUND_SUCCESS:
      animator.playAnimation(successGameAnimation);
      break;

    case SimonGame::GAME_SUCCESS:
      animator.playAnimation(gameCompleteAnimation);
      break;
  }

  while (animator.isActive()) {
    animator.update();
    ledDisplay.update();
  }  
}
