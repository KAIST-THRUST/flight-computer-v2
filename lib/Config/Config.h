/**
 * @file Config.h
 * @brief File containing main configurations of the project.
 *
 */

#pragma once

/* DAQ System configurations. */
constexpr unsigned int DAQ_NUM_OF_SENSORS = 25; // Maximum number of sensors connected.
constexpr unsigned int DAQ_NUM_OF_MUXS = 2;     // Maximum number of MUXs connected.
constexpr unsigned int DAQ_ADC_RESOLUTION = 12; // ADC resolution in bits.
constexpr unsigned int MAX_MESSAGE_SIZE = 256;  // Maximum size of a log message.

/* DAQ Circuit related configurations. */
constexpr unsigned int VOLTAGE_DIVIDER_R1 = 10000; // Voltage divider resistor 1 in Ohms.
constexpr unsigned int VOLTAGE_DIVIDER_R2 = 10000; // Voltage divider resistor 2 in Ohms.
constexpr unsigned int VOLTAGE_DIVIDER_R4 = 10000; // Voltage divider input voltage in Volts.

// Derived constants
constexpr unsigned int DAQ_ADC_MAX = (1U << DAQ_ADC_RESOLUTION) - 1; // Maximum value of ADC.
