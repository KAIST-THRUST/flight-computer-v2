#pragma once

#include <Arduino.h>
#include <Config.h>

enum class CommandType : uint8_t {
  BALL_VALVE_CONTROL,
  SOLENOID_VALVE_CONTROL,
  EMERGENCY_STOP,
  NUM_OF_COMMANDS // Number of commands.
};

struct Command {
  bool is_valid;    // Indicates if the command is valid or not.
  CommandType type; // Type of the command.

  /* Id number of the valve. */
  int valve_id;

  /* For BALL_VALVE_CONTROL command, this will be the angle of the valve.
     For SOLENOID_VALVE_CONTROL command, this will be either 1 or 0, each indicating open/close. */
  int valve_position;
};

constexpr size_t COMMAND_MESSAGE_SIZE = sizeof(CommandType) + 2 * sizeof(int);

class CommandParser {
private:
public:
  CommandParser() {}

  /**
   * @brief Parse the command from the binary message.
   *
   * @param message The message to parse.
   * @return Parsed command.
   */
  Command parse(const char *message);
};
