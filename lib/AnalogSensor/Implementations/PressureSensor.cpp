#include "PressureSensor.h"

const double LowRangePressureSensor::getSensorData(int raw_data) const {
  double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
  double current = voltage / 150.0;
  double pressure = map(current, 0.004, 0.020, 0.0, 1000);
  return psi2bar(pressure);
}

const double HighRangePressureSensor::getSensorData(int raw_data) const {
  double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
  double current = voltage / 150.0;
  double pressure = map(current, 0.004, 0.020, 0.0, 2000);
  return psi2bar(pressure);
}
