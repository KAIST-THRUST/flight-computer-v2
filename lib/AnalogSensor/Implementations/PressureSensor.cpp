#include "PressureSensor.h"

const double LowRangePressureSensor::getSensorData(int raw_data) const
{
  /* TODO: Implement the conversion from raw data to pressure for the low
  range sensor. */
  double LowRangePressure_result = static_cast<double>(raw_data) / static_cast<double>(DAQ_ADC_MAX) * psi2bar(1000);
  return LowRangePressure_result;
}

const double HighRangePressureSensor::getSensorData(int raw_data) const
{
  /* TODO: Implement the conversion from raw data to pressure for the high
  range sensor. */
  double HighRangePressure_result = static_cast<double>(raw_data) / static_cast<double>(DAQ_ADC_MAX) * psi2bar(2000);
  return HighRangePressure_result;
}
