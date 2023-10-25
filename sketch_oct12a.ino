#include "Config.h"
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"
#include "http.h"

void setup() {

  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  start_AP_mode();
  init_WIFI(true);
  server_init();
  init_MQTT();
  String state_topic = "esp8266-" + id() + "/state";
  String command_topic = "esp8266-" + id() + "/command";
  mqtt_client.publish(state_topic.c_str(), "Hello");
  mqtt_client.subscribe(command_topic.c_str());
}

void loop() {
server.handleClient();
mqtt_client.loop();
delay(100);
}
