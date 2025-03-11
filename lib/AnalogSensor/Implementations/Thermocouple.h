/**
 * @file Thermocouple.h
 * @brief A class to read various types of thermocouple sensors.
 *
 */

#pragma once

#include "../AnalogSensorTypes.h"

/**
 * @brief A class to read K-type thermocouple sensor for high temperature range using AD8495
 * amplifier.
 *
 */
class KTypeThermocoupleHigh : public AnalogSensor {
public:
  KTypeThermocoupleHigh(uint8_t pin_num) : AnalogSensor(pin_num) {}
  KTypeThermocoupleHigh(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : AnalogSensor(mux, mux_pin_num) {}

  const double getSensorData(int raw_data) const override;
};

/**
 * @brief A class to read K-type thermocouple sensor for low temperature range using AD8495
 * amplifier.
 *
 */
class KTypeThermocoupleLow : public AnalogSensor {
public:
  KTypeThermocoupleLow(uint8_t pin_num) : AnalogSensor(pin_num) {}
  KTypeThermocoupleLow(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : AnalogSensor(mux, mux_pin_num) {}

  const double getSensorData(int raw_data) const override;
};
