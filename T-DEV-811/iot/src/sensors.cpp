#include <Arduino.h>
#include "pinout.h"

void initSensors()
{
  // Serial.println("Initializing sensors...");
  pinMode(22, OUTPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, OUTPUT);
  pinMode(30, INPUT);

  pinMode(52, OUTPUT);
  pinMode(50, INPUT);
  pinMode(48, INPUT);
  pinMode(46, OUTPUT);
  pinMode(44, INPUT);

  pinMode(53, OUTPUT);
  pinMode(51, INPUT);
  pinMode(49, INPUT);
  pinMode(47, OUTPUT);
  pinMode(45, INPUT);
}

bool readTiltSensor(const int tiltPin_)
{
  return digitalRead(tiltPin_);
}

bool readInfraredSensor(const int infraredLedPin_, const int infraredPin_)
{
  digitalWrite(infraredLedPin_, HIGH);
  delay(10);
  bool result = digitalRead(infraredPin_);
  delay(10);
  digitalWrite(infraredLedPin_, LOW);
  return result;
}

float readUltrasonicSensor(const int trigPin_, const int echoPin_)
{
  long duration;
  float distance = 0;

  digitalWrite(trigPin_, LOW);
  // delayMicroseconds(2);
  delay(0.2);
  digitalWrite(trigPin_, HIGH);
  delay(1);
  // delayMicroseconds(10);
  digitalWrite(trigPin_, LOW);

  duration = pulseIn(echoPin_, HIGH);
  distance = (duration * 0.034) / 2;
  return distance;
}
