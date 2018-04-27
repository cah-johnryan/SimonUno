#include "Keyboard.h"

Keyboard::Keyboard(const Button* const buttons, const int buttonCount) : 
    buttons_(buttons), 
    buttonCount_((buttonCount < maxButtonCount_) ? buttonCount : maxButtonCount_)
    { };
    
void Keyboard::begin() const {
  for (int i = 0; i < buttonCount_; i++) {
    buttons_[i].begin();
  }
}

void Keyboard::scan() {  
  // Read current button state from all the buttons into our state array.
  for (int button = 0; button < buttonCount_; button++) {
    buttonState_[button] = buttons_[button].readState();
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
