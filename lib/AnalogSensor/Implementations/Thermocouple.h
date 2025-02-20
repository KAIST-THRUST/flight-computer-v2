

#pragma once

#include "AnalogSensorTypes.h"


/**
 * @brief A class to read K-type thermocouple sensor using AD8495 amplifier.
 * 
 */
class KTypeThermocouple : public AnalogSensor {
    public:
        KTypeThermocouple(uint8_t pin_num): AnalogSensor(pin_num) {}
        KTypeThermocouple(AnalogSensorMux *mux, uint8_t mux_pin_num)
            : AnalogSensor(mux, mux_pin_num) {}
    
        cosnt double getSensorData(int raw_data) const override;
};