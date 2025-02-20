#include "Thermocouple.h"


//K Type Thermocouple 
const double KTypeThermocouple::getSensorData(int raw_data) const {
    const double voltage = (raw_data / DAQ_ADC_MAX) * 5.0;
    const double temperature = (voltage - 1.25) / 0.005;
    return temperature
}