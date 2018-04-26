#ifndef SIMON_PATTERN_H
#define SIMON_PATTERN_H

#include <Arduino.h>
#include "Color.h"

/**
 * Random pattern generator for a simon game.
 */
class SimonPattern {
public:
  static const unsigned int MAX_PATTERN_LENGTH = 20;

private:
  const unsigned int colorCount_;
  const Color* const colorList_;

  Color pattern_[MAX_PATTERN_LENGTH];
  unsigned int patternSize_;

public:
  /**
   * Creates a simon pattern with a given list of colors as options
   */
  SimonPattern(const Color* const colorList, const unsigned int colorCount);

  /**
   * Clears the current pattern out and starts a new pattern.
   */
  void clear();

  /**
   * Adds a new step to the pattern.
   * 
   * @return True if successful, false if pattern is already at it's max size
   */
  bool addStep();

  /**
   * Checks how many steps are in the current pattern.
   * 
   * @return Number of steps in the pattern.
   */
  const unsigned int getSize() const;

  /**
   * Fetches the color for a given step in the pattern.
   * 
   * @param step Step to fetch the color for.
   * @retrun Color for the given step.
   */
  const Color& getStepColor(const unsigned int step) const;
};

#endif /* SIMON_PATTERN_H */
