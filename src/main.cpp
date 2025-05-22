// A simple example of testing each unit of the DAQ.

#include <AnalogSensor.h>
#include <CommandParser.h>
#include <Config.h>
#include <Logger.h>
#include <Valve.h>

AnalogSensorMux mux0(14, 20, 21, 22, 23);
AnalogSensorMux mux1(15, 20, 21, 22, 23);

KTypeThermocoupleHigh tt1(&mux0, 0);
KTypeThermocoupleLow tt2(&mux0, 1);
LowRangePressureSensor pt1(&mux1, 0);
HighRangePressureSensor pt2(&mux1, 1);
AnalogSensorManager sensor_manager;
BallValve valve(8);
SolenoidValve sv(28);
CommandParser command_parser;
char command_buffer[COMMAND_MESSAGE_SIZE];

void excuteCommand(Command &command);

void setup() {
  Serial.begin(115200);
  mux0.begin();
  mux1.begin();
  sensor_manager.begin();
  sensor_manager.addSensor(&pt1);
  sensor_manager.addSensor(&pt2);
  sensor_manager.addSensor(&tt1);
  sensor_manager.addSensor(&tt2);
  valve.begin();
  sv.begin();
  delay(2000);
  Serial.setTimeout(0);
}

void loop() {
  /* Control test. */
  if (Serial.readBytes(command_buffer, COMMAND_MESSAGE_SIZE) == COMMAND_MESSAGE_SIZE) {
    struct Command command = command_parser.parse(command_buffer);
    excuteCommand(command);
  }

  /* Analog sensor test. */
  sensor_manager.updateSensorData(); // Fetches sensor data from the sensors.
  const double *data_arr = sensor_manager.getSensorData();
  logger.logBinary(LogType::DATA, millis(), (byte *)data_arr, sizeof(double) * 4,
                   LogStream::SERIAL_MAIN);

  /* For human readable output, uncomment the following lines. */
  // Serial.print("PT1: ");
  // Serial.print(data_arr[0]);
  // Serial.print(" PT2: ");
  // Serial.print(data_arr[1]);
  // Serial.print(" TT1: ");
  // Serial.print(data_arr[2]);
  // Serial.print(" TT2: ");
  // Serial.println(data_arr[3]);
}

void excuteCommand(Command &command) {
  if (command.is_valid) {
    switch (command.type) {
    case CommandType::BALL_VALVE_CONTROL:
      if (command.valve_position >= 0 && command.valve_position <= 90) {
        valve.open(command.valve_position);
      }
      break;
    case CommandType::SOLENOID_VALVE_CONTROL:
      if (command.valve_position == 0) {
        sv.close();
      } else if (command.valve_position == 1) {
        sv.open();
      }
      break;
    case CommandType::EMERGENCY_STOP:
      sv.close();
      valve.close();
      break;
    default:
      logger.log(LogType::ERROR, millis(), "Invalid command type", LogStream::SERIAL_MAIN);
      break;
    }
  }
}
