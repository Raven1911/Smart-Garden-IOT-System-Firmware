#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "DHT20.h"

extern Adafruit_NeoPixel NeoPixel;
extern const int pump;
extern const int fan;
extern DHT20 DHT;
extern const int soilMoisturePin;

void pumpWater();
void controlFan();
void controlRGB();

#endif