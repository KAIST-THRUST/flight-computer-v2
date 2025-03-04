#include "Logger.h"

bool LogManager::begin() {
  Serial.begin(115200);
  return true;
}

void LogManager::log(LogType type, uint32_t timestamp, const char *message, LogStream stream) {
  formatter->formatText(type, timestamp, message, buffer);
  if (stream == LogStream::SERIAL_MAIN || stream == LogStream::BOTH) {
    Serial.println(buffer);
  }
  if (stream == LogStream::SD_CARD || stream == LogStream::BOTH) {
    // TODO: Implement logging to SD card.
  }
}

void LogManager::logBinary(LogType type, uint32_t timestamp, const byte *data, size_t size,
                           LogStream stream) {
  size_t len = formatter->formatBinary(type, timestamp, data, size, (byte *)buffer);
  if (stream == LogStream::SERIAL_MAIN || stream == LogStream::BOTH) {
    Serial.write((byte *)buffer, len);
  }
  if (stream == LogStream::SD_CARD || stream == LogStream::BOTH) {
    // TODO: Implement logging to SD card.
  }
}

LogManager logger(new LogFormatter());
