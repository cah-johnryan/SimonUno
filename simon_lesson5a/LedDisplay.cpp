#include "LedDisplay.h"

LedDisplay::LedDisplay(const Led* const leds, const int ledCount, const RgbControl& rgbControl, const int refreshInterval) : leds_(leds), ledCount_(ledCount), rgbControl_(rgbControl), timer_(EventTimer(refreshInterval)) {};

void LedDisplay::begin() {
  for (int i=0; i<ledCount_; i++) {
    leds_[i].begin();
  }  
}
  
void LedDisplay::blank() {
  for (int i=0; i<ledCount_; i++) {
    colorRam_[i] = COLORS::OFF;
  }
}
  
void LedDisplay::turnLedOn(const int led, const Color& color) {
  colorRam_[led] = color;
}
  
void LedDisplay::turnLedOff(const int led) {
  colorRam_[led] = COLORS::OFF;
}
  
void LedDisplay::update() {
  // If the last led has been turned on for enough time let's move on to the next one.
  if (timer_.hasEventFired()) {
    // First turn the last one off.
    leds_[activeLed_].turnOff();

    // Move the the next led, wrapping around to the first one if necessary
    activeLed_++;
    if (activeLed_ >= ledCount_) {
      activeLed_ = 0;
    }

    // Set the color of the next led and turn it on if it is not off or black.
    rgbControl_.setColor(colorRam_[activeLed_]);
    if (colorRam_[activeLed_] != COLORS::OFF) {
      leds_[activeLed_].turnOn();
    }
  } 
}

unsigned int LedDisplay::getLedCount() const {
  return ledCount_;
}
