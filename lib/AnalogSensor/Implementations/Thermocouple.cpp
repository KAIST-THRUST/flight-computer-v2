#include "Thermocouple.h"

// K Type Thermocouple for 0 to 1000 degree
const double KTypeThermocoupleHigh::getSensorData(int raw_data) const {
  double voltage = ((double)raw_data / DAQ_ADC_MAX) * 3.3;
  voltage *= 2; // Calibration
  double temperature = map(voltage, 0.0, 5.0, 0.0, 1000.0);
  return temperature;
}

// K Type Thermocouple for -250 to 750 degree
const double KTypeThermocoupleLow::getSensorData(int raw_data) const {
  double voltage = ((double)raw_data / DAQ_ADC_MAX) * 3.3;
  voltage *= 2; // Calibration
  double temperature = map(voltage, 0.0, 5.0, -250.0, 750.0);
  return temperature;
}
