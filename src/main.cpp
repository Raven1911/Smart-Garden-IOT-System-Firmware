#include <Arduino.h>
#include <global_var.hpp>
#include <music_dec.hpp>
#include <sensors.hpp>

void setup() {
  Serial.begin(115200);
  pinMode(soilMoisturePin, INPUT);
  play_music(BUZZER_PIN);  // Chơi nhạc khi khởi động
}

void loop() {
  // put your main code here, to run repeatedly:
  readSoilMoisture();
}
