#include "sensors.hpp"

extern DHT20 DHT; //*********** */


void readDHT20()
{
  DHT.read();
  Value_Humidity = DHT.getHumidity();
  Value_Temperature = DHT.getTemperature();
  Serial.print("Temperature: ");
  Serial.println(DHT.getTemperature());
  Serial.print("Humidity: ");
  Serial.println(DHT.getHumidity());

}

void readSoilMoisture()
{
  int soilMoistureValue = analogRead(soilMoisturePin);
  int soilMoisturePercentage = (soilMoistureValue * 100 / 4095);
  Value_SoilMoisture = soilMoisturePercentage;
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercentage);
  Serial.println("%");
}

void readLight()
{
  int lightValue = analogRead(light);
  int lightPercentage = lightValue * 100 / 4095;
  Value_Light = lightPercentage;
  Serial.print("Light Level: ");
  Serial.print(lightPercentage);
}