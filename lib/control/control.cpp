#include "control.hpp"

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

//control manual initialization
void pump_control_manual(bool active){
  digitalWrite(pump, active);
}

void fan_control_manual(int fanSpeed){
  analogWrite(fan, fanSpeed);
  
}


//
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
  // digitalWrite(fan, HIGH);

}

void ledwhite_on()
{   
  NeoPixel.setPixelColor(1, NeoPixel.Color(255, 255, 255));
  NeoPixel.setPixelColor(2, NeoPixel.Color(255, 255, 255)); 
  NeoPixel.setPixelColor(3, NeoPixel.Color(255, 255, 255));  
  NeoPixel.show();
}

void ledwhite_off()
{
  
}

void ledred_on()
{
  // NeoPixel.clear(); 
  NeoPixel.setPixelColor(0, NeoPixel.Color(255, 0, 0)); 
  NeoPixel.show();
}

void ledgreen_on()
{
  // NeoPixel.clear(); 
  NeoPixel.setPixelColor(0, NeoPixel.Color(0, 255, 0)); 
  NeoPixel.show();
}

