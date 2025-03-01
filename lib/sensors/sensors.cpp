#include "sensors.hpp"

extern DHT20 DHT; //*********** */


void readDHT20()
{
  DHT.read();
  Serial.print("Temperature: ");
  Serial.println(DHT.getTemperature());
  Serial.print("Humidity: ");
  Serial.println(DHT.getHumidity());
}

void readSoilMoisture()
{
  int soilMoistureValue = analogRead(soilMoisturePin);
  int soilMoisturePercentage = map(soilMoistureValue, 0, 4095, 0, 100);
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercentage);
  Serial.println("%");
}

void readLight()
{
  int lightValue = analogRead(light);
  int lightPercentage = map(lightValue, 0, 4095, 0, 100);
  Serial.print("Light Level: ");
  Serial.print(lightPercentage);
}