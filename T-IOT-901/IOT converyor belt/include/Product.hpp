#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <ArduinoJson.h>
#include <vector>

class Product {
public:
    Product();
    ~Product() = default;

    Product(String id, String ref, String label, String warehouse_id, String entity);

    static Product parseFromJson(const String &jsonResponse);
    void printProduct() const;

    String id;
    String ref;
    String label;
    String warehouse_id;
    String entity;
};

#endif