/**
 * @file FlowSensor.h
 * @brief A class to read various types of flow sensors.
 *
 */

#pragma once

#include "../AnalogSensorTypes.h"

/**
 * @brief A class to read flow sensor for rate of fluid movement
 * using the larger flow meter - 15 DN
 *
 */
class FlowSensorHigh : public AnalogSensor {
public:
  FlowSensorHigh(uint8_t pin_num) : AnalogSensor(pin_num) {}
  FlowSensorHigh(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : AnalogSensor(mux, mux_pin_num) {}

  const double getSensorData(int raw_data) const override;
};

/**
 * @brief A class to read flow sensor for rate of fluid movement
 * using the smaller flow meter - 6 DN
 *
 */
class FlowSensorLow : public AnalogSensor {
  public:
    FlowSensorLow(uint8_t pin_num) : AnalogSensor(pin_num) {}
    FlowSensorLow(AnalogSensorMux *mux, uint8_t mux_pin_num)
        : AnalogSensor(mux, mux_pin_num) {}
  
    const double getSensorData(int raw_data) const override;
  };
  
