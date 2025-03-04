/**
 * @file Logger.h
 * @brief The header file that contains the LogManager class and the global logger object.
 *
 */

#pragma once
#include <Arduino.h>
#include <Config.h>
#include <LogFormatter.h>

class LogManager {
private:
  LogFormatter *formatter;
  char buffer[MAX_MESSAGE_SIZE];
  // TODO: Implement ring buffer.

public:
  LogManager(LogFormatter *formatter) : formatter(formatter) {}

  bool begin();

  /**
   * @brief Log a message in text format.
   *
   * @param type The type of the log message.
   * @param timestamp The timestamp of the log message in milliseconds.
   * @param message The message to log in string format.
   * @param stream The stream to log the message to. Currently only supports SERIAL_MAIN.
   */
  void log(LogType type, uint32_t timestamp, const char *message, LogStream stream);

  /**
   * @brief Log a message in text format. The timestamp is set to the current time.
   *
   * @param type The type of the log message.
   * @param message The message to log in string format.
   * @param stream The stream to log the message to. Currently only supports SERIAL_MAIN.
   */
  void log(LogType type, const char *message, LogStream stream) {
    log(type, millis(), message, stream);
  }

  /**
   * @brief Log a message in text format into the main serial stream.
   * The timestamp is set to the current time.
   *
   * @param type The type of the log message.
   * @param message The message to log in string format.
   */
  void log(LogType type, const char *message) {
    log(type, millis(), message, LogStream::SERIAL_MAIN);
  }

  /**
   * @brief Log a data type message.
   *
   * @param timestamp The timestamp of the log message in milliseconds.
   * @param data The data to log in string format.
   * @param stream The stream to log the message to. Currently only supports SERIAL_MAIN.
   */
  void logData(uint32_t timestamp, const char *data, LogStream stream) {
    log(LogType::DATA, timestamp, data, stream);
  }

  /**
   * @brief Log in binary format.
   *
   * @param type The type of the log message.
   * @param timestamp The timestamp of the log message in milliseconds.
   * @param data The data to log in binary format.
   * @param size The size of the data.
   * @param stream The stream to log the message to. Currently only supports SERIAL_MAIN.
   */
  void logBinary(LogType type, uint32_t timestamp, const byte *data, size_t size, LogStream stream);
};

extern LogManager logger;
