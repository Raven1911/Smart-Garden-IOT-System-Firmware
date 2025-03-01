#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "DHT20.h"
#include "global_var.hpp"

#endif
#ifdef __cplusplus
extern "C"
{
#endif


void pump_on();
void pump_off();  
void controlFan();  
// void controlRGB();
void led_on();

#ifdef __cplusplus
}
#endif