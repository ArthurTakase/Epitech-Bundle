#ifndef WIFI_REQUEST_HANDLER_HPP
#define WIFI_REQUEST_HANDLER_HPP

#include <WiFi.h>
#include <M5Stack.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "Product.hpp"

#define WIFI_SSID "iPhone de Geoffrey"
#define WIFI_PASSWORD "Geoffreybg"
#define API_KEY "8tq9sVP2YEzbFk0k6H99UWoL49UtS1uw"

#define BASE_URL "http://34.163.18.219/api/index.php"

class WiFiRequestHandler
{
public:
    WiFiRequestHandler();
    ~WiFiRequestHandler();

    bool connectWiFi();
    String getLocalIP();

    Product getProductById(int id);
    void postStockMovement(Product product);

private:
    WiFiMulti wiFiMulti;
};

#endif
