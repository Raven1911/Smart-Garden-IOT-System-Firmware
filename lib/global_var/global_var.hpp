#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif


#define BUZZER_PIN 25 //  BUZZER_PIN



/// Configuration MQTT Server and Wifi Connection
const char* ssid = "ACLAB";
const char* password = "ACLAB2023";
const char* mqtt_server = "test.mosquitto.org";
// const char* topicSub = "0rm10p/read/Mario@M7";  // Topic nhận dữ liệu
const char* topicSub = "server/sensors/esp32";  // Topic nhận dữ liệu
const char* topicPub = "/home/sensors/esp32";         // Topic gửi dữ liệu
























#ifdef __cplusplus
}
#endif

#endif