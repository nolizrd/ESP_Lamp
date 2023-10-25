#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YourSSID";      // Название вашей Wi-Fi сети
const char* password = "YourPassword";  // Пароль Wi-Fi сети

ESP8266WebServer server(80);
void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Введите данные для подключения к Wi-Fi</h1>";
  html += "<form method='post' action='/connect'>";
  html += "SSID (название сети): <input type='text' name='ssid'><br>";
  html += "Пароль: <input type='password' name='password'><br>";
  html += "<input type='submit' value='Подключиться'>";
  html += "</form></body></html>";
  
  server.send(200, "text/html", html);
}

void handleConnect() {
  String ssid = server.arg("ssid");
  String password = server.arg("password");
  
  if (ssid != "" && password != "") {
    // Попытка подключения к указанной Wi-Fi сети
    if (WiFi.begin(ssid.c_str(), password.c_str())) {
      server.send(200, "text/plain", "Подключено к Wi-Fi. Перезагрузка устройства...");
      delay(1000);
      ESP.reset();
    } else {
      server.send(200, "text/plain", "Не удалось подключиться к Wi-Fi.");
    }
  } else {
    server.send(200, "text/plain", "Введите название сети и пароль.");
  }
}

void server_init(){
  server.on("/", HTTP_GET, handleRoot);
  server.on("/connect", HTTP_POST, handleConnect);
  
  server.begin();
  Serial.println("HTTP server started");
   WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
