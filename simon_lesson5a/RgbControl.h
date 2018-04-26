#ifndef RGBCONTROL_H
#define RGBCONTROL_H

#include <Arduino.h>

#include "Color.h"

/**
 * Controller for setting color for an RGB led.
 */
class RgbControl {
private:
  const int redPin_;
  const int greenPin_;
  const int bluePin_;

public:
  /**
   * 
   */
  constexpr RgbControl(const int redPin, const int greenPin, const int bluePin) : redPin_(redPin), greenPin_(greenPin), bluePin_(bluePin) {};

  /**
   * Initializes the RGB 
   */
  void begin() const {
    pinMode(redPin_, OUTPUT);
    pinMode(greenPin_, OUTPUT);
    pinMode(bluePin_, OUTPUT);
    setColor(COLORS::OFF);
  }

  /**
   * Sets the color of the RGB otuput.
   */
  void setColor(const Color &color) const {
    analogWrite(redPin_, color.red());
    analogWrite(greenPin_, color.green());
    analogWrite(bluePin_, color.blue());
  }
};

#endif /* RGBCONTROL_H */
