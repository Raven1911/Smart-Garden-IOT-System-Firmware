#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "DHT20.h"
#include "global_var.hpp"

// extern Adafruit_NeoPixel NeoPixel;

void pump_on();
void pump_off();  
void controlFan();  
// void controlRGB();
void led_on();

#endif