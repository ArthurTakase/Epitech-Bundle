#include "Motion.hpp"

Motion::Motion() {}

void Motion::initialize()
{
    pinMode(MOTION_INIT_PIN, OUTPUT);
    digitalWrite(MOTION_INIT_PIN, HIGH);
    pinMode(MOTION_READ_PIN, INPUT);
    Serial.println("Motion sensor initialized.");
}

bool Motion::isMotionDetected() const
{
    return digitalRead(MOTION_READ_PIN) == HIGH;
}
