#ifndef MOTION_SENSOR_HPP
#define MOTION_SENSOR_HPP

#include <M5Stack.h>

#define MOTION_INIT_PIN 26
#define MOTION_READ_PIN 36

class Motion
{
public:
    Motion();
    ~Motion() = default;

    void initialize();
    bool isMotionDetected() const;
};

#endif
