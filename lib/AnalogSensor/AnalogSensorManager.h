/**
 * @file AnalogSensorManager.h
 * @brief A class that manages multiple analog sensors synchronously.
 *
 */

#pragma once

#include "AnalogSensorTypes.h"
#include <ADC.h>
#include <Config.h>

constexpr size_t MAX_NUM_OF_SENSORS = DAQ_NUM_OF_SENSORS;
constexpr size_t DEFAULT_ADC_RESOLUTION = DAQ_ADC_RESOLUTION;

/**
 * @brief A class to manage and synchronize readings from multiple analog
 * sensors.
 *
 */
class AnalogSensorManager {
private:
  // Array of pointers to sensors.
  AnalogSensor *sensors[MAX_NUM_OF_SENSORS];

  // Array to store sensor data values.
  double sensor_data[MAX_NUM_OF_SENSORS];

  // Array for A0 sensor indices.
  int group_a0[MAX_NUM_OF_SENSORS];

  // Array for A1 sensor indices.
  int group_a1[MAX_NUM_OF_SENSORS];

  ADC *adc;
  uint8_t num_of_sensors;
  uint8_t num_of_a0_sensor;
  uint8_t num_of_a1_sensor;

  bool isA0Sensor(AnalogSensor *sensor) const;
  bool isA1Sensor(AnalogSensor *sensor) const;
  bool isA0A1Sensor(AnalogSensor *sensor) const;
  bool isInGroupA0(AnalogSensor *sensor) const;
  bool isInGroupA1(AnalogSensor *sensor) const;

  /**
   * @brief Sets the multiplexer channel if necessary.
   * @param sensor Pointer to sensor.
   */
  void setMuxIfNeeded(AnalogSensor *sensor) const;

public:
  AnalogSensorManager();

  /**
   * @brief Adds a sensor to the manager.
   * @param sensor Pointer to the sensor to add.
   * @return true if sensor was added successfully.
   */
  bool addSensor(AnalogSensor *sensor);

  /**
   * @brief Initializes the ADC configurations.
   */
  void begin();

  /**
   * @brief Reads and updates sensor data for all managed sensors.
   */
  void updateSensorData();

  /**
   * @brief Retrieves the latest sensor data.
   * @return Pointer to an array of sensor data doubles.
   */
  const double *getSensorData() const { return sensor_data; }
};
