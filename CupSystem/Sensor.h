#ifndef SENSOR_H
#define SENSOR_H
#include <arduino.h>
class Sensor
{
public:
  Sensor(int Pin);
  int GetSensorValue(void); // moet een bool functie zijn.
private:
int SensorPin;
};

#endif
