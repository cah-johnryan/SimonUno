#include "EventTimer.h"

EventTimer::EventTimer(unsigned long interval) : interval(interval), nextFire(millis() + interval) {};

bool EventTimer::hasEventFired() {
  unsigned long current = millis();
  if (((int32_t)(current - nextFire) >= 0)) {
    nextFire = millis() + interval;
    return true;
  } else {
    return false;
  }
}

void EventTimer::reset() {
  nextFire = millis() + interval;
}

void EventTimer::setInterval(unsigned long interval) {
  this->interval = interval;
  reset();
}
