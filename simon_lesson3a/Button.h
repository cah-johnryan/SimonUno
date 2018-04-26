#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * Object to read a button input asigned to a given color.  Button should be connected so
 * when the button is pushed it is connected to ground.
 */
class Button {
private:
  const int pin_;
  const int id_;

public:
  /**
   * Constructor which takes in the pin number which is used to control the button.
   * 
   * @param pin Digital pin this button is connected to.
   * @param id Numeric id for this button.
   */
  constexpr Button(const int pin, const int id) : pin_(pin), id_(id)  {};

  /**
   * Configures the button pin.
   */
  void begin() const;

  /**
   * Reads the current state of this button.
   * 
   * @return True if the button is pressed.
   */
  bool readState() const;

  int getId() const;
};

#endif /* BUTTON_H */
