#include "ServoMotor.hpp"

ServoMotor::ServoMotor() {}

void ServoMotor::initialize()
{
    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(SERVO_PIN, PWM_CHANNEL);
    Serial.println("Servo motor initialized");
}

void ServoMotor::setAngle(int angle)
{
    int dutyCycle = map(angle, 0, 180, 3277, 6554);
    ledcWrite(PWM_CHANNEL, dutyCycle);
}

int ServoMotor::calculateAngle(const int warehouseId)
{
    switch (warehouseId)
    {
    case 1:
        return 23;
    case 2:
        return -12;
    case 3:
        return -40;
    default:
        return 0;
    }
}
