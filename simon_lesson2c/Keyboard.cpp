#include "Keyboard.h"

Keyboard::Keyboard(const Button* const buttons, const int buttonCount) : 
    buttons_(buttons), 
    buttonCount_((buttonCount < maxButtonCount_) ? buttonCount : maxButtonCount_), 
    timer_(EventTimer(debounceInterval_)) { };
    
void Keyboard::begin() const {
  for (int i = 0; i < buttonCount_; i++) {
    buttons_[i].begin();
  }
}

void Keyboard::scan() {
  // If it has been long enough since last time we checked buttons lets do it again
  if (timer_.hasEventFired()) {
    
    // Read current button state from all the buttons into our state array.
    for (int button = 0; button < buttonCount_; button++) {
      stateBuffer_[button][stateBufferIndex_] = buttons_[button].readState();
    }
    // Increment index so we store the next round of button states in the next location
    stateBufferIndex_++;
    // Loop around and start overwriting the oldest states once we have filled the array
    if (stateBufferIndex_ >= debounceCount_) { stateBufferIndex_ = 0; }

    // Now loop through the buttons to check to see if they have stabalized
    for (int button = 0; button < buttonCount_; button++) {
      // Check to see if all of this buttons readings are the same
      bool consistent = true;
      bool pressed = stateBuffer_[button][0];      
      for (int i=1; consistent && i < debounceCount_; i++) {
        consistent = (pressed == stateBuffer_[button][i]);
      }
      // if they are then update the buttonstate
      if (consistent) {
        buttonState_[button] = pressed;
      }
    }
  }
}   

const Button* const Keyboard::buttonPressed() const {
  // Loop through all buttons and return the first one pressed.
  for (int button = 0; button < buttonCount_; button++) {
    if (buttonState_[button]) { return &buttons_[button]; }
  }
  // If no buttons where pressed then return null.
  return NULL;
}
