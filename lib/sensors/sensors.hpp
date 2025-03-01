#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <Arduino.h>
#include "sensors.hpp"
#include <Arduino.h>
#include "DHT20.h"
#include "global_var.hpp"

void readDHT20();
void readSoilMoisture();
void readLight();

#endif