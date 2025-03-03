#include "WiFiRequestHandler.hpp"

WiFiRequestHandler::WiFiRequestHandler()
{
    wiFiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
}

WiFiRequestHandler::~WiFiRequestHandler() {}

bool WiFiRequestHandler::connectWiFi()
{
    int attemptCount = 0;
    while (wiFiMulti.run() != WL_CONNECTED) {
        M5.Lcd.print(".");
        delay(300);
        attemptCount++;
        if (attemptCount > 8) {
            M5.Lcd.println("\nConnection failed!");
            return false;
        }
    }
    M5.Lcd.println("\nWiFi connected");
    return true;
}

String WiFiRequestHandler::getLocalIP()
{
    return WiFi.localIP().toString();
}

Product WiFiRequestHandler::getProductById(int id)
{
    Product product;
    String endpoint = "/products/" + String(id);
    String url = BASE_URL + endpoint;
    HTTPClient http;

    http.begin(url);
    http.addHeader("DOLAPIKEY", API_KEY);
    int httpCode = http.GET();

    if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK) {
            String response = http.getString();
            product = Product::parseFromJson(response);
            product.printProduct();
        } else
            M5.Lcd.printf("HTTP GET request failed with code: %d\n", httpCode);
    } else
        M5.Lcd.printf("GET request failed: %s\n", http.errorToString(httpCode).c_str());

    http.end();

    return product;
}

void WiFiRequestHandler::postStockMovement(Product product)
{
    String endpoint = "/stockmovements";
    String url = BASE_URL + endpoint;
    String payload = "{\"product_id\": " + product.id + ",\"warehouse_id\": " + product.warehouse_id + ",\"qty\": -1}";

    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("DOLAPIKEY", API_KEY);

    int httpCode = http.POST(payload);

    if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK)
            M5.Lcd.println("Success");
        else
            M5.Lcd.printf("POST request failed with code: %d\n", httpCode);
    } else
        M5.Lcd.printf("POST request failed: %s\n", http.errorToString(httpCode).c_str());

    http.end();
    return;
}