#include "Animator.h"

Animator::Animator(LedDisplay& ledDisplay) : ledDisplay_(ledDisplay), timer_(EventTimer(1000)), activeAnimation_(NULL) {}

void Animator::displayAnimationFrame() {
  for(unsigned int i = 0; i < ledDisplay_.getLedCount(); i++) {
    ledDisplay_.turnLedOn(i, activeAnimation_->getFrameLedColor(i));
  }
  timer_.setInterval(activeAnimation_->getFrameInterval());
}

void Animator::update() {
  if (activeAnimation_ != NULL && timer_.hasEventFired()) {
    if (activeAnimation_->nextFrame()) {
      displayAnimationFrame();
    } else {
      ledDisplay_.blank();
      activeAnimation_ = NULL;
    }
  }
}

bool Animator::isActive() {
  return activeAnimation_ != NULL;
}

void Animator::playAnimation(Animation& animation) {
  activeAnimation_ = &animation;
  animation.reset();
  displayAnimationFrame();  
}

