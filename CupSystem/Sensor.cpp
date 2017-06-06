#include "Sensor.h"
Sensor(int Pin):SensorPin(Pin)
{

}
int Sensor::GetSensorValue(void) // moet een bool functie zijn.
{
  bool value = digitalRead(SensorPin);
  return value; // stuurt al wel een bool terug.
}
