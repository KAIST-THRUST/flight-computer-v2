#include "Thermocouple.h"

// K Type Thermocouple
const double KTypeThermocouple::getSensorData(int raw_data) const {
  double voltage = ((double)raw_data / DAQ_ADC_MAX) * 3.3;
  double temperature = map(voltage, 0.0, 3.3, 0.0, 1000.0);
  return temperature;
}
