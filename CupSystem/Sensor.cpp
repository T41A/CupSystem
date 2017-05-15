#include "Sensor.h"
Sensor(int Pin):SensorPin(Pin)
{

}
int Sensor::GetSensorValue(void)
{
  bool value = digitalRead(SensorPin);
  return value;
}
