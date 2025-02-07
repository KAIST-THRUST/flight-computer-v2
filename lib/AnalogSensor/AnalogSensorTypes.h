/**
 * @file AnalogSensorTypes.h
 * @brief Data structures for representing analog sensors and MUXs.
 *
 */

#pragma once

#include <Arduino.h>
#include <Config.h>

#define MAX_NUM_OF_SENSORS DAQ_NUM_OF_SENSORS
#define DEFAULT_ADC_RESOLUTION DAQ_ADC_RESOLUTION

/**
 * @brief A data structure that represents an analog sensor multiplexer.
 * @details This class is used to control the CD74HC4067 multiplexer.
 *
 */
class AnalogSensorMux {
private:
  const uint8_t s0_pin; // Digital control pin 0.
  const uint8_t s1_pin; // Digital control pin 1.
  const uint8_t s2_pin; // Digital control pin 2.
  const uint8_t s3_pin; // Digital control pin 3.

public:
  const uint8_t sig_pin; // Analog signal pin.

  AnalogSensorMux(uint8_t sig_pin, uint8_t s0_pin, uint8_t s1_pin,
                  uint8_t s2_pin, uint8_t s3_pin)
      : s0_pin(s0_pin), s1_pin(s1_pin), s2_pin(s2_pin), s3_pin(s3_pin),
        sig_pin(sig_pin) {}

  void begin() const {
    pinMode(s0_pin, OUTPUT);
    pinMode(s1_pin, OUTPUT);
    pinMode(s2_pin, OUTPUT);
    pinMode(s3_pin, OUTPUT);

    digitalWriteFast(s0_pin, LOW);
    digitalWriteFast(s1_pin, LOW);
    digitalWriteFast(s2_pin, LOW);
    digitalWriteFast(s3_pin, LOW);
  }

  /**
   * @brief Set the MUX channel.
   *
   * @param channel Channel number (0-15).
   * @warning begin() must be called before using this function.
   */
  void setChannel(uint8_t channel) const {
    digitalWriteFast(s0_pin, bitRead(channel, 0));
    digitalWriteFast(s1_pin, bitRead(channel, 1));
    digitalWriteFast(s2_pin, bitRead(channel, 2));
    digitalWriteFast(s3_pin, bitRead(channel, 3));
    delayNanoseconds(6); // Minimum delay required for the MUX to settle.
  }
};

/**
 * @brief A data structure that represents an analog sensor.
 *
 * Inherit from this class and implement getSensorData method.
 */
class AnalogSensor {
public:
  /* Analog pin number of the sensor.
  If the sensor is connected to a MUX, it is the pin number of the MUX. */
  const uint8_t pin_num;

  /* Channel number connected to the MUX.
  If the sensor is not connected to a MUX, it is set to 255. */
  const uint8_t mux_pin_num;

  /* Pointer to the MUX object.
  If the sensor is not connected to a MUX, it is set to nullptr. */
  const AnalogSensorMux *mux;

  // Constructor for the sensor not connected to a MUX.
  AnalogSensor(uint8_t pin_num)
      : pin_num(pin_num), mux_pin_num(255), mux(nullptr) {}

  // Constructor for the sensor connected to a MUX.
  AnalogSensor(AnalogSensorMux *mux, uint8_t mux_pin_num)
      : pin_num(mux->sig_pin), mux_pin_num(mux_pin_num), mux(mux) {}

  virtual ~AnalogSensor() {}

  /**
   * @brief Convert the raw sensor data to a meaningful value.
   *
   * @param raw_data The raw sensor data.
   * @return The converted sensor value.
   */
  virtual double getSensorData(int raw_data) = 0;
};
