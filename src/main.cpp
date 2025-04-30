// A simple example of testing each unit of the DAQ.

#include <AnalogSensor.h>
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
}

void loop() {
  // Analog sensor test.
  sensor_manager.updateSensorData(); // Fetches sensor data from the sensors.
  const double *data_arr = sensor_manager.getSensorData();
  Serial.print("PT1: ");
  Serial.print(data_arr[0]);
  Serial.print(" PT2: ");
  Serial.print(data_arr[1]);
  Serial.print(" TT1: ");
  Serial.print(data_arr[2]);
  Serial.print(" TT2: ");
  Serial.println(data_arr[3]);

  // Ball valve test.
  valve.open(0);
  Serial.println(valve.showAngle());
  delay(2000);
  valve.open(90);
  Serial.println(valve.showAngle());
  delay(2000);

  // Solenoid valve test.
  sv.open();
  Serial.println(sv.isOpen() ? "Open" : "Closed");
  delay(500);
  sv.close();
  Serial.println(sv.isOpen() ? "Open" : "Closed");
  delay(500);
}
