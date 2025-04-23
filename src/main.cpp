// A simple example of using the AnalogSensor library to read data.

#include <AnalogSensor.h>
#include <Config.h>
#include <Logger.h>

AnalogSensorMux mux0(14, 20, 21, 22, 23);
AnalogSensorMux mux1(15, 20, 21, 22, 23);

KTypeThermocoupleLow tt1(&mux0, 0);
KTypeThermocoupleHigh tt2(&mux0, 1);
LowRangePressureSensor pt1(&mux1, 0);
HighRangePressureSensor pt2(&mux1, 1);
AnalogSensorManager sensor_manager;

void setup() {
  Serial.begin(115200);
  delay(2000);
  sensor_manager.begin();
  sensor_manager.addSensor(&pt1);
  sensor_manager.addSensor(&pt2);
  sensor_manager.addSensor(&tt1);
  sensor_manager.addSensor(&tt2);
}

void loop() {
  sensor_manager.updateSensorData();
  const double *data_arr = sensor_manager.getSensorData();
  Serial.print("PT1: ");
  Serial.print(data_arr[0]);
  Serial.print(" PT2: ");
  Serial.print(data_arr[1]);
  Serial.print(" TT1: ");
  Serial.print(data_arr[2]);
  Serial.print(" TT2: ");
  Serial.println(data_arr[3]);
  delay(1000);
}
