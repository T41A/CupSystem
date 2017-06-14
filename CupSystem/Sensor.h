#ifndef SENSOR_H
#define SENSOR_H
#include <arduino.h>
class Sensor
{
public:
  Sensor(int Pin);
  int Read(void);
private:
int SensorPin;
};

#endif
