// A simple example of using the AnalogSensor library to read data.

#include <AnalogSensor.h>
#include <Config.h>

constexpr uint8_t PT1_PIN = A0;
constexpr uint8_t PT2_PIN = A1;
constexpr uint8_t TT1_PIN = A2;
constexpr uint8_t TT2_PIN = A3;

LowRangePressureSensor pt1(PT1_PIN);
HighRangePressureSensor pt2(PT2_PIN);
KTypeThermocoupleHigh tt1(TT1_PIN);
KTypeThermocoupleLow tt2(TT2_PIN);
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
