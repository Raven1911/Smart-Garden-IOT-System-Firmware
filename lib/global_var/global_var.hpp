#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

#include <Arduino.h>
#include "Wire.h"

#ifdef __cplusplus
extern "C"
{
#endif

// GPIO configuration
#define BUZZER_PIN 25      //  BUZZER_PIN
#define soilMoisturePin 32 // cảm biến đất
#define light 33           // cảm biến ánh sáng
#define pump 19
#define fan 27
#define PIN_NEO_PIXEL 26
#define NUM_PIXELS 4

    // software timer configuration
    void millis_update(void);
    extern unsigned long millis_present;
#define priod_receiver_data 100

    // variable receiver data
    struct deviceName
    {
        String name;
        bool active;
        String value;
    };

    // variable receiver data
    extern deviceName Fan1;
    extern deviceName Pump1;
    extern deviceName Led1;

    extern deviceName Fan2;
    extern deviceName Pump2;
    extern deviceName Led2;

    extern bool State_FSM;
    /// Configuration MQTT Server and Wifi Connection
    extern const char *ssid;
    extern const char *password;
    extern const char *mqtt_server;
    // const char* topicSub = "0rm10p/read/Mario@M7";  // Topic nhận dữ liệu
    extern const char *topicSub; // Topic nhận dữ liệu
    extern const char *topicPub; // Topic gửi dữ liệu

    // biến từ cảm biến
    extern int Value_SoilMoisture;
    extern int Value_Light;
    extern float Value_Temperature;
    extern float Value_Humidity;

    void pinSetup(void);

#ifdef __cplusplus
}
#endif

#endif