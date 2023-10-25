//#include <ESP8266WebServer.h>
//#include <ESP8266WiFiMulti.h>
//
//ESP8266WebServer server(80);   //Web server object. Will be listening in port 80 (default for HTTP)
//
//void handle_root() {
//  String html = "<html><body>";
//  html += "<h2>Wi-Fi Setup</h2>";
//  html += "<form method='post' action='/save-wifi'>";
//  html += "SSID: <input type='text' name='ssid' value=''><br>";
//  html += "Password: <input type='password' name='password'><br>";
//  html += "<input type='submit' value='Save'>";
//  html += "</form>";
//  html += "</body></html>";
//
//  server.send(200, "text/html", html);
//}
//
//bool connectToWiFi(String ssid, String password) {
//  WiFi.begin(ssid, password);
//  int attempts = 0;
//  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
//    delay(1000); // Попробуйте подключиться каждую секунду в течение 30 секунд
//    attempts++;
//  }
//  return WiFi.status() == WL_CONNECTED;
//}
//
//void handleSaveWiFi() {
//  if (server.hasArg("ssid") && server.hasArg("password")) {
//    String ssid = server.arg("ssid");
//    String password = server.arg("password");
//    // Сохраните SSID и пароль в EEPROM или другом хранилище
//    // Для примера, мы просто перезаписываем значения в памяти
//
//    // Попробуйте подключиться к домашней Wi-Fi
//    if (connectToWiFi(ssid, password)) {
//      // Успешное подключение
//      // Отключите точку доступа ESP8266
//      WiFi.softAPdisconnect(true);
//      server.send(200, "text/plain", "Wi-Fi settings saved and connected.");
//    } else {
//      // Не удалось подключиться
//      server.send(200, "text/plain", "Failed to connect to Wi-Fi.");
//    }
//  } else {
//    server.send(400, "text/plain", "Bad Request");
//  }
//}
//
//void server_init(){ //происходит инициализация и запуск веб-сервера.
//  server.on("/",HTTP_GET, handle_root); //Когда пользователь открывает браузер и вводит IP-адрес ESP8266 в адресной строке, выполняется GET запрос к корневому пути. Этот запрос будет обрабатываться функцией handle_root.
// //строка устанавливает обработчик для HTTP POST запроса, который будет обслуживать путь "/LED".Этот POST запрос будет инициироваться, когда пользователь нажимает кнопку "Switch LED" на веб-странице, что вызывает переключение состояния светодиода.
//  server.on("/save-wifi",HTTP_POST, handle_root);
//  server.begin();
//  Serial.println("HTTP Server is on, on port"+String(web_port));
//
//}
