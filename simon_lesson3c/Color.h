#ifndef COLOR_H
#define COLOR_H

#include <Arduino.h>

/**
 * Class to represent a color to be displayed on an led.
 */
class Color {
private:
  byte red_;
  byte green_;
  byte blue_;

public:
  /**
   * Default constrcutor to create a Off/Black color.
   */
  constexpr Color() : red_(0), green_(0), blue_(0) {};

  /**
   * Constructor to represent an RGB color value.
   */
  constexpr Color(byte red, byte green, byte blue) : red_(red), green_(green), blue_(blue) {};

  /**
   * Method to retreive the red vale for this color.
   */
  inline byte red() const {
    return red_;
  }
  
  /**
   * Method to retreive the green vale for this color.
   */
  inline byte green() const {
    return green_;
  }

  /**
   * Method to retreive the blue vale for this color.
   */
  inline byte blue() const {
    return blue_;
  }

  /**
   * Assignment operator to allow setting color values.
   */
  Color & operator=(const Color &rhs) {
    if (this != &rhs) {
      red_ = rhs.red_;
      green_ = rhs.green_;
      blue_ = rhs.blue_;
    }
    return *this;
  }

  /**
   * Equality operator to check to see if two color objects contain the same color
   */
  bool operator==(const Color &other) const {
    return (red_ == other.red_) && (blue_ == other.blue_) && (green_ == other.green_);
  }
  
  /**
   * Inequailty operator to check to see if two color objects contain different colors.
   */
  bool operator!=(const Color &other) const {
    return !(*this == other);
  }
};

/**
 * Namespace including common colors.
 */
namespace COLORS {
  constexpr Color OFF       = Color(  0,   0,   0);
  constexpr Color BLACK     = Color(  0,   0,   0);
  constexpr Color RED       = Color(128,   0,   0);
  constexpr Color GREEN     = Color(  0, 128,   0);
  constexpr Color BLUE      = Color(  0,   0, 128);
  constexpr Color YELLOW    = Color(128, 128,   0);
  constexpr Color PURPLE    = Color(128,   0, 128);
  constexpr Color BLUEGREEN = Color(  0, 196,  76);
  constexpr Color WHITE     = Color(128, 128,  76);
}

#endif // COLOR_H
