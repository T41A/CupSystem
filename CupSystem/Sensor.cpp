#include "Sensor.h"
Sensor::Sensor(int Pin):SensorPin(Pin)
{
pinMode(Pin,INPUT);
}
int Sensor::Read(void)
{
  int value = analogRead(SensorPin);
  if(value < 500)
  {
   return 1;
  }
  else
  {
    return 0;
  }
}
