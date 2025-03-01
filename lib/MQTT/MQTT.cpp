#include <MQTT.hpp>


long lastMsg = 0;  // Thời điểm gửi tin nhắn cuối cùng

// Khởi tạo MQTT Client
WiFiClient espClient;
PubSubClient client(espClient);



void init_Wifi_and_MQTT(void){
    // Kết nối WiFi
  Serial.print("Đang kết nối WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi đã kết nối");

  // Cấu hình MQTT Server và callback
  client.setServer(mqtt_server, 1883);
  client.setCallback(receiver_data);
}


// Transmit_data
void Transmit_receiver_data(void) {
    if (!client.connected()) {
      reconnect();  // Kết nối lại nếu mất kết nối
    }
    client.loop();  // Lắng nghe dữ liệu từ MQTT
  
    // Gửi dữ liệu mỗi 100 ms 
    if (millis_present - lastMsg > priod_receiver_data) {
      lastMsg = millis_present;
      StaticJsonDocument<80> doc;
      doc["temperature"] = 25;
      doc["humidity"] = 60;
      doc["pressure"] = 1012;
      doc["gas"] = 300;
  
      char output[80];
      serializeJson(doc, output);
  
      Serial.println("------------------------------------------------");
      Serial.println("Gửi dữ liệu tới topic:");
      Serial.println(topicPub);
      Serial.println(output);
      client.publish(topicPub, output);
      Serial.println("------------------------------------------------");
    }
  }


// Hàm xử lý khi nhận dữ liệu từ MQTT
// Dự phòng dung lượng đủ để chứa dữ liệu JSON
StaticJsonDocument<200> receivedValues;  

// Hàm xử lý khi nhận dữ liệu từ MQTT
void receiver_data(char* topic, byte* payload, unsigned int length) {
  // Kiểm tra dữ liệu payload có hợp lệ không
  if (payload == nullptr || length == 0) {
    Serial.println("Received empty or invalid payload.");
    return;
  }

  // Chuyển payload (dữ liệu nhận được) thành chuỗi string
  char message[length + 1];
  memcpy(message, payload, length);
  message[length] = '\0';  // Đảm bảo kết thúc chuỗi

  // In ra chuỗi JSON nhận được
  Serial.println("Received JSON string:");
  Serial.println(message);

  // Giải mã JSON từ chuỗi string
  DeserializationError error = deserializeJson(receivedValues, message);
  if (error) {
    Serial.printf("JSON parsing failed: %s\n", error.c_str());
    return;
  }

  // Kiểm tra và lấy các giá trị từ JSON
  if (receivedValues.containsKey("deviceName")) {
    //fan1
    if (receivedValues["deviceName"].as<String>() == "Fan1"){
        Fan1.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Fan1.name.c_str());

        if (receivedValues.containsKey("active")) {
            Fan1.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Fan1.active);
          } else {
            Serial.println("No Fan1 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Fan1.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Fan1.value);
          } else {
            Serial.println("No Fan1 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }
    }

    //Pump1
    if (receivedValues["deviceName"].as<String>() == "Pump1"){
        Pump1.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Pump1.name.c_str());

        if (receivedValues.containsKey("active")) {
            Pump1.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Pump1.active);
          } else {
            Serial.println("No Pump1 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Pump1.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Pump1.value);
          } else {
            Serial.println("No Pump1 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }

    }

    //Led1
    if (receivedValues["deviceName"].as<String>() == "Led1"){
        Led1.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Led1.name.c_str());

        if (receivedValues.containsKey("active")) {
            Pump1.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Led1.active);
          } else {
            Serial.println("No Led1 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Led1.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Led1.value);
          } else {
            Serial.println("No Led1 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }
    }

    //Fan2
    if (receivedValues["deviceName"].as<String>() == "Fan2"){
        Fan2.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Fan2.name.c_str());

        if (receivedValues.containsKey("active")) {
            Fan2.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Fan2.active);
          } else {
            Serial.println("No Fan2 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Fan2.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Fan2.value);
          } else {
            Serial.println("No Fan2 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }
    }

    //Pump2
    if (receivedValues["deviceName"].as<String>() == "Pump2"){
        Pump2.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Pump2.name.c_str());

        if (receivedValues.containsKey("active")) {
            Pump2.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Pump2.active);
          } else {
            Serial.println("No Pump2 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Pump2.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Pump2.value);
          } else {
            Serial.println("No Pump2 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }

    }

    //Led2
    if (receivedValues["deviceName"].as<String>() == "Led2"){
        Led2.name = receivedValues["deviceName"].as<String>();
        Serial.printf("Device Name: %s\n",  Led2.name.c_str());

        if (receivedValues.containsKey("active")) {
            Led2.active = receivedValues["active"].as<bool>();
            Serial.printf("Active: %d\n", Led2.active);
          } else {
            Serial.println("No Led2 active found in JSON.");
          }

        if (receivedValues.containsKey("value")) {
            Led2.value = receivedValues["value"].as<String>();
            Serial.printf("Active: %d\n", Led2.value);
          } else {
            Serial.println("No Led2 value found in JSON.");
        }

        if (receivedValues.containsKey("state")) {
          State_FSM = receivedValues["state"].as<bool>();
          Serial.printf("state: %d\n", State_FSM);
        }
    }

  } 
  else {
    Serial.println("No deviceName found in JSON.");
  }



//   if (receivedValues.containsKey("active")) {
//     bool active = receivedValues["active"].as<bool>();
//     Serial.printf("Active: %d\n", active);
//   } else {
//     Serial.println("No active found in JSON.");
//   }

//   if (receivedValues.containsKey("value")) {
//     JsonVariant value = receivedValues["value"];
//     if (value.isNull()) {
//       Serial.println("Value is null");
//     } else {
//       Serial.printf("Value: %s\n", value.as<String>().c_str());
//     }
//   } else {
//     Serial.println("No value found in JSON.");
//   }
}


// Hàm tự động kết nối lại MQTT
void reconnect() {
    while (!client.connected()) {
      Serial.print("Đang kết nối lại MQTT...");
      String clientId = "ESP32Client-" + String(random(0xffff), HEX);
      if (client.connect(clientId.c_str())) {
        Serial.println("Đã kết nối MQTT");
        client.subscribe(topicSub);  // Đăng ký nhận dữ liệu từ topic
        Serial.print("Đã đăng ký lắng nghe topic: ");
        Serial.println(topicSub);
      } else {
        Serial.print("Kết nối thất bại, mã lỗi: ");
        Serial.println(client.state());
        delay(5000); // Đợi 5 giây trước khi thử lại
      }
    }
  }
  