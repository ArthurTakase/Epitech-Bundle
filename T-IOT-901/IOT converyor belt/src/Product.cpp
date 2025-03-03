#include "Product.hpp"
#include <M5Stack.h>

Product::Product() {}

Product::Product(String id, String ref, String label, String warehouse_id, String entity)
    : id(id), ref(ref), label(label), warehouse_id(warehouse_id), entity(entity) {}

Product Product::parseFromJson(const String &jsonResponse)
{
    size_t capacity = JSON_OBJECT_SIZE(5) + jsonResponse.length() * 2;
    DynamicJsonDocument doc(capacity);


    DeserializationError error = deserializeJson(doc, jsonResponse);

    if (error) {
        M5.Lcd.printf("Erreur lors du parsing JSON: %s\n", error.c_str());
        return Product();
    }

    Product product(
        doc["id"].as<String>(),
        doc["ref"].as<String>(),
        doc["label"].as<String>(),
        doc["fk_default_warehouse"].as<String>(),
        doc["entity"].as<String>());

    return product;
}

void Product::printProduct() const
{
    M5.Lcd.printf("Id: %s\nRef: %s\nLabel: %s\nfk_default_warehouse: %s\nEntity: %s\n\n", id.c_str(), ref.c_str(), label.c_str(), warehouse_id.c_str(), entity.c_str());
}
