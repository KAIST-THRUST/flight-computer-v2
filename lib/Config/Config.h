/**
 * @file Config.h
 * @brief File containing main configurations of the project.
 *
 */

#pragma once

#define DAQ_NUM_OF_SENSORS 25 // Maximum number of sensors connected.
#define DAQ_NUM_OF_MUXS 2     // Maximum number of MUXs connected.
#define DAQ_ADC_RESOLUTION 12 // ADC resolution in bits.

#define DAQ_ADC_MAX ((1<<(DAQ_ADC_RESOLUTION)) - 1) // Maximum value of DAQ