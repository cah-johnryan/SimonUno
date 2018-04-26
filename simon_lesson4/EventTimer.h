#ifndef EVENTTIMER_H
#define EVENTTIMER_H

#include <Arduino.h>

/**
 * EventTimer object which can be used to execute code at regular intervals.  
 * Accuracy is dependant on how often hasEventFired is called.
 * 
 * @tparam interval Time between events firing in milliseconds.  This is a template parameter in order to allow static construction of event timers inside other objects.
 */
class EventTimer {
private:
  unsigned long interval;
  unsigned long nextFire;

public:
  EventTimer(unsigned long interval);

  /**
   * Checks to see if enough time has that the event should be executed.  Timer
   * will automatically be reset once fire has been ready.
   * 
   * @return True if event has fired.
   */
  bool hasEventFired();

  /**
   * Resets the timer to fire after the interval from this moment.
   */
  void reset();

  /**
   * Sets a new interval and resets the timer.
   */
  void setInterval(unsigned long interval);
};

#endif /* EVENTTIMER_H */
