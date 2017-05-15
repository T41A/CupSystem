#ifndef SENSOR_H
#define SENSOR_H
#include <arduino.h>
class Sensor
{
public:
  Sensor(int Pin);
  int GetSensorValue(void);
private:
int SensorPin;
};

#endif
