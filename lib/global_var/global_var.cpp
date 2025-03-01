#include <global_var.hpp>

//software timer configuration
unsigned long millis_present = 0;
void millis_update(void){
    millis_present = millis();
}

/// Configuration MQTT Server and Wifi Connection
const char* ssid = "ACLAB";
const char* password = "ACLAB2023";
const char* mqtt_server = "test.mosquitto.org";


const char* topicSub = "Smart-Garden-IOT/receiver_data/esp32";  // Topic nhận dữ liệu
const char* topicPub = "Smart-Garden-IOT/transmit_data/esp32";  // Topic gửi dữ liệu


deviceName Fan1 = {"Fan1", true, "High"};
deviceName Pump1 = {"Pump1", false, "Low"};
deviceName Led1 = {"Led1", true, "Medium"};

deviceName Fan2 = {"Fan2", true, "High"};
deviceName Pump2 = {"Pump2", false, "Low"};
deviceName Led2 = {"Led2", true, "Medium"};

//biến từ cảm biến
int Value_SoilMoisture = 0;
int Value_Light = 0;
float Value_Temperature = 0.0;
float Value_Humidity = 0.0;
bool State_FSM = true;

void pinSetup (void){
    pinMode(pump, OUTPUT);
    pinMode(fan, OUTPUT);
    pinMode(soilMoisturePin, INPUT);
    Wire1.begin(21, 22); //chân của I2C
}