#include "PressureSensor.h"

const double LowRangePressureSensor::getSensorData(int raw_data) const {
  /* TODO: Implement the conversion from raw data to pressure for the low
  range sensor. */
  double LowRangePressureSensor_result = 0;
  int scope = power(2, DAQ_ADC_RESOLUTION)-1;
  LowRangePressureSensor_result=raw_data*(70/scope);
  return LowRangePressureSensor_result;
}

const double HighRangePressureSensor::getSensorData(int raw_data) const {
  /* TODO: Implement the conversion from raw data to pressure for the high
  range sensor. */
  double HighRangePressureSensor_result = 0;
  int scope = power(2, DAQ_ADC_RESOLUTION)-1;
  HighRangePressureSensor_result=raw_data*(138/scope);
  return HighRangePressureSensor_result;
}
