#include "control.hpp"

void pump_on()
{
  digitalWrite(pump, HIGH);
}

void pump_off()
{
  digitalWrite(pump, LOW);
} 

void controlFan()
{
  float temperature = Value_Temperature;
  int fanSpeed = temperature * 100 /255;
  analogWrite(fan, fanSpeed);
}

void Led_on()
{   
  // for (int i = 0; i < NUM_PIXELS; i++)
  // {
  //   NeoPixel.setPixelColor(i, NeoPixel.Color(255, 255, 255));
  //   NeoPixel.show();
  // }
}

// void controlRGB()
// {
//   for (int i = 0; i < NUM_PIXELS; i++)
//   {
//     NeoPixel.setPixelColor(i, NeoPixel.Color(0, 255, 0));
//     NeoPixel.show();
//   }
// }