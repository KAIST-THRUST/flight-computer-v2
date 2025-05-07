#include "CommandParser.h"

Command CommandParser::parse(const char *message) {
  Command current_command = {false, CommandType::NUM_OF_COMMANDS, -1, -1};
  CommandType type;
  char *offset = (char *)message;
  int valve_id, valve_position;

  // Fetch the command type.
  memcpy(&type, offset, sizeof(CommandType));
  offset += sizeof(CommandType);
  if (static_cast<uint8_t>(type) >= static_cast<uint8_t>(CommandType::NUM_OF_COMMANDS)) {
    current_command.is_valid = false; // Invalid command type.
    return current_command;
  }
  current_command.type = type;

  // Parse the command based on the type.
  switch (type) {
  case CommandType::EMERGENCY_STOP:
    current_command.valve_id = -1;       // No valve id for emergency stop.
    current_command.valve_position = -1; // No valve position for emergency stop.
    break;

  case CommandType::BALL_VALVE_CONTROL:
  case CommandType::SOLENOID_VALVE_CONTROL: {
    memcpy(&valve_id, offset, sizeof(int));
    offset += sizeof(int);
    if (valve_id < 0) {
      current_command.is_valid = false; // Invalid valve id.
      return current_command;
    }
    current_command.valve_id = valve_id;

    // Fetch the valve position.
    memcpy(&valve_position, offset, sizeof(int));
    if (valve_position < 0) {
      current_command.is_valid = false; // Invalid valve position.
      return current_command;
    }
    current_command.valve_position = valve_position;
    break;
  }

  default:
    current_command.is_valid = false;
    return current_command;
  }

  current_command.is_valid = true; // Valid command.
  return current_command;
}
