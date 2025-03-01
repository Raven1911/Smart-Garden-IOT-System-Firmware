#include "display.hpp"

extern LiquidCrystal_I2C lcd;
extern DHT20 DHT;

void lcdDisplay()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(DHT.getTemperature(), 1);
  lcd.print("C");
  int lightValue = analogRead(light);
  int lightPercentage = map(lightValue, 0, 4095, 0, 100);
  lcd.print(" L:");
  lcd.print(lightPercentage);
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(DHT.getHumidity(), 1);
  lcd.print("%");
  lcd.print(" S:");
  int soilMoistureValue = analogRead(soilMoisturePin);
  int soilMoisturePercentage = map(soilMoistureValue, 0, 4095, 0, 100);
  lcd.print(soilMoisturePercentage);
  lcd.print("%");
}