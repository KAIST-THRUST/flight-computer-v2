#include "PressureSensor.h"
#include "../Config/Config.h"

const double LowRangePressureSensor::getSensorData(int raw_data) const {
  double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
  double current = voltage / VOLTAGE_DIVIDER_R4;;
  double pressure = map(current, 0.004, 0.020, 0.0, 1000);
  return psi2bar(pressure);
}

const double HighRangePressureSensor::getSensorData(int raw_data) const {
  double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
  double current = voltage / VOLTAGE_DIVIDER_R4;;
  double pressure = map(current, 0.004, 0.020, 0.0, 2000);
  return psi2bar(pressure);
}


/* 

  flow R4

  pressure R4

  thermo R1 + R2. but read from R1


*/