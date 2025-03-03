#ifndef JSON_H
#define JSON_H

#include <Arduino.h>
#include <ArduinoJson.h>

void parseJson(const String &jsonString);
char *printJson(const int id, const bool isOpen, const bool isFilled, const bool isTilted);

#endif