#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif


#define BUZZER_PIN 25 //  BUZZER_PIN
#define soilMoisturePin  32 //cảm biến đất 
#define light  33 //cảm biến ánh sáng



/// Configuration MQTT Server and Wifi Connection
extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;
// const char* topicSub = "0rm10p/read/Mario@M7";  // Topic nhận dữ liệu
extern const char* topicSub;  // Topic nhận dữ liệu
extern const char* topicPub;        // Topic gửi dữ liệu
























#ifdef __cplusplus
}
#endif

#endif