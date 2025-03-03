#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <M5Stack.h>
#include <Wire.h>
#include "Module_GRBL_13.2.h"

#define STARTING_MOTOR_AFTER_A_STOP "~"
#define STOPPING_MOTOR "!"
#define RELATIVE_MODE "G91"
#define STEPMOTOR_I2C_ADDR 0x70

class Motor
{
public:
    Motor();
    ~Motor() = default;

    void initialize();
    void handleMotorInstructions(bool isProductReferenced, bool shouldMotorBeActive);
    bool isPaused() const;
    void setMotorPaused(bool paused);

private:
    Module_GRBL grbl;
    bool isMotorPaused;
};

#endif
