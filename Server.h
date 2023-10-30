#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void handle_root(){
  String page_code = "<form action=\"/wifi\" method=\"POST\">";
  page_code +="SSID: <input type='text' name='ssid'><br>";
  page_code +="Password: <input type='password' name='password'><br>";
  page_code +="<input type='submit' value='Connect'>";
  page_code += "</form>";
  server.send(200,"text/html", page_code);
}


void handle_led(){
  
 ssid_client = server.arg("ssid").c_str();
 password_client = server.arg("password").c_str();

  
  // Выведите значения в Serial Monitor
  Serial.println(ssid_client);
  Serial.println(password_client);
  init_WIFI(false,ssid_client,password_client);
  // Здесь вы можете выполнять другие действия, связанные с полученными данными.

  // Отправьте ответ на клиентскую сторону
  server.send(200, "text/html", "Connection Successful");
  }
//  bool current = digitalRead(led_pin);
//  digitalWrite(led_pin, !current);
//  
//  server.sendHeader("Location","/");
//  server.send(303);
  
void server_init(){
  server.on("/",HTTP_GET, handle_root);
  server.on("/wifi", HTTP_POST, handle_led);
  server.begin();
  Serial.println("HTTP Server is on, on port"+String(web_port));

}
