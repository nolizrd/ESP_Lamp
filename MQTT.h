#include <PubSubClient.h>

PubSubClient mqtt_client(wifi_client);

void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Message received on topic: ");
  Serial.print(topic);
  Serial.print("Message is: ");
  for (int i = 0; i < length; i++) {
    char messageChar = (char)payload[i];
    Serial.print(messageChar);

    if (messageChar == 'd') {
      digitalWrite(led_pin, LOW);
    } else if (messageChar == 'u') {
      digitalWrite(led_pin, HIGH);
    }
  Serial.println();
  }
}

void init_MQTT(){
  mqtt_client.setServer(mqtt_broker, mqtt_port);
  mqtt_client.setCallback(callback);
  while(!mqtt_client.connected()){
    Serial.println("Trying to connect: ");
    Serial.println(mqtt_broker);
    String client_id = "esp8266_" + id();
    bool succes = mqtt_client.connect(client_id.c_str());
    if(succes){
      Serial.println("Successfully connected with " + client_id);
        
    }else{
      Serial.println("Successfully connected with " + client_id);
      Serial.println(mqtt_client.state());
      delay(2000);
    }
  }
}
