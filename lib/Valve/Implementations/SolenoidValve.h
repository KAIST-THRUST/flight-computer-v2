/**
 * @file SolenoidValve.h
 * @brief A class for controlling a solenoid valve.
 * 
 */

#pragma once

#include <Arduino.h>
#include <Config.h>

/**
 * @brief A data structure that represents a solenoid valve.
 * @details This class is used to control a [model name] solenoid valve.
 *
 */
class SolenoidValve {
private:
  const uint8_t pin_num; // Digital pin number connected.

public:
  SolenoidValve(uint8_t pin_num) : pin_num(pin_num) {}

  void begin() const {
    pinMode(pin_num, OUTPUT);
    digitalWriteFast(pin_num, LOW);
  }

  void open() const { digitalWriteFast(pin_num, HIGH); }

  void close() const { digitalWriteFast(pin_num, LOW); }
};
