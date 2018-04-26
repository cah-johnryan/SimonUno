#ifndef LEDDISPLAY_H
#define LEDDISPLAY_H

#include <Arduino.h>
#include "EventTimer.h"
#include "Led.h"
#include "RgbControl.h"

/**
 * Object to control an array of Leds.
 * 
 * @tparam ledCount Number of leds in the display.
 * @tparam leds List of Led objects which this display controls
 */
class LedDisplay {
private:
  static const unsigned int maxLedCount_ = 10;

  const int ledCount_;
  const Led* const leds_;
  const RgbControl& rgbControl_;

  EventTimer timer_;
  Color colorRam_[maxLedCount_];
  int activeLed_ = 0;
  
public:
  /**
   * Constructor for LedDisplay.
   * 
   * @param leds Array of leds to control.
   * @param ledCount Number of leds in the array.
   * @param rgbControl Control which sets the color of the display.
   * @param refreshInterval Time in miliseconds to keep each led lit before switching.
   */
  LedDisplay(const Led* const leds, const int ledCount, const RgbControl& rgbControl, const int refreshInterval);

  /**
   * Initializes the LedDisplay properly setting up GPIO and any internal tacking.
   */
  void begin();
  
  /**
   * Blanks the display so no Leds are on.
   */
  void blank();

  /**
   * Turns on an Led and displays a specified colors.
   */
  void turnLedOn(const int led, const Color& color);

  /**
   * Turns off an Led
   */
  void turnLedOff(const int led);

  /**  
   * Updates the display switching Leds when necessary.  Must be called 
   * faster than refresh interval.
   */
  void update();

  /**
   * Checks the number of leds in this display.
   * 
   * @return Number of leds in the display.
   */
  unsigned int getLedCount() const;
};

#endif /* LEDDISPLAY_H */
