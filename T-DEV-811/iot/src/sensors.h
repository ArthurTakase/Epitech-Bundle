#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

void initSensors();

bool readTiltSensor(const int tiltPin_);
bool readInfraredSensor(const int infraredLedPin_, const int infraredPin_);
float readUltrasonicSensor(const int trigPin_, const int echoPin_);

#endif