#ifndef LED_H
#define LED_H

#include <Arduino.h>

/**
 * Class representing an individual LED which can be turned on or off.
 */
class Led {
private:
  const int pin_;
  
public:
  /**
   * Constructor which takes in the pin number which is used to control the LED.
   * 
   * @param onOffPin Pin used to turn the Led on or off.
   */
  constexpr Led(const int onOffPin) : pin_(onOffPin) {};
  
  /**
   * Configures the LED pin.
   */
  void begin() const {
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, HIGH);
  }

  /**
   * Turns on the LED.
   */
  void turnOn() const {
    digitalWrite(pin_, LOW);
  }

  /**
   * Turns off the LED.
   */
  void turnOff() const {
    digitalWrite(pin_, HIGH);
  }
};

#endif /* LED_H */
