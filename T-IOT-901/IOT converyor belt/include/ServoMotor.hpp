#ifndef SERVOMOTOR_HPP
#define SERVOMOTOR_HPP

#include <M5Stack.h>
#include "NodeManager.hpp"

#define PWM_CHANNEL 0
#define PWM_FREQUENCY 50
#define PWM_RESOLUTION 16
#define SERVO_PIN 26

class ServoMotor
{
public:
    ServoMotor();
    ~ServoMotor() = default;

    void initialize();
    void setAngle(int angle);
    int calculateAngle(const int warehouseId);

};

#endif
