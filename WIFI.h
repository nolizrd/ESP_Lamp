// THIS is WIFI.h
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifi_multi;
WiFiClient wifi_client;


String ip = "(IP unset)"; //"192.168.4.1"

String id(){
  uint8_t mac[WL_MAC_ADDR_LENGTH];//MAC address my computer
  int last = WL_MAC_ADDR_LENGTH - 1;
  int prelast = WL_MAC_ADDR_LENGTH - 2;
  WiFi.softAPmacAddress(mac);
  String id = String(mac[prelast],HEX)+String(mac[last],HEX);
  return id;
}

bool start_AP_mode(){
  IPAddress AP_IP(192,168,4,1);
  IPAddress mask(255,255,255,0);
  String ssid_name = ssid_AP + id();
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(AP_IP,AP_IP,mask);
  WiFi.softAP(ssid_name.c_str(),ssid_pass.c_str());
  ip = WiFi.softAPIP().toString();
//  Serial.println(ip);
  Serial.println("WiFi up in Ap mode, " + ssid_name);
  return true;
}

bool start_client_mode(const String& ssid_client,const String& password_client){
  wifi_multi.addAP(ssid_client.c_str(), password_client.c_str());
  while(wifi_multi.run() != WL_CONNECTED){
    delay(100);
  }
  Serial.println("WiFi up in client mode, ");
  Serial.println(ssid_client);
  return true;
}

bool init_WIFI(bool mode_AP,const String& ssid_client, const String& password_client){
if(mode_AP){
  start_AP_mode();
  ip = WiFi.softAPIP().toString();
  Serial.println("ESP now has IP adress "+ip);
}else{
  start_client_mode(ssid_client,password_client);
  ip=WiFi.localIP().toString();
}
return true;
}
