#ifndef PEIZOBUZZER_H
#define PEIZOBUZZER_H

#include <Arduino.h>

/**
 * Class to control a piezo buzzer.
 */
class PiezoBuzzer {
private:
  const int pin_;

public:
  /**
   * Creates a new PiezoBuzzer class.
   * 
   * @param pin Digital pin number of the pin which is connected to the positive side of the buzzer.
   */
  constexpr PiezoBuzzer(const int pin) : pin_(pin) {};

  /**
   * Initializies the buzzer IO pins.
   */
  void begin() const;

  /**
   * Turns on the buzzer.
   */
  void turnOn() const;

  /**
   * Turns off the buzzer.
   */
  void turnOff() const;
};

#endif // PEIZOBUZZER_H
