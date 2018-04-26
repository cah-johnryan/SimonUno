#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include "Button.h"
#include "EventTimer.h"

/**
 * Class which scans a collection of buttons and keeps track of the current active button.
 */
class Keyboard {
private:
  const static unsigned int debounceInterval_ = 5; // Amount of time in milliseconds between reading buttons
  const static unsigned int debounceCount_ = 10;   // Number of consequtive consistent reads before we declare a button state change
  const static unsigned int maxButtonCount_ = 10;  // Maximum number of buttons we can keep track of

  const int buttonCount_;  
  const Button* const buttons_;  

  EventTimer timer_;
  bool stateBuffer_[maxButtonCount_][debounceCount_];
  byte stateBufferIndex_;  
  bool buttonState_[maxButtonCount_];

public:
  /**
   * Constructor for creating a keyboard.
   * 
   * @param buttons Pointer to a button array contianing the buttons this keyboard will scan.
   * @param buttonCount Number of buttons in the button array.
   */
  Keyboard(const Button* const buttons, const int buttonCount);

  /**
   * Initializes the keyboard configuring all the buttons for reading.
   */
  void begin() const;

  /**
   * Scans the keyboard for changes.
   */
  void scan();

  /**
   * Returns the currently active button on the keyboard.
   * 
   * @return Pointer to the button which is pressed or NULL if no button is pressed.
   */
  const Button* const buttonPressed() const;
};

#endif /* KEYBOARD_H */
