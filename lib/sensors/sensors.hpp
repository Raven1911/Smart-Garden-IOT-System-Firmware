#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <Arduino.h>
#include "sensors.hpp"
#include <Arduino.h>
#include "DHT20.h"
#include "global_var.hpp"


#ifdef __cplusplus
extern "C"
{
#endif

void readDHT20();
void readSoilMoisture();
void readLight();

#ifdef __cplusplus
}
#endif
#endif