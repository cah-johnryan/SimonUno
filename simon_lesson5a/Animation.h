#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>

#include "Color.h"

/**
 * Abstract class defining the interface for animation objects.
 */
class Animation {

public:
  /**
   * Resets the animation to the begining.
   */
  virtual void reset() = 0;

  /**
   * Advances the animation to the next frame.
   * 
   * @return True if successful, false if there are no more frames.
   */
  virtual const bool nextFrame() = 0;

  /**
   * Gets the display color for a given led for the current frame.
   * 
   * @param led Ordinal position of the led in the array
   * @return Color to set the display to.
   */
  virtual const Color& getFrameLedColor(unsigned int led) = 0;

  /**
   * Gets the length of time to display the current frame in milliseconds.
   */
  virtual const unsigned int getFrameInterval() = 0;
};

#endif /* ANIMATION_H */
