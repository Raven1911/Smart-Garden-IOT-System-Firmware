#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

//GPIO configuration
#define BUZZER_PIN 25 //  BUZZER_PIN


//software timer configuration
void millis_update(void);
extern unsigned long millis_present;
#define priod_receiver_data 100

//variable receiver data
struct deviceName {
    String name;
    bool active;
    String value;
};

//variable receiver data
extern deviceName Fan1;
extern deviceName Pump1;
extern deviceName Led1;

extern deviceName Fan2;
extern deviceName Pump2;
extern deviceName Led2;

extern bool State_FSM;
/// Configuration MQTT Server and Wifi Connection
extern const char* ssid;
extern const char* password;
extern const char* mqtt_server;
// const char* topicSub = "0rm10p/read/Mario@M7";  // Topic nhận dữ liệu
extern const char* topicSub;  // Topic nhận dữ liệu
extern const char* topicPub;         // Topic gửi dữ liệu


























#ifdef __cplusplus
}
#endif

#endif