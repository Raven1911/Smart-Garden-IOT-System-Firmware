#include "control.hpp"

#define NUM_PIXELS 16 // Define the number of pixels

// extern Adafruit_NeoPixel NeoPixel;
// extern const int pump;
// extern const int fan;
// extern DHT20 DHT;
// extern const int soilMoisturePin;

extern Adafruit_NeoPixel NeoPixel;
extern const int pump;
extern const int fan;
extern DHT20 DHT;
extern const int soilMoisturePin;

void pumpWater()
{
  int soilMoisture = analogRead(soilMoisturePin);
  digitalWrite(pump, soilMoisture < 30 ? HIGH : (soilMoisture > 50 ? LOW : digitalRead(pump)));
}

void controlFan()
{
  int temperature = DHT.getTemperature();
  digitalWrite(fan, temperature > 27 ? HIGH : LOW);
}

void controlRGB()
{
  for (int i = 0; i < NUM_PIXELS; i++)
  {
    NeoPixel.setPixelColor(i, NeoPixel.Color(0, 255, 0));
    NeoPixel.show();
  }
}