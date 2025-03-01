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
// const char* topicSub = "0rm10p/read/Mario@M7";  // Topic nhận dữ liệu
const char* topicSub = "server/sensors/esp32";  // Topic nhận dữ liệu
const char* topicPub = "/home/sensors/esp32";         // Topic gửi dữ liệu


deviceName Fan1 = {"Cooling Fan", true, "High"};
deviceName Pump1 = {"Water Pump", false, "Low"};
deviceName Led1 = {"LED Light", true, "Medium"};

deviceName Fan2 = {"Cooling Fan", true, "High"};
deviceName Pump2 = {"Water Pump", false, "Low"};
deviceName Led2 = {"LED Light", true, "Medium"};
