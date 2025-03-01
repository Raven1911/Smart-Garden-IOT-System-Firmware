#include <Arduino.h>
#include <global_var.hpp>
#include <music_dec.hpp>
#include <MQTT.hpp>
#include <FSM_SETTING.hpp>

void setup()
{
  Serial.begin(115200);
  play_music(BUZZER_PIN); // Chơi nhạc khi khởi động
  init_Wifi_and_MQTT();
  pinSetup();
}

void loop()
{
  millis_update();
  Transmit_receiver_data();
  // put your main code here, to run repeatedly:
  FSM_Main();
}
