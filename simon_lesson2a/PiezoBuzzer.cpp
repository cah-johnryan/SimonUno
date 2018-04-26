#include "PiezoBuzzer.h"

void PiezoBuzzer::begin() const {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void PiezoBuzzer::turnOn() const {
  digitalWrite(pin_, HIGH);
}

void PiezoBuzzer::turnOff() const {
  digitalWrite(pin_, LOW);
}
