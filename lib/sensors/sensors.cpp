#include "sensors.hpp"

DHT20 DHT; //*********** */
int soilMoistureSensor;
int lightSensor;
int temperatureSensor;
int humiditySensor;

void valueSensor()
{
  readDHT20();
  readSoilMoisture();
  readLight();
}

void readDHT20()
{
  DHT.read();
  Value_Humidity = DHT.getHumidity();
  Value_Temperature = DHT.getTemperature();
  // Serial.print("Temperature: ");
  // Serial.println(DHT.getTemperature());
  // Serial.print("Humidity: ");
  // Serial.println(DHT.getHumidity());

}

void readSoilMoisture()
{
  int soilMoistureValue = analogRead(soilMoisturePin);
  soilMoistureSensor = (soilMoistureValue * 100 / 4095);
  Value_SoilMoisture = soilMoistureSensor;
  // Serial.print("Soil Moisture: ");
  // Serial.print(soilMoistureSensor);
  // Serial.println("%");
}

void readLight()
{
  int lightValue = analogRead(light);
  lightSensor = lightValue * 100 / 4095;
  Value_Light = lightSensor;
  // Serial.print("Light Level: ");
  // Serial.print(lightSensor);
}