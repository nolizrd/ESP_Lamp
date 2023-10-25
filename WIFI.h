
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifi_multi;
WiFiClient wifi_client;

String ip = "(IP unset)"; //"192.168.4.1" Определение строки ip с начальным значением "(IP unset)", которое будет использоваться для хранения IP-адреса ESP8266.

String id(){ //Это функция, которая возвращает уникальный идентификатор ESP8266 на основе его MAC-адреса.
             //MAC-адрес извлекается из ESP8266, и последние два байта MAC-адреса конвертируются в строку и возвращаются в виде идентификатора.
  uint8_t mac[WL_MAC_ADDR_LENGTH];//MAC address my computer
  int last = WL_MAC_ADDR_LENGTH - 1;
  int prelast = WL_MAC_ADDR_LENGTH - 2;
  WiFi.softAPmacAddress(mac);
  String id = String(mac[prelast],HEX)+String(mac[last],HEX);
  return id;
}

bool start_AP_mode(){
  //функция запускает ESP8266 в режиме точки доступа (AP). Она настраивает IP-адрес точки доступа, 
  //маску подсети, и имя сети (SSID) на основе ssid_AP и пароля ssid_pass. 
  //После этого ESP8266 становится доступным как точка доступа с указанными настройками.
  IPAddress AP_IP(192,168,4,1);//создается объект IPAddress с адресом 192.168.4.1. IP-адрес будет назначен ESP8266 в качестве адреса точки доступа.
  IPAddress mask(255,255,255,0);
  String ssid_name = ssid_AP + id();
  WiFi.disconnect();
  WiFi.mode(WIFI_AP); //Устанавливает режим работы ESP8266 как точку доступа.
  WiFi.softAPConfig(AP_IP,AP_IP,mask);
  WiFi.softAP(ssid_name.c_str(),ssid_pass.c_str()); 
  //ESP8266 запускает точку доступа с заданным именем ssid_name и паролем ssid_pass, которые указаны в вашем коде.
  ip = WiFi.softAPIP().toString(); //IP-адрес ESP8266, который был назначен точке доступа, извлекается и сохраняется в переменной ip.
  Serial.println("WiFi up in Ap mode, " + ssid_name);
  return true;
}

bool start_client_mode(){ //для настройки ESP8266 в режиме клиента, чтобы он мог подключиться к существующей Wi-Fi сети
  wifi_multi.addAP(ssid_client,pass_client);
  while(wifi_multi.run() != WL_CONNECTED){ // это статус, означающий успешное подключение к сети. Внутри цикла также есть delay(100);который добавляет задержку в 100 миллисекунд между попытками подключения. 
    delay(100);
  }
  Serial.println("WiFi up in client mode, ");
  Serial.println(ssid_client);
  return true;
}

bool init_WIFI(bool mode_AP){ // аргумент mode_AP, который указывает, должен ли ESP8266 находиться в режиме точки доступа (AP) или в режиме клиента
if(mode_AP){
  start_AP_mode();
  ip = WiFi.softAPIP().toString();
}else{
  start_client_mode();
  ip=WiFi.localIP().toString();
}
Serial.println("ESP now has IP adress "+ip);
return true;
}
