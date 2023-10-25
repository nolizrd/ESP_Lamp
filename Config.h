String ssid_AP = "ESP_WIFIRITA"; //AP for access point/router
String ssid_pass = "ESP_8266_123";//8 символов миниму для пароля
//точка доступа долдна быть 2.4 GHz
char* ssid_client = "Redmi 12";//name my network on phone (take it from HotSpot on phone)
char* pass_client = "66664444";
int web_port = 80;
int led_pin = LED_BUILTIN;

char* mqtt_broker = "broker.emqx.io";
int mqtt_port = 1883;
