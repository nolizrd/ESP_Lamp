//#include <UnoWiFiDevEd.h>

#include "Config.h"
const char* ssid_client = "";
const char* password_client = "";
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  init_WIFI(true,"","");
  start_AP_mode();
  //Serial.begin(115200);
  server_init();
// 
  
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  server.handleClient();
  
  if (WiFi.status() ==WL_CONNECTED) {
     init_MQTT();
    String state_topic = "esp8266-" + id() + "/state";
  String command_topic = "esp8266-" + id() + "/command";
  
  mqtt_client.publish(state_topic.c_str(), "hello");
  mqtt_client.subscribe(command_topic.c_str());
    mqtt_client.loop();
    delay(1000);
  }else{
    if(WiFi.getMode()!=WIFI_AP){
    start_AP_mode();
    }
  }
}
