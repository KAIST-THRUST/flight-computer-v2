#pragma once

#include <Arduino.h>
#include <Servo.h>

#undef MIN_PULSE_WIDTH;
#undef MAX_PULSE_WIDTH;

#define MIN_PULSE_WIDTH       500     // the shortest pulse sent to a servo
#define MAX_PULSE_WIDTH      2500     // the longest pulse sent to a servo

class BallValve{

    private:
    Servo servo;
    const uint8_t pin_num;

    public:
    BallValve(uint8_t BallValve_pin_num);
    void begin();

    void open();
    void halfOpen();
    void close();

    void open(int angle);

    int showAngle();

};

