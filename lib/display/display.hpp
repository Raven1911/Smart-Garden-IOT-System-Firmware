#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "DHT20.h"
#include "global_var.hpp"


#ifdef __cplusplus
extern "C"
{
#endif

void lcdDisplay();

#ifdef __cplusplus
}
#endif
#endif