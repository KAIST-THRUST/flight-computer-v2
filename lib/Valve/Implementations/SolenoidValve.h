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
  bool is_open;          // Whether the valve is open or not.

public:
  SolenoidValve(uint8_t pin_num) : pin_num(pin_num), is_open(0) {}

  void begin() const {
    pinMode(pin_num, OUTPUT);
    digitalWriteFast(pin_num, LOW);
  }

  void open() {
    digitalWriteFast(pin_num, HIGH);
    is_open = true;
  }

  void close() {
    digitalWriteFast(pin_num, LOW);
    is_open = false;
  }

  bool isOpen() const { return is_open; }
};
