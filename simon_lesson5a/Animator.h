#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Arduino.h>
#include "Animation.h"
#include "EventTimer.h"
#include "LedDisplay.h"

/**
 * Object which plays animations on an LedDisplay.
 */
class Animator {
private:
  LedDisplay& ledDisplay_;
  Animation* activeAnimation_;
  EventTimer timer_;

  /**
   * Private function to display the current animation frame.
   */
  void displayAnimationFrame();

public:
  /**
   * Creates a new animator.
   * 
   * @param ledDisplay Display object where animation will be displayed.
   */
  Animator(LedDisplay& ledDisplay);

  /**
   * Update the animation.  Checks to see if it's time to display a new frame and
   * sends new frame to the display if necessary.
   */
  void update();

  /**
   * Checks to see if an animation is in progress.
   * 
   * @return True if an animation is playing, false if animation is finished.
   */
  bool isActive();

  /**
   * Plays a given animation on the display.  Animations are held
   * by reference and must be available during the lifetime of the 
   * animation.
   * 
   * @param Animation object to play on the display.
   */
  void playAnimation(Animation& animation);
};

#endif /* ANIMATOR_H */
