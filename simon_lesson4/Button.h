#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "Color.h"

/**
 * Object to read a button input asigned to a given color.  Button should be connected so
 * when the button is pushed it is connected to ground.
 */
class Button {
private:
  const int pin_;
  const int id_;
  const Color color_;

public:
  /**
   * Constructor which takes in the pin number which is used to control the button.
   * 
   * @param pin Digital pin this button is connected to.
   * @param id Numeric id for this button.
   * @param color Color that this button represents in game.
   */
  constexpr Button(const int pin, const int id, const Color& color) : pin_(pin), id_(id), color_(color)  {};

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

  /**
   * Reads the id assocaited with this button.
   * 
   * @return Id for this button.
   */
  int getId() const;

  /**
   * Reads the color associated with this button.
   * 
   * @return Color for this button.
   */
  const Color& getColor() const;
};

#endif /* BUTTON_H */
