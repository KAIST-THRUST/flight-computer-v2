#pragma once

#include <Arduino.h>
#include <Config.h>

enum class LogType : uint8_t { INFO, WARNING, ERROR, DATA };

enum class LogStream : uint8_t { SERIAL_MAIN, SD_CARD, BOTH };

class LogFormatter {
public:
  size_t formatText(LogType type, uint32_t time, const char *message, char *buffer) {
    // Write timestamp in format HH:MM:SS.mmm.
    uint32_t ms = time % 1000;
    uint32_t seconds = (time / 1000) % 60;
    uint32_t minutes = (time / 60000) % 60;
    uint32_t hours = (time / 3600000);
    int offset = sprintf(buffer, "%02lu:%02lu:%02lu.%03lu ", hours, minutes, seconds, ms);

    // Add a prefix to the message based on the log type.
    switch (type) {
    case LogType::INFO:
      offset += sprintf(buffer + offset, "[info] ");
      break;
    case LogType::WARNING:
      offset += sprintf(buffer + offset, "[warn] ");
      break;
    case LogType::ERROR:
      offset += sprintf(buffer + offset, "[err!] ");
      break;
    case LogType::DATA:
      offset += sprintf(buffer + offset, "[data] ");
      break;
    }

    sprintf(buffer + offset, "%s", message);
    return strlen(buffer);
  }

  size_t formatBinary(LogType type, uint32_t time, const byte *data, size_t size, byte *buffer) {
    byte *offset = buffer;
    // Write the header of the log. It contains log type, timestamp, and size of the body.
    uint8_t type_num = static_cast<uint8_t>(type);
    memcpy(offset, &type_num, sizeof(uint8_t));
    offset += sizeof(uint8_t);
    memcpy(offset, &time, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    memcpy(offset, &size, sizeof(size_t));
    offset += sizeof(size_t);

    // Write the data.
    memcpy(offset, data, size);
    return offset - buffer + size;
  }
};
