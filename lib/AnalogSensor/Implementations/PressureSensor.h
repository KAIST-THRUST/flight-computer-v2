/**
 * @file PressureSensor.h
 * @brief Classes for reading pressure sensor data for multiple sensors
 * with different pressure ranges.
 *
 */

#pragma once

#include "../AnalogSensorTypes.h"
#include <Config.h>
#include <Utils.h>

/**
 * @brief A class to read pressure sensor data with low range.
 * 
 * @note This class controls the M325M-000005-01KPG pressure sensor.
 */
class LowRangePressureSensor : public AnalogSensor {
public:
  LowRangePressureSensor(uint8_t pin_num) : AnalogSensor(pin_num) {}
  LowRangePressureSensor(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : AnalogSensor(mux, mux_pin_num) {}

  const double getSensorData(int raw_data) const override;
};

/**
 * @brief A class to read pressure sensor data with high range.
 * 
 * @note This class controls the MLH02KPSP01B pressure sensor.
 */
class HighRangePressureSensor : public AnalogSensor {
public:
  HighRangePressureSensor(uint8_t pin_num) : AnalogSensor(pin_num) {}
  HighRangePressureSensor(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : AnalogSensor(mux, mux_pin_num) {}

  const double getSensorData(int raw_data) const override;
};
