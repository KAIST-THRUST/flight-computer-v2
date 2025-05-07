#include "Thermocouple.h"
#include "../Config/Config.h"

// K Type Thermocouple for 0 to 1000 degree
const double KTypeThermocoupleHigh::getSensorData(int raw_data) const {
  double v_out = ((double)raw_data / DAQ_ADC_MAX) * 3.3;

  double v_in = v_out * ((VOLTAGE_DIVIDER_R1 + VOLTAGE_DIVIDER_R2) / (double)VOLTAGE_DIVIDER_R2);

  double temperature = map(v_in, 0.0, 5.0, 0.0, 1000.0);
  return temperature;
}

// K Type Thermocouple for -250 to 750 degree
const double KTypeThermocoupleLow::getSensorData(int raw_data) const {
  double v_out = ((double)raw_data / DAQ_ADC_MAX) * 3.3;
  
  double v_in = v_out * ((VOLTAGE_DIVIDER_R1 + VOLTAGE_DIVIDER_R2) / (double)VOLTAGE_DIVIDER_R2);

  double temperature = map(v_in, 0.0, 5.0, -250.0, 750.0);
  return temperature;
}
