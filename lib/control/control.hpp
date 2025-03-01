#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "DHT20.h"
#include "global_var.hpp"


#ifdef __cplusplus
extern "C"
{
#endif

extern Adafruit_NeoPixel NeoPixel;

void pump_on();
void pump_off();  
void controlFan();
void ledwhite_on();
void ledred_on();
void ledgreen_on();

#ifdef __cplusplus
}
#endif
#endif