#include "EventTimer.h"

EventTimer::EventTimer(unsigned long interval) : interval_(interval), nextFire_(millis() + interval) {};

bool EventTimer::hasEventFired() {
  unsigned long current = millis();
  if (((int32_t)(current - nextFire_) >= 0)) {
    nextFire_ = millis() + interval_;
    return true;
  } else {
    return false;
  }
}

void EventTimer::reset() {
  nextFire_ = millis() + interval_;
}

void EventTimer::setInterval(unsigned long interval) {
  this->interval_ = interval;
  reset();
}
