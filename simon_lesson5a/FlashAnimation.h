#ifndef FLASH_ANIMATION_H
#define FLASH_ANIMATION_H

#include <Arduino.h>
#include "Animation.h"

/**
 * Animates the display by flashing all the leds with a single color.
 */
class FlashAnimation : public Animation {
private:
  typedef enum {
    LED_ON,
    LED_OFF,
    FINAL_DELAY
  } FlashState;

  const Color color_;
  const unsigned int flashCount_;
  const unsigned int onTime_;
  const unsigned int offTime_;

  unsigned int displayedCount_;
  FlashState state_;

public:
  /**
   * Creates a flash animation for a given color count and timings.
   */
  FlashAnimation(const Color& color, unsigned int flashCount, unsigned int onTime, unsigned int offTime);

  // Standard Animiation methods (see Animation.h)
  void reset();
  const bool nextFrame();
  const Color& getFrameLedColor(unsigned int led);
  const unsigned int getFrameInterval();    
};

#endif /* PATTERN_ANIMATION_H */
