#include <Arduino.h>
// #include <ArduinoJson.h>

void parseJson(const String &jsonString)
{
  // StaticJsonDocument<200> doc; // Adjust the size according to your JSON data
  // DeserializationError error = deserializeJson(doc, jsonString);
  // const long id = doc["ID"];        // Replace "key" with the actual key in your JSON
  // const char *value = doc["VALUE"]; // Replace "key" with the actual key in your JSON
  // switch (id)
  // {
  // case 1:
  //   if (strcmp(value, "FULL") == 0)
  //   {
  //     if (photoResistorStateFilled != true)
  //     {
  //       photoResistorStateFilledOld = photoResistorStateFilled;
  //       photoResistorStateFilled = true;
  //     }
  //   }
  //   else
  //   {
  //     if (photoResistorStateFilled != false)
  //     {
  //       photoResistorStateFilledOld = photoResistorStateFilled;
  //       photoResistorStateFilled = false;
  //     }
  //   }

  //   break;
  // case 2:
  //   if (strcmp(value, "FULL") == 0)
  //   {
  //     if (USStateFilled != true)
  //     {
  //       USStateFilledOld = USStateFilled;
  //       USStateFilled = true;
  //     }
  //   }
  //   else if (strcmp(value, "EMPTY") == 0)
  //   {
  //     if (USStateFilled != false)
  //     {
  //       USStateFilledOld = USStateFilled;
  //       USStateFilled = false;
  //     }
  //   }
  // break;

  // default:
  // break;
  // }
}

char *printJson(const int id, const bool isOpen, const bool isFilled, const bool isTilted)
{
  char *json = (char *)malloc(100 * sizeof(char));
  sprintf(json, "{\"id\":%d,\"isFilled\":\"%s\",\"isOpen\":\"%s\",\"isTilted\":\"%s\"}", id, isFilled ? "true" : "false", isOpen ? "true" : "false", isTilted ? "true" : "false");
  return json;
}
