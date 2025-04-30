#include "FlowSensor.h"

const double FlowSensorHigh::getSensorData(int raw_data) const {
    double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
    double current = voltage / 150;
    double flowrate = map(current, 0.004, 0.020, 0.0, 3000); // in kg/h
    return flowrate;
}

const double FlowSensorLow::getSensorData(int raw_data) const {
    double voltage = map((double)raw_data, 0, DAQ_ADC_MAX, 0.0, 3.3);
    double current = voltage / 150;
    double flowrate = map(current, 0.004, 0.020, 0.0, 1200); // in kg/h
    return flowrate;
}
