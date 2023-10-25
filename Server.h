//#include <ESP8266WebServer.h>
//
//ESP8266WebServer server(80); //Это означает, что веб-сервер будет прослушивать входящие запросы на порту 80
//
//void handle_root(){  // Функция генерирует HTML-страницу c "Switch LED", и отправляет эту страницу клиенту с кодом состояния 200 (Успешно).
//  String page_code = "<form action=\"/LED\" method=\"POST\">";
//  page_code +="<input type=\"submit\" value=\"Switch LED\">";
//  page_code += "</form>";
//  server.send(200,"text/html", page_code);
//}
//
//void handle_led(){ //обработчик вызывается,когда нажимает кнопку "Switch LED" на веб-странице. Функция переключает состояние светодиода, изменяя его яркость с помощью функций digitalRead() и digitalWrite(). 
//  bool current = digitalRead(led_pin); //считывает текущее состояние пина led_pin и сохраняет его в переменной current. Функция digitalRead(led_pin) возвращает true (или HIGH), если пин включен (светодиод горит) и false (или LOW), если пин выключен (светодиод не горит).
//  digitalWrite(led_pin, !current); //Эта строка изменяет состояние пина led_pin, инвертируя его значение. Если current равно true, то !current станет false, и наоборот. Таким образом, это переключает состояние светодиода.
//  server.sendHeader("Location","/");
//  server.send(303);
//}
//
//void server_init(){ //происходит инициализация и запуск веб-сервера.
//  server.on("/",HTTP_GET, handle_root); //Когда пользователь открывает браузер и вводит IP-адрес ESP8266 в адресной строке, выполняется GET запрос к корневому пути. Этот запрос будет обрабатываться функцией handle_root.
//  server.on("/LED", HTTP_POST, handle_led); //строка устанавливает обработчик для HTTP POST запроса, который будет обслуживать путь "/LED".Этот POST запрос будет инициироваться, когда пользователь нажимает кнопку "Switch LED" на веб-странице, что вызывает переключение состояния светодиода.
//  server.begin();
//  Serial.println("HTTP Server is on, on port"+String(web_port));
//
//}
